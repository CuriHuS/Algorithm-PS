#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<pair<int, int>> v;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}

	sort(v.begin(), v.end());

	int dp[501] = { 0, };
	dp[0] = 0;
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[i].second > v[j].second)
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	//for (int i = 0; i < N; i++)
	//{
	//	cout << dp[i] << " ";
	//}
	//

	int answer = 0;
	if (N == 1) cout << 0;
	else cout << N - *max_element(dp, dp + N) -1;
}