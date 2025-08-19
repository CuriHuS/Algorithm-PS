#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int N;
	cin >> N;
	priority_queue<int> pq;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		pq.push(-a);
	}

	long long result = 0;

	while (pq.size() > 1)
	{
		int a = - pq.top();
		pq.pop();
		int b = - pq.top();
		pq.pop();
		pq.push(- (a + b));
		result += (a + b);
	}
	cout << result;

}