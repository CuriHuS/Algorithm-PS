#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M, K;
	int answer = 2100000000;
	cin >> N >> M >> K;
	vector<vector<char>> v;
	vector<vector<int>> dp;

	vector<int> temp2;
	vector<char> temp;
	for (int i = 0; i <= M; i++)
	{
		temp.push_back(0);
		temp2.push_back(0);
	}
	v.push_back(temp);
	dp.push_back(temp2);
	

	for (int i = 0; i < N; i++)
	{
		vector<char> temp;
		vector<int> temp2;
		
		temp.push_back(0);
		temp2.push_back(0);

		string a;
		cin >> a;
		for (int j = 0; j < M; j++)
		{
			temp.push_back(a[j]);
			if (i % 2 == 1)
			{
				if (j % 2 == 1)
				{
					if (a[j] == 'B') temp2.push_back(0);
					else temp2.push_back(1);
				}
				else
				{
					if (a[j] == 'W') temp2.push_back(0);
					else temp2.push_back(1);
				}
			}
			else
			{
				if (j % 2 == 0)
				{
					if (a[j] == 'B') temp2.push_back(0);
					else temp2.push_back(1);
				}
				else
				{
					if (a[j] == 'W') temp2.push_back(0);
					else temp2.push_back(1);
				}
			}
		}
		v.push_back(temp);
		dp.push_back(temp2);
	}	

	// 1,1이 블랙일 때
	vector<vector<int>> dp2 = dp;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			// dp2는 화이트로 변경함.
			if (dp2[i][j] == 1) dp2[i][j] = 0;
			else dp2[i][j] = 1;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
			dp2[i][j] = dp2[i][j] + dp2[i - 1][j] + dp2[i][j - 1] - dp2[i - 1][j - 1];
		}
	}


	//for (int i = 0; i <= N; i++)
	//{
	//	for (int j = 0; j <= M; j++)
	//	{
	//		cout << dp[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	for (int i = 0; i <= N - K; i++)
	{
		for (int j = 0; j <= M - K; j++)
		{
			int result = dp[i + K][j + K] - dp[i + K][j] - dp[i][j + K] + dp[i][j];
			int result2 = dp2[i + K][j + K] - dp2[i + K][j] - dp2[i][j + K] + dp2[i][j];
			if (min(result,result2) < answer)
			{
				answer = min(result, result2);
			}
		}
	}

	cout << answer;
}