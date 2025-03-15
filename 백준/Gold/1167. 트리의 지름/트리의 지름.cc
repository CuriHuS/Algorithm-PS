#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> v[100001];
bool visit_list[100001];
long long maxCnt = 0;
long long maxIdx = 0;
long long cnt;

void dfs(int x)
{
	visit_list[x] = true;
	for (int i = 0; i < v[x].size(); i++)
	{
		if (visit_list[v[x][i].first] == false)
		{
			cnt += v[x][i].second;
			if (maxCnt < cnt)
			{
				maxCnt = cnt;
				maxIdx = v[x][i].first;
			}
			dfs(v[x][i].first);
			cnt -= v[x][i].second;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;

	int num1, num2, num3;
	for (int i=0; i<n; i++)
	{
		cin >> num1;
		while (true)
		{
			cin >> num2;
			if (num2 == -1) break;
			cin >> num3;
			v[num1].push_back(make_pair(num2, num3));
		}
	}

	dfs(1);
	for (int i = 1; i <= n; i++) visit_list[i] = false;
	dfs(maxIdx);


	cout << maxCnt;
}