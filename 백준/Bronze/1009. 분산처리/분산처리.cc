#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int a, b;
		cin >> a >> b;
		int result = 1;
		for (int j = 0; j < b; j++)
		{
			result = (result * a) % 10;
		}
		if (result == 0) result = 10;
		cout << result << '\n';
	}
}