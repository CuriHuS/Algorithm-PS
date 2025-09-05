#include <iostream>
#include <vector>
#include <algorithm>

int root[200001];

int find(int x)
{
	if (root[x] == x) return x;
	else return root[x] = find(root[x]);
}

void uni(int x, int y)
{
	x = find(x);
	y = find(y);
	root[y] = x;
}

bool union_find(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y) return true;
	else return false;
}

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		int m, n;
		cin >> m >> n;
		if (m == 0 && n == 0) return 0;

		int x, y, z;

		vector<pair<int, pair<int, int>>> edges;
		long long answer = 0;

		for (int i = 0; i < n; i++)
		{
			cin >> x >> y >> z;
			edges.push_back({ z, {x, y} });
			answer += z;
		}

		sort(edges.begin(), edges.end());

		for (int i = 0; i < m; i++) root[i] = i;
		for (int i = 0; i < edges.size(); i++)
		{
			z = edges[i].first;
			x = edges[i].second.first;
			y = edges[i].second.second;
			if (!union_find(x, y))
			{
				uni(x, y);
				answer -= z;
			}
		}
		cout << answer <<"\n";
	}
}