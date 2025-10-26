#include <iostream>
#include <vector>

using namespace std;

void change(vector<int>& s, int n)
{
	if (s[n] == 0) s[n] = 1;
	else s[n] = 0;
}

int main()
{
	int N;
	cin >> N;
	vector<int> switches(N+1, 0);
	for (int i = 1; i <= N; i++)
	{
		cin >> switches[i];
	}

	int s;
	cin >> s;

	for (int i = 0; i < s; i++)
	{
		int sex, num;
		cin >> sex >> num;


		if (sex == 1)
		{
			for (int j = 1; num * j <= N; j++)
			{
				if (switches[num * j] == 1)
				{
					switches[num * j] = 0;
				}
				else switches[num * j] = 1;
			}
		}

		else
		{
			int idx = 0;
			for (int j = 1; num - j >= 1 && num + j <= N; j++)
			{
				if (switches[num - j] == switches[num + j])
				{
					++idx;
					continue;
				}
				break;
			}
			change(switches, num);
			for (int j = 1; j <= idx; j++)
			{
				change(switches, num + j);
				change(switches, num - j);
			}

		}
	}

	for (int i = 1; i <= N; i++)
	{
		
		cout << switches[i] << " ";
      if (i%20 == 0) cout << "\n";
	}

}