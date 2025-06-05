#include <string>
#include <vector>

using namespace std;


int dfs(int index, int sum, vector<int> numbers, int target)
{
    // 마지막인 경우
    if (index == numbers.size())
    {
        return sum == target ? 1 : 0;
    }
    
    return dfs(index+1, sum + numbers[index], numbers, target) + dfs(index+1, sum - numbers[index], numbers, target);
}


int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    answer = dfs(0, 0, numbers, target);
    
    return answer;
}

