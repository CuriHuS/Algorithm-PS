#include <iostream>
#include <string>
#include <vector>
using namespace std;

void isPalindrome(vector<int> v, bool& isCheck)
{
	for (int i = 0; i < v.size() / 2; i++)
	{
		if (v[i] != v[v.size()-1-i])
		{
			isCheck = false;
			return;
		}
	}
	isCheck = true;
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
		int input;
		cin >> input;
		vector<int> v;
		bool isCheck = false;
		for (int i = 2; i <= 64; i++)
		{
			int j = input;
			while (j > 0)
			{
				v.push_back(j%i);
				j /= i;
			}

			isPalindrome(v, isCheck);
			if (isCheck)
			{
				cout << "1\n";
				break;
			}

			v.clear();
		}

		if (!isCheck) cout << "0\n";
	}
}