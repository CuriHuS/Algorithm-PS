#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    priority_queue<pair<int, int>> pq;
    
    vector<pair<int, int>> graph[n+1];
    // index: 출발 위치, 좌측: cost, 우측: 도착 위치
    
    for (int i=0; i<fares.size(); i++)
    {
        graph[fares[i][0]].push_back(make_pair(fares[i][1], fares[i][2]));
        graph[fares[i][1]].push_back(make_pair(fares[i][0], fares[i][2]));
    }
    
    int distA[201];
    for (int i=1; i<=n; i++)
    {
        distA[i] = 99999999;
    }
    distA[a] = 0;
    pq.push(make_pair(0, a));

    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        for (int i=0; i<graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;
            int nCost = graph[cur][i].second;
            if (distA[next] > cost + nCost)
            {
                distA[next] = cost + nCost;
                pq.push(make_pair(-distA[next], next));
            }
        }
    }
    
    int distB[201];
    for (int i=1; i<=n; i++)
    {
        distB[i] = 99999999;
    }
    distB[b] = 0;
    pq.push(make_pair(0, b));

    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        for (int i=0; i<graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;
            int nCost = graph[cur][i].second;
            if (distB[next] > cost + nCost)
            {
                distB[next] = cost + nCost;
                pq.push(make_pair(-distB[next], next));
            }
        }
    }
    
    
    int distS[201];
    for (int i=1; i<=n; i++)
    {
        distS[i] = 99999999;
    }
    distS[s] = 0;
    pq.push(make_pair(0, s));

    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        for (int i=0; i<graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;
            int nCost = graph[cur][i].second;
            if (distS[next] > cost + nCost)
            {
                distS[next] = cost + nCost;
                pq.push(make_pair(-distS[next], next));
            }
        }
    }
    
    int dist[201];
    for (int i=1; i<=n; i++)
    {
        dist[i] = distA[i] + distB[i] + distS[i];
    }
    
    int minDist = 99999999;
    for (int i=1; i<=n; i++)
    {
        if (minDist > dist[i]) minDist = dist[i];
    }
    
    answer = minDist;
    
    return answer;
}