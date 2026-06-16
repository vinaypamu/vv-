#include <iostream>
using namespace std;

int main() {
    double a = 10.0;
    double b=9.999; //almost not equal precision
    double c = 9.999999999999999999;//almost equal precision
    if (a == b) {
        cout << "a and b are equal" << endl;
    } else {
        cout << "a and b are not equal" << endl;
    }
    if (a == c) {
        cout << "a and c are equal" << endl;
    } else {
        cout << "a and c are not equal" << endl;
    }

    return 0;
}

