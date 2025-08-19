#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string a;
	string b;
	string c;
	cin >> a >> b >> c; 

	int*** lcs = new int**[a.length()+1];

	for (int i = 0; i <= a.length(); i++)
	{
		lcs[i] = new int*[b.length()+1];
		for (int j = 0; j <= b.length(); j++)
		{
			lcs[i][j] = new int[c.length()+1];
			for (int k = 0; k <= c.length(); k++)
			{
				lcs[i][j][k] = 0;
			}
		}
	}

	for (int i = 1; i <= a.length(); i++)
	{
		for (int j = 1; j <= b.length(); j++)
		{
			for (int k = 1; k <= c.length(); k++)
			{
				if (a[i - 1] == b[j - 1] && a[i-1] == c[k - 1])
				{
					lcs[i][j][k] = lcs[i - 1][j - 1][k-1] + 1;
				}

				else
				{
					lcs[i][j][k] = max(lcs[i][j - 1][k], max(lcs[i - 1][j][k], lcs[i][j][k-1]));
				}
			}
		}
	}

	cout << lcs[a.length()][b.length()][c.length()];
}