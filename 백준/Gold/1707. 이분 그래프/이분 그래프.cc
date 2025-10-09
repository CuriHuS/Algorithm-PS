#include <iostream>
#include <vector>

#define MAX 20001
using namespace std;

vector<int> graph[MAX];
bool isBiGraph;

void dfs(int x, vector<bool>& visited, vector<int>& group)
{
	if (!isBiGraph) return;
	// 첫 방문
	if (x == -1)
		group[x] = x % 2;
	visited[x] = true;

	for (int j = 0; j < graph[x].size(); j++)
	{
		int y = graph[x][j];
		if (group[y] == -1)
			group[y] = (group[x] + 1) % 2; // 인접한 정점 다른 그룹
		else
		{
			if (group[y] == group[x])
			{
				isBiGraph = false;
				return;
			}
		}
		if (!visited[y])
			dfs(y, visited, group);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int K;
	cin >> K;
	while (K--)
	{
		int V, E;
		cin >> V >> E;

		for (int i = 1; i <= V; i++)
		{
			graph[i].clear();
		}

		for (int i = 0; i < E; i++)
		{
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		vector<int> group(V + 1, -1);
		isBiGraph = true;
		vector<bool> visited(V + 1, false);

		for (int i=1; i<=V; i++)
			if (!visited[i])
				dfs(i, visited, group);

		if (isBiGraph) cout << "YES\n";
		else cout << "NO\n";
	}
}