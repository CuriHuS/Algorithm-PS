#include <iostream>
using namespace std;

int N, M;

// parameter로 주어진 배열 내에 value가 있는지 탐색하는 함수
// 있으면 true 반환
// O(N) 
bool find(int list[], int value, int length) {
	for (int i = 0; i < length; i++) {
		if (list[i] == value) return true;
	}
	return false;
}

// 저장된 배열, m: 종료 길이, cnt: 현재 배열 길이, idx: 탐색할 수
void dfs(int list[], int m, int cnt, int n) {
	if (cnt == m) {
		for (int i = 0; i < cnt; i++) {
			cout << list[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (find(list, i, cnt)) {
			continue;
		}
		list[cnt] = i;
		dfs(list, m, cnt + 1, n);
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	int L[8] = { 0 };
	dfs(L, M, 0, N);
}
