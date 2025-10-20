#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	
	int answer = 0;
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++)
	{
		int target = v[i];
		int start = 0;
		int end = N - 1;
		if (start == i)
		{
			start++;
		}
		if (end == i)
		{
			end--;
		}
		
		bool isSame = false;
		while (start < end)
		{
			int mid = v[start] + v[end];
			if (mid == target)
			{
				isSame = true;
				break;
			}

			if (mid > target)
			{
				end -= 1;
				if (i == end)
				{
					end -= 1;
				}
			}
			else
			{
				start += 1;
				if (i == start)
				{
					start += 1;
				}
			}
		}
		if (isSame) answer += 1;
	}
	cout << answer;
}