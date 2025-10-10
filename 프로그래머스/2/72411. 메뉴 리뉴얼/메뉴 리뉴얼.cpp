#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

unordered_map<string, int> orderCountTable;

void calcOrderCustomers(string menus)
{
    orderCountTable[menus]++;
}
// 메뉴 조합 만들기
void makeCourseMenu(int n, vector<char> menus, string result)
{
    if (result.size() == n)
    {
        calcOrderCustomers(result);
        return;
    }
    for (int i=0; i<menus.size(); i++)
    {
        makeCourseMenu(n, vector<char>(menus.begin()+i+1, menus.end()), result + menus[i]);
    }
    return;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    sort(course.begin(), course.end());
    
    for (int i=0; i<course.size(); i++)
    {
        orderCountTable.clear();
        // 같은 가짓수로 이루어진 메뉴 할당 끝
        for (int j=0; j<orders.size(); j++)
        {
         // orders[j]를 vector 화.
            vector<char> temp;
            string s;
            for (int k=0; k<orders[j].size(); k++)
            {
                temp.push_back(orders[j][k]);
            }
            sort(temp.begin(), temp.end());
            makeCourseMenu(course[i], temp, s);
        }
        
        int maxCount = 0;
        for (auto& n : orderCountTable)
        {
            maxCount = max(n.second, maxCount);
        }
        
        for (auto& n : orderCountTable)
        {
            if(maxCount >= 2 && maxCount == n.second)
            {
                answer.push_back(n.first);
            }
        }
    }
        
    sort(answer.begin(), answer.end());
    return answer;
}