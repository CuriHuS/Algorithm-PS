#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<pair<int, int>> points;

long calcDist(pair<int, int> a, pair<int, int> b)
{
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

long divide(vector<pair<int, int>>& v, int left, int right)
{
	if (right - left <= 3)
	{
		long minDist = LONG_MAX;
		for (int i = left; i < right; i++)
		{
			for (int j = i + 1; j < right; j++)
			{
				minDist = min(minDist, calcDist(v[i], v[j]));
			}
		}
		return minDist;
	}

	int mid = (left + right) / 2;
	int midX = v[mid].first;

	long d1 = divide(v, left, mid);
	long d2 = divide(v, mid, right);
	long dist = min(d1, d2);


	vector<pair<int, int>> temp;
	for (int i = left; i < right; i++)
	{
		long dx = v[i].first - midX;
		if (dx * dx < dist)
		{
			temp.push_back(v[i]);
		}
	}

	sort(temp.begin(), temp.end(), [](pair<int, int>& a, pair<int, int>& b) {
		return a.second < b.second;
		});

	
	for (int i = 0; i < temp.size(); i++)
	{
		for (int j = i + 1; j < temp.size(); j++)
		{
            long dy = temp[j].second - temp[i].second;
            if (dy * dy >= dist) break;
			dist = min(dist, calcDist(temp[i], temp[j]));
		}
	}

	return dist;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		points.push_back({ x,y });
	}

	sort(points.begin(), points.end());

	cout << divide(points, 0, n);
}