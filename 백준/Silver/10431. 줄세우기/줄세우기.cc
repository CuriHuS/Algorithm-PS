#include <iostream>
#include <vector>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int P;
	cin >> P;
	while (P--)
	{
		int T;
		cin >> T;

		vector<int> v;
		int a; int result = 0;
		cin >> a;
		v.push_back(a);
		for (int i = 1; i < 20; i++)
		{
			bool check = false;
			cin >> a;
			for (int j=0; j<v.size(); j++)
			{
				if (a < v[j])
				{
					result += (v.size() - j);
					v.insert(v.begin() + j, a);
					check = true;
					break;
				}
			}
			if (!check) v.push_back(a);
		}
		cout << T << " " << result << endl;
	}
}