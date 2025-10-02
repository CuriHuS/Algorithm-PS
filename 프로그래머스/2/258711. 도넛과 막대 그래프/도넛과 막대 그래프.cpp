#include <string>
#include <vector>
#include <iostream>

using namespace std;
    
   
vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4);
    int inNums[1000001] = {};
    int outNums[1000001] = {};

    int maxVertex= 0;
    
    for (int i=0; i<edges.size(); i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];
        maxVertex = max(maxVertex, max(a,b));
        outNums[a] += 1;
        inNums[b] += 1;
    }
    
    int start = 0;
    int graphCount = 0;
    /*
    // 생성한 정점과 연결된 엣지 모두 삭제
    for (int i=1; i<=maxVertex; i++)
    {
        if (inNums[i] == 0 && outNums[i] >= 2)
        {
            start = i; // 생성한 정점
            
            for (auto iter = edges.begin(); iter != edges.end();)
            {
                bool isErase = false;
                for (auto n : *iter)
                {
                    if (isErase)
                    {
                        inNums[n]--;
                    }
                    
                    else if (n == start)
                    {
                        isErase = true;
                    }
                }
                if (isErase)
                {
                    iter = edges.erase(iter);
                    graphCount++;
                }
                else
                    iter++;
            }
            
            break;
        }
    }
    */
    
    for (int i=1; i<=maxVertex; i++)
    {
        // 생성된 정점
        if (inNums[i] == 0 && outNums[i] >= 2)
        {
            answer[0] = i;
        }
        // 8자 모양 그래프
       if (inNums[i] >= 2 && outNums[i] >= 2)
       {
           answer[3]++;
       }
        
        // 막대 모양
        else if (outNums[i] == 0 && inNums[i] >= 1)
        {
            answer[2]++;
        }
    }
    
    answer[1] = outNums[answer[0]] - answer[3] - answer[2];
    
    return answer;
}