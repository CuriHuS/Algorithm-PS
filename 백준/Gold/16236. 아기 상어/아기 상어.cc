#include <iostream>
#include <queue>
using namespace std;


int graph[21][21]; // 공간
int babyScale = 2; // 아기 상어 크기
int experience; // 현재 먹은 물고기 수(크기 커지면 초기화)
int babyX, babyY; // 아기 상어 좌표

// 디버깅 함수
void Print(int N)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
}

// 물고기 먹는 함수
void Eat(int& exp)
{
	exp++;
	if (exp == babyScale)
	{
		exp = 0;
		babyScale++;
	}
}

// 물고기 탐색 함수
pair<pair<int, int>, int> Find(int N)
{

	int dx[4] = { -1,0,0, 1 };
	int dy[4] = { 0,-1,1, 0 };

	queue<pair<int, int>> q;
	q.push(make_pair(babyX, babyY));
	int distance = 999999;
	int resultX = 0;
	int resultY = 0;
	int visit_list[21][21];
	for (int i = 1; i <= 20; i++)
	{
		for (int j = 1; j <= 20; j++)
			visit_list[i][j] = 0;
	}

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nowX = x + dx[i];
			int nowY = y + dy[i];

			if (visit_list[nowX][nowY] != 0 || nowX <= 0 || nowX > N || nowY <= 0 || nowY > N)  continue;

			// 아기 상어 보다 작은 물고기 발견
			if (babyScale > graph[nowX][nowY] && graph[nowX][nowY] != 0 && graph[nowX][nowY] != 9)
			{
				// 처음 발견했을 때
				if (distance > visit_list[x][y] + 1)
				{
					visit_list[nowX][nowY] = visit_list[x][y] + 1;
					distance = visit_list[nowX][nowY];
					resultX = nowX;
					resultY = nowY;
				}

				// 거리가 같은 경우 누가 더 높이 있는지 검사
				else if (distance == visit_list[x][y]+1)
				{
					if (resultX > nowX)
					{
						resultX = nowX;
						resultY = nowY;
					}

					// 같은 높이일 때 누가 더 왼쪽에 있는지 검사
					else if (resultX == nowX)
					{
						// 새로운 탐색 위치가 더 좌측임
						if (resultY > nowY)
						{
							resultX = nowX;
							resultY = nowY;
						}
					}
				}
			}

			// 지나갈 수 있음(빈 공간이거나 같은 크기의 물고기)
			else if (babyScale >= graph[nowX][nowY])
			{
				visit_list[nowX][nowY] = visit_list[x][y]+1;
				q.push(make_pair(nowX, nowY));
			}
		}
	}
	return make_pair(make_pair(resultX, resultY), distance);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 9)
			{
				babyX = i;
				babyY = j;
			}
		}
	}

	bool momHelp = false;
	int time = 0;



	while (!momHelp)
	{
		pair<pair<int, int>,int> result = Find(N);
		int x = result.first.first;
		int y = result.first.second;
		int dist = result.second;

		if (x == 0 && y == 0)
		{
			momHelp = true;
		}

		else
		{
			time += dist;
			graph[babyX][babyY] = 0;
			babyX = x;
			babyY = y;
			Eat(::experience);
			graph[x][y] = 9;
		}
	}
	cout << time;
}