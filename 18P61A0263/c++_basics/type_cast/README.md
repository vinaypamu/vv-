type_cast is two types one is explicite other is implicite.
1) explicite is complier do not converts auto matically  one data type to anther . manully it adding somthing to convert one data type to anther.
2) implicite is compiler automatically converts one data type to anther.


example :

Implicit Type Casting
This happens automatically when you assign a value of one type to a variable of 
int a = 10;
double b = a; // Implicit type casting from int to double
 
here a value is converted and assingned to b automatically.


example :
Explicit Type Casting
You need to do this manually. There are several ways to perform explicit type casting in C++:

C-style cast
Static cast
Dynamic cast
Const cast
Reinterpret cast

1. C-style Cast
This is the traditional way to cast types in C++. It looks like this:
double a = 3.14;
int b = (int)a; // C-style cast from double to int out put is 3
int double c = (b * 1.0 )/2; // here c value 1.5

2. Static Cast
This is the preferred way to cast in C++ because it is more type-safe than C-style casting. It looks like this:
double a = 3.14;
int b = static_cast<int>(a); // Static cast from double to int



 
 
