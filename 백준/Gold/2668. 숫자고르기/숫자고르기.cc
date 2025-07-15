#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int arr[101];
bool visited[101];
vector<int> ans;

void dfs(int cur, int start)
{
	if (visited[cur])
	{
		if (cur == start)
		{
			ans.push_back(cur);
		}
		return;
	}
	visited[cur] = true;
	dfs(arr[cur], start);
}

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++)
	{
		memset(visited, false, sizeof(visited));
		dfs(i, i);
	}
	
	cout << ans.size() << endl;
	for (auto x : ans) cout << x << "\n";
}