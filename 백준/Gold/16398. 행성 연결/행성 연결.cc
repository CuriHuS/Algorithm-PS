#include <iostream>
#include <queue>

using namespace std;

int root[1000];
priority_queue<pair<int, pair<int, int>>> pq;

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
	
	if (x != y)	root[y] = x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;

	int a;
	for (int i = 0; i < N; i++)
	{
		root[i] = i;
		for (int j = 0; j < N; j++)
		{
			cin >> a;
			if (j > i) pq.push({ -a, {i, j} });
		}
	}

	long long answer = 0;
	while (!pq.empty())
	{
		int cost = - pq.top().first;
		int from = pq.top().second.first;
		int to = pq.top().second.second;
		pq.pop();

		if (!union_find(from, to))
		{
			uni(from, to);
			answer += cost;
		}
	}

	cout << answer;
}