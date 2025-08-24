#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int points[3][2];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> points[i][j];
		}
	}

	while (true)
	{
		float grade1 = (float)(points[0][1] - points[1][1]) / (points[0][0] - points[1][0]);
		float grade2 = (float)(points[0][1] - points[2][1]) / (points[0][0] - points[2][0]);

		// 1. 세 점이 일직선 위에 있으면
		if (grade1 == grade2)
		{
			cout << "X";
			break;
		}

		// 2. 세 변의 길이가 같으면
		int sides[3];
		for (int i = 0; i < 3; i++)
		{
			sides[i] = pow(points[i][1] - points[(i + 1) % 3][1], 2) + pow(points[i][0] - points[(i + 1) % 3][0], 2);
		}

		sort(sides, sides + 3);

		if (sides[0] == sides[1] && sides[1] == sides[2])
		{
			cout << "JungTriangle";
			break;
		}

		// 3. 두 변의 길이가 같으면
		else if (sides[0] == sides[1] || sides[0] == sides[2] || sides[1] == sides[2])
		{
			if (sides[0] + sides[1] < sides[2])
			{
				cout << "Dunkak2Triangle";
				break;
			}
			else if (sides[0] + sides[1] == sides[2])
			{
				cout << "Jikkak2Triangle";
				break;
			}
			else
			{
				cout << "Yeahkak2Triangle";
				break;
			}
		}

		// 4. 세 변의 길이가 모두 다르면
		else
		{
			if (sides[0] + sides[1] < sides[2])
			{
				cout << "DunkakTriangle";
				break;
			}
			else if (sides[0] + sides[1] == sides[2])
			{
				cout << "JikkakTriangle";
				break;
			}
			else
			{
				cout << "YeahkakTriangle";
				break;
			}
		}

	}
}