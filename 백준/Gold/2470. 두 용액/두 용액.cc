#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int arr[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int s = 0;
	int e = N - 1;

	int closeToZero = 2000000001;
	int ade[2];

	sort(arr, arr + N);

	while (s < e)
	{
		int sum = arr[s] + arr[e];
		if (sum == 0)
		{
			ade[0] = arr[s];
			ade[1] = arr[e];
			break;
		}

		else if (abs(sum) < abs(closeToZero))
		{
			closeToZero = sum;
			ade[0] = arr[s];
			ade[1] = arr[e];
		}
		
		if (sum < 0)
		{
			s++;
		}
		else
		{
			e--;
		}
	}
	

	cout << ade[0] << " " << ade[1];
}