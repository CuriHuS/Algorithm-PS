#include <iostream>
#include <queue>
using namespace std;
int main() {
	int N;
	cin >> N;
	int** G = new int* [N]; // 연결 그래프 배열
	int** result = new int* [N]; // 출력 그래프 배열
	for (int i = 0; i < N; i++) {
		G[i] = new int[N];
		result[i] = new int[N];
		for (int j = 0; j < N; j++) {
			cin >> G[i][j];
			result[i][j] = 0;
		}
	}
	// DFS 알고리즘
	for (int i = 0; i < N; i++) {
		queue<int> q; // q에는 다음 탐색할 배열의 인덱스를 저장
		bool* visit = new bool[N]; // visit은 무한 반복을 제어하기 위해 방문한 곳을 저장
		for (int j = 0; j < N; j++) {
			visit[j] = 0;
			if (G[i][j] == 1) q.push(j);
		} // 위 for문에서 visit 배열을 초기화하며 i번째 배열에서 방문할 곳이 있
		while (!q.empty()) {
			int iter = q.front(); q.pop(); // iter: 방문할 인덱스 
			if (visit[iter] == 0) { 
				visit[iter] = 1;
				for (int j = 0; j < N; j++) {
					if (visit[j] == 0 && G[iter][j] == 1)	q.push(j);
				} // 방문하지 않은 곳에 다음 방문할 곳을 찾으면 q에 넣어준다
			}
		}
		for (int j = 0; j < N; j++) {
			result[i][j] = visit[j]; // visit 1차원 배열을 result 2차원 배열의 각 행에 저장
		}
		delete visit; // 정답코드 관계x
	}
	// 출력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << result[i][j] << " ";
		cout << "\n";
	}
	// 정답 관계 x
	delete[] result;
	delete[] G;
}
