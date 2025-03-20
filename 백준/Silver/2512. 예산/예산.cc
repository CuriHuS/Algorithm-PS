#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	int* arr = new int[N];
	int budgetSum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		budgetSum += arr[i];
	}

	sort(arr, arr + N);

	int M;
	cin >> M;

	if (M >= budgetSum) cout << arr[N - 1];
	else
	{
		int right = arr[N-1];
		int left = 1;
		int index = -1;
		int leftSum = 0;
		for (int i = 0; i < N; i++)
		{
			if (arr[i] * (N-index-1) <= M - leftSum)
			{
				left = arr[i];
				leftSum += arr[i];
				index = i;
			}
			else
			{
				right = arr[i];
				break;
			}
		}
		int mid = 0;
		int result = 0;
		while (left <= right)
		{
			mid = (left + right) / 2;
			budgetSum = mid * (N - index - 1) + leftSum;

			if (budgetSum > M)
			{
				right = mid - 1;
			}

			else if (budgetSum <= M)
			{
				left = mid + 1;
				result = mid;
			}
		}

		cout << result;

	}
}