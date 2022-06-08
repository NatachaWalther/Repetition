#include <iostream>
#include <string>

using namespace std;


//___________________PVA1___________________________

void aufgabe_1_15() {

	int n1 = 1;
	int n2 = 10;

	// for
	for (n1; n1 <= n2; n1++) {
		cout << n1 << "\n";
	}

	// while

	while (n1 <= n2) {
		cout << n1 << "\n";
		n1++;
	}

	// do while

	do
	{
		cout << n1 << "\n";
		n1++;
	} while (n1 <= n2);

}

//struct Person{
//
//	string nachname;
//	string vorname;
//	int alter;
//
//};

void aufgabe_1_17(){

	Person person;
	cout << "Vorname:\n";
	cin >> person.vorname;

	cout << person.vorname;


}

void aufgabe_1_18(){

	string zeichenkette{ "17462309" };

	int number = stoi(zeichenkette);

	cout << number << "\n";
	int counter = 0;

	for (int i = 0; i <= zeichenkette.length(); i++) {

		cout << zeichenkette[i] << "\n";
		counter += zeichenkette[i];

	}

	cout << "Quersumme: " << counter;


}



int main() {

	//aufgabe_1_15();
	//aufgabe_1_17();
	//aufgabe_1_18();
	

}