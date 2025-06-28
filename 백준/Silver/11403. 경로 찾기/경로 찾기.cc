#include <iostream>
#include <algorithm>
#define INF 9999999

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	int** graph = new int* [N];
	for (int i = 0; i < N; i++)
	{
		graph[i] = new int[N];
		for (int j = 0; j < N; j++)
		{
			graph[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (graph[i][j] == 0)
				graph[i][j] = INF;
		}
	}

	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (graph[i][j] == INF)
				cout << 0 << " ";
			else cout << 1 << " ";
		}
		cout << "\n";
	}
}