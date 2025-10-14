#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1001;
int root[MAX];

int find(int x)
{
	if (root[x] == x)
	{
		return x;
	}
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
	
	if (x != y) root[y] = x;
}

int main()
{
	int N, M;
	cin >> N >> M;
	vector<char> schools(N+1, '0');
	for (int i = 1; i <= N; i++)
	{
		char a;
		cin >> a;
		schools[i] = a;
	}

	for (int i = 0; i <= N; i++) root[i] = i;

	priority_queue<pair<int, pair<int, int>>> pq;

	for (int i = 0; i < M; i++)
	{
		int u, v, d;
		cin >> u >> v >> d;
		pq.push({ -d, {u, v} });
	}

	int result = 0;

	while (!pq.empty())
	{
		int from = pq.top().second.first;
		int to = pq.top().second.second;
		int dist = - pq.top().first;

		pq.pop();

		if (schools[from] == schools[to]) continue;

		if (!union_find(from, to))
		{
			uni(from, to);
			result += dist;
		}
	}

	for (int i = 2; i <= N; i++)
	{
		if (!union_find(i, 1))
		{
			cout << -1;
			return 0;
		}
	}

	cout << result;

}