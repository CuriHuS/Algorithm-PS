#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	// queue 두개를 준비해.

	priority_queue<int> leftPQ;
	priority_queue<int> rightPQ;

	if (N == 1)
	{
		int n;
		cin >> n;
		cout << n;
		return 0;
	}
	else if (N >= 2)
	{
		int first, second;
		cin >> first >> second;

		if (first < second)
		{
			leftPQ.push(first);
			rightPQ.push(-second);
		}
		else
		{
			leftPQ.push(second);
			rightPQ.push(-first);
		}

		cout << first << "\n";
		cout << leftPQ.top() << "\n";
	}

	for (int i = 3; i <= N; i++)
	{
		int n;
		cin >> n;

		int left = leftPQ.top();
		int right = -rightPQ.top();

		// left가 더 많은 상태
		if (leftPQ.size() > rightPQ.size())
		{
			// 근데 left에 들어와야해.
			if (leftPQ.top() > n)
			{
				int temp = leftPQ.top();
				leftPQ.pop();
				leftPQ.push(n);
				rightPQ.push(-temp);
			}

			// 상관 없어
			else
			{
				rightPQ.push(-n);
			}
		}
		// rightQ에 더 많은 수가 있어.
		else
		{
			// 근데 right에 들어와야 해.
			// 그러면, 밀어내야겠지.
			if (-rightPQ.top() < n)
			{
				int temp = -rightPQ.top();
				rightPQ.pop();
				rightPQ.push(-n);
				leftPQ.push(temp);
			}

			// right 안 들어가도 되면 left로
			else
			{
				leftPQ.push(n);
			}
		}



		if (leftPQ.size() >= rightPQ.size())
		{
			cout << leftPQ.top() << "\n";
		}
		else
		{
			cout << -rightPQ.top() << "\n";
		}
	}
}