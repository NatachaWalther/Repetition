# Übungen Buch

## PVA 1

### 1.12
1.12 Schreiben Sie eine Schleife, die eine gegebene Zahl binär ausgibt, indem Sie mit geeigneten Bit-Operationen prüfen, welche Bits der Zahl gesetzt sind. Tipp: Verwenden Sie
die Zahl 1, verschoben um 0 bis z.B. 31 Bit-Positionen, als »Maske«. Mögliche Ergebnisse
können sein:
5 → 00000000000000000000000000000101
-5 → 11111111111111111111111111111011
Es ist zu sehen, dass -5 intern als Zweierkomplement von 5 dargestellt wird.

```cpp
//  Zahl binaer ausgeben
#include <iostream>
using namespace std;

int main()
{
	//cout << "Eingabe einer Zahl: ";
	int zahl{ 5 };
	//cin >> zahl;
	int anzahlDerBytes{ sizeof zahl };
	int anzahlDerBits{ 8 * anzahlDerBytes };

	cout << " binaer :  ";
	/* ToDo Schleife */
	for (int k = anzahlDerBits - 1; k >= 0; --k) {
		if (zahl & (1 << k)) {
			cout << '1';
		}
		else {
			cout << '0';
		}
	}
	cout << '\n';

	zahl = -5;
	cout << " binaer :  ";
	/* ToDo Schleife */
	for (int k = anzahlDerBits - 1; k >= 0; --k) {	
	//Iteriert durch Bits
		if (zahl & (1 << k)) {						
		//Wenn das Bit an der Stelle 1 ist print 1, sonst 0
			cout << '1';
		}
		else {
			cout << '0';
		}
	}
	cout << '\n';
}
/*
Bemerkung: Die 1 in der if (...)-Bedingung ist vom Typ
int. Sie muss durch mindestens so viele Bits wie zahl
repräsentiert werden. Wenn zahl als long deklariert werden
soll, ist daher 1L zu schreiben.
*/
```


### 1.15 
Berechnen Sie die Summe aller natürlichen Zahlen von n1 bis n2 mit a) einer forSchleife, b) einer while-Schleife, c) einer do while-Schleife, d) ohne Schleife. Es sei n2 =
n1 vorausgesetzt.
```cpp
void Aufgabe_1_15() {

	int n1 = 1;
	int n2 = 10;

	// for
	for (n1; n1 <= n2; n1++){
		cout << n1 << "\n";
	}

	// while
	while (n1 <= n2) {
		cout << n1 << "\n";
		n1++;
	}

	// do while
	do {
		cout << n1 << "\n";
		n1++;
	} while (n1 <= n2);
}
```

### 1.17 
Schreiben Sie eine Struktur (struct) namens Person, die Vorname, Nachname und
Alter einer Person enthält. Vorname und Nachname seien vom Typ string, Alter vom
Typ int. Verwenden Sie diese Struktur in einem Programm so, dass den Elementen der
Struktur Werte mit cin (Eingabe über die Tastatur) zugewiesen werden. Anschließend
sollen die Elemente auf dem Bildschirm ausgegeben werden.

```cpp
struct Person{
	string nachname;
	string vorname;
	int alter;
};

void aufgabe_1_17(){
	Person person;
	cout << "Vorname:\n";
	cin >> person.vorname;
	cout << person.vorname;
}
```

### 1.18 
Gegeben sei eine Zeichenkette des Typs string, die eine natürliche Zahl darstellen
soll und daher nur aus Ziffern besteht. Beispiel: "17462309".
a) Wandeln Sie den String in eine Zahl z vom Typ long um.
b) Berechnen Sie die Quersumme von z.
Geben Sie die Zahl und die Quersumme auf dem Bildschirm aus.

```cpp
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
```
### 1.19 
Etwas schwierig und nur für Knobelfreunde: Schreiben Sie ein Programm, das eine
einzugebende natürliche Zahl in römischer Darstellung ausgibt. Die römischen Ziffern
seien in einem konstanten String zeichenvorrat = "IVXLCDM" gegeben. Die meistens verwendete syntaktische Regel lautet: Keine Ziffer außer ’M’ darf mehr als dreimal hintereinanderstehen. Das heißt, ein vierfaches Vorkommen wird durch Subtraktion vom nächsthöheren passenden Wert ersetzt. Subtraktion geschieht durch Voranstellen des kleineren
Werts. So wird 4 nicht zu IIII, sondern zu IV, und 9 wird nicht zu VIIII, sondern zu IX.
```cpp
#include <iostream>
using namespace std;
int aufgabe_1_19(){
  cout << "Umwandlung einer natürlichen(!) dezimalen Ganzzahl in "
          "eine römische Zahl.\n Dezimalzahl eingeben:";
  unsigned int dezimalzahl{0};
  cin >> dezimalzahl;
  // Position                 0123456
  const string zeichenvorrat{"IVXLCDM"};
  int zehner{1000};                          // Start mit M=1000
  int n {6};                                 // Position 6
  string ergebnis;

  while (dezimalzahl != 0) {          // Ziffern sukzessive abtrennen
    auto ziffer = dezimalzahl / zehner;

    if ((ziffer > 3 && zehner == 1000)          // Tausender
        || ziffer <= 3) {                       // oder 0,1,2,3
      for (unsigned int i = 1; i <= ziffer; i++) {
        ergebnis += zeichenvorrat.at(n);
      }
    }
    else if (ziffer <= 4) {          // 4
      ergebnis += zeichenvorrat.at(n);
      ergebnis += zeichenvorrat.at(n + 1);
    }
    else if (ziffer <= 8) {          // 5,6,7,8
      ergebnis += zeichenvorrat.at(n + 1);
      for (unsigned int i = 1; i <= ziffer - 5; i++) {
        ergebnis += zeichenvorrat.at(n);
      }
    }
    else {
      ergebnis += zeichenvorrat.at(n);          // 9
      ergebnis += zeichenvorrat.at(n + 2);
    }
    n -= 2;
    dezimalzahl %= zehner;
    zehner /= 10;
  }
  cout << "Ergebnis: " << ergebnis << '\n';
}
```

### 1.20 
Schreiben Sie ein Programm, das beliebig viele Zahlen im Bereich von -99 bis
+100 (einschließlich) von der Standardeingabe liest. Der Zahlenbereich sei in 10 gleich
große Intervalle eingeteilt. Sobald eine Zahl außerhalb des Bereichs eingegeben wird, sei
die Eingabe beendet. Das Programm soll dann für jedes Intervall ausgeben, wie viele
Zahlen eingegeben worden sind. Benutzen Sie für -99, +100 usw. Konstanten (const).
Zur Speicherung der Intervalle soll ein vector<int> verwendet werden.
```cpp
#include <iostream>
#include <vector>
using namespace std;

int aufgabe_1_20()
{
  constexpr int minimum{-99};
  constexpr int maximum{100};
  constexpr int intervallzahl{10};
  constexpr int intervallbreite{(maximum - minimum + 1) / intervallzahl};
  int eingabe{0};
  vector<int> intervalle(intervallzahl);

  cout << "Bitte Zahlen im Bereich " << minimum << " bis " 
       << maximum << " eingeben:\n";

  cin >> eingabe;
  while (eingabe >= minimum && eingabe <= maximum) {
    intervalle[(eingabe - minimum) / intervallbreite]++;
    cin >> eingabe;
  }
  for (int i = 0; i < intervallzahl; i++) {
    cout << "Intervall " << i * intervallbreite + minimum << " .. "
         << (i + 1) * intervallbreite + minimum - 1 << ": " 
         << intervalle[i] << '\n';
  }
}
```

### 1.21 
Das folgende Problem ist klassisch und es haben sich schon viele Menschen damit
beschäftigt: Wenn Zahlen Achterbahn fahren. Gegeben sei eine natürliche Zahl > 0.
1. Wenn die Zahl gerade ist, teile sie durch 2. Wenn nicht, multipliziere sie mit 3 und
addiere 1.
2. Wenn die sich ergebende Zahl größer als 1 ist, wende Schritt 1 auf diese Zahl an.
Wenn nicht, ist das Verfahren beendet.
Es zeigt sich, dass die Zahlen erheblich anwachsen können und auch wieder kleiner
werden – daher der Name Achterbahn. Schreiben Sie ein Programm, das eine Startzahl als
Eingabe erwartet und den obigen Algorithmus durchführt. Lassen Sie sich die erreichte
Zahl und das erreichte Maximum anzeigen. Am Ende des Programms soll ausgegeben
werden, wie viele Iterationen (Durchläufe der Schleife) bis zum Ende des Programms
benötigt werden. Mit den Anweisungen
string dummy {""};
getline(cin, dummy); // weiter mit Tastendruck
können Sie die Ausgabe nach Erreichen eines neuen Höchstwerts anhalten. Versuchen
Sie die Startzahlen 4096, 142587, 1501353. Bei der ersten Zahl (4096) ist klar, dass
der Algorithmus schnell endet, weil 4096 eine Zweierpotenz ist. Die Frage ist letztlich:
Gibt es eine Startzahl, mit der der Algorithmus nicht irgendwann endet? Dieses Problem
tritt auch unter einer Reihe anderer Namen auf: Syracuse-Problem, Ulams-Problem oder
Collatz-Problem. Hinweis: Bei großen Zahlen wie der letzten angegebenen wird der intZahlenbereich überschritten; nehmen Sie stattdessen long long.

```cpp
#include <iostream>
#include <string>
using namespace std;

int aufgabe_1_21()
{
  cout << "Bitte eine Startzahl > 0 eingeben: ";
  long long zahl;
  cin >> zahl;
  cin.ignore(1000, '\n');          // Tastaturpuffer löschen
  int iterationen = 0;
  long long maxzahl = 0LL;
  while (zahl > 1) {
    ++iterationen;
    if (zahl % 2 == 0) {          // Zahl ist gerade
      zahl /= 2;
    }
    else {
      zahl = 3 * zahl + 1;
    }
    cout << zahl << '\n';
    if (maxzahl < zahl) {
      maxzahl = zahl;
      cout << " neues Maximum. Weiter mit ENTER\n";
      string dummy;
      getline(cin, dummy);          // weiter mit Tastendruck
    }
  }
  cout << iterationen << " Iterationen. Maximale Zahl = " << maxzahl << '\n';
}
```
### 1.22 
Schreiben Sie ein Progamm, das den Inhalt einer Datei hexadezimal ausdruckt.
Tipp: Da manche Compiler char als signed char implementieren, man aber für die Darstellung eine unsigned-Zahl braucht, muss ein Zeichen etwa wie folgt umgewandelt werden:
```cpp
char c {’?’}; // evtl. signed
while (datei.get(c)) { // lesen
unsigned char uc = static_cast<unsigned char>(c);
unsigned int zahl = static_cast<unsigned int>(uc);
// zahl hier weiterverarbeiten ...
}
```
Da das eine Übungsaufgabe ist, versuchen Sie, ohne hex auszukommen, wie Sie es etwa
mit der Zeile cout << hex << "0x" << 255 << ’\n’; ausprobieren können.

```cpp
#include <cstdlib>          // für exit()
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
  cout << "Dateiname :";
  string Quelldateiname{"unbekannt"};
  cin >> Quelldateiname;

  ifstream quelle(Quelldateiname, ios::binary);
  if (!quelle) {          // muss existieren
    cerr << Quelldateiname << " kann nicht geöffnet werden!\n";
    exit(-1);
  }

  // char ist notwendig, weil get(unsigned char&) nicht
  // implementiert ist (GNU C++)
  char c{'x'};          // signed!
  unsigned int count = 0;
  while (quelle.get(c)) {
    unsigned char uc = static_cast<unsigned char>(c);
    unsigned int zahl = static_cast<unsigned int>(uc);
    const string codierung{"0123456789ABCDEF"};
    // 2 stellig ausgeben
    cout << codierung.at(zahl / 16) << codierung.at(zahl % 16) << ' ';
    if (++count % 20 == 0) {
      cout << '\n';
    }
  }
  cout << '\n';
}
```
### 1.23 
Erweiterung zur vorigen Aufgabe: Erst 16 Buchstaben und dann die zugehörigen
16 Hex-Codes pro Zeile ausgeben.
```cpp
#include <cstdlib>          // für exit()
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
  cout << "Dateiname :";
  string Quelldateiname{"?"};
  cin >> Quelldateiname;

  ifstream quelle(Quelldateiname, ios::binary);
  if (!quelle) {          // muss existieren
    cerr << Quelldateiname << " kann nicht geöffnet werden!\n";
    exit(-1);
  }

  unsigned int count {0};
  constexpr unsigned int zeilenlaenge {16};
  string buchstaben;
  string hexcodes;
  // char ist notwendig, weil get(unsigned char&) nicht
  // implementiert ist (GNU C++)
  char c{'x'};
  while (quelle.get(c)) {
    unsigned char uc {static_cast<unsigned char>(c)};
      unsigned int zahl {static_cast<unsigned int>(uc)};
    const string codierung{"0123456789ABCDEF"};
    hexcodes += codierung.at(zahl / 16);
    hexcodes += codierung.at(zahl % 16);
    hexcodes += ' ';
    if (c < ' ') {          // nicht druckbares Zeichen
      c = '.';
    }
    buchstaben += c;
    ++count;
    count %= zeilenlaenge;
    if (count == 0) {
      cout << buchstaben << "   " << hexcodes << '\n';
      buchstaben = "";
      hexcodes = "";
    }
  }
  if (count != 0) {          // Rest ausgeben
    cout << buchstaben;
    for (unsigned int i = 0; i < (zeilenlaenge - count); ++i) {
      cout << ' ';
    }
    cout << "   " << hexcodes << '\n';
  }
  cout << '\n';
}
```
### 1.24 
Schreiben Sie ein Programm stat.cpp, das eine Statistik für eine Textdatei ausgibt,
deren Name eingegeben werden soll. Ein mögliches Ergebnis:
Anzahl der Zeichen = 16437, Anzahl der Worte = 2526, Anzahl der Zeilen = 220
Ein Wort sei hier als ununterbrochene Folge von Buchstaben definiert, wobei Umlaute
hier nicht als Buchstaben zählen sollen, weil sie nicht Teil des ASCII-Zeichensatzes sind.
In der Anzahl der Zeichen soll die Zeilenendekennung nicht enthalten sein.
```cpp
//  Datei-Statistik
#include <cstdlib>          // für exit()
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
  cout << "Dateiname :";
  string Quelldateiname{"?"};
  cin >> Quelldateiname;
  ifstream quelle(Quelldateiname);
  if (!quelle) {          // muss existieren
    cerr << Quelldateiname << " kann nicht geöffnet werden!\n";
    exit(-1);
  }

  char c {'\n'};          // wegen der Abfrage in Zeile 38, falls die Datei leer ist
  long zeichenzahl {0l};
  long wortzahl {0l};
  long zeilenzahl {0l};
  bool istWort {false};

  while (quelle.get(c)) {
    if (c == '\n') {
      ++zeilenzahl;
    }
    else {
      ++zeichenzahl;
    }
    // Umlaute werden nicht berücksichtigt
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
      istWort = true;          // Wortanfang, oder c ist in einem Wort
    }
    else {
      if (istWort) {
        ++wortzahl;          // Wortende überschritten
      }
      istWort = false;
    }
  }
  if (c != '\n') {          // Die letzte Zeile enthält kein abschließendes \n.
    ++zeilenzahl;           // trotzdem mitzählen
  }
  if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
    // das letzte Zeichen ist in einem Wort, das noch nicht mitgezählt wurde
    ++wortzahl;
  }
  cout << "Anzahl der Zeichen (ohne Zeilenendekennung) = " << zeichenzahl << '\n';
  cout << "Anzahl der Worte   = " << wortzahl << '\n';
  cout << "Anzahl der Zeilen  = " << zeilenzahl << '\n';
}
```
### 1.25 
Es geht um ein Programm, das zu einer gegebenen Matrikelnummer den Namen
heraussucht. Gegeben sei eine Datei mit den Namen und den Matrikelnummern von Studierenden. Dabei folgt auf eine Zeile mit dem Namen eine Zeile mit der Matrikelnummer.
Das #-Zeichen ist die Endekennung. Beispiel:

Robby Williams

123456

Keith Richards

746453

Heinz Erhardt

6329430

\#

A) Schreiben Sie ein Programm, das eine Datei dieser Struktur mit beliebig vielen Einträgen einliest. Dabei sollen ein Name und die dazugehörende Matrikelnummer ein struct
des Typs StudentIn bilden. Name und Matrikelnummer seien beide vom Typ string. Die
Daten sollen in einem Vektor des Typs vector<StudentIn> abgespeichert werden. Geben
Sie den Inhalt des Vektors zur Kontrolle aus.
B) Anschließend soll das Programm eine Matrikelnummer erfragen und daraufhin den
zugehörigen Namen ausgeben (bzw. die Meldung »nicht gefunden«). Die Abfrage soll
beliebig oft möglich sein. Wird X oder x eingegeben, beendet sich das Programm.
```cpp
// Loesung noch ohne Funktionen
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct StudentIn {
  string name;
  string matrikelnummer;
};

int main()
{
  vector<StudentIn> studierende;
  cout << "Einlesen (Aufgabenteil A):\n";
  ifstream daten("datenzuAufg25.txt");
  while (daten) {
    string zeile;
    getline(daten, zeile);
    if (zeile == "#") {          // Endekennung gefunden
      break;
    }
    StudentIn student;
    student.name = zeile;
    getline(daten, zeile);
    student.matrikelnummer = zeile;
    studierende.push_back(student);
  }
  daten.close();
  if (studierende.empty()) {          // oder size() == 0
    cout << "keine Daten vorhanden!\n";
    return 1;
  }
  // Testausgabe
  for (auto stud : studierende) {
    cout << stud.name << "   " << stud.matrikelnummer << '\n';
  }

  cout << "Namen suchen (Aufgabenteil B):\n";
  string gesuchteMatNr;
  while (true) {
    cout << "Matrikelnummer? (X = Ende)";
    cin >> gesuchteMatNr;
    if (gesuchteMatNr == "X" || gesuchteMatNr == "x") {
      break;
    }
    else {
      bool gefunden = false;
      for (auto stud : studierende) {
        if (gesuchteMatNr == stud.matrikelnummer) {
          cout << stud.name << " gefunden.\n";
          gefunden = true;
          break;
        }
      }
      if (!gefunden) {
        cout << "nicht gefunden!\n";
      }
    }
  }
  cout << "Programmende" << '\n';
}
```

## Repe PVA 1 Moodle
### 1. Gegeben ist folgendes Programm:
```cpp
#include <iostream>
using namespace std;

int main()
{
	int summand1;
	int summand2;

	// Lies zwei Zahlen ein
	caut << " Zwei ganze Zahlen eingeben:";
	cin >> summand1 >> summand2;
	/* Berechne die Summe beider Zahlen
	 */
	int summe = summand1 + summand2;

	// Zeige das Ergebnis auf dem Bildschirm an
	cout << "Summe=" << summe << '\n';
	return 0;
}
```
Welche Meldung gibt der Compiler aus?
Die richtige Antwort ist:

Fehler	C2065	"caut": nichtdeklarierter Bezeichner

### 2. Gegeben ist folgendes Programm

```cpp
#include <iostream>
using namespace std;

int main()
{
	int summand1;
	summand2;

	// Lies zwei Zahlen ein
	cout << " Zwei ganze Zahlen eingeben:";
	cin >> summand1 >> summand2;
	/* Berechne die Summe beider Zahlen
	 */
	int summe = summand1 + summand2;

	// Zeige das Ergebnis auf dem Bildschirm an
	cout << "Summe=" << summe << '\n';
	return 0;
}
```
Was gibt der Compiler aus?

Die richtige Antwort ist:
Fehler	C2065	"summand2": nichtdeklarierter Bezeichner

### 3. GGT

```cpp
#include <iostream>
using namespace std;

int main()
{
  int x {27};
  int y {36};

  cout << "Der GGT von " << x << " und " << y << " ist ";
  while (x != y) {
    if (x > y) {
      x -= y;
    }
    else {
      y -= x;
    }
  }
  cout << x << '\n';
}
```

## Übungen Word

### P1-1

Schreiben Sie ein Programm, dass folgendes ausgibt:

Peter: Hey Frank, I just learned how to add two numbers together.

Frank: Cool!

Peter : Give me the first number.

Frank: 2.

Peter : Ok, and give me the second number.

Frank: 5.

Peter : Ok, here's the answer: 2 + 5 = 7.

Frank: Wow! You are amazing!


### P1-2
Aufgabe P1-2: Was wird hier ausgegeben? Was bedeutet die Ausgabe?
```cpp
void printSizeOfPrimitiveDataTypes(){
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
```
Ausgabe: -> Grösse in Bytes 

sizeof signed char a      1

sizeof signed short b     2

sizeof signed int c       4

sizeof signed long d      4

sizeof signed long long e 8

sizeof float f            4

sizeof double g           8

sizeof long double h      8

sizeof bool i             1


### P-1-4

Schreiben Sie ein Programm, das ein String rückwärts geschrieben ausgibt 

```cpp
void revOfStr(string& str)
{
	int n = str.length();

	// Swap character starting from two
	// corners
	for (int i = 0; i < n / 2; i++)
		swap(str[i], str[n - i - 1]);
}


void aufgabe_1_4() {
	{
		string str;
		cout << "\n\n Reverse a string:\n";
		cout << "----------------------\n";
		cout << " Enter a string: ";
		getline(cin, str);
		revOfStr(str);
		cout << " The string in reverse are: " << str << "\n";
		system("pause");
	}
}
```

### P-1-5
Pointer. Ergänzen Sie das folgende Programm:

```cpp
#include <iostream>
using namespace std;

int main() {
	int  var = 20;   // actual variable declaration.
	int  *ip;        // pointer variable 

	ip = &var;       // store address of var in pointer variable

	cout << "Value of var variable: ";
	cout << var << endl;

	// to Do: print the address stored in ip pointer variable
	cout << ip << endl;

	// to Do: access the value at the address available in pointer
	cout << *ip << endl;

	system("pause");
	return 0;
}
```

### P-1-6
Scope Resolution: Was gibt folgendes Programm aus? 

```cpp
int x;  // Global x    
int main() 
{ 
  int x = 10; // Local x 
  cout << "Value of global x is " << ::x; 
  cout << "\nValue of local x is " << x;   
  return 0; 
} 
```
Value of global x is 0 -> Ausserhalb = global

Value of local x is 10 -> innerhalb = local

### P-1-7

Analysieren Sie die folgende Funktion vectorExample aus dem Beispiel VectorsAndArrays und vervollständigen Sie das Programm um ein Sortieralgorithmus:

```cpp
void vectorExample(int size){
	std::cout << "Beispiel zu vector" << std::endl;
	std::vector<int> v(size);
	for(int &x : v){
		x = rng() % 100 + 1;
	}
	/* ToDo sortieren der Zahlen (ohne sort-Funktion stl) */
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++){
		std::cout << *it << ", ";
	}
	std::cout << std::endl;
}
```

```cpp
#include <vector>

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
```

### P-1-9
Functions: Vervollständigen Sie das folgende Programm:

```cpp
#include <iostream>
#include <string>
using namespace std;

// Function Signature
double getIncome(string);
double computeTaxes(double);
void printTaxes(double);

double computeTaxes(double income)
{
	if (income < 5000) return 0.0;
	return 0.07*(income - 5000.0);
}

double getIncome(string prompt)
{
    double income;
    std::cout << prompt << endl;
	std::cin >> income;
    return income;
}

void printTaxes(double taxes)
{
	std::cout << "Taxes: " << taxes << endl;
}

int main()
{
	// Get the income;
	double income = getIncome("Please enter the employee income: ");

	// Compute Taxes
	double taxes = computeTaxes(income);

	// Print employee taxes
	printTaxes(taxes);
	system("pause");
}
```

### P-1-10
Ergänzen Sie das Programm so, das Grossbuchstaben in Kleinbuchstaben umgewandelt werden und umgekehrt. Alle übrigen Zeichen bleiben unverändert.

```cpp
#include <iostream>
#include <string>

void swapLetters(std::string &letter) {
    for (int i = 0; i < letter.length(); i++) {
        if (isupper(letter[i])) {
            letter[i] = tolower(letter[i]);
        } else {
            letter[i] = toupper(letter[i]);
        }
    }
}

int main(){
    std::cout << "Aufgabe 1......... " << std::endl;
    std::string line;
    /* Eingabe */
    std::cout << "Text = ";
    getline(std::cin, line);
    
    /* Verarbeitung*/
    swapLetters(line);

   /* Ausgabe */
   std::cout << line << std::endl;
   std::cout << "...... 1. Aufgabe! " << std::endl;
  return 0;

}
```

### P-1-11
Ergänzen Sie das folgende Programm mit der Methode push, pop und display

```cpp
#include <iostream>
using namespace std;

int stack[100], n = 100, top = -1;

void push(int val) {
	if (top+1 < n) {
        top++;
        stack[top] = val;
    } else {
        std::cout << "Stack is full" << std::endl;
    }
}

void pop() {
	stack[top] = 0;
    top--;
}

void display() {
    
    std::cout << "stackpointer: " << top << "\n";
    std::cout << "stacksize: " << n << "\n";
	for (auto &&i : stack)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
}

int main() {
	int ch, val;
	cout << "1) Push in stack" << endl;
	cout << "2) Pop from stack" << endl;
	cout << "3) Display stack" << endl;
	cout << "4) Exit" << endl;
	do {
		cout << "Enter choice: " << endl;
		cin >> ch;
		switch (ch) {
		case 1: {
			cout << "Enter value to be pushed:" << endl;
			cin >> val;
			push(val);
			break;
		}
		case 2: {
			pop();
			break;
		}
		case 3: {
			display();
			break;
		}
		case 4: {
			cout << "Exit" << endl;
			break;
		}
		default: {
			cout << "Invalid Choice" << endl;
		}
		}
	} while (ch != 4);
      //System("pause");
	return 0;
}
```

## PVA 2

### 2-1
Vergleich Geschwindigkeit 2 Programme mit und ohne constexpr. Fibonacci

```cpp
#include<iostream> 
using namespace std; 
  
constexpr long int fib(int n) 
{
    return (n <= 1) ? n : fib(n - 1) + fib(n - 2);
} 
  
int main () 
{ 
    // value of res is computed at compile time.  
    const long int res = fib(40); 
    cout << res; 
    return 0; 
} 
```

### 2-2

Schreiben Sie eine Funktion int dauerInSekunden(int stunden, int minuten, int
sekunden), die die Gesamtzahl der Sekunden zurückgibt, berechnet aus den Parametern.

```cpp
int dauerInSekunden(int stunden, int minuten, int sekunden) {

	int dauer = 0;
	dauer += sekunden;
	dauer += (minuten * 60);
	dauer += (stunden * 60 * 60);

	return dauer;
}
```
### 2-3
Schreiben Sie eine Funktion double power(double x, int y), die x^y berechnen soll.
Wenn Sie nicht mehr genau wissen sollten, was x

```cpp
#include <cmath>          // wegen pow(), s.u.
#include <iostream>
using namespace std;

double power(double x, int y);

int main()
{
  cout << "x^y berechnen. Zahlen x und y eingeben (y ganzzahlig):";
  double x{0.0};
  int y{0};
  cin >> x >> y;
  cout << "x^y  = " << power(x, y) << '\n';
  cout << "pow(x,y)  = " << pow(x, y) << '\n';          // aus cmath
}

// Die Funktion power() entspricht der Funktion  pow()
//  der C++-Bibliothek ( <cmath>}.

double power(double x, int y)
{
  double ergebnis{1};
  bool negativ {false};
  if (y < 0) {
    y = -y;
    negativ = true;
  }
  for (int i = 0; i < y; ++i) {
    ergebnis *= x;
  }
  if (negativ) {
    ergebnis = 1.0 / ergebnis;
  }
  return ergebnis;
}
```
### 2-4

Schreiben Sie die Funktion zur Berechnung der Fakultät von Seite 114 als rekursive
Funktion. Dabei gilt: 0! = 1, 1! = 1, n! = n · (n – 1)!

```cpp
#include <iostream>
using namespace std;

long fakultaet(int n);

int main()
{
  cout << "Ganze Zahl >= 0 eingeben: ";
  int n{0};
  cin >> n;
  cout << n << "! = " << fakultaet(n) << '\n';
}

long fakultaet(int n)
{
  if (n < 2) {
    return 1;          // Rekursionsabbruch
  }
  return n * fakultaet(n - 1);
}
```

### 2-5
Copy Constructor: Vervollständigen Sie den folgenden Code:

```cpp
#include<iostream> 
using namespace std; 
  
class Point 
{ 
private: 
    int x, y; 
public: 
    Point(int x1, int y1) { x = x1; y = y1; } 
  
    // Copy constructor 
    Point(const Point &p2) {x = p2.x; y = p2.y; } 
  
    int getX()            {  return x; } 
    int getY()            {  return y; } 
}; 
  
int main() 
{ 
    Point p1(10, 15); // Normal constructor is called here 
    Point p2 = p1; // Copy constructor is called here 
  
    // Let us access values assigned by constructors 
    // code here
    std::cout << "x: " << p1.getX() << " y: " << p1.getY() << endl;	
    std::cout << "x: " << p2.getX() << " y: " << p2.getY() << endl;	
  
    return 0; 
}
```

### 2-6
Destructor: Vervollständigen Sie die Aufgabe P2-3 mit einem Class destructor und bestätigen Sie dies, indem die Ausgabe mit dem folgenden Satz: «object is deleted» ergänzt wird.  

```cpp
#include <iostream> 
using namespace std; 
  
class construct { 
public: 
    int a, b; 
  
    // Default Constructor 
    construct () 
    { 
        a = 10; 
        b = 20; 
    } 

    ~construct (){
        std::cout << "object is deleted";
    }
}; 
  
int main() 
{ 
    // display a, b
    // code here
    construct obj;
    std::cout << obj.a << "\n" << obj.b << endl;
     
    return 0; 
} 
```

### 2-7
Vervollständigen den folgenden Code so, dass Sie diese Ausgabe erhalten:

Ausgabe: 
Assignment operator called
Copy constructor called

```cpp
#include<iostream>  
#include<stdio.h>  
  
using namespace std;  
  
class Test  
{  
    public:  
    Test() {}  
    Test(const Test &t)  
    {  
        cout<<"Copy constructor called "<<endl;  
    }  
      
    Test& operator = (const Test &t) 
    { 
        cout<<"Assignment operator called "<<endl; 
        return *this; 
    }  
};  
  
// Driver code 
int main()  
{  
    //code here  
    Test x;
    Test y;
    y = x;
    Test b = x;

}  
```

### 2-8

2.8 Schreiben Sie eine Funktion istAlphanumerisch(const string& text), die true 
zurückgibt, wenn text nur Buchstaben und Ziffern enthält, andernfalls false.

```cpp
#include <iostream>
#include <string>

bool istAlphanumerisch(const std::string& text);

int main()
{
  std::string einText{"?"};
  std::cout << "Zeichenfolge eingeben:";
  std::getline(std::cin, einText);
  if (istAlphanumerisch(einText)) {
    std::cout << "Die eingegebene Zeichenkette enthält "
                 "nur Buchstaben und Ziffern.\n";
  }
  else {
    std::cout << "Die eingegebene Zeichenkette enthält NICHT "
                 "nur Buchstaben und Ziffern.\n";
  }
}

bool istAlphanumerisch(const std::string& text)
{
  bool ergebnis{true};
  for (char zeichen : text) {
    bool istZiffer {zeichen >= '0' && zeichen <= '9'};
    bool istBuchstabe {(zeichen >= 'A' && zeichen <= 'Z') || (zeichen >= 'a' && zeichen <= 'z')};
    // && bindet stärker, die Klammern sind nur zur besseren Lesbarkeit
    if (!istZiffer && !istBuchstabe) {
      ergebnis = false;
      break;          // weitere Prüfungen sind nicht notwendig
    }
  }
  return ergebnis;
}
```

## PVA 3

### 3-1
Schreiben Sie eine Klasse Person, die nur die Attribute Name (Typ std::string) und
Alter (Typ int) hat. Die Klasse soll die Methoden getName() und getAlter() zum Abfragen der Attribute enthalten. setName(const std::string& neuer Name) und setAlter(int
neuesAlter) dienen zum Ändern der Attribute. Schreiben Sie dazu ein main()-Programm,
das ein Person-Objekt für die 22-Jährige Annabella Meier anlegt und zum Beispiel die
folgenden Ausgaben tätigt:


Annabella Meier ist 22 Jahre alt.


Annabella Meier hatte Geburtstag. Sie ist jetzt 23 Jahre alt.


Sie hat auch geheiratet. Ihr Name ist jetzt Annabella Schulz.


Im main()-Programm sind die Namen und Altersangaben der Ausgabe natürlich durch
die entsprechenden Funktionsaufrufe zu bewerkstelligen.
Erweitern Sie anschließend die Klasse (und den Konstruktor) um das Attribut Geschlecht.
Dazu fügen Sie in der Datei Person.h vor der Klasse Person die Deklaration enum class
Geschlecht {m, w}; ein. Geben Sie im main()-Programm mithilfe der Elementfunktionen
istFrau() bzw. istMann() aus, ob die dort angelegte Person Frau oder Mann ist.

```cpp
//Person.h

#ifndef PERSON_H
#define PERSON_H
#include <string>

enum class Geschlecht { m, w };

class Person {
public:
  Person(const std::string& name_, int alter_, Geschlecht g)
      : name{name_}, alter{alter_}, geschlecht{g}
  {
  }
  const std::string& getName() const { return name; }
  void setName(const std::string& neuerName) { name = neuerName; }
  int getAlter() const { return alter; }
  void setAlter(unsigned int neuesAlter) { alter = neuesAlter; }
  bool istFrau() const { return geschlecht == Geschlecht::w; }
  bool istMann() const { return geschlecht == Geschlecht::m; }

private:
  std::string name;
  int alter;
  Geschlecht geschlecht;
};
#endif

//Main.cpp
#include "Person.h"
#include <iostream>
using namespace std;

int main()
{
  Person person("Annabella Meier", 22, Geschlecht::w);
  cout << person.getName() << " ist " << person.getAlter() << " Jahre alt.\n";
  person.setAlter(person.getAlter() + 1);          // Geburtstag
  cout << person.getName() << " hatte Geburtstag. Sie ist jetzt " << person.getAlter()
       << " Jahre alt.\n";
  person.setName("Annabella Schulz");          // Namensänderung
  cout << "Sie hat auch geheiratet. Ihr Name ist jetzt " << person.getName() << ".\n";

  if (person.istFrau()) {
    cout << person.getName() << " ist eine Frau.\n";
  }
  if (person.istMann()) {
    cout << person.getName() << " ist ein Mann.\n";
  }
}
```

### 3-3
Ergänzen Sie das untenstehende Programm, um diese Ausgabe zu erhalten:
The new copied character array is : C++
The 1st string before swapping is : C++ is for genius
The 2nd string before swapping is : C++ rocks
The 1st string after swapping is : C++ rocks
The 2nd string after swapping is : C++ is for genius

```cpp
#include <string>
#include <iostream>
using namespace std;

int main() { 
    // Initializing 1st string 
    string str1 = "C++ is for genius";   
    // Declaring 2nd string 
    string str2 = "C++ rocks";   
    // Declaring character array 
    char ch[5];   
    // using copy() to copy elements into char array 
    // copies "C++" 
    str1.copy(ch, 4);
    // Diplaying char array 
    cout << ch << endl;
    // Displaying strings before swapping 
    cout << str1 << "\n" << str2 << endl;
    // using swap() to swap string content 
    str1.swap(str2);
    // Displaying strings after swapping 
    cout << str1 << "\n" << str2 << endl;
    return 0;   
}
```

### 3-4
Pointer-to-Pointer  ergänzen Sie den untenstehenden Code:

```cpp
#include <iostream>

using namespace std;

int main() {
	int  var;
	int  *ptr;
	int  **pptr;

	var = 3000;

	// take the address of var
	ptr = &var;

	// take the address of ptr using address of operator &
	pptr = &ptr;

	// write out value of var, value available at *ptr, value available at **pptr
    cout << var << "\n" << *ptr << "\n" << *pptr << endl;

	
	return 0;
}
```

### 3-5
Pointer-to-Function  ergänzen Sie den untenstehenden code:

```cpp
#include <iostream>
using namespace std;

int doppel(int);
int dreifach(int);
int vierfach(int);

int main()
{
	int eingabe;
	int var =0;
	int (*zeiger) (int) = NULL; //Zeiger auf einer int Funktion
	for (; ;) {  //Ereignisschleife, 
      	//here you should enter the factor 2,3 or 4        
        cout << "here you should enter the factor 2,3 or 4" << endl;                           
        cin >> eingabe;
		//use switch to choose factor 
		switch (eingabe)
        {
        case 2:
            zeiger = doppel;
            break;
        case 3:
            zeiger = dreifach;
            break;
        case 4:
            zeiger = vierfach;
            break;
        
        default:
            cout << "Entered wrong number" << endl;      
            exit(-1);
            break;
        }

        //here you enter the number you want to multiply with the //factor and display the result 
        cout << "here you enter the number you want to multiply with the factor" << endl;
        cin >> eingabe;
        cout << "result:" << zeiger(eingabe) << endl;
	 } //end for
     
    return 0;
}

 
int doppel(int  x){
	 return (x * 2);
}

 int dreifach(int x) {
	 return(x * 3);
 }

 int vierfach(int x) {
	 return(x * 4);
 }
```

### 3-6
This-Pointer. Finden Sie den Fehler im untenstehenden Code:

```cpp
#include<iostream> 
using namespace std;

class Test1
{
private:
	int x;
public:
	Test1(int x = 0) { 
        this->x = x; //when we use the same name data member x
    }
	void change(Test1 *t) { this->x = t->x; } 
	void print() { 
cout << "x = " << x << endl; 
}
};

int main()
{
	Test1 obj(5);
	Test1 *ptr = new Test1(10);
	obj.change(ptr);
	obj.print();
	return 0;
} 
```

## PVA 4

### 4-1
Vererbung. Lassen Sie den untenstehenden Code laufen und sehen Sie wie den Aufruf von Konstruktoren und Destruktoren bei der Vererbung funktionieren

```cpp
//This program demonstrates the order in which base and derived class
//constructors and destructors are called.
#include <iostream>
using namespace std;

//***********
//Base class declaration
//***********

class BaseClass
{
public:
	BaseClass() //default constructor
		 {
			cout << "This is the BaseClass constructor.\n";
		}
	~BaseClass() //destructor
		{
			cout << "This is the BseClass destructor.\n";
		}

};

//**********
//Derived class declaration
//**********

class DerivedClass : public BaseClass
{
public:
	DerivedClass() //default constructor
		{
			cout << "This is the DerivedClass constructor.\n";
		}
	~DerivedClass() //destructor
		{
			cout << "This is the DerivedClass destructor.\n";
		}
};

//********
//main function
//********

int main() {
	cout << "We will now define a DerivedClass object.\n";
	DerivedClass Object;
	cout << "The end of program.\n";
	system("pause");
	return 0;
}

/* ----- OUTPUT ----- */
// We will now define a DerivedClass object.
// This is the BaseClass constructor.       
// This is the DerivedClass constructor.    
// The end of program.
// Press any key to continue . . . 
// This is the DerivedClass destructor.
// This is the BseClass destructor.
```

### 4-2
Vervollständigen Sie die Klasse Time.cpp mit dem Header-File Time.h und die Unterklasse TimexExt.cpp mit dem Header-File TimeExt.h und testen Sie es, so dass Sie folgendes erhalten:

```cpp
// main.cpp
#include "exttime.h"
int main(int argc, char const *argv[])
{
    /* code */
    ExtTime a;
    ExtTime b(0,49,2, PDT);

    a.Write();
    a.Set(16,49,23, CDT);
    a.Write();
    b.Write();
    b.Write();
    return 0;
}

// exttime.h
#pragma once
#include "time.h"

enum ZoneType { EST, CST, MST, PST, EDT, CDT, MDT, PDT };


class ExtTime : Time
{
private:
    /* data */
    ZoneType zone;
public:
    ExtTime(int initH, int initM, int initS, ZoneType initZone);
    ExtTime();

    void Set(int h, int m, int s, ZoneType timeZone);
    void Write() const;
    // void Write() const override;
};

// exttime.cpp
#include <iostream>
using namespace std;
#include <string>

#include "time.h"
#include "exttime.h"

void  ExtTime::Set(int h, int m, int s, ZoneType timeZone)
{
	Time::Set(h, m, s);  // same name function call
	zone = timeZone;
}

void  ExtTime::Write()   const  // function overriding
{
	string  zoneString[8] =
	{ "EST", "CST", "MST", "PST", "EDT", "CDT", "MDT", "PDT" };

	Time::Write();
	cout << " " << zoneString[zone] << endl;
}

ExtTime::ExtTime(int initH, int initM, int initS, ZoneType initZone)
	: Time(initH, initM, initS)
	// constructor initializer
{
	zone = initZone;}
ExtTime::ExtTime()
{
	zone = EST;
}

```

### 4-3
This-Pointer. Finden Sie den Fehler im untenstehenden Code:

```cpp
// main,cpp
#include <iostream>
#include "person.h"
#include "aufshr.h"

Person *Belegschaft[10];
int main(){
	Aufseherin *AufsZg;
	Programmiererin *ProgZg;
	Sekretaer *SekrZg;

	std::cout << "Belegschaft XYZ -- Der Gehalt ist monatlich.\n\n";

	AufsZg = new Aufseherin;
   	AufsZg->InitDaten("Hirraly", 7000, "Praesidentin");
   	Belegschaft[0] = AufsZg;

   	ProgZg = new Programmiererin;
   	ProgZg->InitDaten("Jenny Hacker", 5000, "Testerin",  "Pascal");
   	Belegschaft[1] = ProgZg;

   	ProgZg = new Programmiererin;
   	ProgZg->InitDaten("OOP Genie", 9500, "Analysevorstand", "C++");
   	Belegschaft[2] = ProgZg;

   	SekrZg = new Sekretaer;
   	SekrZg->InitDaten("Till Tipper", 1300, 1, 85);
   	Belegschaft[3] = SekrZg;

   	AufsZg = new Aufseherin;
   	AufsZg->InitDaten("Elli Wichtig", 4350, "Verkaufsvorstand");
   	Belegschaft[4] = AufsZg;

   	ProgZg = new Programmiererin;
   	ProgZg->InitDaten("Elfriede Soundso", 4750, "Code Warterin",
								"Assemblersprache");
   	Belegschaft[5] = ProgZg;

   //code for Zeige(): alle 6 obigen Objekte ausgeben 
   for (size_t i = 0; i < 6; i++)
   {
       Belegschaft[i]->Zeige();
   }
   
	return 0;
}

// person.h
#pragma once
#include <string>

class Person
{
protected:	  // Diese Variablen sind in Subklassen verfügbar
   std::string Name;
   int Gehalt;
public:
   virtual void Zeige(void);
};

// person.cpp
#include <iostream>
#include "person.h"

// Diese Funktion sollte nie aufgerufen werden. Sollte
// dies passiert, betrachten wir das als Fehler.
void Person::Zeige(void)
{
   std::cout << "Person::Zeige - fehlende Funktion in der Subklasse\n";
}

// aufshr.h
#pragma once
#include "person.h"

class Programmiererin : public Person
{
private:
    /* data */
    std::string Position;
    std::string Sprache;

public:
    void Zeige();
    void InitDaten(std::string name, int gehalt, std::string position, std::string sprache);
};

class Aufseherin : public Person
{
private:
    /* data */
    std::string Position;
public:
    void Zeige();
    void InitDaten(std::string name, int gehalt, std::string position);
};

class Sekretaer : public Person
{
private:
    /* data */
    int Skill;
    int TipProMin;
public:
    void Zeige();
    void InitDaten(std::string name, int gehalt, int skill, int tipProMin);
};

// aufshr.cpp
#include "aufshr.h"
#include <string>
#include <iostream>

void Programmiererin::InitDaten(std::string name, int gehalt, std::string position, std::string sprache){
    Name = name;
    Gehalt = gehalt;
    Position = position;
    Sprache = sprache;
}

void Programmiererin::Zeige(){

   std::cout << "Programmiererin::Zeige\n";
   std::cout << Name << "\n";
   std::cout << Gehalt << "\n";
   std::cout << Position << "\n";
   std::cout << Sprache << "\n" << std::endl;
}

void Aufseherin::InitDaten(std::string name, int gehalt, std::string position){
    Name = name;
    Gehalt = gehalt;
    Position = position;
}

void Aufseherin::Zeige(){
   std::cout << "Aufseherin::Zeige\n";
   std::cout << Name << "\n";
   std::cout << Gehalt << "\n";
   std::cout << Position << "\n" << std::endl;
}

void Sekretaer::InitDaten(std::string name, int gehalt, int skill, int tipProMin){
    Name = name;
    Gehalt = gehalt;
    Skill = skill;
    TipProMin = tipProMin;
}

void Sekretaer::Zeige(){
   std::cout << "Sekretaer::Zeige\n";
   std::cout << Name << "\n";
   std::cout << Gehalt << "\n";
   std::cout << Skill << "\n";
   std::cout << TipProMin << "\n" << std::endl;
}

```

### 4-4
Abstract Class / Pure Virtual Function
Ergänzen Sie den code und testen Sie getArea für die Klassen Circle und Rectangle  

```cpp
#include <iostream>
using namespace std;

class shape{
     public:
         virtual void getArea() =0;  //pure virtual function
};
class Circle: public shape{
      public: 
        void getArea(){
            cout<< "Enter the radius "<< endl;
            int r;
            cin>> r;
            cout << " The area of circle is : " << (3.14*r*r) << endl;
        };
};
class Rectangle: public shape{
    public:
    //code here, tip: area of rectangle = height * lengthvoid getArea(){
          
    void getArea(){
        cout << "Enter the side a "<< endl;
        int a;
        cin>> a;
        cout<< "Enter the side b "<< endl;
        int b;
        cin>> b;
        cout << " The area of rectangle is : " << (a*b);
    };
};

int main(int argc, char const *argv[])
{
    Circle circle;
    Rectangle rect;

    circle.getArea();
    rect.getArea();

    return 0;
};
```

### 4-5
Multiple Inheritance
a)	Lassen Sie das folgende Programm laufen. Was kriegen Sie als Ausgabe?
b)	Beschreiben Sie wie es zu dieser Ausgabe gekommen ist

```cpp
 #include<iostream> 
using namespace std; 
class Person { 
   // Data members of person  
public: 
    Person(int x)  { cout << "Person::Person(int ) called" << endl;   } 
}; 
  
class Faculty : public Person { 
   // data members of Faculty 
public: 
    Faculty(int x):Person(x)   { 
       cout<<"Faculty::Faculty(int ) called"<< endl; 
    } 
}; 
  
class Student : public Person { 
   // data members of Student 
public: 
    Student(int x):Person(x) { 
        cout<<"Student::Student(int ) called"<< endl; 
    } 
}; 
  
class TA : public Faculty, public Student  { 
public: 
    TA(int x):Student(x), Faculty(x)   { 
        cout<<"TA::TA(int ) called"<< endl; 
    } 
}; 
  
int main()  { 
    TA ta1(30); 
} 

/* ----- OUTPUT ----- */
// Person::Person(int ) called
// Faculty::Faculty(int ) called
// Person::Person(int ) called
// Student::Student(int ) called
// TA::TA(int ) called
// Multiple inheritence von links nach rechts konstruktor aufgerufen und immer zuerst parent
```

### 4-6
Multiple Inheritance
Die Lösung zur Mehrdeutlichkeit der Aufgabe P4-5 ist das Schlüsselwort virtual.
a)	Lassen Sie das folgende Programm laufen, was ist die Ausgabe?
b)	Beschreiben Sie wie es zu dieser Ausgabe gekommen ist

```cpp
#include<iostream> 
using namespace std; 
class Person { 
public: 
    Person(int x)  { cout << "Person::Person(int ) called" << endl;   } 
    Person()     { cout << "Person::Person() called" << endl;   } 
}; 
  
class Faculty : virtual public Person { 
public: 
    Faculty(int x):Person(x)   { 
       cout<<"Faculty::Faculty(int ) called"<< endl; 
    } 
}; 
  
class Student : virtual public Person { 
public: 
    Student(int x):Person(x) { 
        cout<<"Student::Student(int ) called"<< endl; 
    } 
}; 
  
class TA : public Faculty, public Student  { 
public: 
    TA(int x):Student(x), Faculty(x)   { 
        cout<<"TA::TA(int ) called"<< endl; 
    } 
}; 
  
int main()  { 
    TA ta1(30); 
} 

/* ----- OUTPUT ----- */
// Person::Person() called
// Faculty::Faculty(int ) called
// Student::Student(int ) called
// TA::TA(int ) called
// Vererbter konstruktor wird wegen virtual nur einmal aufgerufen
```

### 4-8
Class Templates. Vervollständigen Sie den folgenden Code um folgende Ausgabe zu erhalten: 1 2 3 4 5 6 

```cpp
#include <iostream> 
using namespace std;

template <typename T>
class Array {
private:
	T *ptr;
	int size;
public:
	Array(T arr[], int s);
	void print();
};

template <typename T>
Array<T>::Array(T arr[], int s) {
	ptr = new T[s];
	size = s;
	for (int i = 0; i < size; i++)
		ptr[i] = arr[i];
}

template <typename T>
void Array<T>::print() {
	for (int i = 0; i < size; i++)
		cout << " " << *(ptr + i);
	cout << endl;
}

int main() {
	//code here
    int i[]={1,2,3,4,5,6};
    Array<int> a(i, 6);
    a.print();
}

```

### 4-9
Templates. Vervollständigen Sie den folgenden Code um von zwei ganze Zahlen 100 und 75, die grössere Zahl auszugeben

```cpp
// class templates
#include <iostream>
using namespace std;

template <class T>
class mypair {
    T a, b;
public:
    mypair(T first, T second)
    {
        a = first; b = second;
    }
    T getmax();
};

template <class T>
T mypair<T>::getmax()
{
    T retval;
    retval = a > b ? a : b;
    return retval;
}

int main() {

    //code here
    mypair<int> a(4,10);
    std::cout << "Max is: " << a.getmax() << endl;
}

```

### 4-10
Templates. Vervollständigen Sie den folgenden Code 

```cpp
#include <iostream> 
using namespace std;

template < class T>
class Maths {
	T a, b;
public:
	 Maths(T x, T y) {
	 a = x;
	 b = y;
 }
 T maxValue();
};

template < class T>
class Maths {
    T a, b;
    public:
    Maths(T x, T y) {
    a = x;
    b = y;
    }
    T maxValue();
};

int main() {
	Maths<int> mat(45, 76);//change the type to double, float, 
	cout << mat.maxValue()<<endl;	
	return 0;
}

```

## PVA 5

### 5-1
Operator-Überladung
Vervollständigen Sie den folgenden Code:

```cpp
#include <iostream>
using namespace std;

class Box {
public:
    double getVolume(void) {
        return length * breadth * height;
    }
    void setLength(double len) {
        length = len;
    }
    void setBreadth(double bre) {
        breadth = bre;
    }
    void setHeight(double hei) {
        height = hei;
    }

    // operator + to add two Box objects.
    Box operator+(const Box& b) {
        //code here
        Box out;
        out.setLength(this->length + b.length);
        out.setBreadth(this->breadth + b.breadth);
        out.setHeight(this->height += b.height);
        return out;
        
    }

private:
    double length;      // Length of a box
    double breadth;     // Breadth of a box
    double height;      // Height of a box
};

int main() {
    Box Box1;                // Declare Box1 of type Box
    Box Box2;                // Declare Box2 of type Box
    Box Box3;                // Declare Box3 of type Box
    double volume = 0.0;     // Store the volume of a box here
    // box 1 specification
    Box1.setLength(6.0);
    Box1.setBreadth(7.0);
    Box1.setHeight(5.0);
    // box 2 specification
    Box2.setLength(12.0);
    Box2.setBreadth(13.0);
    Box2.setHeight(10.0);
   
    // volume of box 1
    volume = Box1.getVolume();
    cout << "Volume of Box1 : " << volume << endl;

    // volume of box 2
    volume = Box2.getVolume();
    cout << "Volume of Box2 : " << volume << endl;

    // Add two object as follows:
    Box3 = Box1 + Box2;

    // volume of box 3
    volume = Box3.getVolume();
    cout << "Volume of Box3 : " << volume << endl;

    return 0;
}

```

### 5-2
Operator-Überladung:
Vervollständigen Sie den folgenden Code:

```cpp
#include<iostream> 
using namespace std;

class Complex {
private:
	int real, imag;
public:
	Complex(int r = 0, int i = 0) { real = r;   imag = i; }

	// This is automatically called when '+' is used with 
	// between two Complex objects 
	Complex operator + (Complex const &obj) {
		//code here
        Complex out;
        out.real = this->real + obj.real;
        out.imag = this->imag + obj.imag;
		return out;
	}
	void print() { cout << real << " + i" << imag << endl; }
};

int main()
{
	Complex c1(10, 5), c2(2, 4);
	Complex c3 = c1 + c2; // An example call to "operator+" 
	c3.print();
}

```

### 5-3
Operator-Überladung
Um das Thema zu begreifen, erstellen wir eine Klasse Integer mit nur einem Attribut value. 
 
Auftrag:
Fügen Sie noch den Increment-Operator hinzu:
a)	Den pre-increment, damit a = ++x; funktioniert
b)	Den post.increment, damit a = x--; funktioniert

```cpp
#include <iostream>
#include "Integer.h"

int main() {
	Integer x = 8;
	Integer y = 6;

	Integer a, b, c, d;

	a = x + y;
	b = x - y;
	c = x * y;
	d = x / y;

	std::cout << " a = " << a.getValue() << std::endl;
	std::cout << " b = " << b.getValue() << std::endl;
	std::cout << " c = " << c.getValue() << std::endl;
	std::cout << " d = " << d.getValue() << std::endl;
}

// Integer.h
#pragma once

class Integer
{
private:
    int value;
public:
    Integer(){};
    Integer(int val);
    int getValue(){return value;}

    Integer operator+(Integer const &obj);
    Integer operator-(Integer const &obj);
    Integer operator*(Integer const &obj);
    Integer operator/(Integer const &obj);
    Integer operator++(int);
    Integer operator++();
};

Integer::Integer(int val)
{
    value = val;
}

Integer Integer::operator+(Integer const &obj) {
    Integer out;
    out.value = this->value + obj.value;
    return out;
}

Integer Integer::operator-(Integer const &obj) {
    Integer out;
    out.value = this->value - obj.value;
    return out;
}

Integer Integer::operator*(Integer const &obj) {
    Integer out;
    out.value = this->value * obj.value;
    return out;
}

Integer Integer::operator/(Integer const &obj) {
    Integer out;
    out.value = this->value / obj.value;
    return out;
}

// prefix operator
Integer Integer::operator++() {
    Integer out;
    out.value = value++;
    return out;
}

// postfix operator
Integer Integer::operator++(int) {
    Integer out;
    out.value = value++;
    return out;
}

```

### 5-4
Function Pointer
Vervollständigen Sie den untenstehenden Code um die folgende Ausgabe zu erhalten:
Fun 1
Fun 2

```cpp
#include <iostream>   

// Two simple functions 
void fun1() { printf("Fun1\n"); }
void fun2() { printf("Fun2\n"); }

// A function that receives a simple function as parameter and calls the function
void wrapper(void (*fun)()) {
    fun();
}

int main() {
    wrapper(fun1);
    wrapper(fun2);
    return 0;
}

```

### 5-5a
Function object
a.	Vervollständigen Sie den folgenden Code:

```cpp
#include <iostream>
using namespace std;
class MultBy {
    int mult;
public:
    MultBy(int n) : mult(n) {}
    int operator() (int n) { return mult * n; }
};
int main() {
    //code here
    MultBy a(4);
    MultBy b(10);
    MultBy c(15);

    
    std::cout << a(5) << std::endl;
    std::cout << b(12) << std::endl;
    std::cout << c(2) << std::endl;
    //display 4 times 5 using function object MultBy
    //display 10 times 12 using MultBy
    //display 15 times 2 using MultBy
}

```

### 5-5b
b.	Vervollständigen Sie den folgenden Code:

```cpp
#include <iostream>

class myFunctorClass
{
public:
	myFunctorClass(int x) : _x(x) {}
	int operator() (int y) { return _x + y; }
private:
	int _x;
};

int main()
{
	// add 5 with 6 using myFunctorClass
	myFunctorClass out(5);
    std::cout << out(6) << std::endl;
	return 0;
}

```

### 5-7
decltype keyword

Was ist die Ausgabe des folgenden Codes & warum?

```cpp
#include <iostream>
using namespace std;

int fun1() { return 10; }
char fun2() { return 'g'; }

int main()
{
    // Data type of x is same as return type of fun1()
    // and type of y is same as return type of fun2()
    decltype(fun1()) x;
    decltype(fun2()) y;

    cout << typeid(x).name() << endl;
    cout << typeid(y).name() << endl;

    return 0;
}

/* ----- OUTPUT -----  */
// i (integer)
// c (char)
//  Data type is same as return type
```

### 5-8
declval Keyword

```cpp
#include <utility>      // std::declval
#include <iostream>     // std::cout
using namespace std;

class A {              // abstract class
public:
	virtual int value() = 0;
};

class B : public A {    // class with specific constructor
	int val_;
public:
	B(int i, int j) :val_(i* j) {}
	int value() { return val_; }
};

int main() {
    decltype(declval<A>().value()) a;
    decltype(declval<B>().value()) b;
    decltype(B(0,0).value()) c;
	//code here, please write 3 lines of code for the following purposes:
	// a is an int object that invokes the value function from class A   
	// b is an int object that invokes the value function from class B
	// c uses the constructor of class B and has the initial values i=0 & j=0 
	a = b = B(10, 2).value();
	cout << a << '\n';
	cout << c << '\n';
	return 0;
}

```

### 5-9
Exception Handling
Das Programm unten ergänzen, um die folgende Ausgabe zu erhalten:

Before try
Inside try
Exception Caught
After catch (Will be executed)

```cpp
#include <iostream> 
using namespace std;   
int main() 
{ 
   cout << "Before try\n"; 
   try
   {
        cout << "Inside try\n";
        unsigned int x = -1;  
        throw out_of_range("int not negative");
   }
   catch(const exception &e)
   {
       cout << "exception caught" << endl;
       std::cerr << e.what() << '\n';
   }
   
    cout << "After exception" << endl;
return 0; 
}

```

### 5-10
Exception Handling
Was ist die Ausgabe des folgenden Programmes?

```cpp
#include <iostream> 
using namespace std;   
int main() { 
    try  { 
       throw 10; 
      //throw ‘a’;
    } 
    catch (int x)  { 
        cout << "Caught " << x; 
    } 
    catch (...)  { 
        cout << "Default Exception\n"; 
    } 
    return 0; 
}

/* ----- OUTPUT ----- */
// 10
```

### 5-11
Exception Handling: Nested try-catch-blocks
Ergänzen des Codes (unten) um die folgende Ausgabe zu erhalten:

Handle partially
Handle remaining

```cpp

#include <iostream> 
using namespace std;   
int main() 
{ 
    try { 
        try  { 
            throw 20; 
        } catch(...) {
            cout << "handle partially" << endl;
            throw 10;
        }
    } catch(...) {
            cout << "handle remainig" << endl;
    }
    return 0; 
}

```

### 5-12
Exception Handling
Ergänzen des Codes (unten) um die folgende Ausgabe zu erhalten:

Constructer of Test
Destructor of Test
Caught 10

```cpp
// Constructer of Test
// Destructor of Test
// Caught 10

#include <iostream> 
using namespace std;   
class Test { 
public: 
   Test() { cout << "Constructor of Test " << endl; } 
  ~Test() { cout << "Destructor of Test "  << endl; } 
}; 

int main() { 
//code here  
    try
    {
        Test a;
        throw 10;
    }
    catch(int e)
    {
        std::cerr << "Caught " << e << '\n';
    }
    
}

```

## PVA 6

### 6-1
Test

```cpp

```

### 6-2
Test

```cpp

```

### 6-3
Test

```cpp

```

### 6-4
Test

```cpp

```

### 6-5
Test

```cpp

```

### 6-6
Test

```cpp

```

### 6-7
Test

```cpp

```

### 6-8
Test

```cpp

```

### 6-9
Test

```cpp

```

### 6-10
Test

```cpp

```

### 6-11
Test

```cpp

```

### 6-12
Test

```cpp

```

## PVA 7

### 7-1
Test

```cpp

```

### 7-2
Test

```cpp

```

### 7-3
Test

```cpp

```

### 7-4
Test

```cpp

```

### 7-5
Test

```cpp

```

### 7-6
Test

```cpp

```

### 7-7
Test

```cpp

```

### 7-8
Test

```cpp

```

### 7-9
Test

```cpp

```

### 7-10
Test

```cpp

```

### 7-11
Test

```cpp

```

### 7-12
Test

```cpp

```

## PVA 8

### 8-1
Test

```cpp

```

### 8-2
Test

```cpp

```

### 8-3
Test

```cpp

```

### 8-4
Test

```cpp

```

### 8-5
Test

```cpp

```

### 8-6
Test

```cpp

```

### 8-7
Test

```cpp

```

### 8-8
Test

```cpp

```

### 8-9
Test

```cpp

```

### 8-10
Test

```cpp

```

### 8-11
Test

```cpp

```

### 8-12
Test

```cpp

```

## PVA 9

### 9-1
Test

```cpp

```

### 9-2
Test

```cpp

```

### 9-3
Test

```cpp

```

### 9-4
Test

```cpp

```

### 9-5
Test

```cpp

```

### 9-6
Test

```cpp

```

### 9-7
Test

```cpp

```

### 9-8
Test

```cpp

```

### 9-9
Test

```cpp

```

### 9-10
Test

```cpp

```

### 9-11
Test

```cpp

```

### 9-12
Test

```cpp

```