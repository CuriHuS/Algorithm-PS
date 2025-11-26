#include <iostream>
#include <deque>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	deque<int> dq;
	for (int i = 1; i <= N; i++)
	{
		dq.push_back(i);
	}

	int answer = 0;
	for (int i = 0; i < M; i++)
	{
		int target;
		cin >> target;
		
		int count = 0;
		while (dq.front() != target)
		{
			dq.push_back(dq.front());
			dq.pop_front();
			count += 1;
		}
		dq.pop_front();
		if (N - count < count)
		{
			count = N - count;
		}
		answer += count;
		--N;
	}
	cout << answer;
}