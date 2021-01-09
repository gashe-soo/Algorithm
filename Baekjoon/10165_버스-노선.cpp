// 백준 10165번 버스-노선

/*
정렬 문제
1. 버스 노선을 저장
    - 만약 시작점보다 끝점이 작은 경우는 n를 더해서 순환 구조를 직선 구조로 변환
    - 만약 끝 점이 n를 넘어간다면 시작점,끝점 모두 n를 빼서 또 저장 => 앞부터 확인하면 한번만 돌면 된다.
2. 정렬
    - 시작점이 작은 것부터
    - 시작점 같다면 끝점이 더 큰 것 부터

3. 포함 여부 확인
    - 하나의 기준 노선을 저장
    - 만약 이전 기준 노선에 포함되어 있지 않다면 그게 새로운 기준 노선

4. 정렬 및 중복 제거.

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Bus {
    int idx, start, end;
    bool operator<(const Bus& b)
    {
        if (start == b.start)
            return end > b.end;
        return start < b.start;
    }
};

int n, m;
vector<Bus> line;
vector<int> ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    int s, e;
    for (int i = 1; i <= m; i++) {
        cin >> s >> e;
        if (s > e) {
            e += n;
        }
        if (e > n) {
            line.push_back({ i, s - n, e - n });
        }
        line.push_back({ i, s, e });
    }

    sort(line.begin(), line.end());

    int bStart = 0, bEnd = 0;
    for (int i = 0; i < line.size(); i++) {
        if (line[i].end <= bEnd)
            continue;
        bStart = line[i].start, bEnd = line[i].end;
        ans.push_back(line[i].idx);
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}