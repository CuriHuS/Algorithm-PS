#include <iostream>
#include <vector>
using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, W;
	cin >> T >> W;

	int dp[31][3] = {};

	int a;

	for (int t = 0; t < T; t++)
	{
		cin >> a;
		for (int i = 0; i <= W; i++)
		{
			dp[i][a]++;
		}
		dp[0][2] = 0;

		for (int i = 1; i <= W; i++)
		{
			if (a == 1)
				dp[i][1] = max(dp[i - 1][2] + 1, dp[i][1]);
			else if (a == 2)
				dp[i][2] = max(dp[i - 1][1] + 1, dp[i][2]);
		}
		//cout << t+1 << "번째: " << dp[W][1] << " " << dp[W][2] << "\n";
	}

	//cout << dp[W][1] << " " << dp[W][2];
	cout << max(dp[W][1], dp[W][2]);
}