#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

vector<pair<int, int>> points;

long long calcDist(pair<int, int> a, pair<int, int> b)
{
    return (long long)(a.first - b.first) * (a.first - b.first) + 
           (long long)(a.second - b.second) * (a.second - b.second);
}

long long divide(vector<pair<int, int>>& v, int left, int right)
{
    if (right - left <= 3)
    {
        long long minDist = LLONG_MAX;
        for (int i = left; i < right; i++)
        {
            for (int j = i + 1; j < right; j++)
            {
                minDist = min(minDist, calcDist(v[i], v[j]));
            }
        }
        return minDist;
    }
    
    int mid = (left + right) / 2;
    int midX = v[mid].first;
    
    long long d1 = divide(v, left, mid);
    long long d2 = divide(v, mid, right);
    long long dist = min(d1, d2);
    
    // midX로부터 sqrt(dist) 거리 내에 있는 점들만 수집
    vector<pair<int, int>> strip;
    for (int i = left; i < right; i++)
    {
        long long dx = v[i].first - midX;
        if (dx * dx < dist)
        {
            strip.push_back(v[i]);
        }
    }
    
    // y좌표를 기준으로 정렬
    sort(strip.begin(), strip.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    
    // strip 내에서 최소 거리 찾기
    for (int i = 0; i < strip.size(); i++)
    {
        // y좌표 차이가 sqrt(dist)보다 작은 점들만 확인
        for (int j = i + 1; j < strip.size(); j++)
        {
            long long dy = strip[j].second - strip[i].second;
            if (dy * dy >= dist) break;  // y좌표 차이가 크면 더 이상 확인할 필요 없음
            
            dist = min(dist, calcDist(strip[i], strip[j]));
        }
    }
    
    return dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    points.reserve(n);  // 메모리 재할당 최소화
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
    
    sort(points.begin(), points.end());
    
    cout << divide(points, 0, n) << '\n';
    
    return 0;
}