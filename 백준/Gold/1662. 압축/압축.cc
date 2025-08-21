#include <iostream>
#include <stack>

using namespace std;

int UnZip(string& str, int s, int e, int top, int stack[], int endBracket[])
{
	int len = 0;

	for (int i = s; i < e; i++)
	{
		if (str[i] == '(')
		{
			--len;
			len += UnZip(str, i+1, endBracket[i], top, stack, endBracket) * (str[i - 1] - '0');
			i = endBracket[i];
		}
		else
		{
			++len;
		}
	}
	return len;
}

int main()
{
	string S;
	cin >> S;

	int stack[51];
	int endBracket[51];
	int top = 0;
	for (int i = 0; i < S.length(); i++)
	{
		if (S[i] == '(')
		{
			stack[top] = i;
			top += 1;
		}

		else if (S[i] == ')')
		{
			top -= 1;
			endBracket[stack[top]] = i;
		}
	}

	cout << UnZip(S, 0, S.length(), top, stack, endBracket);
}