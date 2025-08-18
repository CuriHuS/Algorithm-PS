#include <iostream>

using namespace std;

void dfs(int n, int m, int visited[], int arr[], int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == 0)
		{
			arr[cnt] = i;
			visited[i] = 1;
			dfs(n, m, visited, arr, cnt + 1);
			visited[i] = 0;
		}
	}
	return;
}

int main()
{
	int N, M;
	cin >> N >> M;
	int arr[9] = { 0 };
	int visited[9] = { 0 };

	dfs(N, M, visited, arr, 0);
}