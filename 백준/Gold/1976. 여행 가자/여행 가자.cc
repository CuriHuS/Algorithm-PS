#include <iostream>
#include <queue>

using namespace std;

int root[201];
int graph[201][201];

int find(int x)
{
	if (root[x] == x) return x;
	return root[x] = find(root[x]);
}

bool union_find(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y) return true;
	return false;
}

void uni(int x, int y)
{
	x = find(x);
	y = find(y);
	
	if (x != y)	root[x] = y;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		root[i] = i;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> graph[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (graph[i][j] == 1)
			{
				if (!union_find(i, j))	uni(i, j);
			}
		}
	}

	int a;
	queue<int> q;
	for (int i = 0; i < m; i++)
	{
		cin >> a;
		q.push(a);
	}

	int start = q.front();
	q.pop();

	bool isAvailable = true;

	while (!q.empty())
	{
		int next = q.front();
		q.pop();

		if (union_find(start, next))
		{
			continue;
		}
		else
		{
			isAvailable = false;
			break;
		}
	}
	if (isAvailable) cout << "YES";
	else cout << "NO";
}