#include <iostream>
#include <string>
using namespace std;

bool check(int n) { // 자리에 있는 숫자가 다른지 확인
	string str = to_string(n);
	if (str[0] == '0' || str[1] == '0' || str[2] == '0') return false;
	if (str[0] != str[1] && str[1] != str[2] && str[0] != str[2]) return true;
	return false;
}

int main() {
	int chance[1000] = { '0' };
	for (int i = 111; i < 1000; i++) {
		if (check(i)) { 
			chance[i] = i; 
			//cout << i << ",";
		}
	}

	int N, SUM, S ,B; // 입력값 변수
	int count = 0;
	cin >> N;
	for (int a = 0; a < N; a++) {
		cin >> SUM >> S >> B;
		string sum = to_string(SUM); // 자리마다 숫자들을 비교하기 위해 string 타입으로 바꿔줌
		for (int i = 111; i < 1000; i++) {
			int strike = 0, ball = 0;
			int index[3] = { 0 }; // strike인 자리수를 ball의 경우에서 고려하지 않기 위해 index다값을 저장해준다
			if (chance[i] != 0) { // 0인 경우는 strike와 ball이 달라서 제거된 경우와 자리마다 숫자가 다르지 않은 경우이다.
				string str = to_string(chance[i]); // 경우의 수들도 string으로 변환해줌
				for (int j = 0; j < 3; j++) {
					if (str[j] == sum[j]) { // 각 자리가 strike인지 확인한다.
						strike++;
						index[j] = 1;
					}
				}
				if (strike == S) { // strike 개수가 맞은 경우에만 ball 가능성을 탐색
					for (int j = 0; j < 3; j++) {
						if (index[j] == 0) { //strike가 아닌 자리수에만 ball 탐색
							if (j == 0) { // strike가 첫 번째 자리(100의 자리)가 아닌 경우
								if (str[j] == sum[j + 1]) ball++;
								if (str[j] == sum[j + 2]) ball++;
							} // 어차피 strike 자리수와 비교해도 숫자가 다르기 때문에 동일하게 처리해도 된다. 이후 반복
							else if (j == 1) {
								if (str[j] == sum[j + 1]) ball++;
								if (str[j] == sum[j - 1]) ball++;
							}
							else if (j == 2) {
								if (str[j] == sum[j - 1]) ball++;
								if (str[j] == sum[j - 2]) ball++;
							}
						}
					}

					if (ball != B) chance[i] = 0; // ball의 개수가 다르면 0으로 처리
				}
				else {
					chance[i] = 0;
					continue;
				}
			}
		}
	}
	for (int i = 111;i < 1000; i++) {
		if (chance[i] != 0) count++;
	} // 가능한 수들은 0이 아닌 수로 저장되므로 0이 아닌 수를 세준다.
	cout << count;
}
