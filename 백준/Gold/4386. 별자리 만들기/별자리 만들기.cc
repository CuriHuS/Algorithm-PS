#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int root[101];

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
	int n;
	cin >> n;
	vector<pair<double, double>> vertex;

	double x, y;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		vertex.push_back({ x,y });
	}

	vector<pair<double, pair<double, double>>> edges;


	for (int i = 0; i < n; i++)
	{
		root[i] = i;
		double x = vertex[i].first;
		double y = vertex[i].second;
		for (int j = 0; j < n; j++)
		{
			for (int j = 0; j < i; j++)
			{
				double distance = pow(pow(vertex[j].first - x, 2) + pow(vertex[j].second - y, 2), 0.5);
				edges.push_back({ distance, {i, j} });
			}
		}
	}

	double answer = 0;

	sort(edges.begin(), edges.end());
	for (int i = 0; i < edges.size(); i++)
	{
		double distance = edges[i].first;
		int from = edges[i].second.first;
		int to = edges[i].second.second;
		if (!union_find(from, to))
		{
			uni(from, to);
			answer += distance;
		}
	}


	//dist[0] = 0;
	//for (int i = 1; i < n; i++)
	//{
	//	double x = vertex[i].first;
	//	double y = vertex[i].second;

	//	for (int j = 0; j < i; j++)
	//	{
	//		double distance = pow(pow(vertex[j].first - x, 2) + pow(vertex[j].second - y, 2), 0.5);
	//		cout << x << ", " << y << "와"<< vertex[j].first << ", " << vertex[j].second << "의 거리: " << distance << "\n";
	//		
	//		dist[i] = min(dist[i], distance);
	//	}
	//}

	cout.precision(2);
	cout << fixed << answer;
}