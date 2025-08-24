#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	long long velocity = v[n-1];
	for (int i = n - 2; i >= 0; i--)
	{
		if (v[i] >= velocity)
		{
			velocity = v[i];
		}

		else
		{
			velocity = ceil((double)velocity/v[i]) * v[i];
		}
	}

	cout << velocity;
}