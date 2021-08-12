// swap two doubles
void swap(double &a, double &b) {
	double t = a;
	a = b;
	b = t;
}

// sort
void sort(double & a, double & b, double & c) {
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);
}



#include <iostream>
using namespace std;

void test() {
	double num1, num2, num3;
	cin >> num1 >> num2 >> num3;
	sort(num1, num2, num3);
	cout << num1 << " " << num2 << " " << num3 << endl;
}

int main() {
	for (int i = 0; i < 10; ++ i) {
		test();
	}
}