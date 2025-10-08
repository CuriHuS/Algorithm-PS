#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int calcFee(int times, int basicTime, int basicFee, int unitTime, int unitFee)
{
    return basicFee + max((float)0, ceil((times - basicTime)/(float)unitTime) * unitFee);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<string, int> inHash;
    map<string, int> timeHash;
    map<string, int> feeHash;
    
    for (int i=0; i<records.size(); i++)
    {
        int hours = stoi(records[i].substr(0, 2));
        int minutes = stoi(records[i].substr(3, 2));
        string nums = records[i].substr(6, 4);
        string ioType = records[i].substr(11,2);
        
        if (ioType == "IN")
        {
            inHash[nums] = hours * 60 + minutes;
        }
        else
        {
            timeHash[nums] += hours*60 + minutes - inHash[nums];
            inHash[nums] = -1;
        }
    }
    
    int maxExitTime = 23*60+59;
    
    for (auto& n : inHash)
    {
        if (n.second != -1)
        {
            timeHash[n.first] += maxExitTime - n.second;
        }
    }
    
    for (auto&n : timeHash)
    {
        answer.push_back(calcFee(n.second, fees[0], fees[1], fees[2], fees[3]));
    }
    
    return answer;
}