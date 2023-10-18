#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main() {
	// 입출력 시간 단축 코드
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	int N, M, K;
	cin >> N >> M;


	int** map = new int* [N]; // 옥수수 가치 graph
	bool** visit = new bool* [N];

	for (int i = 0; i < N; i++) {
		map[i] = new int[M];
		visit[i] = new bool[M];
	}

	priority_queue<pair<int, int>> pq; // 우선순위 큐 사용
    
    // pq 요소를 pair로 만들었는데
    // first 요소에는 옥수수 가치
    // second 요소에는 2차원 배열을 1차원 배열로 나타냈을 때 수
    // 이후 second 요소를 2차원으로 바꾸는 과정 존재

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			visit[i][j] = false;
			if (j == 0 || j == M - 1 || i == 0 || i == N - 1) {
				pq.push(make_pair(map[i][j], i*M + j));
				visit[i][j] = true;
			}
		}
	}
	cin >> K;

	int try_time = 0;

	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };

	int max_x = 0, max_y = 0;

	while (K > try_time) {


		// pq에서 1차원 배열 요소를 2차원으로 적용하기 위해 바꿔준다
		max_x = pq.top().second / M;
		max_y = pq.top().second % M;
		pq.pop();

		// 답안 코드
		cout << max_x + 1 << " " << max_y + 1 << "\n";

		// 다음 시도를 위해 visit 처리
		visit[max_x][max_y] = true;


		// bfs 알고리즘 사용
        // visit은 실제 방문하지 않았어도 중복으로 pq에 push 되는 경우를 방지하기 위해
        // true로 설정해준다.
        // 어차피 pq에 들어가면 접근 가능한 옥수수이기 때문!
		for (int i = 0; i < 4; i++) {
			if (0 <= dx[i] + max_x && dx[i] + max_x < N && 0 <= dy[i] + max_y && dy[i] + max_y < M) {
				if (!visit[dx[i] + max_x][dy[i] + max_y]) {
					pq.push(make_pair(map[dx[i]+max_x][dy[i]+max_y], (dx[i]+max_x)*M + dy[i] + max_y));
					visit[dx[i] + max_x][dy[i] + max_y] = true;
				}
			}
		}



		try_time++;
	}
}
