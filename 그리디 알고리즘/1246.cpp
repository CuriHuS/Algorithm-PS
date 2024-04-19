#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	long long int sum = 0; // 총 수익 (중간 저장용)
	long long int bestSum = 0; // 최고 수익
	int Egg = N;
	int bestPrice = 0; // 결과 값
	int* consumer = new int[M];
	for (int i = 0; i < M; i++) {
		cin >> consumer[i];
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			if (consumer[i] <= consumer[j] && Egg>0) {
				sum += consumer[i];
				Egg--;
			}
		}
		if (sum > bestSum) { // 이번 판매가 지금까지 판매했던 돈보다 많음
			bestPrice = consumer[i];
			bestSum = sum;
		}
		sum = 0;
		Egg = N;
	}
	cout << bestPrice << " " << bestSum;
}
