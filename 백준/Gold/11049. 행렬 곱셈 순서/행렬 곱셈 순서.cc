#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	int arr[501][2];
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i][0] >> arr[i][1];
	}

	int dp[501][501];
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			dp[i][j] = 0;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		dp[i][i + 1] = arr[i][0] * arr[i][1] * arr[i + 1][1];
	}

	for (int j = 2; j <= N; j++)
	{
		for (int i = 1; i+j <= N; i++)
		{
			for (int k = i; k < i + j; k++)
			{
				if (dp[i][i + j] == 0)
				{
					dp[i][i + j] = dp[i][k] + dp[k + 1][i + j] + arr[i][0] * arr[k+1][0] * arr[i + j][1];
				}
				else
				{
					dp[i][i + j] = min(dp[i][i + j], dp[i][k] + dp[k + 1][i + j] + arr[i][0] * arr[k + 1][0] * arr[i + j][1]);
				}
			}
		}
	}

	cout << dp[1][N];
	// 참고: https://developerbee.tistory.com/98
}