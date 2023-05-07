#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string S;
	getline(cin, S);
	vector<char> v1;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '<') { // 태그인 경우
			for (int j = i; j < S.size(); j++) {
				cout << S[j];
				if (S[j] == '>') {
					i = j; // 다음 실행은 tag 이후부터
					break;
				}
			}
		}
		else if (S[i] == ' ') cout << ' '; // 다음이 공백인 경우에 따로 처리
		else { // tag가 아닌 경우 => 출력을 거꾸로 해줘야 하는 경우
			if (i == S.size() - 1) { // 마지막인 경우(특수)
				v1.push_back(S[i]);
				for (int j = v1.size() - 1; j >= 0; j--) {
					cout << v1[j];
					v1.pop_back();
				}
			}
			else { // 일반 문자
				v1.push_back(S[i]);
				if (S[i + 1] == '<' || S[i + 1] == ' ') { // 다음이 Tag나 공백인 경우 출력을 해주어야함
					for (int j = v1.size() - 1; j >= 0; j--) {
						cout << v1[j];
						v1.pop_back();
					}
				}
			}
		}
	}
}
