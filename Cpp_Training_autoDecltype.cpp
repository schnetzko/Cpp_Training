//============================================================================
// Name        : Cpp_Training_autoDecltype.cpp
// Author      : Nico
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <typeinfo>
#include <cmath>

using namespace std;

template<class A, class B>
auto add(A a, B b) -> decltype (a + b)
{
	return a + b;
}

auto get_function(int arg) -> double (*)(double){
	switch (arg){
		case 0:
			return cos;
		case 1:
			return fabs;
		default:
			return sin;
	}
}

void test1_auto(){
	auto var0 = 5;
	auto var1 = 5.0;
	auto var2 = "some characters";
	auto var3 = {5, 0, 2, -200};
	auto var4 = add(5, 5.0);
	auto func5 = get_function(0);
	auto func6 = [](int x) {return x + 4;}; // lambda expression

	cout << ":: test1_auto() ::" << endl;

	cout << "type of var0: " << typeid(var0).name() << endl;
	cout << "type of var1: " << typeid(var1).name() << endl;
	cout << "type of var2: " << typeid(var2).name() << endl;
	cout << "type of var3: " << typeid(var3).name() << endl;
	cout << "type of var4: " << typeid(var4).name() << endl;
	cout << "type of func5: " << typeid(func5).name() << endl;
	cout << "func5(3.5): " << func5(3.5) << endl;
	cout << "type of func6: " << typeid(func6).name() << endl;
	cout << "func6(4): " << func6(4) << endl;
}

void test2_decltype(){
	int var0 = 5;
	decltype (var0) var1;
	auto func2 = [](int x) -> int	// lambda expression
	{
		return x + 4;
	};
	auto func3 = [](int x)			// lambda expression, but what's the difference to the function before?
	{
		return x + 4;
	};
	decltype(func2) func4 = func2;
	decltype(func3) func5 = func3;

	cout << ":: test2_decltype() ::" << endl;

	cout << "type of var0: " << typeid(var0).name() << endl;
	cout << "type of var1: " << typeid(var1).name() << endl;
	cout << "type of func2: " << typeid(func2).name() << endl;
	cout << "func2(4): " << func2(4) << endl;
	cout << "type of func3: " << typeid(func3).name() << endl;
	cout << "func3(4): " << func3(4) << endl;
	cout << "type of func4: " << typeid(func4).name() << endl;
	cout << "func4(4): " << func4(4) << endl;
	cout << "type of func5: " << typeid(func5).name() << endl;
	cout << "func5(4): " << func5(4) << endl;
}

int main(void) {
	test1_auto();
	cout << endl;
	test2_decltype();
	return EXIT_SUCCESS;
}

