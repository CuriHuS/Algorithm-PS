// 기존 문제는 "모든" 숫자를 쓰는 문제
// 아래 코드는 입력받은 숫자를 활용하여 가장 큰 30의 배수를 만드는 코드
// 즉, 일부 숫자를 희생시켜 30의 배수를 만든다.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string N;
	string answer;
	vector<int> count(10, 0);
	cin >> N;
	for (int i = 0; i < N.length(); i++) {
		count[static_cast<int>(N[i])-'0']++;
	}
	if (count[0] == 0) {
		cout << -1;
	}
	else {
		int sum = 0;
		for (int i = 0; i < 10; i++) {
			sum += i * count[i];
		}

		if (sum % 3 == 0) { // 3의 배수인 경우
			for (int i = 9; i >= 0; i--) {
				for (int j = 0; j < count[i]; j++) answer.append(to_string(i));
			}
			if (answer.length() > 1) cout << answer;
			else cout << -1;
		}
		else { // 3의 배수가 아닐 때
			if (sum % 3 == 1) {
				if (count[1] + count[4] + count[7] > 0) { // 1,4,7이 있는 경우
					for (int i = 1; i < 8; i += 3) {
						if (count[i] > 0) {
							count[i]--;
							break;
						}
					} 
					for (int i = 9; i >= 0; i--) {
						for (int j = 0; j < count[i]; j++) answer.append(to_string(i));
					}
					if (answer.length() > 1) cout << answer;
					else cout << -1;
				} // 1,4,7이 없으면 3의 배수가 될 수 없다.
				else cout << -1;
			}
			else { // sum%3==2
				if (count[2] + count[5] + count[8] > 0) { // 2,5,8이 있는 경우
					for (int i = 2; i < 9; i += 3) {
						if (count[i] > 0) {
							count[i]--;
							break;
						}
					}
					for (int i = 9; i >= 0; i--) {
						for (int j = 0; j < count[i]; j++) answer.append(to_string(i));
					}
					if (answer.length() > 1) cout << answer;
					else cout << -1;
				}
				else { // 2,5,8이 없으면
					int c = 2;
					if (count[1] + count[4] + count[7] >= 2) { // 2,4,7 중 두 개를 뺴면 3의 배수
						while(c>0){
							if (count[1] > 0) {
								count[1]--;
								c--;
								continue;
							}
							else if (count[4] > 0) {
								count[4]--;
								c--;
								continue;
							}
							else {
								count[7]--;
								c--;
								continue;
							}
						}
						for (int i = 9; i >= 0; i--) {
							for (int j = 0; j < count[i]; j++) answer.append(to_string(i));
						}
						cout << answer;

					}
					// 2,5,8 1,4,7이 없으면 무조건 3의 배수라 else로 안 빼도 됨.
				}
			}
		}
	}
}
