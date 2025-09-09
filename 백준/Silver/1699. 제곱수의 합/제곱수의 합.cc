#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	int dp[100001];
	cin >> N;	
	// 1, 4, 9, 16, 25 ...
	vector<int> nums;
	int n = 1;
	for (int i = 1; i * i <= N; i++)
	{
		nums.push_back(i * i);
	}

	dp[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		dp[i] = 100000;
		for (int j = 0; j < nums.size(); j++)
		{
			if (nums[j] > i) break;
			dp[i] = min(dp[i - nums[j]] + 1, dp[i]);
		}
	}
	cout << dp[N];
}