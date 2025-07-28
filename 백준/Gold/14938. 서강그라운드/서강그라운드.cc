#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 999999

int main()
{
	int n, l, m, r;
	cin >> n >> m >> r;
	vector<pair<int, int>> graph[101];
	int items[101]; int result[101];
	for (int i = 1; i <= n; i++)
	{
		cin >> items[i];
		result[i] = 0;
	}

	int a, b;
	for (int i = 1; i <= r; i++)
	{
		cin >> a >> b >> l;
		graph[a].push_back({b, l});
		graph[b].push_back({ a,l });
	}
	int dist[101];
	for (int t = 1; t <= n; t++)
	{
		for (int i = 1; i <= n; i++) dist[i] = INF;
		dist[t] = 0;

		priority_queue<pair<int, int>> pq;
		pq.push({ 0,t  });

		while (!pq.empty())
		{
			int cost = -pq.top().first;
			int cur = pq.top().second;
			pq.pop();

			for (int i = 0; i < graph[cur].size(); i++)
			{
				int nCost = graph[cur][i].second;
				int next = graph[cur][i].first;
				if (dist[next] > nCost + cost)
				{
					dist[next] = nCost + cost;
					pq.push({ -dist[next], next });
				}
			}
		}

		for (int i = 1; i <= n; i++)
		{
			if (dist[i] <= m)
			{
				result[t] += items[i];
			}
		}
	}

	cout << *max_element(result + 1, result + (n+1));
}