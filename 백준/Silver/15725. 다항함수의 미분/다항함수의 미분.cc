#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	string f;
	cin >> f;
	
	string x;
	int xIdx = -1;

	float answer = 0;

	bool isNegative = false;
	if (f[0] == '-') isNegative = true;

	if (!isNegative)
	{
		for (int i = 0; i < f.length(); i++)
		{
			if (f[i] == 'x')
			{
				xIdx = i;
				break;
			}
			else
			{
				x += f[i];
			}
		}
	}
	else
	{
		for (int i = 1; i < f.length(); i++)
		{
			if (f[i] == 'x')
			{
				xIdx = i;
				break;
			}
			else
			{
				x += f[i];
			}
		}
	}

	if (x.length() > 0 && xIdx != -1)
	{	
		if (isNegative)
		{
			answer = - stof(x);
		}
		else
		{
			answer = stof(x);
		}
	}
	if (isNegative)
	{
		if (xIdx == 1)
			answer = -1;
	}
	else
	{
		if (xIdx == 0)
			answer = 1;
	}

	cout << answer;
}