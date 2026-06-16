#include <iostream>
using namespace std;

int main() {
    bool x = true;
    bool y = false;

    // Default behavior
    cout << "Default (no boolalpha):" << endl;
    cout << "x: " << x << endl; // Outputs: 1
    cout << "y: " << y << endl; // Outputs: 0

    // Using boolalpha
    cout << "Using boolalpha:" << endl;
    cout << "start" << boolalpha << "end\n"; // Enable boolalpha
    cout << "x: " << x << endl; // Outputs: true
    cout << "y: " << y << endl; // Outputs: false

    // Using noboolalpha
    cout << "Using noboolalpha:" << endl;
    cout << noboolalpha; // Disable boolalpha
    cout << "x: " << x << endl; // Outputs: 1
    cout << "y: " << y << endl; // Outputs: 0

    return 0;
}

