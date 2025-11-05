#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum spaceType
{
	WALL,
	EMPTY
};

struct maze
{
	spaceType type;
	int jihoonTime;
	int fireTime;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int R, C;
	cin >> R >> C;
	vector<vector<maze>> graph(R, vector<maze>(C, { EMPTY, -1,-1 }));
	queue<pair<int, int>> fireStart;
	pair<int, int> jihoonStart;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			char a;
			cin >> a;
			if (a == '#')
			{
				graph[i][j].type = WALL;
				continue;
			}
			if (a == 'J')
			{
				jihoonStart = { i, j };
				graph[i][j].jihoonTime = 0;
				continue;
			}
			if (a == 'F')
			{
				fireStart.push({ i,j });
				graph[i][j].fireTime = 0;
				continue;
			}
		}
	}

	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };

	queue<pair<int, int>> q;
	q.push({ jihoonStart.first, jihoonStart.second });
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
			{
				continue;
			}

			if (graph[nx][ny].type == WALL)
			{
				continue;
			}

			// 이미 지나쳤던 곳
			if (graph[nx][ny].jihoonTime != -1)
				continue;

			graph[nx][ny].jihoonTime = graph[x][y].jihoonTime + 1;
			q.push({ nx,ny });
		}
	}

	// 불 BFS
	while (!fireStart.empty())
	{
		int x = fireStart.front().first;
		int y = fireStart.front().second;
		fireStart.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
			{
				continue;
			}
			if (graph[nx][ny].type == WALL)
			{
				continue;
			}

			// 이미 지나쳤던 곳
			if (graph[nx][ny].fireTime != -1)
				continue;

			graph[nx][ny].fireTime = graph[x][y].fireTime + 1;
			fireStart.push({ nx,ny });
		}
	}

	int minExitTime = 1000001;
	for (int i = 0; i < R; i++)
	{
		if (i == 0 || i == R - 1)
		{
			for (int j = 0; j < C; j++)
			{
				if (graph[i][j].type == WALL) continue;

				if (graph[i][j].jihoonTime == -1) continue;

				if (graph[i][j].fireTime == -1)
				{
					minExitTime = min(minExitTime, graph[i][j].jihoonTime);
				}

				if (graph[i][j].jihoonTime < graph[i][j].fireTime)
				{
					minExitTime = min(minExitTime, graph[i][j].jihoonTime);
				}
			}
		}

		else
		{
			for (int j = 0; j < C; j++)
			{
				if (j != 0 && j != C - 1) continue;

				if (graph[i][j].type == WALL) continue;

				if (graph[i][j].jihoonTime == -1) continue;

				if (graph[i][j].fireTime == -1)
				{
					minExitTime = min(minExitTime, graph[i][j].jihoonTime);
				}

				if (graph[i][j].jihoonTime < graph[i][j].fireTime)
				{
					minExitTime = min(minExitTime, graph[i][j].jihoonTime);
				}
			}
		}
	}
	if (minExitTime == 1000001) cout << "IMPOSSIBLE";
	else cout << minExitTime + 1;
}