#include <iostream>
#include <vector>

using namespace std;

bool isEqual(vector<bool> A, vector<bool> B)
{
	for (int i = 1; i <= A.size() - 2; i++)
	{
		if (A[i] != B[i])
		{
			return false;
		}
	}
	return true;
}

void push(vector<bool>& buttons, int n)
{
	if (n > 1) buttons[n-1] = !buttons[n-1];
	buttons[n] = !buttons[n];
	if (n < buttons.size() - 2) buttons[n + 1] = !buttons[n + 1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<bool> dp(N + 2, false);
	vector<bool> target(N + 2, false);

	string s;
	cin >> s;

	for (int i = 0; i < N; i++)
	{
		dp[i + 1] = s[i] - '0';
	}

	vector<bool>dp2 = dp;

	s = "";
	cin >> s;
	for (int i = 0; i < N; i++)
	{
		target[i + 1] = s[i] - '0';
	}

	// 첫번째 스위치 누른다.
	push(dp, 1);
	int result1 = 1;
	bool isAnswer = false;
	for (int i = 2; i <= N; i++)
	{
		if (dp[i - 1] == target[i - 1])
		{
			continue;
		}
		else
		{
			push(dp, i);
			result1 += 1;
		}
	}

	if (isEqual(dp, target))
	{
		isAnswer = true;
	}

	int answer = 999999;
	if (isAnswer) answer = result1;
	
	isAnswer = false;
	int result2 = 0;

	for (int i = 2; i <= N; i++)
	{
		if (dp2[i - 1] == target[i - 1])
		{
			continue;
		}
		else
		{
			push(dp2, i);
			result2 += 1;
		}
	}

	if (isEqual(dp2, target))
	{
		isAnswer = true;
	}

	if (isAnswer) answer = min(answer, result2);
	
	if (answer == 999999) cout << -1;
	else	cout << answer;
	
}