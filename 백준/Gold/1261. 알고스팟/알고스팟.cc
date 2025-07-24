#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 999999

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	int graph[101][101];
	int dist[101][101];
	for (int i = 1; i <= M; i++)
	{
		string a;
		cin >> a;

		for (int j = 1; j <= N; j++)
		{
			dist[i][j] = INF;
			graph[i][j] = a[j - 1] - char('0');
		}
	}

	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };

	queue<pair<int, int>> q;
	q.push({ 1,1 });
	dist[1][1] = 0;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M)
			{
				if (dist[ny][nx] > dist[y][x] + graph[y][x])
				{
					dist[ny][nx] = dist[y][x] + graph[y][x];
					q.push({ ny, nx });
				}
			}
		}
	}

	cout << dist[M][N];
}