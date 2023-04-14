#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int score[5] = { 0 }; // 5장의 카드 숫자 크기 비교용 sort함
	char color[5] = { 0 }; // 카드 컬러 비교용
	int card[10] = { 0 }; // 카드 숫자 별 리스트로 한 장 당 1씩 오름
	int same_card[10] = { 0 }; // card 배열 sort용 배열
	
	for (int i = 0;i < 5;i++) {
		cin >> color[i] >> score[i];
		card[score[i]] ++;
		same_card[score[i]]++;
	}

	sort(score, score + 5);

	bool all_Color = true;
	for (int i = 0; i < 4 && all_Color; i++) { // 컬러가 다 같은지 확인
		if (color[i] != color[i + 1]) all_Color = false;
	}
	bool straight = true;
	for (int i = 0; i < 4 && straight; i++) { // 숫자가 스트레이트인지 확인(연속적인지)
		if (score[i] != score[i + 1] - 1) straight = false;
	}

	sort(same_card, same_card + 10, greater<>()); // 내림차순으로 정렬(3,2 장이 같다면 3,2,0,0 이런식으로 배열)

	int four, three, two;
	for (int i = 0; i < 10; i++) { // 똑같은 숫자인 카드가 4장 있으면 four 3장 있으면 three 2장이면 two에 저장
		if (card[i] == 4) four = i;
		else if (card[i] == 3) three = i;
		else if (card[i] == 2) two = i;
	}


	if (all_Color == true && straight==true) { // 1번 케이스
		cout << 900 + score[4];
	}
	else {
		if (same_card[0] == 4) { // 2번 케이스
			cout << 800 + four;
		}
		else if (same_card[0] == 3 && same_card[1]==2) { //3번 케이스
			
			cout << 700 + three * 10 + two;
		}
		else if (all_Color == true) { // 4번 케이스
			cout << 600 + score[4];
		}
		else if (straight == true) { // 5번 케이스
			cout << 500 + score[4];
		}
		else if (same_card[0] == 3) { // 6번 케이스
			cout << three + 400;
		}
		else if (same_card[0] == 2 && same_card[1] == 2) { // 7번 케이스
			int two_2;
			for (int i = 0; i < 10; i++) { // 여기서 two에는 숫자가 같은 카드가 두 장이 두 쌍 있는데 그 중 큰 수가 저장되고 two_2에 더 작은 수를 정해주면 반복 종료
				if (card[i] == 2) {
					two_2 = i;
					break;
				}
			}
			cout << 300 + 10 * two + two_2;
		}
		else if (same_card[0] == 2) { // 8번 케이스
			cout << 200 + two;
		}
		else { // 9번 
			cout << 100 + score[4];
		}
	}
}
