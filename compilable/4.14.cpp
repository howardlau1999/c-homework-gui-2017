#include <iostream>

using namespace std;

int main() {
    int i = 5;
    int n;
    while (i--) {
		cin >> n;
        bool two = n % 2 == 0;
        bool three = n % 3 == 0;
        cout << n << " ";
        if (two && three)
        cout << "is divisible by 2 and 3." << endl;
        else if (two || three)
        cout << "is divisible by 2 or 3, but not both." << endl;
        else if (!(two || three))
        cout << "is not divisible by 2 or 3." << endl;
	}
    return 0;
}