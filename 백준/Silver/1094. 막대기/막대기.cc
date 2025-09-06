#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int X;
	cin >> X;

	int sum = 64;
	int answer = 1;
	priority_queue<int> pq;
	pq.push(-64);
	while (sum > X)
	{
		int stick = - pq.top();
		int halfstick = stick / 2;
		//길이가 가장 짧은 막대를 절반으로 자른다.
		pq.push(-halfstick);		pq.push(-halfstick);

		// 위에서 자른 막대의 절반 중 하나를 버리고 남아있는 막대의 합
		sum -= halfstick;
		if (sum >= X)
		{
			sum = sum;
		}
		else
		{
			sum += halfstick;
			answer++;
		}
	}
	cout << answer;
}