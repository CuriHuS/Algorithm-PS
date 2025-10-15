#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const long long INF = 1e9;

struct graph
{
	vector<pair<int, pair<int, int>>> edges;
	vector<vector<int>> adj;
};

vector<int> inputCity()
{
	int N, M, start, end;
	cin >> N >> M >> start >> end;
	return { N,M,start,end };
}

vector<int> inputEarning(int N)
{
	vector<int> temp(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> temp[i];
	}
	return temp;
}

graph input(int N, int M)
{
	graph v;
	v.adj.assign(N, vector<int>());

	for (int i = 0; i < M; i++)
	{
		int s, e, c;
		cin >> s >> e >> c;

		v.edges.push_back({ c, {s,e} });
		v.adj[s].push_back(e);
	}
	return v;
}

bool isInPath(const graph& v, int N, int start, int end)
{
	vector<bool> visited(N, false);
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		if (cur == end) return true;

		for (int next : v.adj[cur])
		{
			if (!visited[next])
			{
				visited[next] = true;
				q.push(next);
			}
		}
	}
	return false;
}

bool bellmanFord(int start, int end, int city, graph& v, vector<long long>& dist, vector<int>& earn)
{
	dist[start] = -earn[start];
	vector<int> cycle;
	for (int i = 0; i < city; i++)
	{

		for (int j = 0; j < v.edges.size(); j++)
		{
			int from = v.edges[j].second.first;
			int to = v.edges[j].second.second;
			int cost = v.edges[j].first;

			if (dist[from] == INF) continue;

			if (dist[to] > dist[from] + cost - earn[to])
			{
				dist[to] = dist[from] + cost - earn[to];
				if (i == city - 1)
				{
					cycle.push_back(to);
				}
			}
		}
	}

	for (int node : cycle)
	{
		if (isInPath(v, city, node, end))
		{
			return true;
		}
	}

	return false;
}

long long solution(int city, int start, int end, graph v, vector<int> earn)
{
	vector<long long> dist(city, INF);
	bool isCycle = bellmanFord(start, end, city, v, dist, earn);


	if (dist[end] == INF)
	{
		cout << "gg";
		return -INF;
	}

	if (isCycle)
	{
		cout << "Gee";
		return -INF;
	}

	return dist[end];
}

int main()
{
	vector<int> v = inputCity();
	int cityCount = v[0];
	int startCity = v[1];
	int endCity = v[2];
	int trafficCount = v[3];

	graph city = input(cityCount, trafficCount);
	vector<int> earnings = inputEarning(cityCount);

	int maxEarning = solution(cityCount, startCity, endCity, city, earnings);
	if (maxEarning == -INF)
	{
		return 0;
	}
	cout << -maxEarning;
}