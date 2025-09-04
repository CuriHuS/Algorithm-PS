#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int root[1001];

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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M;
	int from, to, cost;

	cin >> N >> M;

	vector<pair<int, pair<int, int>>> edges;

	for (int i = 0; i < M; i++)
	{
		cin >> from >> to >> cost;
		edges.push_back({ cost, {from, to} });
	}

	sort(edges.begin(), edges.end());
	int answer = 0;
	
	for (int i = 1; i <= N; i++) root[i] = i;

	for (int i = 0; i < edges.size(); i++)
	{
		cost = edges[i].first;
		from = edges[i].second.first;
		to = edges[i].second.second;

		if (!union_find(from, to))
		{
			uni(from, to);
			answer += cost;
		}
	}
	cout << answer;
}