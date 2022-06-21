#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct Struktur {
	int x;
	int y;
};
// ...

int main() {

Struktur s{ 4, 9 };
std::cout << s.x << "\n"; // direkter Zugriff mit Punktoperator
Struktur* sptr{ &s }; // Zeiger auf s
std::cout << sptr->x << "\n";


	return 0;
}