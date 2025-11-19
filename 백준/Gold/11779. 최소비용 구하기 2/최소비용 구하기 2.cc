#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

vector<int> path(1001); // 최단 경로 저장
vector<pair<int, int>> bus[1001]; // 버스 경로 저장

void input(int&n, int&m)
{
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		bus[from].push_back({ to, cost });
	}
}

void input2(int& n, int& m)
{
	cin >> n;
	cin >> m;
}

void dijkstra(vector<int>& dist, int start, int end)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cost = - pq.top().first;
		pq.pop();

		if (dist[cur] < cost) continue;

		for (int i = 0; i < bus[cur].size(); i++)
		{
			int next = bus[cur][i].first;
			int nCost = bus[cur][i].second + cost;

			if (dist[next] > nCost)
			{
				dist[next] = nCost;
				pq.push({ -nCost, next });
				path[next] = cur;
			}
		}
	}
}

void findPath(stack<int>& st, int& city, int end, int start)
{
	st.push(end);
	for (int i = end; i != start;)
	{
		st.push(path[i]);
		int temp = i;
		i = path[i];
	}
	city = st.size();
}

void printResult(int& minCost, int& city, stack<int> pathStack)
{
	cout << minCost << "\n" << city << "\n";
	while (pathStack.size() > 0)
	{
		cout << pathStack.top() << " ";
		pathStack.pop();
	}
}

void solution()
{
	int n;
	int m;
	input(n, m);

	int start, end;
	input2(start, end);

	vector<int> dist(n + 1, INT_MAX);
	dijkstra(dist, start, end);
	vector<int> path;
	int city = 0;
	int minCost = dist[end];
	
	stack<int> pathStack;
	findPath(pathStack, city, end, start);

	printResult(minCost, city, pathStack);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solution();
}