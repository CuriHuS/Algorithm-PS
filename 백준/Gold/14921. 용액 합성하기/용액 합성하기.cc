#include <iostream>
#include <vector>
#include <climits>
using namespace std;

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
		cin >> a;
		A.push_back(a);
	}

	int start = 0;
	int end = N - 1;

	int B = INT_MAX;

	while (start < end)
	{
		if (abs(A[start] + A[end]) < abs(B))
		{
			B = A[start] + A[end];
		}

		if (A[start] + A[end] < 0)
		{
			start++;
		}
		else
		{
			end--;
		}
	}

	cout << B;
}