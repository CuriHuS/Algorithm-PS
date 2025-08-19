#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct lecture
{
	int start;
	int end;

	bool operator<(const lecture& other) const {
		// 우선순위 큐는 기본적으로 max heap이므로
		// 작은 값이 우선순위가 높게 하려면 부등호를 반대로
		if (start == other.start)
			return end > other.end;  // start가 작은 것이 우선순위 높음
		return start > other.start;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	int b, c;
	priority_queue<lecture> pq;
	priority_queue<int> v;
	for (int i = 0; i < N; i++)
	{
		cin >> b >> c;
		pq.push({ b,c });
	}

	v.push(- pq.top().end);
	pq.pop();
	while (!pq.empty())
	{
		int start = pq.top().start;
		int end = pq.top().end;
		
		// 이미 있는 강의실 사용 가능한 경우
		if (-v.top() <= start)
		{
			v.pop();
		}
		v.push(-end);
		pq.pop();
	}
	cout << v.size();
}