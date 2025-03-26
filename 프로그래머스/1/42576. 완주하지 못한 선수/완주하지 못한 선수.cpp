#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> run;
    
    for (int i=0; i<completion.size(); i++)
    {
        run[completion[i]]++;
    }
    
    for (int i=0; i<participant.size(); i++)
    {
        if (run.find(participant[i]) != run.end())
        {
            run[participant[i]] -= 1;
            if (run[participant[i]] == -1)
            {
                answer = participant[i];
                break;
            }
        }
        else
        {
            answer = participant[i];
            break;
        }
    }
    
    return answer;
}