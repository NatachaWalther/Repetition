#include <iostream>
#include <string>
#include <vector>


using namespace std;



int p_1_1(){

	int number1;
	int number2;

	cout << "Peter: Hey Frank, I just learned how to add two numbers together.\n";
	cout << "Frank : Cool!\n";
	cout << "Peter : Give me the first number.\n";
	cin >> number1;
	cout << "Frank: " << number1 << "\n";
	cout << "Peter : Ok, and give me the second number.\n";
	cin >> number2;
	cout << "Frank: " << number2 << "\n";
	cout << "Peter : Ok, here's the answer: " << number1 << " + " << number2 << " = " << number1 + number2 << "\n";
	cout << "Frank : Wow!You are amazing!\n";

	return 0;

}

//Aufgabe P1 - 2: Was wird hier ausgegeben ? Was bedeutet die Ausgabe ?
void printSizeOfPrimitiveDataTypes() {
	signed char a;
	signed short b;
	signed int c;
	signed long d;
	signed long long e;
	float f;
	double g;
	long double h;
	bool i;


	std::cout << "sizeof signed char a      " << sizeof(a) << std::endl;
	std::cout << "sizeof signed short b     " << sizeof(b) << std::endl;
	std::cout << "sizeof signed int c       " << sizeof(c) << std::endl;
	std::cout << "sizeof signed long d      " << sizeof(d) << std::endl;
	std::cout << "sizeof signed long long e " << sizeof(e) << std::endl;
	std::cout << "sizeof float f            " << sizeof(f) << std::endl;
	std::cout << "sizeof double g           " << sizeof(g) << std::endl;
	std::cout << "sizeof long double h      " << sizeof(h) << std::endl;
	std::cout << "sizeof bool i             " << sizeof(i) << std::endl;
}

void aufgabe1_7(int size) {
	std::cout << "Beispiel zu vector" << std::endl;
	std::vector<int> v(size);

	// Generiere Zahl
	for (int& x : v) {
		x = rand() % 100 + 1;
	}

	//Print Vektor
	cout << "Vorher: \n";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << ", ";
	}
	cout << "\n";
	// Bubblesort
	for (size_t i = 0; i < v.size() - 1; ++i) {
		for (size_t j = 0; j < v.size() - i - 1; ++j) {
			if (v.at(j) > v.at(j + 1))
				std::swap(v.at(j), v.at(j + 1));
		}
	}
	cout << "\n";
	cout << "Nachher: \n";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << ", ";
	}

	std::cout << std::endl;
}





int main() {

	aufgabe1_7(10);


}