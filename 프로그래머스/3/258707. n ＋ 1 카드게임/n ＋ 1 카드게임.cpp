#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

bool isMatch(int n, unordered_set<int>& A, unordered_set<int>& B)
{
    for (auto&a : A)
    {
        auto it = B.find(n+1 - a);
        if (it != B.end())
        {
            A.erase(a);
            B.erase(*it);
            return true;
        }
    }
    return false;
}

int solution(int coin, vector<int> cards) {
    int answer = 1;
    
    int n = cards.size();
    unordered_set<int> deck, draw;    
    
    // 초반 덱 세팅
    for (int i=0; i<n/3; i++)
    {
        deck.insert(cards[i]);
    }
    
    // 뽑았다 치면 된다.
    
    for (int i=n/3; i<n; i+=2)
    {
        draw.insert(cards[i]);
        draw.insert(cards[i+1]);
        
        // 손 내 덱으로 n+1 만들 수 있다.
        if (isMatch(n, deck, deck))
        {
            
        }
        else if (coin >=1 && isMatch(n, deck, draw))
        {
            coin-=1;
        }
        else if (coin >= 2 && isMatch(n, draw, draw))
        {
            coin-=2;
        }
        else
        {
            break;
        }
        answer++;
    }
    
    
    return answer;
}