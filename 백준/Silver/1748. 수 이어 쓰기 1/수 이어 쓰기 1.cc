#include <iostream>

using namespace std;

int main()
{
	long long answer = 0;
	int N;
	int num = 1;
	cin >> N;

	for (int i = 1; i <= N; i*=10)
	{
		answer += (N - i + 1);
	}
	cout << answer;
}