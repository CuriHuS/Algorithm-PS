#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string N;
	cin >> N;

	string bomb;
	cin >> bomb;

	vector<char> v;
	int idx = 0;

	for (int i = 0; i < N.length(); i++)
	{
		v.push_back(N[i]);
		
		bool isBoom = true;
		for (int j = bomb.length() - 1; j >= 0; j--)
		{
			if (v.size() < j)
			{
				isBoom = false;
				break;
			}
			if (v[v.size()-1 - (bomb.length()-1 - j)] != bomb[j])
			{
				isBoom = false;
				break;
			}
		}

		if (isBoom)
		{
			for (int j = 0; j < bomb.length(); j++)
			{
				v.pop_back();
			}
		}
	}

	if (v.size() == 0) cout << "FRULA";

	else
	{
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i];
		}
	}

}