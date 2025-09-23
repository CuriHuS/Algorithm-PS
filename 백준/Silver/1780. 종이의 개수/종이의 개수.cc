#include <iostream>
#include <vector>
using namespace std;

int minusCnt = 0;
int zeroCnt = 0;
int oneCnt = 0;

void divide(vector<vector<int>>& v, int n, int x, int y)
{
	if (n == 1)
	{
		if (v[x][y] == -1) minusCnt++;
		else if (v[x][y] == 0) zeroCnt++;
		else if (v[x][y] == 1) oneCnt++;
		return;
	}

	bool isZero = false;
	bool isOne = false;
	bool isMinus = false;
	for (int i = x; i < x+n; i++)
	{
		for (int j = y; j < y+n; j++)
		{
			if (v[i][j] == 0) isZero = true;
			else if (v[i][j] == 1) isOne = true;
			else if (v[i][j] == -1) isMinus = true;
		}
	}

	if (isZero && !isOne && !isMinus)
	{
		zeroCnt++;
		return;
	}
	else if (!isZero && isOne && !isMinus)
	{
		oneCnt++;
		return;
	}
	else if (!isZero && !isOne && isMinus)
	{
		minusCnt++;
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			divide(v, n/3, x+i*n/3, y+j*n/3);
		}
	}
		
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<vector<int>> v;

	for (int i = 0; i < N; i++)
	{
		vector<int> temp;
		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;
			temp.push_back(a);
		}
		v.push_back(temp);
	}

	divide(v, N, 0, 0);
	cout << minusCnt << "\n" << zeroCnt << "\n" << oneCnt;
}