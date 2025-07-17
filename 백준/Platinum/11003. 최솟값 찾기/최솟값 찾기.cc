#include <iostream>
#include <deque>
#include <vector>
using namespace std;

struct A
{
	int data; // 값
	int pos; // 위치
}; 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, L;
	cin >> N >> L;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) cin >> arr[i];
	
	deque<A> dq;
	for (int i = 0; i < N; i++)
	{
		if (!dq.empty() && i == dq.front().pos + L)
			dq.pop_front();
		while (!dq.empty() && dq.back().data > arr[i])
			dq.pop_back();
		dq.push_back({ arr[i], i });
		cout << dq.front().data << " ";
	}
}