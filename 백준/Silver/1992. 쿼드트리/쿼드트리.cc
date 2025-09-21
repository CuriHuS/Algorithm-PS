#include <iostream>
#include <vector>

using namespace std;

void divide(vector<vector<int>>& v, int n, int x, int y)
{
	if (n == 1)
	{
		cout << v[x][y];
		return;
	}

	bool isZero = true;
	bool isOne = true;

	for (int i = x; i < x + n; i++)
	{
		for (int j = y; j < y + n; j++)
		{
			if (v[i][j] == 0)
			{
				isOne = false;
			}
			else
			{
				isZero = false;
			}

			if (!isOne && !isZero) break;
		}
		if (!isOne && !isZero) break;
	}

	if (isOne)
	{
		cout << 1;
	}
	else if (isZero)
	{
		cout << 0;
	}
	else
	{
		cout << "(";
		divide(v, n / 2, x, y); // 2사분면
		divide(v, n / 2, x, y + n / 2); // 1사분면
		divide(v, n / 2, x + n / 2, y); // 3사분면
		divide(v, n / 2, x + n / 2, y + n / 2); // 4사분면
		cout << ")";
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	string s;

	vector<vector<int>> v;

	for (int i = 0; i < N; i++)
	{
		cin >> s;
		vector<int> temp;
		for (int j = 0; j < s.length(); j++)
		{
			temp.push_back(s[j] - '0');
		}
		v.push_back(temp);
	}

	divide(v, N, 0 ,0);
}