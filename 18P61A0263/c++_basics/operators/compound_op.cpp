#include<iostream>
using namespace std;
int main()
{
int a=10,b{7};
cout << " a value is " << a << endl;
cout << " b value is " << b << endl;
b+=a;
cout  << "b+=a is "  << b << endl;
cout << " a value is " << a << endl;
cout << " b value is " << b << endl;
cout  << "a+=b is "  << (a+=b)  << endl;
cout << " a value is " << a << endl;
cout << " b value is " << b << endl;

}
