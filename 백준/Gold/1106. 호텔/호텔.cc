#include <iostream>

using namespace std;

int main()
{
	int C, N;	
	// dp[비용] = { 고객 수 }
	int dp[100001] = { 0 };
	cin >> C >> N;
	for (int i = 0; i < N; i++)
	{
		int cost, customer;
		cin >> cost >> customer;

		for (int j = cost; j <= 100000; j++)
		{
			dp[j] = max(dp[j], dp[j - cost] + customer);
		}
	}

	for (int i = 0; i <= 100000; i++)
	{
		if (dp[i] >= C)
		{
			cout << i;
			break;
		}
	}
}