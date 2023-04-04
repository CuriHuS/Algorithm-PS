#include <iostream>
#include <deque>

using namespace std;

int main() {
	deque<int> truck; // 다리를 건너지 못한 트럭 큐
	deque<int> on_bridge; // 다리 위 상태 큐
	int n, w, L, time = 0, on_bridge_weight = 0;
  // on_bridge_weight: 다리 위 트럭 무게 총합
	cin >> n >> w >> L;
	int weight;
	for (int i = 0; i < n; i++) {
		cin >> weight;
		truck.push_back(weight);
	}
	for (int i = 0; i < w; i++) {
		on_bridge.push_back(0);
	}

	while (!truck.empty()) { // 남은 트럭이 없으면 종료
		int q = truck.front(); // 남은 트럭 중 맨 앞 대기 중인 트럭
		int p = on_bridge.front(); // 다리 위에 있는 트럭 중 가장 앞에 있는 트럭(다음 차례에 나갈 트럭)
		
		if (on_bridge_weight + q-p > L) { //무게 초과시
			on_bridge.pop_front();
			on_bridge.push_back(0);
			
		}
		else { // 무게를 버틸 수 있을 때
			on_bridge_weight += q;
			on_bridge.pop_front();
			on_bridge.push_back(q); // 다리 위 큐로 q 입력
			truck.pop_front(); // 대기 중인 트럭 큐에서 제거
		}
		
		on_bridge_weight -= p; // 앞에 있는 트럭은 지나감
		time++;
		

	}

	cout << time + w; // 마지막 트럭이 다리 위에 올라가면 종료되므로 w(다리 길이)를 더해준다.
	
}
