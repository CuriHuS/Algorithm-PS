#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string a;
	string b;
	cin >> a >> b; 

	int** lcs = new int*[a.length()+1];

	for (int i = 0; i <= a.length(); i++)
	{
		lcs[i] = new int[b.length()+1];
		for (int j = 0; j <= b.length(); j++)
		{
			lcs[i][j] = 0;
		}
	}

	for (int i = 1; i <= a.length(); i++)
	{
		for (int j = 1; j <= b.length(); j++)
		{
			if (a[i-1] == b[j-1])
			{
				lcs[i][j] = lcs[i - 1][j-1] + 1;
			}

			else
			{
				lcs[i][j] = max(lcs[i][j - 1], lcs[i-1][j]);
			}
		}
	}

	cout << lcs[a.length()][b.length()];
}