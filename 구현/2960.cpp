#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int>number(N - 1, 0);
	for (int i = 0; i < number.size(); i++) {
		number[i] = i + 2;
	}
	int remove = 0; // 몇 번 제거되었는지 확인
	bool go = true;
	while (go) {
		int P = number[0];
		remove++;
		number.erase(number.begin());
		if (remove == K) {
			cout << P;
			break;
		}
		for (int i = 0; i < number.size(); i++) {
			if (number[i] % P == 0) { // 소수가 아닌 수 발견 시
				int P2 = number[i]; // 제거되기 전에 수 저장
				number.erase(number.begin() + i); // 벡터에서 해당 수 제거
				i--; // 전 단계에서 벡터의 요소를 제거하여 원래 i+1 인덱스의 요소가 i로 바뀌었으므로 해당 요소까지 확인할 수 있게
				remove++;
				if (remove == K) { // K번째 제거된 수 확인
					cout << P2; // 위에서 제거되기 전에 수를 저장한 변수를 출력한다.
					go = false;
					break;
				}
			}
		}
	}
}
