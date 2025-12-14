#include <iostream>
#include <cmath>
using namespace std;

static int count = 0;
const float pi = 3.1415927;
const int inchToMile = 63360;
const float secondToHour = 3600;

void printResult(double dist, double mph)
{
	dist = round(dist * 100) / 100;
	mph = round(mph * 100) / 100;
	cout << fixed;
	cout.precision(2);
	cout << "Trip #" << ::count << ": " << dist << " " << mph << '\n';
}

int main()
{
	double diameter = 0;
	int rpm = 0;
	float seconds = 0;
	while (true)
	{
		cin >> diameter >> rpm >> seconds;
		if (rpm == 0) return 0;
		double wheelLength = diameter * pi;
		double distance = wheelLength * rpm / inchToMile;
		double mph = distance / (seconds/secondToHour);
		::count += 1;
		printResult(distance, mph);
	}
}