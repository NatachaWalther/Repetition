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

 **Int to String** 

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

 **Stringstream**

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
	cout << "globales ::a= " << ::a << ’\n’;{ 

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
# PVA 2

## Funktionen

Aufbau: 
```cpp
rückgabetyp funktionsname(parameterliste);

//Deklaration
int summe(int a, int b);

//Definition
int summe(int a, int b) {
	return a+b;
}

```
### Übergabe per Wert

Innerhalb der Funktion wird mit einer Kopie gearbeitet, der originale Parameter bleibt unverändert

```cpp
#include <iostream>
int addiere_5(int); // Deklaration (Funktionsprototyp)
int main()
{
int i{0};
std::cout << i << " = Wert von i\n";
auto erg = addiere_5(i); // Aufruf (auto statt int)
std::cout << erg << " = Ergebnis von addiere_5\n";
std::cout << i << " = i unverändert!\n";
}
int addiere_5(int x) // Definition
{
x += 5;
return x;
}
```
### Rekursion
Funktion ruft sich selber auf

Beispiel Quersumme: 
```cpp
#include <iostream>

int qsum(long z)                        
// Parameter per Wert übergeben (Grunddatentyp)
{
  if (z != 0) {
    int letzteZiffer = z % 10;
    return letzteZiffer + qsum(z / 10); 
	// Rekursion
  }
  else {                                
  // Abbruchbedingung z == 0
    return 0;
  }
}

int main()
{
  std::cout << "Zahl: ";
  long zahl {0L};
  std::cin >> zahl;
  std::cout << "Quersumme = " << qsum(zahl) << '\n';
}
```
### Übergabe per Referenz

Wenn das Objekt verändert werden soll muss es als Referenz übergeben werden

```cpp
int i = 10;
int& j = i;		//Referenz auf i

using namespace std;

void addiere_7(int& zahl); // int& = Referenz auf int
int main() {
	int i{0};
	cout << i << " = alter Wert von i\n";
	addiere_7(i); // Syntax wie bei Übergabe per Wert
	cout << i << " = neuer Wert von i nach addiere_7\n";
}
void addiere_7(int& x) // int& = Referenz auf int {
	x += 7; // Original des Aufrufers wird geändert!
}
```
### Überladen von Funktionen

Mehrere Funktionen mit selbem Namen und anderen parametern, bsp. Print Funktion.


### Inline Funktionen



```cpp
inline int quadrat(int x){
	return x*x;
}
```

### constexpr Funktionen
werden zur Übersetzungszeit berechnet (Bsp als ```constexpr size_t SIZE = 5;```)

constexpr-Funktionen sind gleichzeitig inline. Das bedeutet, dass Deklaration und Definition in derselben Übersetzungeinheit sein müssen. Damit der Compiler die Funktion
nutzen kann, muss die Definition vor dem Aufruf von ihm gelesen worden sein. Die
Definition einer constexpr-Funktion, die von mehreren Übersetzungseinheiten genutzt
werden soll, gehört daher in eine Header-Datei. Das Schlüsselwort inline entfällt

## Makros

#include liest Dateien ein
#define, #if, #ifdef, #ifndef, #elif, #else, #endif steuern Compilationsablauf

* #define X definiert ein Symbol X.
* #if B lässt den Compiler die nächste Zeile verarbeiten, falls der konstante Ausdruck B wahr ist.
* #ifdef X fragt ab, ob X definiert ist.
* #ifndef X fragt ab, ob X undefiniert ist.
* #else gibt eine Alternative an.
* #elif entspricht #else #if.
* #endif beschließt jede mit #if beginnende Konstruktion

 Vermeiden mehrfacher Inkludierung mit #ifndef und #define

**Empfehlung für den Aufbau von Header-Dateien**

Eine Möglichkeit für den Aufbau von Header-Dateien ist das folgende Schema:

Schema für den Aufbau einer Header-Datei mit dem Namen fn.h
```cpp
#ifndef FN_H
#define FN_H
// hier folgen die Deklarationen
#endif // FN_H
```

## Namensräume

Sichbarkeitsbereich (Scope) 

```cpp
// Deklaration
namespace SpecialSoftwareGmbH_KlassenBibliothek {
// ....
}
// Abkürzung
namespace sskb = SpecialSoftwareGmbH_KlassenBibliothek;
// Benutzung der Abkürzung
using namespace sskb;
```

## Auto

Bei constexpr- und anderen inline-Funktionen liest der Compiler den gesamten Funktionskörper vor der ersten Verwendung, einschließlich der return-Anweisung. Das ermöglicht dem Compiler, den Rückgabetyp zu ermitteln, sowohl in der Funktionsdefinition, als auch beim Aufruf der Funktion. In solchen Fällen muss man nicht den Datentyp
erst nachsehen, sondern kann das bekannte Schlüsselwort auto verwenden.

## Header
Files mit Endung .h -> Einbinden mit #include \<iostream>

## Objektorientierung
### Klassen
Die Abstraktion von ähnlichen Eigenschaften und Verhaltensweisen ähnlicher Objekte.
Onjekt als Ausprägung einer Klasse.

```cpp
class Ort1 { // Version 1
public:
int getX() const; // const: siehe Text unten
int getY() const;
void aendern(int x, int y); // x, y = neue Werte
private:
int xKoordinate;
int yKoordinate;
}; 
```
Eine Datenänderung kann ausschließlich über eine geeignete Methode erfolgen,
zum Beispiel aendern(). Die x- und die y-Koordinate haben anfangs undefinierte Werte.
C++ initialisiert sie nicht automatisch mit 0. Das Schlüsselwort const oben drückt aus,
dass die damit ausgezeichneten Elementfunktionen das Objekt nicht verändern können
und deswegen auch auf konstante Objekte anwendbar sind. getX() und getY() geben nur
Zahlen zurück, ohne die privaten Daten zu verändern, während aendern() die vorherigen
Werte der privaten Variablen überschreibt.

#### Objekt erzeugen
```cpp
int main() // Anwendung der Ort1-Klasse
{
Ort1 einOrt1; // Objekt erzeugen
einOrt1.aendern(100, 200);
std::cout << "Der Ort hat die Koordinaten x = "
<< einOrt1.getX() << " und y = " << einOrt1.getY() << ’\n’;
}
```

Objekte können wie einfache Variablen als konstant deklariert werden. Um jegliche Änderungen zu vermeiden, dürfen Methoden von konstanten Objekten nur dann aufgerufen werden (ausgenommen Konstruktoren und Destruktoren), wenn sie als konstante
Elementfunktionen deklariert und definiert sind

#### inline-Elementfunktionen

```cpp
class Ort1 {
public:
int getX() const; // Prototyp
int getY() const; // Prototyp
void aendern(int x, int y); // Prototyp
private:
int xKoordinate;
int yKoordinate;
};
// ========= inline-Implementierung ===========
inline int Ort1::getX() const { return xKoordinate; }
inline int Ort1::getY() const { return yKoordinate; }
inline void Ort1::aendern(int x, int y) {
xKoordinate = x;
yKoordinate = y;
}
```
Diese Variante hat den Vorteil, dass die Implementierung der Methoden nicht direkt
innerhalb der Klassendeklaration sichtbar ist. Dadurch kann eine Klassendeklaration
übersichtlicher werden.

### Konstruktoren

#### Standardkonstruktor
Falls kein Konstruktor angegeben wird, wird einer vom System automatisch erzeugt
(implizite Konstruktordeklaration). Ohne die direkte Initialisierung der Attribute enthalten dann die Daten des Objekts unbestimmte Werte. Dieser
vordefinierte Konstruktor (englisch default constructor) kann auch selbst geschrieben
werden, um Attribute bei Anlage des Objekts zu initialisieren. Der Standardkonstruktor
hat keine Parameter. Für eine Klasse X wird er einfach mit X(); deklariert.

```cpp
// in Ort1.h
class Ort1 { // Variante 4
public:
Ort1(); // neuer Standardkonstruktor
// Rest wie oben
}

// in Ort1.cpp
Ort1::Ort1() // neuer Standardkonstruktor
{
xKoordinate = 0; // Koordinaten des Nullpunkts
yKoordinate = 0;
}
```

#### Allgemeiner Konstruktor
Allgemeine Konstruktoren können im Gegensatz zu Standardkonstruktoren Parameter
haben und genau wie Funktionen überladen werden. Das heißt, dass es mehrere allgemeine Konstruktoren mit unterschiedlichen Parameterlisten geben kann.

```cpp
// in Ort1.h
class Ort1 { // Variante 6
	public:
		Ort1(int x, int y); // Allgemeiner Konstruktor
// Rest wie oben
}

// in Ort1.cpp
Ort1::Ort1(int x, int y){ // Allgemeiner Konstruktor
	xKoordinate = x;
	yKoordinate = y;
}

// Aufruf
Ort1 nochEinOrt1(70, 90);
```
#### Kopierkonstruktor
Ein Kopierkonstruktor wird im Englischen copy constructor oder copy initializer genannt.
Er dient dazu, ein Objekt mit einem anderen zu initialisieren. Der erste (und im Allgemeinen einzige) Parameter des Kopierkonstruktors ist eine Referenz auf ein Objekt derselben
Klasse. Die Deklaration eines Kopierkonstruktors der Klasse X lautet X(X&);. Weil ein Objekt, das dem Kopierkonstruktor als Argument dient, nicht verändert werden soll, wird
es als Referenz auf const übergeben: X(const X&). Falls kein Kopierkonstruktor vorgegeben wird, wird bei Bedarf vom System einer erzeugt, der die einzelnen Elemente des
Objekts kopiert. D

```cpp
Ort(const Ort& einOrt)
// Kopie der einzelnen Elemente
	: xKoordinate{einOrt.xKoordinate},
	yKoordinate{einOrt.yKoordinate}{
// Anzeige des Aufrufs nur zur Demonstration
std::cout << "Kopierkonstruktor für ("
	  << xKoordinate << ", " << yKoordinate << ") aufgerufen\n";
}
```
### Destruktoren
Destruktoren dienen dazu, Aufräumarbeiten für nicht mehr benötigte Objekte zu leisten. Wenn Destruktoren nicht vorgegeben werden, werden sie vom System automatisch
erzeugt (implizite Deklaration). Der häufigste Zweck ist die Speicherfreigabe, wenn der
Gültigkeitsbereich eines Objekts verlassen wird. Konstruktoren haben die Aufgabe, Ressourcen zu beschaffen, Destruktoren obliegt es, sie wieder freizugeben. Die Reihenfolge
des Aufrufs der Destruktoren ist umgekehrt wie die der Konstruktoren.
Die Objekte werden nach der *letzten* Anweisung ihres Blocks zerstört.

```cpp
#include <iostream>

class Beispiel {
public:
  explicit Beispiel(int i = 0)                       // Konstruktor
      : zahl{i}
  {
    std::cout << "Objekt " << zahl << " wird erzeugt.\n";
  }

  ~Beispiel()                               // Destruktor
  {
    std::cout << "Objekt " << zahl << " wird zerstört.\n";
  }

private:
  int zahl;
};

Beispiel ein_globales_Beispiel;  // globale Variable, durch Vorgabewert mit 0 initialisiert

int main()
{
  std::cout << "main wird begonnen\n";
  Beispiel beispiel1(1);
  {
    std::cout << "    neuer Block\n    ";
    Beispiel beispiel2(2);
    std::cout << "    Block wird verlassen\n    ";
  }
  std::cout << "main wird verlassen\n";
}

//Output
Die Ausgabe des Programms ist:
Objekt 0 wird erzeugt.
main wird begonnen
Objekt 1 wird erzeugt.
	neuer Block
	Objekt 2 wird erzeugt.
	Block wird verlassen
	Objekt 2 wird zerstört.
main wird verlassen
Objekt 1 wird zerstört.
Objekt 0 wird zerstört
```
### Gegenseitige Abhängigkeit von Klassen
Was tun, wenn bei zwei Klassen jede die Methoden der jeweils anderen Klasse benutzt?
Es nutzt nichts, die Header-Datei der jeweils anderen Klasse miteinzuschließen, weil der
Compiler die nötigen Informationen nicht bekommt.

Wenn A.h zuerst gelesen wird, wird bei Ausführung der dritten Zeile B.h eingelesen. Die
Ausführung der dritten Zeile von B.h scheitert jedoch, weil A_h nun definiert ist und der
Rest von A.h nicht zur Kenntnis genommen wird. Die Lösung des Problems besteht in
der Vorwärtsdeklaration:

```cpp
// Datei A.h					// Datei B.h
#ifndef A_h					#ifndef B_h
#define A_h					#define B_h
class B; //Vorwärtsdeklaration			class A; //Vorwärtsdeklaration
class A {					class B {
	public:						public:
	void benutzeB(const B&);			void machWasMitA(A*);
	void eineAMethode();				void eineBMethode() const;
	// ... usw.					// ... usw.
};						};
#endif						#endif
```
Die Notation A* bedeutet »Zeiger3
auf Objekt der Klasse A«. In den Header-Dateien werden gegenseitig nur die Klassennamen bekannt gemacht. Die Kenntnisnahme der Methoden wird auf die Implementierungsdateien verschoben. Dies funktioniert dann, wenn die
Header-Dateien ausschließlich Zeiger oder Referenzen der jeweils anderen Klasse enthalten, aber keine Methodenaufrufe. Dies kann leicht erreicht werden, wenn auf inlineMethoden verzichtet wird, die Methoden der anderen Klasse benutzen. Die dazu notwendige Struktur wird für zwei Klassen gezeigt, eine Erweiterung auf die gegenseitige
Abhängigkeit mehrerer Klassen ist nach diesem Muster leicht möglich.

# PVA 3

## Zeiger

```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```


