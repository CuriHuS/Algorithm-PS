#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// 두 단어의 다른 글자
int diffwords(string wordA, string wordB)
{
    int wordLen = wordA.length();
    int result = 0;
    for (int i=0; i<wordLen; i++)
    {
        if (wordA[i] == wordB[i])
        {
            continue;
        }
        result += 1;
    }
    return result;
}

// dfs로 해결할 때 주의할 점
// visit_list는 초반에 가져가는 거 그대로 가져가기.(이후 초기화)
// 최소 방문 횟수는 따로 저장해서 출력

void dfs(int& answer, int step, string begin, string target, vector<string> words, int* visit_list)
{
    if (begin == target)
    {
        answer = min(answer, step);
        return;
    }
    
    for (int i=0; i<words.size(); i++)
    {
        if (visit_list[i] == 0 && diffwords(begin, words[i]) == 1)
        {
            visit_list[i] = 1;
            dfs(answer, step+1, words[i], target, words, visit_list);
            visit_list[i] = 0;
        }
        continue;
    }
    return;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 999999;
    int* visit_list = new int [words.size()];
    for (int i=0; i<words.size(); i++)
    {
        visit_list[i] = 0;
    }
    dfs(answer, 0, begin, target, words, visit_list);
    
    if (answer == 999999) return 0;
    return answer;
}