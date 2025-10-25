#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

struct Node {
    int idx;
    long long val;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D;
    cin >> N >> D;
    vector<long long> A(N), dp(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    deque<Node> dq;
    long long ans = LLONG_MIN;

    for (int i = 0; i < N; i++) {
        // D 범위 밖의 인덱스 제거
        while (!dq.empty() && dq.front().idx < i - D)
            dq.pop_front();

        // 현재 dp 계산
        if (dq.empty()) dp[i] = A[i];
        else dp[i] = A[i] + max(0LL, dq.front().val);

        // deque 정리 (뒤에서 작은 값 제거)
        while (!dq.empty() && dq.back().val <= dp[i])
            dq.pop_back();

        dq.push_back({ i, dp[i] });
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
}