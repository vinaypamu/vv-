#include<iostream>
using namespace std;
int main()
{
int num=100,n_num{8};
double avg{0.0};
cout << "\nintially  avg = " << avg <<  endl ;
avg = num/n_num; // here we are not using any predefined lib function and not converting forcefully . 
cout << "\navg = num/n_num " <<endl;
cout << "nrml type cast of avg= " << avg << endl; 
avg = (1.0 * num )/n_num; // here we are not using any predefined lib function 
cout << "\navg = (1.0 * num )/n_num " <<endl;
cout << "forcefull type cast of avg= " << avg << endl << "\nusing static_cast <type> (var)" << endl;
cout << "static_cast<double> (num)/n_num" << endl;
avg =  static_cast<double> (num) / n_num; // here we are using predefined lib function which is converts automatically;
cout << "after static_cast of avg =" << avg  << endl;
int a = static_cast<int> (avg);
cout << "converting double to int a= static_cast<int> (avg)\n " << " a value is " << a << endl;
return 0;
}

