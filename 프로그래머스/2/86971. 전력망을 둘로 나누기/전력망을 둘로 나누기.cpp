#include <string>
#include <vector>

using namespace std;

int root[101];

int find(int x)
{
    if (root[x] == x)
        return x;
    else
    {
        return find(root[x]);
    }
}

void union2(int x, int y)
{
    x = find(x);
    y = find(y);
    
    if(x < y) root[y] = x;
    else root[x] = y;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    int temp = 0;
    
    for (int i=0; i<wires.size(); i++)
    {
        for (int j=1; j<=n; j++) // Initialize node
        {
            root[j] = j;
        }
        
        for (int j=0; j<wires.size(); j++)
        {
            if (temp == j)
                continue;
            union2(wires[j][0], wires[j][1]);
        }
        
        int count = 0;
        for (int j = 1; j <= n; j++)
        {
            root[j] = find(j);
        }
        
        for (int j = 1; j <= n; j++)
        {
            if (root[j] == 1)
                count++;
        }
        answer = min(answer, abs(n-count*2));
        temp++;
    }
    return answer;
}