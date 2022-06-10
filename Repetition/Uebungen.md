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
## PVA 2

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




```cpp


```




```cpp


```




```cpp


```



