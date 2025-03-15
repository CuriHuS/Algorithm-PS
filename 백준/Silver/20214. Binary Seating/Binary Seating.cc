#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int t[1001] = { 0, };
	float chance = 0.0f;
	int input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		t[input] ++;
	}

	int count = 0;

	for (int i = 1000; i >= 1; i--)
	{
		if (t[i] >= 1)
		{
			chance += i * pow(0.5f, count) * (1- pow(0.5f, t[i]));
		}
		count += t[i];
	}

	cout << chance;
}