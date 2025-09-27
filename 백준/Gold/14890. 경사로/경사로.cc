#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, L;
	cin >> N >> L;

	vector<vector<int>> graph;
	for (int i = 0; i < N; i++)
	{
		vector<int> temp;
		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;
			temp.push_back(a);
		}
		graph.push_back(temp);
	}

	int answer = 0;

	// 행 탐색
	for (int i = 0; i < N; i++)
	{
		bool isAnswer = true;
		bool isDown = false;
		bool isUp = false;
		int nums = 1;

		for (int j = 1; j < N; j++)
		{
			if (graph[i][j - 1] == graph[i][j])
			{
				nums++;
				if (isDown)
				{
					if (nums >= L)
					{
						nums -= L;
						isDown = false;
					}
				}
				continue;
			}
			// 낮은 곳으로 이동할 때
			else if (graph[i][j - 1] == 1 + graph[i][j])
			{
				if (isDown) // 연속적으로 내려갈 때
				{
					if (nums < L)
					{
						isAnswer = false;
						break;
					}
				}
				isDown = true;
				nums = 1;
				
				if (nums >= L)
				{
					isDown = false;
					nums -= L;
				}

			}
			// 높은 곳으로 이동할 때
			else if (graph[i][j - 1] + 1 == graph[i][j])
			{
				if (isDown)
				{
					if (nums >= L) nums -= L;
					isDown = false;
				}
				if (nums < L)
				{
					isAnswer = false;
					break;
				}
				nums = 1;
			}
			else
			{
				isAnswer = false;
				break;
			}
		}
		if (!isDown && isAnswer)
		{
			answer++;
			//cout << " 행: " << i;
		}
	}

	// 열 탐색
	for (int j = 0; j < N; j++)
	{
		bool isAnswer = true;
		bool isDown = false;
		bool isUp = false;
		int nums = 1;

		for (int i = 1; i < N; i++)
		{
			if (graph[i - 1][j] == graph[i][j])
			{
				nums++;
				if (isDown)
				{
					if (nums >= L)
					{
						nums -= L;
						isDown = false;
					}
				}
				continue;
			}
			// 내려 가는 경우
			else if (graph[i - 1][j] == 1 + graph[i][j])
			{
				if (isDown) // 연속적으로 내려갈 때
				{
					if (nums < L)
					{
						isAnswer = false;
						break;
					}
				}
				isDown = true;
				nums = 1;

				if (nums >= L)
				{
					isDown = false;
					nums -= L;
				}
			}
			// 올라가야 할 때
			else if (graph[i - 1][j] + 1 == graph[i][j])
			{
				if (isDown)
				{
					if (nums >= L)
					{
						nums -= L;
						isDown = false;
					}
				}
				if (nums < L)
				{
					isAnswer = false;
					break;
				}
				nums = 1;
			}
			else
			{
				isAnswer = false;
				break;
			}
		}
		if (!isDown && isAnswer)
		{
			//cout << "열: " << j;
			answer++;
		}
	}

	cout << answer;
}