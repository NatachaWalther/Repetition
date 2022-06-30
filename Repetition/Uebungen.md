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
Wie kann man das untenstehende Programm ergänzen, um die folgende Ausgabe zu erhalten?
Child class disp() function
Parent class disp() function

```cpp
#include <iostream>
using namespace std;
class A {
public:
	void disp() {
		cout << "Parent class disp() function"<<endl;
	}
};
class B : public A {
public:
	void disp() {
		// Baseclass::disp();
		cout << "Child class disp() function"<<endl;
	}
};

int main() {
	
	//Creating object of child class B	
	B obj;
	obj.disp();
	A obj1;
	obj1.disp();
	//code here 	
	
	return 9;
}

```

### 6-2
Function Overloading
Implementieren Sie die Summe-Funktionen

```cpp
#include <iostream>
using namespace std;
// overloaded functions
float sum(int x, int y){
    return x+y;
}
float sum(float x, float y){
    return x+y;
}
float sum(int x, float y){
    return x+y;
}
float sum(float x, int y){
    return x+y;
}
int main() {
	//This will call the second function
	cout << sum(15.7f, 12.7f) << endl;

	//This will call the first function
	cout << sum(200, 100) << endl;

	//This will call the third function
	cout << sum(100, 20.7f) << endl;

	//This will call the fourth function
	cout << sum(90.8f, 30) << endl;
	
	return 0;
}

```

### 6-3
Definieren Sie zwei Wirkfunktionen "printtype" jeweils für ein Argument vom Datentyp "int" und vom Datentyp "double". Jede Wirkfunktion soll den Namen des Datentyps ihres Parameters ausgeben.
double
int

```cpp
#include <iostream> 
#include <string>
using namespace std;

// ... Hier Wirkfunktionen definieren
void printtype(int a){
    cout << decltype(a);
}
void printtype(double a){
    cout << decltype(a).name;
}

int main ( )
{ 
   printtype( 3.1415926 ); 
   cout << endl; 
   printtype(0); 
   cout << endl; 
}

```

### 6-4
transform() in STL
Lassen Sie die folgenden zwei Programme laufen um die Funktionsweise von der Funktion transform() zu verstehen:

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
int square(int x) {
   //define square function
   return x*x;
}
int main() {
   int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   int res[10];
   transform(arr, arr+10, res, square);
   for(int i = 0; i<10; i++) {
      cout << res[i] << "\n";   }
}

```

### 6-5
Function Objects (Functors)   / “Function Operators ()” 

Das untenstehende Programm benutzt transform() in STL um die Elemente des Arrays um eine Zahl zu erhöhen:

Ausgabe: 2 3 4 5 6

```cpp
#include <iostream>
#include<algorithm>
using namespace std;

//Functor 
class increment
{
private:
	int num;
public:
	increment(int n) : num(n) {  }

	// This operator overloading enables calling 
	// operator function () on objects of increment 
	// code here
    int operator() (int n){
        return num+n;
    }
};

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int to_add = 5;

	transform(arr, arr + n, arr, increment(to_add));

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	system("pause");
	return 0;

}

```

### 6-6
for_each()-Funktion in STL
Ändern Sie im untenstehenden Code, den struct auf die Class um. Lassen Sie das Programm danach laufen, um die Funktionsweise von for_each Funktion in STL zu verstehen.

```cpp
#include <iostream>     // std::cout
#include <algorithm>    // std::for_each
#include <vector>       // std::vector

void myfunction(int i) {  // function:
	std::cout << ' ' << i;
}

struct myclass {           // function object type:
	void operator() (int i) { std::cout << ' ' << i; }
} myobject;

int main() {
	std::vector<int> myvector;
	myvector.push_back(10);
	myvector.push_back(20);
	myvector.push_back(30);

	std::cout << "myvector contains:";
	for_each(myvector.begin(), myvector.end(), myfunction);
	std::cout << '\n';

	// or:
	std::cout << "myvector contains:";
	for_each(myvector.begin(), myvector.end(), myobject);
	std::cout << '\n';

	return 0;
}

```

### 6-7
Schreiben Sie a) einen Funktor b) einen Lambda Ausdruck um die Funktion printnumber zu ersetzen:

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 
// Function printnumber can be replaced by a functor or a lambda expression
// void printnumber(int y) {
//     cout << y << endl;
// } 
class printnumber{
public:
    void operator() (int n){cout << n << endl;}
} printnumber;

int main(){
    // auto printnumber = [](int y){cout << y << endl;};
    vector<int> numbers {1, 2, 3, 4, 5, 10, 15, 20, 25, 35, 45, 50};
    for_each(numbers.begin(), numbers.end(), printnumber);
}

```

### 6-8
Lambda Funktion
schreiben Sie einen Lambda - Ausdruck, um die benutzerdefinierte Prädikat Funktion is_greater_than_5 zu ersetzen:

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 
//user defined predicate function
bool is_greater_than_5(int value){
    return (value > 5);
} 
int main(){
    auto is_greater_than_5 = [](int value){return (value > 5);};
    vector<int> numbers { 1, 2, 3, 4, 5, 10, 15, 20, 25, 35, 45, 50 };
    auto greater_than_5_count = count_if(numbers.begin(), numbers.end(), is_greater_than_5); 

//code hier für die Lambda Funktion is_greater_than_5

    cout << "The number of elements greater than 5 is: "
        << greater_than_5_count << "." << endl;
}

```

### 6-9
unique_ptr

Lassen Sie den folgenden Code laufen und betrachten Sie die folgenden Mechanismen: 

1.	unique-ptr erstellen, ersetzen Sie den code mit make_unique Funktion 
2.	überprüfen, ob unique_ptr «leer» ist
3.	reseten der unique_ptr
4.	«Eigentumsrechte» von unique_ptr transferieren
5.	Unique_ptr ist ausserhalb des Geltungsbereiches (Scope) und wird automatisch vernichtet (braucht keinen delete wie der «raw» pointer)
6.	release vom Eigentum des raw-pointers
7.	delete raw pointer

```cpp
#include <memory>  //contains unique_ptr
#include <iostream>
using namespace std;

struct Task
{
	int mId;
	Task(int id) :mId(id)
	{
		cout << "Task::Constructor" << endl;
	}
	~Task()
	{
		cout << "Task::Destructor" << endl;
	}
};

int main()
{
	// Empty unique_ptr object
	unique_ptr<int> ptr1;

	// Check if unique pointer object is empty
	if (!ptr1)  
		cout << "ptr1 is empty" << endl;

	// Check if unique pointer object is empty
	if (ptr1 == nullptr) //if (!ptr)
		cout << "ptr1 is empty" << endl;

	// can not create unique_ptr object by initializing through assignment
	// unique_ptr<Task> taskPtr2 = new Task(); // Compile Error

	// 1: Create a unique_ptr object through raw pointer
	// unique_ptr<Task> taskPtr(new Task(23);
	auto taskPtr = make_unique<Task>(23);

	// 2. Check if taskPtr is empty or it has an associated raw pointer
	if (taskPtr != nullptr) //if(taskPtr)
		cout << "taskPtr is not empty" << endl;

	//Access the element through unique_ptr
	cout << taskPtr->mId << endl;

	cout << "Reset the taskPtr" << endl;
	// 3. Reseting the unique_ptr will delete the associated
	// raw pointer and make unique_ptr object empty
	taskPtr.reset();

	// Check if taskPtr is empty or it has an associated raw pointer
	if (taskPtr == nullptr) //if (!taskPtr)
		cout << "taskPtr is empty" << endl;


	// Create a unique_ptr object through raw pointer
	unique_ptr<Task> taskPtr2(new Task(55));

	if (taskPtr2 != nullptr) //if(taskPtr2)
		cout << "taskPtr2 is  not empty" << endl;

	// unique_ptr object is Not copyable
	//taskPtr = taskPtr2; //compile error

	// unique_ptr object is Not copyable
	//unique_ptr<Task> taskPtr3 = taskPtr2;

	{
		// Transfer the ownership

		unique_ptr<Task> taskPtr4 = move(taskPtr2);


		if (taskPtr2 == nullptr)
			cout << "taskPtr2 is  empty" << endl;

		// 4. ownership of taskPtr2 is transfered to taskPtr4
		if (taskPtr4 != nullptr)
			cout << "taskPtr4 is not empty" << endl;

		cout << taskPtr4->mId << endl;

		//5. taskPtr4 goes out of scope and deletes the assocaited raw pointer
	}

	// Create a unique_ptr object through raw pointer
	unique_ptr<Task> taskPtr5(new Task(55));

	if (taskPtr5 != nullptr)
		cout << "taskPtr5 is not empty" << std::endl;

	// 6. Release the ownership of object from raw pointer
	Task * ptr = taskPtr5.release();

	if (taskPtr5 == nullptr)
		cout << "taskPtr5 is empty" << endl;

	cout << ptr->mId << endl;

       //7. after release ownership of raw pointer, delete of raw pointer is needed 
	delete ptr;
	

	return 0;
}

```

### 6-10
shared_pointer

Lassen Sie den folgenden Code laufen und betrachten Sie die folgenden Mechanismen: 

1.	shared-ptr erstellen, benutzen Sie make_shared Funktion
2.	reference Zahl angeben mit use_count()
3.	Kopieren des shared_ptr
4.	reference Zahl angeben mit use_count()
5.	shared_ptr vergleichen
6.	reseten des shared_ptr
7.	de-attach des shared_ptr

```cpp
#include  <memory> // We need to include this for shared_ptr
#include <iostream>
using namespace std;

int main()
{
	// 1. Creating a shared_ptr through make_shared
	auto p1 = make_shared<int>(78);
// shared_ptr<int> p1(new int);
// 	*p1 = 78;
	cout << "p1 = " << *p1 << endl;  //p1=78

	// 2. Shows the reference count
cout << "p1 Reference count = " << p1.use_count() << endl; //p1 reference count=1

	// 3. Second shared_ptr object will also point to same pointer internally
	// It will make the reference count to 2.
	shared_ptr<int> p2(p1);

	// 4. Shows the reference count
cout << "p2 Reference count = " << p2.use_count() << endl; //p2 reference count=2
cout << "p1 Reference count = " << p1.use_count() << endl; //p1 reference count=1 

	// 5. Comparing smart pointers
	if (p1 == p2)
	{
		cout << "p1 and p2 are pointing to same pointer\n";
	}

	cout << "Reset p1 " << endl;

	p1.reset();

// 6. Reset the shared_ptr, in this case it will not point to any Pointer internally, hence its reference count will become 0.

	cout << "p1 Reference Count = " << p1.use_count() << endl;

	// Reset the shared_ptr, in this case it will point to a new Pointer internally
	// hence its reference count will become 1.

	p1.reset(new int(11));

	cout << "p1  Reference Count = " << p1.use_count() << endl;

// 7. Assigning nullptr will de-attach the associated pointer and make it to //point null
	p1 = nullptr;

	cout << "p1  Reference Count = " << p1.use_count() << endl;

	if (!p1) //if (ptr == NULL)
	{
		cout << "p1 is NULL" << endl;
	}
	
	return 99;
}

```

## PVA 7

### 7-5a
Friend Funktion
Vervollständigen Sie den folgenden Code:

```cpp
#include <iostream>

using namespace std;
class Box {
   double width;   
   public:
      double length;
      friend void printWidth( Box box );
      void setWidth( double wid );
};

// Note: printWidth() is not a member function of any class.
void printWidth( Box box ) {
   /* Because printWidth() is a friend of Box, it can
   directly access any member of this class */
   cout << "Width of box : " << box.width <<endl;
}

void Box::setWidth(double wid){
    width=wid;
}

// Main function for the program
int main() {
   Box box; 
   // code here: set box width without member function
   box.setWidth(10);
   // code here: Use friend function to print the width.
   printWidth(box);
   
   return 0;
}

```

### 7-5b
overloading istream & ostream using friend function
Analysieren Sie den folgenden Code:

```cpp
#include <iostream>
using namespace std;

class Complex
{
private:
	int real, imag;
public:
	Complex(int r = 0, int i = 0)
	{
		real = r;   imag = i;
	}
	friend ostream & operator << (ostream &out, const Complex &c);
	friend istream & operator >> (istream &in, Complex &c);
};

ostream & operator << (ostream &out, const Complex &c)
{
	out << c.real;
	out << "+i" << c.imag << endl;
	return out;
}

istream & operator >> (istream &in, Complex &c)
{
	cout << "Enter Real Part ";
	in >> c.real;
	cout << "Enter Imagenory Part ";
	in >> c.imag;
	return in;
}

int main()
{
	Complex c1;
	cin >> c1;
	cout << "The complex object is ";
	cout << c1;
	system("pause");
	return 0;
}

```

### 7-6
unique_ptr: get vs. release
Analysieren Sie das folgende Programm und ergänzen Sie den code, wie unten verlangt

```cpp
#include <fstream> 
#include <iostream>   
using namespace std; 
int main (int argc, char** argv) { 
    // Open a new file for input/output operations,  
    // discarding any current in the file (assumes a length of zero on opening) 
    fstream myFile("test.txt", ios::in | ios::out | ios::trunc); 
    // Add the characters "Hello World" to the file 
    if (!myFile.is_open()){
        return -1;
    }
    
    //code here
    myFile << "Hello World";
    // Seek to 6 characters from the beginning of the file 
    myFile.seekp(6, ios::beg);
   // Read the next 5 characters from the file into a buffer 
   char A[6];
   myFile.read(A, 5);
    
   // End the buffer with a null terminating character 
    A[5] = 0; 
  // Output the contents read from the file and close it  
    cout << A << endl;   //correct the code error here!
    myFile.close(); 
}

```

### 7-7
unique Pointer

Ersetzen Sie, wenn nötig, im folgenden Code den “Raw-Pointer” mit dem unique_ptr :

```cpp
#include <iostream>
#include <memory>
using namespace std;

class Fraction
{
private:
	int m_numerator{ 0 };
	int m_denominator{ 1 };

public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator{ numerator }, m_denominator{ denominator }
	{
	}

	friend ostream& operator<<(ostream& out, const Fraction &f1)
	{
		out << f1.m_numerator << "/" << f1.m_denominator;
		return out;
	}
};

void printFraction(const Fraction* const ptr)
{
	if (ptr)
		std::cout << *ptr << '\n';
}

int main()
{
    auto ptr = std::make_unique<Fraction>(3,5);
	// Fraction *ptr{ new Fraction{ 3, 5 } };

	printFraction(ptr.get());

	return 0;
}

```

### 7-8
unique_ptr
Ergänzen Sie den folgenden Code, um die untenstehende Ausgabe zu erhalten:

```cpp
#include <iostream>
#include <memory> // for std::shared_ptr
using namespace std;

class Resource
{
public:
	Resource() { cout << "Resource acquired\n"; }
	~Resource() { cout << "Resource destroyed\n"; }
};

int main()
{
	// allocate a Resource object and have it owned by std::shared_ptr
	Resource *res = new Resource;
	shared_ptr<Resource> ptr1 = make_shared<Resource>();
    {
        shared_ptr<Resource> ptr2(res); // use copy initialization to make  another std::shared_ptr pointing to the same thing

        cout << "Killing one shared pointer\n";
        // ptr2 goes out of scope here, but nothing happens
    }
	cout << "Killing another shared pointer\n";

	return 0;
} // ptr1 goes out of scope here, and the allocated Resource is destroyed

```

### 7-9
Shared Pointer
Was ist die Ausgabe des folgenden Programmes? Analysieren Sie das Programm:

```cpp
#include <iostream>
#include <memory> // for std::shared_ptr
#include <string>
using namespace std;

class Person
{
	string m_name;
	std::weak_ptr<Person> m_partner; // initially created empty

public:

	Person(const string &name) : m_name(name)
	{
		cout << m_name << " created\n";
	}
	~Person()
	{
		cout << m_name << " destroyed\n";
	}

	friend bool partnerUp(std::shared_ptr<Person> &p1, shared_ptr<Person> &p2)
	{
		if (!p1 || !p2)
			return false;

		p1->m_partner = p2;
		p2->m_partner = p1;

		cout << p1->m_name << " is now partnered with " << p2->m_name << "\n";

		return true;
	}
};

int main()
{
	auto lucy = make_shared<Person>("Lucy"); // create a Person named "Lucy"
	auto ricky = make_shared<Person>("Ricky"); // create a Person named "Ricky"

	partnerUp(lucy, ricky); // Make "Lucy" point to "Ricky" and vice-versa

	return 0;
}

```

## PVA 8

### 8-2
write the code to generate the following 2-dimensiona array and display the array on the screen

| 1 | 2  | 3  | 4  |
|---|----|----|----|
| 5 | 6  | 7  | 8  |
| 9 | 10 | 11 | 12 |

```cpp
#include <iostream>

using namespace std;

const int ROWS = 3;
const int COLUMNS = 4;

int main(int argc, char const *argv[])
{
    int a[ROWS][COLUMNS];
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            a[i][j] = (i * 4) + j + 1;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

```

### 8-2
Arrays
Write a program that accepts lines of text entered at the keyboard and redisplays them after a blank line is entered.

```cpp
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

string first_string[4];

int main(int argc, char const *argv[])
{
    int i = 0;
    while (cin && i < 4)
    {
        getline(cin, first_string[i]);
        cout << first_string[i] << endl;
        i++;
    };
    return 0;
}

```

### 8-4
vector als sequentieller Container 
Vervollständigen Sie den Code, um die untenstehende Ausgabe zu erhalten:

Ausgabe: 

Size : 5
Capacity : 8   (Achtung: dieser Wert kann variieren, ist auf jeden Fall grösser als 5) 
Max_Size : 4611686018427387903   (Achtung: dieser Wert kann auch variieren)
Size : 4
Vector is not empty
Vector elements are: 1 2 3 4


```cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> g1;

    for (int i = 1; i <= 5; i++)
        g1.push_back(i);

    cout << "Size : " << g1.size();           // code here
    cout << "\nCapacity : " << g1.capacity(); // code here
    cout << "\nMax_Size : " << g1.max_size(); // code here

    // resizes the vector size to 4
    g1.resize(4);

    // prints the vector size after resize()
    cout << "\nSize : " << g1.size(); // code here

    // checks if the vector is empty or not
    // code here
    if (!g1.empty())
        cout << "\nVector is not empty";
    else
        cout << "\nVector is empty";

    // Shrinks the vector
    // code here
    g1.shrink_to_fit();
    cout << "\nVector elements are: ";
    for (auto it = g1.begin(); it != g1.end(); it++)
        cout << *it << " ";

    return 0;
}

```

### 8-6
deque als sequentieller Container 
Vervollständigen Sie den Code um die untenstehende Ausgabe zu erhalten:

Ausgabe:

The deque dequEx is :     15    20    10    30
dequEx.size() : 4
dequEx.max_size() : 4611686018427387903 (Achtung: diese Grösse kann variieren)
dequEx.at(2) : 10
dequEx.front() : 15
dequEx.back() : 30
dequEx.pop_front() :     20    10    30
dequEx.pop_back() :     20    10

```cpp
#include <iostream>
#include <deque>

using namespace std;

void print_dequ(deque<int> g)
{
    deque<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

int main()
{
    deque<int> dequEx;
    dequEx.push_back(10);
    dequEx.push_front(20);
    dequEx.push_back(30);
    dequEx.push_front(15);
    cout << "The deque dequEx is : ";
    print_dequ(dequEx);

    cout << "\ndequEx.size() : " << dequEx.size();         // code here
    cout << "\ndequEx.max_size() : " << dequEx.max_size(); // code here

    cout << "\ndequEx.at(2) : " << dequEx.at(2);     // code here
    cout << "\ndequEx.front() : " << dequEx.front(); // code here
    cout << "\ndequEx.back() : " << dequEx.back();   // code here

    cout << "\ndequEx.pop_front() : ";
    // code here
    dequEx.pop_front();
    print_dequ(dequEx);

    cout << "\ndequEx.pop_back() : ";
    // code here
    dequEx.pop_back();
    print_dequ(dequEx);

    return 0;
}

```

### 8-7
pair als utility Container 
Vervollständigen Sie den Code um die untenstehende Ausgabe zu erhalten:


Ausgabe:

The price of lightbulbs is $0.99
The price of shoes is $39.9
The price of tomatoes is $2.3

```cpp
#include <utility>  // std::pair, std::make_pair
#include <string>   // std::string
#include <iostream> // std::cout

void printPair(std::pair<std::string, double> p)
{
    std::cout << "The price of " << p.first << " is " << p.second << std::endl;
}

int main()
{
    std::pair<std::string, double> product1;                   // default constructor
    std::pair<std::string, double> product2("tomatoes", 2.30); // init constructor
    std::pair<std::string, double> product3(product2);         // copy constructor

    product1 = std::make_pair(std::string("lightbulbs"), 0.99);
    // using make_pair (move)

    product2.first = "shoes"; // the type of first is string
    product2.second = 39.90;  // the type of second is double

    // code here
    printPair(product1);
    printPair(product2);
    printPair(product3);

    return 0;
}

```

### 8-8
set als assoziativer Container:
a)	Vervollständigen Sie den Code um die untenstehende Ausgabe zu erhalten
b)	Was müsste man im header des programmes hinzufügen um diesen Hinweis nicht zu erhalten? : 	«no operator "<<" matches these operands	

Ausgabe:

 A 1
 B 2
 C 3
 D 4
 E 5

```cpp
#include <set>
#include <utility>
#include <iostream>
using namespace std;

void printPair(string first, int second)
{
    cout << first << " " << second << endl;
}

int main()
{

    set<pair<string, int>> mySet;
    // insert values
    mySet.insert(make_pair<string, int>("A", 1));
    mySet.insert(make_pair<string, int>("B", 2));
    mySet.insert(make_pair<string, int>("C", 3));
    mySet.insert(make_pair<string, int>("D", 4));
    mySet.insert(make_pair<string, int>("E", 5));

    for (auto it = mySet.begin(); it != mySet.end(); ++it)
    {
        // x is the first, y is the second element
        // code here
        printPair(it->first, it->second);
    }
    // alternative way to iterate set
    /*
    for (auto const &p : mySet) {
        //code here
    }*/

    return 0;
}

```

### 8-9
multiset als assoziativer Container:
Vervollständigen Sie den Code um die untenstehende Ausgabe zu erhalten

```cpp
#include <iostream>
#include <set>
using namespace std;
int main()
{
    multiset<int, less<int>> ms;
    ms.insert(10);                                // insert 10
    ms.insert(35);                                // insert 35
    ms.insert(10);                                // insert 10 again (allowed)
    cout << "There are " << ms.count(10) << endl; // returns the number of entries of 10
    multiset<int, less<int>>::iterator it;        // creates an iterator
    it = ms.find(10);
    // code here
    if (it != ms.end())
    {
        cout << "10 was found" << endl;
    }

    return 0;
}

```

### 8-10
multiset

Vervollständigen Sie den folgenden Code:

```cpp
#include <iostream>
#include <set>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    multiset<int> ms;
    multiset<int>::iterator it, it1, msIt; // define iterator
    int choice, item;

    while (1)
    {
        cout << "\n---------------------" << endl;
        cout << "Multiset Example" << endl;
        cout << "\n---------------------" << endl;
        cout << "1.Insert Number into the Multiset" << endl;
        cout << "2.Delete Element from the Multiset" << endl;
        cout << "3.Find Element in a Multiset" << endl;
        cout << "4.Count Elements with a specific key" << endl;
        cout << "5.Size of the Multiset" << endl;
        cout << "6.Display Multiset" << endl;
        cout << "7.First Element of the Multiset" << endl;
        cout << "8.Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to be inserted: ";
            cin >> item;
            ms.insert(item);
            break;
        case 2:
            cout << "Enter value to be deleted: ";
            ms.erase(item);
            break;
        case 3:
            cout << "Enter element to find ";
            cin >> item;
            ms.find(item);
            if (it != ms.end())
            {
                cout << item << " was found" << endl;
            }
            break;
        case 4:
            cout << "Enter element to be counted: ";
            cin >> item;
            cout << "Number of elements are: " << ms.count(item) << endl;
            break;
        case 5:
            cout << "Size of the Multiset: " << ms.size() << endl;
            break;
        case 6:
            cout << "Elements of the Multiset:  ";
            for (auto &&i : ms)
            {
                cout << i << " ";
            }
            cout << endl;
            break;
        case 7:
            if (ms.empty())
            {
                cout << "Multiset is empty";
            }
            else
            {
                msIt = ms.begin();
                cout << "The First Element of the Multiset is " << *msIt << endl;
            }
            break;
        case 8:
            exit(1);
            break;
        default:
            cout << "Wrong Choice" << endl;
        }
    }

    return 0;
}

```

### 8-11
map als assoziativer Container:
Vervollständigen Sie den Code um die untenstehende Ausgabe zu erhalten

Ausgabe:

KEY    ELEMENT
1   	 40
2    	30
3    	60

```cpp
#include <map>
#include <iostream>
using namespace std;

int main()
{

    // initialize container
    map<int, int> mp;

    // insert elements in random order
    // code here
    mp.insert({2, 30});
    mp.insert({1, 40});

    auto it = mp.find(2);

    // inserts {3, 60} starting the search from
    // position where 2 is present
    mp.insert(it, {3, 60});

    // prints the elements
    cout << "KEY\tELEMENT\n";
    // code here
    for (auto &&i : mp)
    {
        cout << i.first << "\t" << i.second << endl;
    }

    return 0;
}

```

## PVA 9

### 9-1
unordered_map als assoziativer Container:
Vervollständigen Sie den Code um die untenstehende Ausgabe zu erhalten


Ausgabe: 
Found PI
lambda not found
All Elements : 
loge 		 1
e  		2.718
log10 	 	2.302
root3  		1.732
PI  		3.14
root2  		1.414

```cpp
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main()
{ // Declaring unordMap to be of <string, double> type
    // key will be of string type and mapped value will be of double type
    unordered_map<string, double> unordMap;
    // inserting values by using [] operator
    unordMap["loge"] = 1;
    unordMap["e"] = 2.718;
    unordMap["log10"] = 2.302;
    unordMap["root3"] = 1.732;
    unordMap["PI"] = 3.14;
    unordMap["root2"] = 1.414;
    // code here
    string key = "PI";
    // If key not found in map iterator to end is returned
    if (unordMap.find(key) == unordMap.end())
        std::cout << key << " not found\n\n";
    // If key found then iterator to that key is returned
    else
        std::cout << "Found " << key << "\n\n";
    key = "lambda";
    if (unordMap.find(key) == unordMap.end())
        std::cout << key << " not found\n";
    else
        std::cout << "Found " << key << endl;
    //    iterating over all value of unordMap
    unordered_map<string, double>::iterator itr;
    std::cout << "\nAll Elements : \n";
    for (itr = unordMap.begin(); itr != unordMap.end(); itr++)
    {
        // code here
        std::cout << itr->first << " " << itr->second << std::endl;
    }
}

```

### 9-2
queue als Container Adapter:
Vervollständigen Sie den Code um die untenstehende Ausgabe zu erhalten

Ausgabe:
The queue myQueue is :     10    20    30
myQueue.size() : 3
myQueue.front() : 10
myQueue.back() : 30
myQueue.pop() :     20    30

```cpp
#include <iostream>
#include <queue>
using namespace std;
void printQueue(queue<int> myQ)
{
    queue<int> g = myQ;
    while (!g.empty())
    {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}
int main()
{
    queue<int> myQueue;

    myQueue.push(30);
    myQueue.push(20);
    myQueue.push(10);

    cout << "The queue myQueue is : ";
    printQueue(myQueue);

    cout << myQueue.size() << endl;
    cout << myQueue.front() << endl;
    cout << myQueue.back() << endl;
    cout << "\nmyQueue.pop() : ";
    myQueue.pop();
    printQueue(myQueue);
    return 0;
}

```

### 9-3
priority-queue als Container Adapter
Vervollständigen Sie den Code um die untenstehende Ausgabe zu erhalten

Ausgabe:
The priority queue myPrQueue is :       30      20      10      5       1
myPrQueue.size() : 5
myPrQueue.top() : 30
myPrQueue.pop() :       20      10      5       1

```cpp
#include <iostream>
#include <queue>
using namespace std;
void printPrQueue(priority_queue<int> gq)
{
    priority_queue<int> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';
}
int main()
{
    priority_queue<int> myPrQueue;
    // code here
    // highest value will always be first
    myPrQueue.push(1);
    myPrQueue.push(5);
    myPrQueue.push(30);
    myPrQueue.push(10);
    myPrQueue.push(20);
    cout << "The priority queue myPrQueue is : ";
    printPrQueue(myPrQueue);
    // code here

    cout << myPrQueue.size() << endl;
    cout << myPrQueue.top() << endl;
    myPrQueue.pop();
    printPrQueue(myPrQueue);
    system("pause");
    return 0;
}

```

### 9-4
Iterator
Ergänzen Sie das folgende Programm:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3}; // Declaring a vector
    vector<int>::iterator i;   // Declaring an iterator
    int j;
    for (i = v.begin(); i != v.end(); ++i)
    {
        // Inserting element using iterators
        if (i == v.begin())
        {
            i = v.insert(i, 5); // inserting 5 at the beginning of v
        }
    }
    for (i = v.begin(); i != v.end(); ++i)
    {
        if (i == v.begin() + 1)
        { // Deleting a element using iterators
            i = v.erase(i);
            // i now points to the element after the   deleted element
        }
    }
    // Accessing the elements using iterators
    // code here$

    for (auto &&i : v)
    {
        cout << i << endl;
    }

    // same as above
    for (const auto &i : v)
    {
        cout << i << endl;
    }

    return 0;
}

```

### 9-5
Iterator 
Ergänzen das untenstehende Programm, um die folgende Ausgabe zu erhalten:

Ausgabe:

Elements: 1 2 3 4 5
Squares:  1 4 9 16 25

```cpp
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
using namespace std;

template <typename ForwardIterator>

void square(ForwardIterator first, ForwardIterator last)
{
    cout << "Squares:  ";
    for (; first != last; first++)
    {
        *first = (*first) * (*first);
        cout << *first << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    // code here
    // use begin() , end() to display the output
    cout << "Elements: ";
    for (auto itr = v.begin(); itr != v.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;
    square(v.begin(), v.end());
}

```

### 9-6
Reverse Algorithm
Ergänzen Sie das folgende Programm:

```cpp
// reverse algorithm example
#include <iostream>  // std::cout
#include <algorithm> // std::reverse
#include <vector>    // std::vector

void printVector(std::vector<int> &v)
{
    for (auto &&i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> myvector;
    // set some values:
    for (int i = 1; i < 10; ++i)
        myvector.push_back(i); // 1 2 3 4 5 6 7 8 9

    printVector(myvector);

    std::reverse(myvector.begin(), myvector.end()); // 9 8 7 6 5 4 3 2 1
    // print out content:
    // code here
    printVector(myvector);

    return 0;
}

```

### 9-7
Copy Algorithm 
Ergänzen Sie das folgende Programm: 

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(std::vector<int> &v)
{
    for (auto &&i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main(void)
{
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2(5);
    copy(v1.begin(), v1.end(), v2.begin());
    // display vector 2
    // code here
    printVector(v2);

    return 0;
}

```

### 9-8
Aufgabe 1: Ergänzen Sie das untenstehende Programm, um folgende Antworten zu erhalten:
4 2 10 5 1 8 
1 2 4 5 8 10

```cpp
// 4 2 10 5 1 8
// 1 2 4 5 8 10

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void printVector(std::vector<int> &v)
{
    for (auto &&i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    vector<int> v = {4, 2, 10, 5, 1, 8};
    // code ergänzen

    printVector(v);
    sort(v.begin(), v.end());
    printVector(v);

    return 0;
}

```

### 9-9
Eränzen Sie das untenstehende Programm, um folgende Antworten zu erhalten:
1 9 3 7 5
6 4 8 2 10

```cpp
// 1 9 3 7 5
// 6 4 8 2 10

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool IsOdd(int i)
{
    return (i % 2) == 1;
}

int main()
{
    vector<int> v;

    for (int i = 1; i <= 10; ++i)
        v.push_back(i);

    vector<int>::iterator bound;
    // Variante 1
    for (auto &&i : v)
    {
        if (IsOdd(i))
        {
            cout << i << " ";
        }
    }

    cout << endl;

    for (auto &&i : v)
    {
        if (!IsOdd(i))
        {
            cout << i << " ";
        }
    }

    cout << endl;
    // Variante 2
    bound = partition(v.begin(), v.end(), IsOdd);

    // code ergänzen
    for (auto it = v.begin(); it != bound; ++it)
        std::cout << *it << " ";
    std::cout << endl;

    for (auto it = bound; it != v.end(); ++it)
        std::cout << *it << " ";
    std::cout << endl;

    return 0;
}

```

### 9-10
Ergänzen Sie den folgenden Code  
a) mit einer Lambda-Funktion lamFunc  und 
b) mit einem Functor, um die folgende Ausgabe zu erhalten:


myvector contains: 10 20 30
myvector contains: 10 20 30

```cpp
// a) mit einer Lambda-Funktion lamFunc  und
// b) mit einem Functor, um die folgende Ausgabe zu erhalten:

// myvector contains: 10 20 30
// myvector contains: 10 20 30

#include <iostream>  // cout
#include <algorithm> // for_each
#include <vector>    // vector
using namespace std;

// a: Lambda Function : code ergänzen

// b : Functor: code ergänzen

void lamFunct(int i)
{
    std::cout << i << " ";
}

struct myclass
{ // function object type:
    void operator()(int i) { std::cout << i << " "; }
} funcObj;

int main()
{
    std::vector<int> myvector;
    myvector.push_back(10);
    myvector.push_back(20);
    myvector.push_back(30);

    std::cout << "my vector contains: " << endl;
    for_each(myvector.begin(), myvector.end(), lamFunct); // lambda Funktion
    std::cout << "\n";

    // or:
    std::cout << "my vector contains: " << endl;
    for_each(myvector.begin(), myvector.end(), funcObj); // Funktor
    std::cout << "\n";

    return 0;
}

// -- -- -- -- --Ergänzung zum Function template for_each :

// std::for_each

// template <class InputIterator, class Function>

//     Function
//     for_each(InputIterator first, InputIterator last, Function fn);
// Apply function to range
// Applies function fn to each of the elements in the range [first,last).

// The behavior of this template function is equivalent to:

// template <class InputIterator, class Function>
// Function for_each(InputIterator first, InputIterator last, Function fn)
// {
//     while (first != last)
//     {
//         fn(*first);
//         ++first;
//     }
//     return fn; // or, since C++11: return move(fn);
// }

```
## PVA 10

### 10-1
Dynamische Speicher-Verwaltung 

Gegeben ist die folgende Klasse FiFo, welche einen Ringbuffer darstellt. Der Ringbuffer verfügt über eine vorgegebene Anzahl Plätze, welche bei der Instanziierung bestimmt wird.

Aufgabe:
Ergänzen Sie die Klasse mit
•	einem Copy-Constructor
•	einer Methode resize(int size), bei der resize()-Methode müssen die Werte nicht übernommen werden

```cpp
#include <iostream>
class FiFo
{
public:
    FiFo(int size) : size(size) { buf = new double[size]; }
    FiFo(const FiFo &org); /* ToDo */
    ~FiFo() { delete[] buf; }
    void put(double value);
    double get();
    void resize(int size); /* ToDo */

private:
    void copyBuf(double *a, double *b, int size);
    double *buf = nullptr;
    int size;
    int write = 0;
    int read = 0;
    bool empty = true;
};
FiFo::FiFo(const FiFo &org)
{
    this->size = org.size;
    this->write = org.write;
    this->read = org.read;
    this->empty = org.empty;

    this->buf = new double[this->size];
    copyBuf(this->buf, org.buf, this->size);
}

void FiFo::resize(int size)
{
    double *tmp = this->buf;
    this->buf = new double[size];
    this->read = 0;
    this->write = 0;
    this->empty = true;
    this->size = size;
    delete[] tmp;
}

void FiFo::copyBuf(double *a, double *b, int size)
{
    for (int i = 0; i < size; i++)
    {
        a[i] = b[i];
    }
}

void FiFo::put(double value)
{
    buf[write] = value;
    if (write == read && !empty)
    {
        write = (write + 1) % size;
        read = write;
        // overflow
        std::cout << "overflow" << std::endl;
    }
    else
    {
        write = (write + 1) % size;
    }
    empty = false;
}

double FiFo::get()
{
    double result = 0.0;

    if (!empty)
    {
        result = buf[read];
        read = (read + 1) % size;
        if (read == write)
        {
            empty = true;
        }
    }
    else
    {
        // underflow
        std::cout << "underflow" << std::endl;
    }
    return result;
}

int main()
{
    FiFo f(5);
    f.put(3.14159);
    f.put(12.3456);
    std::cout << f.get() << std::endl;
    std::cout << "" << std::endl;

    FiFo f2(f);
    f2.put(2.78);
    std::cout << f2.get() << std::endl;
    std::cout << "" << std::endl;

    f.resize(10);
    f.put(11.111);
    std::cout << f.get() << std::endl;

    return 0;
}

```

### 10-2
Funktionsparameter 
Können die folgenden Programme gebildet werden?
•	Wenn nicht, warum?
•	Wenn ja, was wird ausgegeben?


```cpp
#include <iostream>

// wrong with default value
// void swap(int& a = 0, int& b = 0) {
void swap(int &a, int &b)
{
    int h = a;
    a = b;
    b = h;
}

int main()
{
    int x = 5;
    int y = 6;

    swap(x, y);

    std::cout << "x = " << x << ", y =" << y << std::endl;
    return 0;
}

```

### 10-3
class template

```cpp

template <typename T>

class Calculator
{
private:
    /* data */
    T num1;
    T num2;

public:
    Calculator(T n1, T n2)
    {
        num1 = n1;
        num2 = n2;
    };

    T add() { return num1 + num2; };
    T subtract() { return num1 - num2; };
    T multiply() { return num1 * num2; };
    T divide() { return num1 / num2; };

    void displayResult()
    {
        cout << "Numbers are: " << num1 << " and " << num2 << "." << endl;
        cout << "Addition is: " << add() << endl;
        cout << "Subtraction is: " << subtract() << endl;
        cout << "Product is: " << multiply() << endl;
        cout << "Division is: " << divide() << endl;
    };
};

```

### 10-4
list

```cpp
// main.cpp
#include <iostream>
#include "NameList.h"
using namespace std;

int main()
{
    NameList aList;
    NameList bList = {"Andrei", "Scott", "Bjarne", "Herb"};
    aList.add("Armstrong");
    aList.add("Aldrin");
    aList.add("Collins");
    cout << "aList = " << endl;
    aList.print();
    cout << endl;
    cout << "\nbList = " << endl;
    bList.print();
    cout << endl;
    return 0;
}

// NameList.h
#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NameList
{
public:
    /* ToDo Constructors */
    NameList(){};
    NameList(vector<string> in) { names = in; };
    /* ToDo print()-Methode*/
    void print()
    {
        for (auto name : names)
        {
            std::cout << name << std::endl;
        }
    };
    /* ToDo add(.....)-Methode*/
    void add(string name) { names.push_back(name); };
    /* 1 Punkt     1 Punkt  */
private:
    vector<string> names;
};

```

### 10-5
std::map

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

string digitToText(int digit)
{
    std::map<int, string> txt{{1, "Eins"}, {2, "Zwei"}, {3, "Drei"}, {4, "Vier"}, {5, "Fünf"}, {6, "Sechs"}, {7, "Sieben"}, {8, "Acht"}, {9, "Neun"}};
    // txt[1];
    string result = "unbekannt";
    if ((digit >= 0) && (digit <= 9))
    {
        return txt[digit];
    }
    return result;
}

int main()
{
    for (int i = -1; i < 11; i++)
    {
        cout << digitToText(i) << endl;
    }
    return 0;
}
```

### 10-6
cast operator

```cpp
class Fraction
{
    int a;
    int b;

public:
    Fraction(int first, int second)
    {
        a = first;
        b = second;
    };

    operator float() { return (float)a / (float)b; };
};

int main(int argc, char const *argv[])
{
    Fraction a(1, 2);
    (float)a;
    return 0;
}

```

### 10-7
shared pointer

```cpp
// main.cpp
#include <iostream>
#include <list>
#include "ProgParam.h"
#include <memory>
#include <string>
using namespace std;

list<shared_ptr<ProgParam>> eingabe(int argc, char *argv[])
{
    list<shared_ptr<ProgParam>> params;
    for (int i = 0; i < argc - 1; i++)
        params.push_back(make_shared<ProgParam>((argv[i + 1])));
    return params;
}

void ausgabe(list<shared_ptr<ProgParam>> params)
{
    for (auto x : params)
        cout << x->getParam() << endl;
}
int main(int argc, char *argv[])
{
    list<shared_ptr<ProgParam>> params = eingabe(argc, argv);
    ausgabe(params);
    return 0;
}

// ProgParam.h
#pragma once
#include <string>
using namespace std;
class ProgParam
{
public:
    ProgParam() : param("leer") {}
    ProgParam(const string &param) : param(param) {}
    ~ProgParam() {}
    string getParam() const { return param; }

private:
    string param;
};
```

### 10-8
vector swap

```cpp
#include <iostream>
#include <vector>
using namespace std;
void exchange(vector<int> &vec)
{
    int size = vec.size();
    int mid = vec.size() / 2;

    for (int i = 0; i < mid; i++)
    {
        int tmp;
        tmp = vec[i];
        vec[i] = vec[mid + i];
        vec[mid + i] = tmp;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    exchange(v);
    for (auto i : v)
    {
        cout << i << endl;
    }
    return 0;
}

```
