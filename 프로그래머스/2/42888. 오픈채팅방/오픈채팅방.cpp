#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    
    vector<vector<string>> v;
    
    
    for(int i=0; i<record.size(); i++)
    {
        stringstream ss(record[i]);
        string word;
        vector<string> words;
        while (getline(ss, word, ' ')) 
        {
            words.push_back(word);
        }
        
        if (words[0] == "Change")
        {
            m[words[1]] = words[2];
        }
        else if (words[0] == "Enter")
        {
            m[words[1]] = words[2];
        }
        
        v.push_back(words);
    }
    
    for (int i=0; i<v.size(); i++)
    {
        if (v[i][0] == "Enter")
        {
            string temp = m[v[i][1]] + "님이 들어왔습니다.";
            answer.push_back(temp);
        }
        else if (v[i][0] == "Leave")
        {
            string temp = m[v[i][1]] + "님이 나갔습니다.";
            answer.push_back(temp);
        }
    }
    
    return answer;
}