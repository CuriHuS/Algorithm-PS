#include <iostream>
#include <cstring>

using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int stack_size = 0; // 실제 스택을 구현할 필요는 없으므로 stack_size를 int형으로 구현
	char ch[100001]; // 문자열 받기
	long long int count = 0; // 총 개수
	cin >> ch;
	int ch_len = strlen(ch); // cstring 필요

	stack_size++; // 첫 입력은 '(' 임이 확정

	for (int i = 1; i < ch_len; i++) {
		if (ch[i] == '(') {
			stack_size++;
		}
		else { // ')'이 입력
			if (ch[i-1] == '(') { // 이전 입력이 '('
				stack_size--;
				count += stack_size;
			}
			else { // 이전 입력이 ')'
				stack_size--;
				count++;
			}
		}
	}
	std::cout << count;
}
