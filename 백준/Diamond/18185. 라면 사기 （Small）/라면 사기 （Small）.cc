#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	int* arr = new int[N + 3];
	for (int i = 0; i <= N + 2; i++) arr[i] = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}


	// 1 5 3 7
	// 5 + 7 * 3 + 3 + 3 * 4 = 5 + 21 + 15 = 41

	int result = 0;
	for (int i = 1; i <= N; i++)
	{
		if (arr[i + 2] > 0 && arr[i + 1] > 0 && arr[i] > 0)
		{
			if (arr[i + 1] > arr[i + 2])
			{
				int diff = arr[i + 1] - arr[i + 2];
				int minimum = min(diff, arr[i]);
				result += minimum * 5;
				for (int k = i; k <= i + 1; k++)
					arr[k] -= minimum;
			}

			int minimum = min(arr[i + 2], min(arr[i + 1], arr[i]));
			result += minimum * 7;
			for (int k = i; k <= i + 2; k++)
				arr[k] -= minimum;
		}

		if (arr[i + 1] > 0 && arr[i] > 0)
		{
			int minimum = min(arr[i + 1], arr[i]);
			result += minimum * 5;
			for (int k = i; k <= i + 1; k++)
				arr[k] -= minimum;
		}

		if (arr[i] > 0)
		{
			result += arr[i] * 3;
			for (int k = i; k <= i; k++)
				arr[k] -= arr[i];
		}
	}
	cout << result;
}