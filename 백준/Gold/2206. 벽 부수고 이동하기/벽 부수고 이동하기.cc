#include <iostream>
#include <queue>

using namespace std;

#define INF 999999

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;
	
	int** graph = new int* [N+1];
	int** visitList = new int* [N + 1];
	long long*** dist = new long long** [N + 1];
	
	for (int i = 0; i <= N; i++)
	{
		graph[i] = new int[M + 1];
		visitList[i] = new int[M + 1];
		dist[i] = new long long* [M + 1];
		for (int j = 1; j <= M; j++)
		{
			visitList[i][j] = 0;
			dist[i][j] = new long long[2];
			//dist[i][j][0] = 1; // 부술 수 있는 횟수
			dist[i][j][1] = INF; // 이동 거리
		}
	}

	string line;
	for (int i = 1; i <= N; i++)
	{
		cin >> line;

		for (int j = 1; j <= M; j++)
		{
			graph[i][j] = line[j-1] - 48;
		}
	}

	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(1, 1), 1));
	dist[1][1][1] = 1;
	dist[1][1][0] = 1;

	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int state = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			// 이동 가능한 거리
			int nowX = x + dx[i];
			int nowY = y + dy[i];


			if (nowX >= 1 && nowX <= N && nowY >= 1 && nowY <= M)
			{
				if (dist[nowX][nowY][1] != INF && state == 0) continue; // 방문했고 내가 못 뚫어
				if (dist[nowX][nowY][1] != INF && dist[nowX][nowY][0] == 1) continue;
				if (graph[nowX][nowY] == 1 && state == 0) continue;

				if (graph[nowX][nowY] == 0)
				{
					// 이동 가능
					dist[nowX][nowY][1] = dist[x][y][1] + 1;
					dist[nowX][nowY][0] = state;
					q.push(make_pair(make_pair(nowX, nowY), state));
					if (nowX == N && nowY == M)
					{
						for (int i = 0; i < q.size(); i++) q.pop();
						break;
					}
				}
				else // 벽인 경우
				{
					// 이동 안 됨, 그래서 부술 수 있는지 확인 필요함.
					if (state == 1)
					{
						// 부수고 이동 가능
						dist[nowX][nowY][0] = 0;
						dist[nowX][nowY][1] = dist[x][y][1] + 1;
						q.push(make_pair(make_pair(nowX, nowY), 0));
					}
				}

				//cout << "이동: " << nowX << " y좌표: " << nowY << "부술 수 있나?: " << state << endl;
			}
		}


	}
	if (dist[N][M][1] == INF) cout << -1;
	else cout << dist[N][M][1];
}