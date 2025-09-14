#include <iostream>

using namespace std;

int root[1000001];

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

	int f, a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> f >> a >> b;

		if (f == 0)
		{
			uni(a, b);
		}

		else
		{
			if (union_find(a, b))
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
	}
}