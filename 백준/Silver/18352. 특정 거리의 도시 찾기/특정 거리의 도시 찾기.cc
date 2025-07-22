#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 300000
#define INF 9999999


vector<int> graph[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, K, X;
	cin >> N >> M >> K >> X;


	int a, b;
	vector<int> answer;
	int* dist = new int[N + 1];
	for (int i = 1; i <= M; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
	}
	for (int i = 1; i <= N; i++) dist[i] = INF;

	dist[X] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, X));

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i];
			int next_cost = 1 + cost;

			if (next_cost < dist[next])
			{
				dist[next] = next_cost;
				pq.push(make_pair(-next_cost, next));
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (dist[i] == K)
		{
			answer.push_back(i);
		}
	}
	if (answer.size() == 0)
	{
		cout << -1;
	}
	else
	{
		for (int i = 0; i < answer.size(); i++)
			cout << answer[i] << "\n";
	}
}