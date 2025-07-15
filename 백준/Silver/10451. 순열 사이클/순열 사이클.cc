#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int arr[1001];
bool visited[1001];
int Count;

void dfs(int node)
{
	visited[node] = true;
	int next = arr[node];
	if (!visited[next])
	{
		dfs(next);
	}
}

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;

		for (int i = 1; i <= N; i++) cin >> arr[i];

		Count = 0;

		for (int i = 1; i <= N; i++)
		{
			if (!visited[i])
			{
				dfs(i);
				Count++;
			}
		}
		memset(visited, false, sizeof(visited));
		cout << Count << endl;
	}
}