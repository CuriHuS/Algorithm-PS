#include <iostream>
using namespace std;

int main()
{
	int n, k;
	int coins[101];
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> coins[i];
	}
	long long dp[10001] = { 0 };
	long long result = 0;
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			result = j + coins[i];
			if(result <= k) dp[result] += dp[j];
		}
	}
	cout << dp[k];
}
