#include <iostream>
#include <queue>
#include <algorithm>

#define INF 999999

using namespace std;

long long goDist[1001]; // 출발 거리
long long backDist[1001]; // 도착 거리
long long totalDist[1001]; // 합계 거리

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N, M, X;
	cin >> N >> M >> X;

	vector<pair<int, int>> vertex[1001];
	vector<pair<int, int>> reverseVertex[1001];
	long long dist[1001];

	int a, b, t;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> t;
		vertex[a].push_back(make_pair(b, t));
		reverseVertex[b].push_back(make_pair(a, t));
	}

	for (int i = 1; i <= N; i++)
	{
		dist[i] = INF;
		goDist[i] = INF;
		backDist[i] = INF;
		totalDist[i] = INF;
	}

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, X));

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost) continue;

		for (int i = 0; i < reverseVertex[cur].size(); i++)
		{
			int next = reverseVertex[cur][i].first;
			int nextCost = reverseVertex[cur][i].second;

			if (dist[next] > cost + nextCost)
			{
				dist[next] = cost + nextCost;
				pq.push(make_pair(-dist[next], next));
			}
		}
	}

	for (int i=1; i<=N; i++) goDist[i] = dist[i];


	// X 마을 -> 각 마을

	pq.push(make_pair(0, X));
	bool visited[1001];
	visited[X] = true;
	for (int i = 1; i <= N; i++) dist[i] = INF;

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost) continue;

		for (int i = 0; i < vertex[cur].size(); i++)
		{
			int next = vertex[cur][i].first;
			int nextCost = vertex[cur][i].second;

			if (dist[next] > cost + nextCost)
			{
				dist[next] = cost + nextCost;
				pq.push(make_pair(-dist[next], next));
			}
		}
	}
	for (int i = 1; i <= N; i++) backDist[i] = dist[i];


	for (int i = 1; i <= N; i++)
	{
		totalDist[i] = goDist[i] + backDist[i];
	}

	long long maxDist = 0;
	for (int i = 1; i <= N; i++)
	{
		if (N == 1) maxDist = 0;
		if (i == X) continue;
		maxDist = max(totalDist[i], maxDist);
	}
	cout << maxDist;
}