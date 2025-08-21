#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;

	int* arr = new int[N+1];
	for (int i = 0; i < N; i++)
	{
		arr[i] = 0;
	}

	arr[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		int a;
		cin >> arr[i];
	}

	sort(arr+1, arr+N+1);
	int diff = 2000000001;

	int start = 1;
	int end = 1;
	
	while (true)
	{
		if (end == N+1 || start == N+1) break;
		if (arr[end] - arr[start] < M)
		{
			end++;
		}
		else
		{
			diff = min(diff, arr[end] - arr[start]);
			start++;
		}
	}

	cout << diff;
}