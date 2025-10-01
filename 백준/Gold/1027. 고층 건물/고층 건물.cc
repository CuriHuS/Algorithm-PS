#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> buildings;
	int a;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		buildings.push_back(a);
	}

	int maximum = 0;
	for (int x1 = 0; x1 < N; x1++)
	{
		int visibleBuildings = 0;
		int y1 = buildings[x1];
		for (int j = 0; j < x1; j++)
		{
			// 다른 고층 빌딩을 보려고 할 때
			int x2 = j;
			int y2 = buildings[j];

			bool isVisible = true;

			// 사이에 다른 빌딩이 있는지 확인
			for (int k = j + 1; k < x1; k++)
			{
				// y = (y1-y2)/(x1-x2)x + y1 -> 직선의 방정식
				// y < (y1-y2)/(x1-x2)x + y1 이어야 보임

				if ((double)buildings[k] - (double)(y1 - y2) / (x1 - x2) * (k-x1) - y1 >= 0)
				{
					isVisible = false;
					break;
				}
			}
			if (isVisible)
			{
				visibleBuildings++;
			}
		}
		//cout << x1 << "앞에 보이는 거: " << visibleBuildings << " ";


		for (int j = x1 + 1; j < N; j++)
		{
			// 다른 고층 빌딩을 보려고 할 때
			int x2 = j;
			int y2 = buildings[j];

			bool isVisible = true;

			// 사이에 다른 빌딩이 있는지 확인
			for (int k = x1+1; k < j; k++)
			{
				// y = (y1-y2)/(x1-x2)x + y1 -> 직선의 방정식
				// y < (y1-y2)/(x1-x2)x + y1 이어야 보임
				if ((double)buildings[k] - (double)(y1 - y2) / (x1 - x2) * (k-x1) - y1 >= 0)
				{
					isVisible = false;
					break;
				}
			}

			if (isVisible) visibleBuildings++;
		}
		//cout << "총 보이는 것: " << visibleBuildings << "\n";
		maximum = max(maximum, visibleBuildings);
	}
	cout << maximum;
}