#include <iostream>

using namespace std;

int root[500000];

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
	else return false;
}

void uni(int x, int y)
{
	x = find(x);
	y = find(y);
	root[x] = y;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	
	int a, b;

	for (int i = 0; i < n; i++)
	{
		root[i] = i;
	}

	int step = 1000001;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		if (!union_find(a, b))
		{
			uni(a, b);
		}
		else
		{
			step = min(step, i+1);
		}
	}

	if (step == 1000001) cout << 0;
	else cout << step;
}