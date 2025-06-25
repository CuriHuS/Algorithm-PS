#include<vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    queue<pair<int, int>> q;
    q.push(make_pair(0,0));
    
    int ** visit_list = new int* [n];
    for (int i=0; i<n; i++)
    {
        visit_list[i] = new int[m];
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            visit_list[i][j] = 0;
        }
    }
    
    int dx[4] = { 1,-1,0,0 };
    int dy[4] = { 0,0,1,-1 };
    
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        
        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (maps[nx][ny] == 0) continue;
                
                if(visit_list[nx][ny] == 0) // 방문 안 한 경우
                {
                    visit_list[nx][ny] = visit_list[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    
    if(visit_list[n-1][m-1] == 0) answer = -1;
    else answer = visit_list[n-1][m-1] + 1;
    
    return answer;
}