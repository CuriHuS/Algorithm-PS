#include <iostream>
using namespace std;

void dfs(int list[], int n, int m, int count){ // 깊이우선탐색으로 인덱스 순서대로 수를 찾아냄.
	if (count == m) { // 마지막 수인 경우(M번째 수인 경우)
		for (int i = 0; i < m; i++) {
			cout << list[i] << " "; // list 내에 있는 값을 하나씩 출력
		}
		cout << "\n";
	}
	else {
		for (int i = 1; i <= n; i++) {
			list[count] = i; // count는 몇 번째 수를 나타내는 변수이다. 1->2->3에서 count는 0,1,2.
			dfs(list, n, m, count+1); // 다음 count(다음 번째 수)를 실행한다.
		}
	}
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); // line 20~21: 입출력 시간 감소
	int N, M;
	int L[7] = { 0 }; // 최대 길이인 7로 미리 array를 만들어둠(어차피 dfs함수에서 최대 길이까지만 출력함)
	cin >> N >> M;
	dfs(L, N, M, 0);
}
