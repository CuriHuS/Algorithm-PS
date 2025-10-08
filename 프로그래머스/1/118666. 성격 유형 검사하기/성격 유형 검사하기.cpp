#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    unordered_map<char, int> hash;
    
    for (int i=0; i<survey.size(); i++)
    {
        hash[survey[i][0]] += max(0, 4-choices[i]);
        hash[survey[i][1]] += max(0, choices[i]-4);
    }
    
    if (hash['R'] >= hash['T'])
        answer += 'R';
    else
        answer += 'T';
    
    if (hash['C'] >= hash['F'])
        answer += 'C';
    else
        answer += 'F';
    
    if (hash['J'] >= hash['M'])
        answer += 'J';
    else
        answer += 'M';
    
    if (hash['A'] >= hash['N'])
        answer += 'A';
    else
        answer += 'N';
    
    
    return answer;
}