#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum Direction
{
	Up = 0,
	Right = 1,
	Down = 2,
	Left = 3
};

struct Snake
{
	Direction direct;
	queue<pair<int, int>> body;
	int x;
	int y;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, K, L;
	cin >> N >> K;

	// 1은 뱀 몸, 2는 사과, 0은 빈 곳
	vector<vector<int>> board;

	for (int i = 0; i < N; i++)
	{
		vector<int> temp;
		for (int j = 0; j < N; j++)
		{
			temp.push_back(0);
		}
		board.push_back(temp);
	}

	for (int i = 0; i < K; i++)
	{
		int a, b;
		cin >> a >> b;
		board[a-1][b-1] = 2;
	}

	cin >> L;

	queue<pair<int, char>> moves;

	for (int i = 0; i < L; i++)
	{
		int a;
		string b;
		cin >> a >> b;
		moves.push({ a,b[0] });
	}

	int step = 0;
	Snake snake;

	snake.direct = (Direction)Right;
	snake.body.push({ 0,0 });
	snake.x = 0;
	snake.y = 0;
	board[0][0] = 1;

	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };

	while (true)
	{
		// 몸 길이 늘리기
		int nx = snake.x + dx[snake.direct];
		int ny = snake.y + dy[snake.direct];
		
		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
		{
			break;
		}

		// 사과 있으면
		if (board[nx][ny] == 2)
		{
			board[nx][ny] = 0;
		}

		// 몸이랑 부딪히면
		else if (board[nx][ny] == 1)
		{
			break;
		}

		// 아무것도 없음
		else
		{
			int x = snake.body.front().first;
			int y = snake.body.front().second;
			snake.body.pop();
			board[x][y] = 0;
		}

		board[nx][ny] = 1;
		snake.x = nx;
		snake.y = ny;
		snake.body.push({ nx, ny });
		step++;

		while (!moves.empty())
		{
			int time = moves.front().first;
			char dir = moves.front().second;

			if (step == time)
			{
				moves.pop();
				if (dir == 'L')
				{
					if (snake.direct - 1 < 0)
					{
						snake.direct = (Direction)3;
					}
					else
					{
						snake.direct = (Direction)(snake.direct - 1);
					}
				}
				else
				{
					if (snake.direct + 1 > 3)
					{
						snake.direct = (Direction)0;
					}
					else
					{
						snake.direct = (Direction)(snake.direct + 1);
					}
				}
			}
			break;
		}
	}

	cout << step + 1;
}