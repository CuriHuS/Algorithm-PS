#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    int sum = 0;
    int temp = s / n;
    if (temp < 1) return {-1};
    for (int i=0; i<n; i++)
    {
        answer.push_back(temp);
        sum += temp;
    }

    while (sum < s)
    {
        for (int i=n-1; i>=0; i--)
        {
            answer[i] += 1;
            sum++;
            if(sum == s) break;
        }
    }
    
    return answer;
}