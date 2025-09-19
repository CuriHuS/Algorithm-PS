#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

int maxChance = 0;
vector<int> answerDices;

void CalcCases(int n, int depth, int sum, vector<int> arr, unordered_map<int, int>& cases, vector<vector<int>>& dices)
{
    if (n==depth)
    {
        cases[sum]++;
        return;
    }    
    
    // depth번 주사위에서 j번이 나온다.
    // 그러면 arr[depth] 번 주사위에서 j를 뽑아 계산하기.
    for (int j=0; j<6; j++)
    {
        sum += dices[arr[depth]][j];
        CalcCases(n, depth+1, sum, arr, cases, dices);
        sum -= dices[arr[depth]][j];
    }
    return;
}

void CalcWinningChance(int n, vector<int> arr, vector<vector<int>>& dices)
{
    vector<int> bArr;
    //vector<int> bCases;
    for (int i=0; i<n; i++)
    {
        if (find(arr.begin(), arr.end(), i) == arr.end())
            bArr.push_back(i);
    }
    
    //vector<int> aCases;
    int temp= 0;
    // arr 세팅의 주사위로 가능한 경우 모두 구하기
    
    unordered_map<int, int> aCases;
    unordered_map<int, int> bCases;
    
    CalcCases(n/2, 0, temp, arr, aCases, dices);
    CalcCases(n/2, 0, temp, bArr, bCases, dices);
    /*
    sort(aCases.begin(), aCases.end());
    sort(bCases.begin(), bCases.end());
    
        
    int wins = 0;

    
    for (int i=0; i<aCases.size(); i++)
    {    
        int start = 0;
        int end = aCases.size() - 1;
        
        int mid = (start+end)/2;
        int here = 0;
        while (start <= end)
        {
            mid = (start+end) / 2;
            
            if (bCases[mid] < aCases[i])
            {
                start = mid + 1;
                here = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        
        wins += here;
    }
    */
    
    vector<int> bCaseSums;
    for (auto& b: bCases)
    {
        bCaseSums.push_back(b.first);
    }
    
    int wins = 0;
    sort(bCaseSums.begin(), bCaseSums.end());

    for (auto& a : aCases) {
    int idx = upper_bound(bCaseSums.begin(), bCaseSums.end(), a.first - 1) - bCaseSums.begin();
    int count = 0;
    for (int i = 0; i < idx; ++i) {
        count += bCases[bCaseSums[i]];
    }
    wins += count * a.second;
}

    
    if (wins > maxChance)
    {
        maxChance = wins;
        answerDices = arr;
    }
    
}

void SelectDice(int n, int start, vector<int> arr, vector<vector<int>>& dices)
{
    if (n/2 == arr.size())
    {
        CalcWinningChance(n, arr, dices);
        return;
    }
    for (int i=start; i<n; i++)
    {
            arr.push_back(i);
            SelectDice(n, i+1, arr, dices);
            arr.pop_back();      
    }
    return;
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    vector<int> temp;
    SelectDice(dice.size(),0, temp, dice);
    
    //cout << maxChance;
    for (int i=0; i<answerDices.size(); i++)
    {
        answer.push_back(answerDices[i]+1);
    }
    return answer;
}