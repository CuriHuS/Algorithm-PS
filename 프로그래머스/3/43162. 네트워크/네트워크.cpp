#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool dfs(int x, int n, int* visit_list, vector<vector<int>> computers)
{
    if (visit_list[x] == 1) return false;
    visit_list[x] = 1;
    for (int i=0; i<n; i++)
    {
        if (i==n) continue; // 본인 거는 1로 뜰테니..
        if (computers[x][i] == 1)
        {
            dfs(i, n, visit_list, computers);
        }
    }
    return true;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int* visit_list = new int [n];
    for (int i=0; i<n; i++)
    {
        visit_list[i] = 0;
    }
    
    for (int i=0; i<n; i++)
    {
        if(dfs(i, n, visit_list, computers))
        {
            answer++;
        }
    }
    
    return answer;
}