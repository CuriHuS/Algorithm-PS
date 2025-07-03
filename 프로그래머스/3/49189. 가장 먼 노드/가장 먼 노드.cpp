#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define INF 999999

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<pair<int, int>> graph[n+1];
    for (int i=0; i<edge.size(); i++)
    {
        graph[edge[i][0]].push_back(make_pair(edge[i][1], 1));
        graph[edge[i][1]].push_back(make_pair(edge[i][0], 1));
    }

    priority_queue<pair<int, int>> PQ;
    PQ.push(make_pair(0, 1));
    
    int* dist = new int[n+1];
    for (int i=0; i<=n; i++) dist[i] = INF;
    dist[1] = 0;
    
    while(!PQ.empty())
    {
        int cost = - PQ.top().first;
        int node = PQ.top().second;
        PQ.pop();
        
        if (dist[node] < cost) continue;
        
        for (int i=0; i<graph[node].size(); i++)
        {
            int next = graph[node][i].first;
            int nCost = graph[node][i].second;
            
            if (dist[next] > nCost + cost)
            {
                dist[next] = nCost + cost;
                PQ.push(make_pair(-dist[next], next));
            }
        }
    }
    int maxDist = 0;
    for (int i=1; i<=n; i++)
    {
        if(maxDist < dist[i])
        {
            answer = 1;
            maxDist = dist[i];
        }
        else if (maxDist == dist[i])
        {
            answer += 1;
        }
    }
    return answer;
}