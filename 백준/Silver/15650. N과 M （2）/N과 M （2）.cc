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
		if (visited[i] == 0 && arr[cnt-1] < i)
		{
			visited[i] = 1;
			arr[cnt] = i;
			dfs(n, m, visited, arr, cnt + 1);
			visited[i] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	int visited[9] = { 0 };
	int arr[9] = { 0 };
	dfs(N, M, visited, arr, 0);
}