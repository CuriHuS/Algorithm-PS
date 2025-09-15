#include <iostream>
#include <vector>

using namespace std;
bool dp[31][40001];

int main()
{
	int N;
	cin >> N;
	vector<int> v;

	dp[0][0] = true;
	for (int i = 1; i <= N; i++)
	{
		int weight;
		cin >> weight;

		for (int j = 0; j < 40001; j++)
		{
			if (dp[i - 1][j]) // 이전 단계에서 만들었던 추이면 true
			{
				dp[i][j] = true; // 이전 단계에서 만든 추 무게(j)
				dp[i][j + weight] = true; // 이번 추랑 합친 무게
				dp[i][weight - j >= 0 ? weight - j : j - weight] = true; // 이전에 만든 추의 무게와 차이
			}
		}
	}

	int m;
	cin >> m;
	while (m--)
	{
		int check;
		cin >> check;
		cout << (dp[N][check] ? "Y" : "N") << " ";
	}
}