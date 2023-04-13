#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool is_Prime(int x) { // 소수 판정
	bool result = true;
	if (x == 1) return false;
	int root = sqrt(x);
	for (int trial_factor = 2; result && trial_factor <= root; trial_factor++) {
		result = (x % trial_factor != 0);
	}
	return result;
}

bool is_Palindrome(string x) { // 펠린드롬 확인
	// 2-> 1번 확인 3->1번 확인 4-> 2번 확인 5->2번확인 6->3번확인이므로 int형 /2 의 결과값과 동일
	int leng = x.length();
	if (leng == 1) return true; // 1인 경우에는 leng/2가 0이 나오므로 따로 처리
	for (int trial = 0; trial < leng/2; trial++) {
		if (x[trial] != x[leng - trial - 1]) return false;
	}
	return true;
}
int main() {
	int N;
	cin >> N;
	for (int i = N; i <= 1003001; i++) { //1,000,000을 입력했을 때 1003001이 소수 및 펠린드롬 수를 만족하는 최대값이다.
		if (is_Prime(i) && is_Palindrome(to_string(i))) {
			cout << i;
			break;
		}
	}
}
