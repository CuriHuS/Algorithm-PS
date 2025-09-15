#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;

	for (int i = 0; i <= 10000; i++) dp[i] =0;

	vector<pair<int, int>> apps;
	for (int i = 0; i < N; i++)
	{
		int m;
		cin >> m;
		apps.push_back({ m,0 });
	}

	for (int i = 0; i < N; i++)
	{
		int c;
		cin >> c;
		apps[i].second = c;
	}

	// 10 20 30 35 40
	// 0 3 3 5 4

	sort(apps.begin(), apps.end());

	dp[0] = 0;
	
	for (int i = 0; i < apps.size(); i++)
	{
		for (int j = 10000; j >= apps[i].second; j--)
		{
			dp[j] = max(dp[j], dp[j-apps[i].second] + apps[i].first);
		}
	}

	int answer = 99999;
	for (int i = 0; i <= 10000; i++)
	{
		if (dp[i] >= M)
		{
			answer = min(answer, i);
		}
	}
	cout << answer;
}