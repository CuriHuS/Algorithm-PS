#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end());
    
    int index = score.size() - 1;
    
    while (index + 1 >= m)
    {
        int p = 10;
        for (int i = 0; i< m; i++)
        {
            if (p > score[index-i])
                p = score[index-i];
        }
        answer += p * m;
        index -= m;
    }
    
    
    return answer;
}