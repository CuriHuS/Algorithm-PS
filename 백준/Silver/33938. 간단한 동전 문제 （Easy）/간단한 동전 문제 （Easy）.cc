#include <iostream>

#define INT_MAX 999999
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    // N=0
    if (N == 0) {
        cout << (M == 0 ? 0 : -1);
        return 0;
    }

    // N=1
    if (N == 1) {
        long long a;
        cin >> a;
        if (a == 0) {                // 0원 동전만 있음
            cout << (M == 0 ? 0 : -1);
            return 0;
        }
        if (M % a == 0) {
            long long k = M / a;
            if (k >= 0) cout << k;   // 개수는 음수 불가
            else cout << -1;
        }
        else {
            cout << -1;
        }
        return 0;
    }

    // N=2
    long long a, b;
    cin >> a >> b;

    // 둘 다 0원 동전
    if (a == 0 && b == 0) {
        cout << (M == 0 ? 0 : -1);
        return 0;
    }

    const int LIM = 1000;            // |M|<=1000이므로 충분
    int best = INT_MAX;

    // 한 쪽 개수 i만 순회하고, 다른 한 쪽은 식으로 계산
    // i>=0, j>=0 만 허용
    for (int i = 0; i <= LIM; ++i) {
        long long sum_i = a * 1LL * i;
        long long rem = M - sum_i;

        // b가 0이면 j로 더할 수 없음 -> rem이 0일 때만 가능
        if (b == 0) {
            if (rem == 0) {
                best = min(best, i); // j=0
            }
            continue;
        }

        // 나누어떨어지고 j가 0 이상이어야 함
        if (rem % b == 0) {
            long long j = rem / b;
            if (j >= 0 && j <= LIM) {
                best = min(best, (int)(i + j));
            }
        }
    }

    cout << (best == INT_MAX ? -1 : best);
    return 0;
}