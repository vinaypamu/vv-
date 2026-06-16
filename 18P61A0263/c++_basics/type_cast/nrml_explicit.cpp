#include<iostream>
using namespace std;
int main()
{
int num{100},n_num{8};
double avg = num/n_num;
// here int by int return value int so compiler not stores 12.5 it store or assigns to double is 12
cout << avg << endl;
return 0;
}

