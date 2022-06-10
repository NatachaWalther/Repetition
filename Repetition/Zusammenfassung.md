# PVA 1

## Basics

```cpp
#include <iostream>
using namespace std;

int main() {

	cout << "Hello World! \n";

}
```

Compiler Direktiven:

#include \<iostream>  für vordefinierte Files
#include "mylib.h"  für userdefinierte Files

-> Libraries und Headerfiles

Namespaces:

using namespace std; für ganzer Namespace

using std::cin für bestimmte Objekte



## Operatoren

### Arithmetische Operatoren
 +, -, *, /, % -> Vorzeichen mit unären Operatoren + und -

 ### Bitweise Arithmetik

 Bitweise Verknüpfung mit |, &, ^, ~, >>, <<
 
 |Operation|Binär|Dezimal
 |---|---|
 |a|1001|9
 |b|0011|3
 |a&b AND|0001|1
 |a\|b OR|1011|11
 |a^b XOR|1010|10
 |~b NICHT|1100|-4
 
 ### Zuweisungsoperatoren
 Weist einen Wert zu
 Standardarithmetisch: +=, -=, *=, \=, %=
 
 Binärarithmetisch: \|=, &=, ^=, <<=, >>=

 ### Prä- und Postinkrement

 ++a -> a inkrementiert und danach verwendet

 a++ -> a wird verwendet und danach inkrementiert
 
 ### Relationale Operatoren
 Vergleich, gibt ein bool als Antwort: ==, >=, <=, <, >, !=

 ### Logische Operatoren

 ||, &&, !

 ### Pointer und Dereferenzierung
 |Methoden | . | name.length()| 
 |---|---|
 |Adresse Pointer |&|&a
 |Wert Pointer|*|*a
 
 Kurzform: (*ptr).length() = ptr->length

 ### Besondere Operatoren
 Bedingung ? wennTrue : wennFalse
 
 Bsp.: max(w1 > w2 ? w1 : w2)
 
 ### Operatorenreihenfolge

 Im Kleinen Buch im Anhang B

 ## Eingebaute Datentypen

 ohne #include verwendbar

 * Ganzzahlen: int, short, long, long long -> (un-)signed
 * Fliesskomma: double, float, long double
 * Zeichen: char, char16_t, char32_t
 * Wahrheitswerte: boolean
 * Zeiger und C-Arrays

 ### Initialisierung

 mit leeren Klammern {} wird vom Compiler initialisiert, Bsp.: int i{} wird zu 0

 ### Konstanten

 Nicht veränderbarer Wert

 * const wenn der Wert zur Kompilationszeit noch nicht bekannt ist
 * constexpr wenn Wert zur Kompilationszeit schon bekannt

 ```cpp
 const double px {45.99};		// constexpr ist hier auch möglich
constexpr unsigned int anzahl {1000};
// weiterer Programmtext ...
px = 17.5;				// Fehlermeldung des Compilers!
anzahl = 10;				// Fehlermeldung des Compilers!
int a {3};				// nicht konstant
a = 5;					// a ändert sich
const int b {a};			// ok, b ist konstant
constexpr int c {a};			// Fehler! nicht aus Literal ableitbar
constexpr int d {3};			// ok, Literal
const int e {4};			// ok, e ist konstant
constexpr int f {e};			// ok, indirekt aus Literal ableitbar
 ```

 ### Typumwandlung

 Umwandlung zum grösseren Typen

 Wichtig: Signed und Unsigned nie Mischen!!

 Int to String

 ```cpp
 #include <iostream>
 #include<string>  
 using namespace std;

 int main() {
	int num = 100;
	string str;

	str = to_string(num);
}
 ``` 

 Stringstream

 convert strings of digits into ints, floats, or doubles
 
 ```cpp
 #include <iostream>
#include <sstream>
using namespace std;
 
int main()
{
    string s = "12345";
 
    // object from the class stringstream
    stringstream geek(s);
 
    // The object has the value 12345 and stream
    // it to the integer x
    int x = 0;
    geek >> x;
 
    // Now the variable x holds the value 12345
    cout << "Value of x : " << x;
 
    return 0;
}
 ``` 

 Weitere Optionen unter String
 
 ```cpp
 
 ```



 ## Gültigkeitsbereich und Sichtbarkeit

 Nach der Deklaration innerhalb des Blocks {}



```cpp
#include <iostream>
using namespace std;
// a und b werden außerhalb eines jeden Blocks deklariert. Sie sind damit globale Variablen.
int a {1};
int b {2};
int main() {
	cout << "globales a= " << a << ’\n’; // Ausgabe von a
	// Innerhalb des Blocks wird eine Variable a deklariert.
	int a {10};

	cout << "lokales a= " << a << ’\n’;
	cout << "globales ::a= " << ::a << ’\n’;{ // Ein neuer Block innerhalb des bestehenden beginnt.

}
```

## Benutzerdefinierte und zusammengesetzte Datentypen

### Enum

```cpp
enum class Farbtyp {rot, grün, blau, gelb};

Farbtyp gewählteFarbe;
Farbtyp farbe {Farbtyp::rot};
```
```cpp
#include <iostream>
using namespace std;
enum class Farbtyp { rot, gruen, blau, gelb };

int main() {
	Farbtyp farbe = Farbtyp::rot; // oder gruen usw.
	switch (farbe) {
		using enum Farbtyp; // !
		case rot : cout << "rot!\n"; break;
		case gruen : cout << "grün!\n"; break;
		case blau : cout << "blau!\n"; break;
		case gelb : cout << "gelb!\n";
	}
}
```
### Strukturen
```cpp
enum class Farbtyp {rot, gelb, gruen};

struct Punkt { // Punkt ist ein Typ
	int x;
	int y;
	bool istSichtbar;
	Farbtyp dieFarbe;
} p; // p ist ein Punkt-Objekt

// q ist ebenfalls ein Punkt-Objekt:
Punkt q; // noch undefinierter Inhalt
// Zugriff, hier: mit Werten versehen
p.x = 270; p.y = 20; // Koordinaten von p
p.istSichtbar = false;
p.dieFarbe = Farbtyp::gelb;
```
### Vektoren

Dynamische Grösse

```cpp
vector <int> v(10);		//Grösse 10
vector<int> v1 {};		// leerer Vektor
vector<int> v2 {7, 0, 9};	// Vektor mit den Elementen 7, 0, 9

cout << v2[1];			//Element 1 -> 0
cout << v2.at(5);		// Prüfen des Zugriffs -> Programmabbruch
```
**Kapazität:**

* size() – Returns the number of elements in the vector.
* max_size() – Returns the maximum number of elements that the vector can hold.
* capacity() – Returns the size of the storage space currently allocated to the vector expressed as number of elements.
* resize(n) – Resizes the container so that it contains ‘n’ elements.
* empty() – Returns whether the container is empty.
* shrink_to_fit() – Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
* reserve() – Requests that the vector capacity be at least enough to contain n elements.

**Zugriff:**
* reference operator [g] – Returns a reference to the element at position ‘g’ in the vector
* at(g) – Returns a reference to the element at position ‘g’ in the vector
* front() – Returns a reference to the first element in the vector
* back() – Returns a reference to the last element in the vector
* data() – Returns a direct pointer to the memory array used internally by the vector to store its owned elements.

**Modifizierung:**
Modifiers:

* assign() – It assigns new value to the vector elements by replacing old ones
* push_back() – It push the elements into a vector from the back
* pop_back() – It is used to pop or remove elements from a vector from the back.
* insert() – It inserts new elements before the element at the specified position
* erase() – It is used to remove elements from a container from the specified position or range.
* swap() – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
* clear() – It is used to remove all the elements of the vector container
* emplace() – It extends the container by inserting new element at position
* emplace_back() – It is used to insert a new element into the vector container, the new element is added to the end of the vector

```cpp
//Loop
vector<int> qus{1, 4, 9, 16, 25};

//Index
for (int index = 0 ; index < qus.size() ; ++index) {
	cout << qus[index];
}

//Iterator
for(auto iterator = qus.begin() ; iterator != qus.end() ; ++iterator) {
	cout << *iterator;
}
```

### Strings

```cpp
#include <string>
```
Aus einzelnen Chars zusammengesetzt

-> Alle Methoden im Lehrbuch Kapitel 31!

```cpp
// String-Objekt einString anlegen und mit "hallo" initialisieren.
string einString {"hallo"}; // einString kann ein beliebiger Name sein.
cout << einString << ’\n’; // String ausgeben


// Beim Vektor wäre stattdessen für die Ausgabe eine Schleife notwendig.
// Die Anzahl der Zeichen kann bei Strings mit length() ermittelt werden.
// String zeichenweise ausgeben, ungeprüfter Zugriff wie bei vector:
for (size_t i = 0; i < einString.length(); ++i) {
	cout << einString[i];
}
cout << ’\n’;

// String zeichenweise mit Indexprüfung ausgeben.
for (size_t i = 0; i < einString.length(); ++i) {
	cout << einString.at(i);
}
cout << ’\n’;

// Die Prüfung geschieht wie beim Vektor. Ein Versuch, einString.at(i)
// mit i ≥ einString.size() abzufragen, führt zum Programmabbruch mit Fehlermeldung.
string eineStringKopie(einString); // Kopie des Strings einString erzeugen
cout << eineStringKopie << ’\n’; // hallo
string diesIstNeu{"neu!"};
eineStringKopie = diesIstNeu; // Kopie durch Zuweisung
cout << eineStringKopie << ’\n’; // neu!
eineStringKopie = "Buchstaben"; // Zuweisung einer Zeichenkette
cout << eineStringKopie << ’\n’; // Buchstaben
einString = ’X’; // Zuweisung nur eines Zeichens vom Typ char
cout << einString << ’\n’; // X
einString += eineStringKopie; // Strings mit dem +=-Operator verketten
cout << einString << ’\n’; // XBuchstaben
einString = eineStringKopie + " ABC"; // Strings mit dem +-Operator verketten
cout << einString << ’\n’; // Buchstaben ABC
einString = "123" + eineStringKopie;
cout << einString << ’\n’; // 123Buchstaben
// einString = "123"+ "ABC"; geht nicht! Erklärung folgt in Kapitel 8
einString = string("123") + "ABC"; // ok!


// Vergleich von Strings
string a{"Albert"};
string b{a};
if (a == b) {
	cout << a << " == " << b << ’\n’;
}
else {
	cout << a << " != " << b << ’\n’;
}
string z{"Alberta"};
if (a < z) {
	cout << a << " < " << z << ’\n’;
}
if (z > a) {
	cout << z << " > " << a << ’\n’;
}
if (z != a) {
	cout << z << " != " << a << ’\n’;
}
string str{’a’, ’b’, ’c’}; // String mit Initialisierungsliste ’a’, ’b’, ’c’
cout << "mit Initialisierungsliste erzeugter String:" << str << ’\n’;
```

-> Standard Library für weitere Infos :
getline,
stod,
stof,
stoi,
stol,
stold,
stoll,
stoul,
stoull,
swap,
to_string,
to_wstring

## Kontrollstrukturen

### If

```cpp
if (x > 1) {
	cout << "x grösser 1 !";
else {
	cout << "x kleiner 1"; 
}
```

### Switch

```cpp
#include <iostream>
using namespace std;
int main() {
 
	switch(zeichen) {
		case ’i’:
		case ’I’:
			zahl = 1;
			break;
		case ’v’ : case ’V’ : zahl = 5; break; // andere Schreibweise
}
```

### While

```cpp
int sum {0};
constexpr int n {1};
constexpr int grenze {99};
while (n <= grenze) {
	sum += n++;
}
```

### Do While

```cpp
do {
	Anweisungen
} while (Bedingung);
```
### For

```cpp
for (int i = 1; i < 70; ++i) {
	cout << i << "\n";
}
```
## Ein- und Ausgabe

#include \<iostream>

cin Standardeingabe (Tastatur, gepuffert)
cout Standardausgabe (Bildschirm, gepuffert)
cerr Standardfehlerausgabe (Bildschirm, nicht gepuffert)
clog Standardfehlerausgabe (Bildschirm, gepuffert)

Wenn mit Leerzeichen `getline(cin, input)` verwenden.

Die Ein- und Ausgabeoperatoren >> und << sind bei Dateien ebenso wie bei der Standardein- und -ausgabe verwendbar. Für die Funktion get() zur Eingabe eines Zeichens gibt
es das Gegenstück put() zur Ausgabe eines Zeichens. Der Header <fstream> enthält die
vom Compiler verlangten Beschreibungen für Dateiobjekte. Die benutzten Funktionen
get(), put(), open() und close() und weitere nutzen die Dateifunktionen des zugrundeliegenden Betriebssystems. 

**Ablauf:**
* Dateiobjekt als Filestream definieren (ifstream oder ofstream)
* Verbindung zur Datei mit open()
* Do Stuff
* Verbindung mit close() wieder schliessen

```cpp
ifstream datei;
datei.open("dateiname.txt");
// ist dasselbe wie
ifstream datei("dateiname.txt");
```
**Schreiben und Lesen Textdatei**


```cpp
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main() {
	string dateiname {"unbekannt"};
	cout << "Dateiname? ";
	getline(cin, dateiname);
	// Datei schreiben
	ofstream datei(dateiname); // Objekt für Ausgabestrom
	if (!datei.good()) { // Fehlerabfrage
		cerr << dateiname << " kann nicht beschrieben werden! Programmabbruch!\n";
		return 1;
	}
	else {
		datei << "geschriebener Text.\nZweite Zeile!\n";
		datei.close(); // Schließen der Datei, damit sie gelesen werden kann
	}
	// Lesen derselben Datei und Anzeige der Zeilen
	ifstream quelle(dateiname); // Objekt für Eingabestrom
	cout << "Der Inhalt von " << dateiname << " ist:\n";
	while (quelle.good()) {
		string zeile;
		getline(quelle, zeile); // Zeile lesen
		cout << zeile << ’\n’;
	}
} // Datei wird am Programmende automatisch geschlossen.
```
**Kopieren von Dateien**

```cpp
#include <cstdlib> // für exit()
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main() {
	string dateiname {"unbekannt"};
	cout << "Quelldatei? ";
	cin >> dateiname;
	ifstream quelle(dateiname, ios::binary); // Objekt für die Eingangsdatei
						// Zu ios::binary siehe Text unten
	if (!quelle.good()) { // Fehlerabfrage
		cerr << dateiname << " kann nicht geöffnet werden!\n";
		exit(-1);
	}

	cout << "Zieldatei? ";
	cin >> dateiname; // ohne Leerzeichen!
	ofstream ziel(dateiname, ios::binary); // Definieren und Öffnen der Ausgabedatei
	if (!ziel.good()) { // Fehlerabfrage
		cerr << dateiname << " kann nicht geöffnet werden!\n";
		exit(-1);
	}

	char ch {’?’};
	while (quelle.get(ch)) {
		ziel.put(ch); // zeichenweise kopieren
	}
} // Dateien werden am Programmende automatisch geschlossen.



```


```cpp


```


```cpp


```


```cpp


```