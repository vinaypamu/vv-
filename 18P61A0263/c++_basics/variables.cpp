#include<iostream>
using namespace std;
int main()
{
int a=10,b{20};
cout << "int a, b" << " values " << "a=" << a << " & b=" << b << endl;
long int num1=20,num2{22};
cout << "long int num1,num2" << " values " << "num1=" << num1 << " & num2=" << num2 << endl;
long long int num3=33,num4{55};
cout << "long long int num3,num4" << " values " << "num3=" << num3 << " & num4=" << num4 << endl;
short int num5=88,num6{77};
cout << "short int num5,num6" << " values " << "num5=" << num5 << " & num6=" << num6 << endl;
unsigned short int num7=80,num8{70};
cout << "unsigned short int num7,num8" << " values " << "num7=" << num7 << " & num8=" << num8 << endl;
unsigned long int num9=99;
cout << "unsigned long int num9" << " values num9=" << num9 << endl;
unsigned long long int num10=123344;
cout << "unsigned long long int num10" << " values num10=" << num10 << endl;
char c='c',d{'h'};
cout << "char c,d" << " values c=" << c  << "& d=" << d <<  endl;
float num12{1.5};
cout << "float num12" << " values num12=" << num12 << endl;
double num13=1.409;
cout << "double num13" << " values num13=" << num13 << endl;
long double num14=1.555;
cout << "long double num14" << " values num14=" << num14 << endl;
return 0;

}
