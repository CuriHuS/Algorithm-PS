#include <iostream>
#include <string>

using namespace std;

int main() {
	int a;
	string B = "0x";
	string C;
	cin >> C;
	B += C;
	a = stoi(B,nullptr,16);
	cout << a;
}
