#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int m;
    while (true)
    {
        cin >> m;
        if (m == 0) break;

        cin.ignore(); // to consume the newline after m
        string s;
        getline(cin, s);

        unordered_map<char, int> freq;
        int left = 0, right = 0, maxLen = 0;

        while (right < s.length()) {
            freq[s[right]]++;

            while (freq.size() > m) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        cout << maxLen << "\n";
    }

    return 0;
}