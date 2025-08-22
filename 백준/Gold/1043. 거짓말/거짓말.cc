#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	int answer = 0;

	int graph[51][51];
	for (int i = 0; i <= M; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			graph[i][j] = 0;
		}
	}
	// 참가X : 0
	// 참가하지만 진실 모름: 1
	// 진실을 알면: 2
	

	// 진실 모르면 0
	// 진실 알면 1
	int truth[51];
	for (int i = 0; i < N; i++) truth[i] = 0;
	
	int a;
	cin >> a;

	queue<int> q;
	for (int i = 0; i < a; i++)
	{
		int n;
		cin >> n;
		truth[n] = 1;
	}

	int num;
	for (int i = 1; i <= M; i++)
	{
		cin >> num;
		int b;
		for (int j = 1; j <= num; j++)
		{
			cin >> b;
			if (truth[b] == 1)
			{
				graph[i][b] = 2;
				q.push(b);
			}
			else graph[i][b] = 1;
		}
	}

	while (!q.empty())
	{
		int next = q.front();
		q.pop();

		for (int i = 1; i <= M; i++)
		{
			if (graph[i][next] != 0)
			{
				graph[i][next] = 2;
				for (int j = 1; j <= N; j++)
				{
					if (graph[i][j] == 1)
					{
						graph[i][j] = 2;
						q.push(j);
					}
				}
			}
		}
	}

	for (int i = 1; i <= M; i++)
	{
		bool check = false;
		for (int j = 1; j <= N; j++)
		{
			if (graph[i][j] == 2)
			{
				check = true;
				break;
			}
		}
		if (!check) answer++;
	}

	cout << answer;
}