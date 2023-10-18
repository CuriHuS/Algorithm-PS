#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, A, B;
	cin >> N >> A >> B;
	
    // Int형으로 하면 q가 최대 10억이기 때문에 원하는 답이 나오지 않음
	long long int* list_A = new long long int[N];
	long long int* list_B = new long long int[N];
	long long int cost = 0;

	priority_queue<pair<long long int, int>> pq;
	
    
    // 우선순위 큐에 pair로 주고 first에는 상점 1과 상점 2의 가격 차이, second에는 index를 넣어줌
    // first에 따라 자동으로 내림차순 정렬되기 때문에
    // pq의 순서에 따라 계산하면 자동으로 최소 비용을 구할 수 있음
	for (int i = 0; i < N; i++) {
		cin >> list_A[i] >> list_B[i];
		pq.push(make_pair((list_A[i] - list_B[i] > 0) ? list_A[i] - list_B[i] : list_B[i] - list_A[i], i));
	}

	for (int i = 0; i < N; i++) {
		if (list_A[pq.top().second] > list_B[pq.top().second]) {
			if (B > 0) {
				B--;
				cost += list_B[pq.top().second];
			}
			else {
				A--;
				cost += list_A[pq.top().second];
			}
		}
		else if (list_A[pq.top().second] < list_B[pq.top().second]) {
			if (A > 0) {
				A--;
				cost += list_A[pq.top().second];
			}
			else {
				B--;
				cost += list_B[pq.top().second];
			}
		}
		else {
			cost += list_A[pq.top().second];
		}
		pq.pop();
	}
	cout << cost;
}
