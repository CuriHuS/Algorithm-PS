#include <iostream>
#include <vector>
using namespace std;

void print(int** n, int N) { // 그래프 출력 함수 정답과 관계 없음
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << n[i][j] << " ";
		}
		cout << "\n";
	}
}

void rain(int** n, int N) { // 비가 한 칸씩 와서 그래프의 지역이 1씩 작아짐
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (n[i][j]>0)	n[i][j]--; // 물에 잠긴 지역은 0, 마이너스로 안 내려감
		}
	}
}

void clear(int** n, int N) { // 2차원 배열 0으로 초기화 (visit_list 초기화를 위한 함수)
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			n[i][j] = 0;
		}
	}
}

bool dfs(int**n, int**v, int x, int y, int N) { // 깊이 우선 탐색 알고리즘 구현 함수
	if (x<0 || x>N - 1 || y<0 || y>N - 1) return false; // 좌표가 그래프 범위를 벗어나면
	if (n[y][x] > 0 && v[y][x] == 0) { // 비에 잠기지 않은 지역 && 방문하지 않은 지역
		v[y][x] = 1;
		dfs(n, v, x, y + 1, N);
		dfs(n, v, x, y - 1, N);
		dfs(n, v, x+1, y, N);
		dfs(n, v, x-1, y, N);
		return true; // 하나의 구로이므로 true 반환
	}
	return false;
}

int main(){
	int N, max_area=1, max_height=0; // max_area = 최대 영역의 수 max_height = 초기 영역 중 최고 높이(반복 횟수)
	cin >> N;
  // 지역 그래프, 방문 그래프 동적할당(delete는 안 했음)
	int** map = new int* [N];
	int** visit_list = new int* [N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[N];
		visit_list[i] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			visit_list[i][j] = 0;
			if (map[i][j] > max_height) max_height = map[i][j];
		}
	}
	for (int t = 0; t <= max_height; t++) { // t= 테스트 케이스로 모든 지역이 잠길 때까지 진행
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (dfs(map, visit_list, i, j, N) == true) { 
					count++; // 영역 개수 추가
				}
			}
		}
		if (count > max_area) max_area = count; // 영역 수가 max_area보다 많으면 max_area를 바꾼다.
		rain(map, N);
		clear(visit_list, N);
	}
  // 실제 정답 코드에는 delete 안 넣음
  for (int i = 0; i < N; i++) {
		delete[] map[i];
		delete[] visit_list[i];
	}
	delete[] map;
	delete[] visit_list;
  
	cout << max_area; // 모든 케이스 중 가장 많은 영역 수 출력
}
