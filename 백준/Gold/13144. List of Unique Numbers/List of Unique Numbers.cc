#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	vector<int> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	if (N == 1)
	{
		cout << 1;;
		return 0;
	}
	
	////// 예제 2번 
	///// 1 2 3 1 2
	//// -1, 12, 123
	//	- 2, 23, 231
	//	- 3, 31, 312
	//	- 1, 12
	//	- 2
	/////


	int end = 0;

	long result = 0;
	set<int> dup;

	for (int start = 0; start < N; ++start)
	{
		while (end < N)
		{
			if (dup.find(arr[end]) != dup.end())
			{
				break;
			}
			dup.insert(arr[end]);
			++end;
		}
		result += end - start;

		dup.erase(arr[start]);
	}


	cout << result;

}