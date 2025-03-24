#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    int cycleNum = 1;
    vector<int> cycles(cards.size());
    vector<int> cycleNumSize;
    
    for (int i=0; i<cards.size(); i++)
    {
        if(cycles[i] != 0) continue;
        int cycleSize = 0;
        cycles[i] = cycleNum;
        cycleSize++;
        int index = cards[i] - 1;
        //cout << i << "번째 시작" << endl;
        while(cycles[index] == 0)
        {
            cycles[index] = cycleNum;
            index = cards[index] - 1;
            cycleSize++;
            cout << index << endl;
        }
        cycleNum++;
        cycleNumSize.push_back(cycleSize);
    }
    
    if (cycleNumSize.size() >= 2)
    {
        sort(cycleNumSize.begin(), cycleNumSize.end());
        answer = cycleNumSize[cycleNumSize.size()-1] * cycleNumSize[cycleNumSize.size()-2];
    }
    
    else
    {
        answer = 0;
    }
    
    return answer;
}