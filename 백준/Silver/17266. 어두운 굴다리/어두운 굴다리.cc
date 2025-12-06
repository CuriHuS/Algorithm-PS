#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int M;
	cin >> M;
	vector<bool> bridge(N+1, false);
	int start = 0;
	int end = 0;
	for (int i = 0; i < M; i++)
	{
		int x;
		cin >> x;
		bridge[x] = true;
		if (i == 0) start = x;
		else if (i == M - 1) end = x;
	}
	int maxLength = 0;
	int tempLength = 0;

	for (int i = 0; i <= N; i++)
	{
		if (bridge[i])
		{
			tempLength = 0;
		}
		else
		{
			tempLength += 1;
		}
		int temp = tempLength;
		if (i > start && i < end)
		{
			temp = tempLength / 2 + 1;
		}
		maxLength = max(maxLength, temp);
	}
	cout << maxLength;
}