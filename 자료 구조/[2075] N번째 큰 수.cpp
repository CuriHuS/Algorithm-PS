#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios::sync_with_stdio(false); //입출력 빨라지는 코드
	priority_queue<int> pq;
	int N, a;
	cin >> N;
	for (int i = 0; i < N * N; i++) {
		cin >> a;
		pq.push(-a);
		if (pq.size() > N) pq.pop();
	}

	cout << -pq.top();
}
