#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<bool> v;

int main()
{
	int N;
	cin >> N;
	v.assign(N, false);
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'R') continue;
		v[i] = true;
	}

	int leftRed = 0;
	int rightRed = 0;
	int leftBlue = 0;
	int rightBlue = 0;

	bool flag = true;
	for (int i = 0; i < N; i++)
	{
		if (flag)
		{
			if (v[i] == false) continue;
			flag = false;
		}
		if (v[i] == false) leftRed += 1;
	}

	flag = true;
	for (int i = 0; i < N; i++)
	{
		if (flag)
		{
			if (v[i]) continue;
			flag = false;
		}
		if (v[i]) leftBlue += 1;
	}

	flag = true;
	for (int i = N-1; i >= 0; i--)
	{
		if (flag)
		{
			if (v[i] == false) continue;
			flag = false;
		}
		if (v[i] == false) rightRed += 1;
	}

	flag = true;
	for (int i = N - 1; i >= 0; i--)
	{
		if (flag)
		{
			if (v[i]) continue;
			flag = false;
		}
		if (v[i]) rightBlue += 1;
	}
	cout << min(min(rightBlue, rightRed), min(leftRed, leftBlue));
}