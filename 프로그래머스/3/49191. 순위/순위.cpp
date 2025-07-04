#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    int ** graph = new int*[n+1];
    for (int i=0; i<n+1; i++)
    {
        graph[i] = new int[n+1];
        for (int j=0; j<n+1; j++)
            graph[i][j] = 0;
    }
    
    for (int i=0; i<results.size(); i++)
    {
        graph[results[i][0]][results[i][1]] = 1;
    }
    
    for (int k=1; k<=n; k++)
    {
        for (int i=1; i<=n ;i++)
        {
            for (int j=1; j<=n; j++)
            {
                if (graph[i][k] == 1 && graph[k][j] == 1)
                    graph[i][j] = 1;
            }
        }
    }
    
    int* answers = new int[n+1];
    for (int i=0; i<=n; i++) answers[i] = 0;
    
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (graph[i][j] == 1)
            {
                answers[i]++;
                answers[j]++;
            }
        }
    }
    
    for (int i=1; i<=n; i++)
    {
        if (answers[i] == n-1)
        {
            answer++;
        }
    }
    
    
    return answer;
}