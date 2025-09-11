#include <iostream>
#include <string>
using namespace std;

string flip(string t)
{
	string temp = "";
	for (int i = t.length() - 1; i > 0; i--)
	{
		temp += t[i];
	}
	return temp;
}

bool find(string t, string s)
{
	if (t.length() == s.length())
	{
		return t == s;
	}
	if (t[0] == 'B' && find(flip(t), s))
	{
		return true;
	}
	if (t[t.length() - 1] == 'A' && find(t.substr(0, t.length()-1), s))
	{
		return true;
	}
	return false;
}


int main()
{
	string S, T;
	cin >> S >> T;

	if (find(T, S))
	{
		cout << 1;
	}
	else cout << 0;
}