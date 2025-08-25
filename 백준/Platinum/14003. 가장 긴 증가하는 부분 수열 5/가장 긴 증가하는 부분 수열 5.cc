#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1000001];
int path[1000001];
int lis[1000001];

int BinarySearch(int left, int right, int target)
{
	int mid;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (lis[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	return left;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	vector<int> A;
	int a;
	for (int i = 0; i < N; i++)
	{
		lis[i] = 0;
		cin >> arr[i];
	}

	int len = 1;
	lis[len] = arr[0];
	path[0] = 1;
	for (int i = 1; i < N; i++)
	{
		if (lis[len] < arr[i])
		{
			len += 1;
			lis[len] = arr[i];
			path[i] = len;
		}
		else
		{
			int idx = BinarySearch(1, len, arr[i]);
			lis[idx] = arr[i];
			path[i] = idx;
		}
	}
	cout << len << endl;
	vector<int> ans;
	for (int i = N-1; i >= 0; i--)
	{
		if (len == path[i])
		{
			ans.push_back(arr[i]);
			len--;
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--)
	{
		cout << ans[i] << " ";
	}
}