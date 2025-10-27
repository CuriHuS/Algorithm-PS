#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(vector<vector<int>>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			cout << v[i][j];
		}
		cout << "\n";
	}
}

int main()
{
	string A, B;
	cin >> A >> B;

	int maxLen = 0;
	vector<vector<int>> v(A.length()+1, vector<int>(B.length()+1, 0));

	for (int i = 1; i <= A.length(); i++)
	{
		for (int j = 1; j <= B.length(); j++)
		{
			if (A[i-1] == B[j-1])
			{
				v[i][j] = v[i - 1][j - 1] + 1;
				maxLen = max(maxLen, v[i][j]);
				continue;
			}
			//v[i][j] = max(v[i - 1][j], v[i][j - 1]);
		}
	}
	cout << maxLen;
}