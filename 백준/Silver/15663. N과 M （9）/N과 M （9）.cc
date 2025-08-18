#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int n, int m, int visited[], int arr[], vector<int> v, int cnt)
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

	int dup = 0;
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 0 && dup != v[i])
		{
			visited[i] = 1;
			arr[cnt] = v[i];
			dup = v[i];
			dfs(n, m, visited, arr, v, cnt + 1);
			visited[i] = 0;
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;

	vector<int> pool;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		pool.push_back(a);
	}
	sort(pool.begin(), pool.end());

	int visited[9] = { 0 };
	int arr[9] = { 0 };
	dfs(N, M, visited, arr, pool, 0);
}