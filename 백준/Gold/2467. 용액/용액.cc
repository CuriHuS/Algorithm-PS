#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	int ade[2] = { 0,0 };

	int start = 0;
	int end = N - 1;

	int minimum = 2000000001;

	while (start < end)
	{
		int sum = v[start] + v[end];
		if (abs(sum) < minimum)
		{
			ade[0] = v[start];
			ade[1] = v[end];
			minimum = abs(sum);
			if (sum == 0) break;
		}

		if (sum < 0)
		{
			start++;
		}
		else
		{
			end--;
		}

	}
	cout << ade[0] << " " << ade[1];
}