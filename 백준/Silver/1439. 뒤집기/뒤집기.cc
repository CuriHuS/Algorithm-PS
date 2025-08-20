#include <iostream>
#include <string>

using namespace std;

int main()
{
	string S;
	cin >> S;
	
	int flip1 = 0; int flip0 = 0;
	if (S[0] == '0') flip0++;
	else flip1++;

	for (int i = 1; i < S.length(); i++)
	{
		if (S[i] != S[i - 1])
		{
			if (S[i] == '0') flip0++;
			else flip1++;
		}
	}
	cout << min(flip1, flip0);
}