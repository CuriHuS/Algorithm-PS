#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(nullptr);
	int N;
	cin >> N;
	vector<int> arr(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	vector<int> sum;
	set<int> U;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			U.insert(arr[i]+arr[j]);
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			if (U.find(arr[j] - arr[i]) != U.end())
			{
				answer = max(answer, arr[j]);
			}
		}
	}

	cout << answer;

}