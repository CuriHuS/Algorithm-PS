#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int arr[10] = { 0 };
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	
	vector<int> v;
	// i = 9, 키 제일 큰 사람
	// i=8, 키 9인 사람 왼쪽에 몇 명있나?
	// 0이라면 dq.push_front()
	// 1이라면 dq.push_back()

	v.push_back(N);

	for (int i = N-2; i >= 0; i--)
	{
		if (arr[i] > 0)
		{
			int num = arr[i];
			for (auto iter = v.begin(); iter != v.end(); iter++)
			{
				if (*iter > i)
				{
					num--;
				}
				if (num == 0)
				{
					v.insert(++iter, i+1);
					break;
				}
			}
		}
		else
		{
			v.insert(v.begin(), i + 1);
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}