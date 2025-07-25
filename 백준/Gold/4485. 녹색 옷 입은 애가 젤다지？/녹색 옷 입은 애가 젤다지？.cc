#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 125
#define INF 999999

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T = 1;
	while (true)
	{
		int N;
		cin >> N;
		if (N == 0) break;
		vector<int> graph[MAX];
		int dist[MAX][MAX];
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int a;
				cin >> a;
				graph[i].push_back(a);
				dist[i][j] = INF;
			}
		}

		priority_queue<pair<int, pair<int, int>>> pq;
		pq.push({ -graph[0][0], {0, 0} });
		dist[0][0] = graph[0][0];
		int dx[4] = { 1,-1,0,0 };
		int dy[4] = { 0,0,1,-1 };

		while (!pq.empty())
		{
			int cost = -pq.top().first;
			int curX = pq.top().second.first;
			int curY = pq.top().second.second;
			pq.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = curX + dx[i];
				int ny = curY + dy[i];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N)
				{
					if (graph[nx][ny] + cost < dist[nx][ny])
					{
						dist[nx][ny] = graph[nx][ny] + cost;
						pq.push({ -dist[nx][ny], {nx, ny} });
					}
				}
			}
		}
		cout << "Problem " << T++ << ": " << dist[N - 1][N - 1] << "\n";
	}
}