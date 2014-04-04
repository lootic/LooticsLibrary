#include "Vector.h"
#include "String.h"

void vector_test() {
	Vector<int,3> a = {1,2,3};
	Vector<int,3> b = {-1,4,2};
	Vector<int,3> c = a+b;
	cout << c;
	b -= a;
	cout << b;
}

void string_test() {
	String string = "test";
}

int main() {
	vector_test();
	string_test();
	//Vector<int,3> b({-1,4,2});
	//cout << (a+b).toString() << endl;
}