#include <iostream>
#include <queue>
using namespace std;

void print(int* m, int n) { //정답과 관련 없음
	for (int i = 0; i < n; i++) {
		cout << m[i] << ", ";
	}
	cout << endl;
}

void refresh1(int* m, int n) {
	for (int i = 0; i < n; i++) m[i] = 0;
}

void refresh2(bool* m, int n) {
	for (int i = 0; i < n; i++) m[i] = 0;
}

// refresh는 매 케이스마다 그래프 초기화를 위한 함수

int sum(int* m, int n) { // 케빈 베이컨 수 계산 함수
	int result = 0;
	for (int i = 0; i < n; i++) {
		result += m[i];
	}
	return result;
}

int main() {
	int N, M, min=9999, answer;
	cin >> N >> M;
	bool** map = new bool*[N]; // 초기화X
	bool* visit = new bool[N]; // 케이스마다 초기화 필요
	int* count = new int[N]; // 케이스마다 초기화 필요
	for (int i = 0; i < N; i++) { 
		visit[i] = 0;
		count[i] = 1;
		map[i] = new bool[N];
		for (int j = 0; j < N; j++) { 
			map[i][j] = 0;
		}
	}
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		map[a - 1][b - 1] = 1;
		map[b - 1][a - 1] = 1;
	}
	queue<int>q;
	int v;
	for (int i = 0; i < N; i++) { // 1~N까지 확인
		q.push(i);
		refresh1(count, N);
		refresh2(visit, N);
		visit[i] = 1;
		while (!q.empty()) {
			v = q.front();
			q.pop();
			for (int j = 0; j < N; j++) {
				if (visit[j] == 0 && map[v][j] == 1) {
					q.push(j);
					visit[j] = 1;
					count[j] = count[v] + 1;
				}
			}
		}
		//print(count, N);

		if (min > sum(count, N)) {
			min = sum(count, N);
			answer = i + 1;
		}
	}
	cout << answer;
}
