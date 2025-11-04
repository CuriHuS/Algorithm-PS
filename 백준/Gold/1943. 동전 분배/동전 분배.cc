#include <iostream>
#include <vector>

using namespace std;

struct coin
{
	int value;
	int count;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int t = 0; t < 3; t++)
	{
		int N;
		cin >> N;

		int sum = 0;		
		vector<coin> coins(N+1, { 0,0 });
		for (int i = 1; i <= N; i++)
		{
			cin >> coins[i].value >> coins[i].count;
			sum += coins[i].value * coins[i].count;
		}

		// 합계가 홀수인 경우 절대 둘로 나눌 수 없어.
		if (sum % 2 != 0)
		{
			cout << 0 << "\n";
			continue;
		}

		vector<vector<bool>> dp(N+1, vector<bool>(sum/2+1, false));
		dp[0][0] = true;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 0; j <= sum/2; j++)
			{
				if (dp[i - 1][j])
				{
					for (int k = 0; k <= coins[i].count; k++)
					{
						int tempSum = j + coins[i].value * k;
						if (tempSum > sum / 2) continue;
						dp[i][j + coins[i].value * k] = true;
					}
				}
			}
		}

		if (dp[N][sum / 2]) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
}