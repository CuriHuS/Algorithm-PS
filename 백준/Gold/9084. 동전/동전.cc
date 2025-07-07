#include <iostream>

using namespace std;

int main()
{
	int T, N, M;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N;
		int* coins = new int[N];
		for (int i = 0; i < N; i++)
		{
			cin >> coins[i];
		}
		cin >> M;
		int* dp = new int[M+1];
		for (int i = 0; i <= M; i++)
		{
			dp[i] = 0;
		}
		dp[0] = 1;

		for (int i = 0; i < N; i++)
		{
			for (int j = coins[i]; j <= M; j++)
			{
				dp[j] += dp[j - coins[i]];
			}
		}
		cout << dp[M] << "\n";
	}
}