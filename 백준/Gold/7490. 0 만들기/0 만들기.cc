#include <iostream>
#include <vector>

using namespace std;

char oper[3] = { ' ', '+', '-' };

int sumArr(vector<char>& arr)
{
	int result = 0;
	int temp = 0;
	bool isMinus = false;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == ' ')
		{
			temp *= 10;
		}
		else if (arr[i] == '-')
		{
			if (isMinus)
			{
				temp *= -1;
			}
			result += temp;
			temp = 0;
			isMinus = true;
		}
		else if (arr[i] == '+')
		{
			if (isMinus)
			{
				temp *= -1;
			}
			result += temp;
			temp = 0;
			isMinus = false;
		}
		else // 숫자인 경우
		{
			temp += (arr[i]-'0');
		}
	}

	if (isMinus) result -= temp;
	else result += temp;

	return result;
}

void dfs(int cur, int end, vector<char> arr)
{
	if (cur > end)
	{
		if (sumArr(arr) == 0)
		{
			for (int i = 0; i < arr.size(); i++)
			{
				cout << arr[i];
			}
			cout << "\n";
		}
		
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		arr.push_back(oper[i]);
		arr.push_back(cur + '0');
		dfs(cur + 1, end, arr);
		arr.pop_back();
		arr.pop_back();
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;

		vector<char> arr;
		arr.push_back('1');
		dfs(2, N, arr);
		cout << "\n";
	}
}