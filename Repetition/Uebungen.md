# �bungen Buch

## PVA 1

### 1.15 
Berechnen Sie die Summe aller nat�rlichen Zahlen von n1 bis n2 mit a) einer forSchleife, b) einer while-Schleife, c) einer do while-Schleife, d) ohne Schleife. Es sei n2 =
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
Alter einer Person enth�lt. Vorname und Nachname seien vom Typ string, Alter vom
Typ int. Verwenden Sie diese Struktur in einem Programm so, dass den Elementen der
Struktur Werte mit cin (Eingabe �ber die Tastatur) zugewiesen werden. Anschlie�end
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
Gegeben sei eine Zeichenkette des Typs string, die eine nat�rliche Zahl darstellen
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
Etwas schwierig und nur f�r Knobelfreunde: Schreiben Sie ein Programm, das eine
einzugebende nat�rliche Zahl in r�mischer Darstellung ausgibt. Die r�mischen Ziffern
seien in einem konstanten String zeichenvorrat = "IVXLCDM" gegeben. Die meistens verwendete syntaktische Regel lautet: Keine Ziffer au�er �M� darf mehr als dreimal hintereinanderstehen. Das hei�t, ein vierfaches Vorkommen wird durch Subtraktion vom n�chsth�heren passenden Wert ersetzt. Subtraktion geschieht durch Voranstellen des kleineren
Werts. So wird 4 nicht zu IIII, sondern zu IV, und 9 wird nicht zu VIIII, sondern zu IX.
```cpp
#include <iostream>
using namespace std;
int aufgabe_1_19(){
  cout << "Umwandlung einer nat�rlichen(!) dezimalen Ganzzahl in "
          "eine r�mische Zahl.\n Dezimalzahl eingeben:";
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
+100 (einschlie�lich) von der Standardeingabe liest. Der Zahlenbereich sei in 10 gleich
gro�e Intervalle eingeteilt. Sobald eine Zahl au�erhalb des Bereichs eingegeben wird, sei
die Eingabe beendet. Das Programm soll dann f�r jedes Intervall ausgeben, wie viele
Zahlen eingegeben worden sind. Benutzen Sie f�r -99, +100 usw. Konstanten (const).
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
besch�ftigt: Wenn Zahlen Achterbahn fahren. Gegeben sei eine nat�rliche Zahl > 0.
1. Wenn die Zahl gerade ist, teile sie durch 2. Wenn nicht, multipliziere sie mit 3 und
addiere 1.
2. Wenn die sich ergebende Zahl gr��er als 1 ist, wende Schritt 1 auf diese Zahl an.
Wenn nicht, ist das Verfahren beendet.
Es zeigt sich, dass die Zahlen erheblich anwachsen k�nnen und auch wieder kleiner
werden � daher der Name Achterbahn. Schreiben Sie ein Programm, das eine Startzahl als
Eingabe erwartet und den obigen Algorithmus durchf�hrt. Lassen Sie sich die erreichte
Zahl und das erreichte Maximum anzeigen. Am Ende des Programms soll ausgegeben
werden, wie viele Iterationen (Durchl�ufe der Schleife) bis zum Ende des Programms
ben�tigt werden. Mit den Anweisungen
string dummy {""};
getline(cin, dummy); // weiter mit Tastendruck
k�nnen Sie die Ausgabe nach Erreichen eines neuen H�chstwerts anhalten. Versuchen
Sie die Startzahlen 4096, 142587, 1501353. Bei der ersten Zahl (4096) ist klar, dass
der Algorithmus schnell endet, weil 4096 eine Zweierpotenz ist. Die Frage ist letztlich:
Gibt es eine Startzahl, mit der der Algorithmus nicht irgendwann endet? Dieses Problem
tritt auch unter einer Reihe anderer Namen auf: Syracuse-Problem, Ulams-Problem oder
Collatz-Problem. Hinweis: Bei gro�en Zahlen wie der letzten angegebenen wird der intZahlenbereich �berschritten; nehmen Sie stattdessen long long.

```cpp
#include <iostream>
#include <string>
using namespace std;

int aufgabe_1_21()
{
  cout << "Bitte eine Startzahl > 0 eingeben: ";
  long long zahl;
  cin >> zahl;
  cin.ignore(1000, '\n');          // Tastaturpuffer l�schen
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
Tipp: Da manche Compiler char als signed char implementieren, man aber f�r die Darstellung eine unsigned-Zahl braucht, muss ein Zeichen etwa wie folgt umgewandelt werden:
```cpp
char c {�?�}; // evtl. signed
while (datei.get(c)) { // lesen
unsigned char uc = static_cast<unsigned char>(c);
unsigned int zahl = static_cast<unsigned int>(uc);
// zahl hier weiterverarbeiten ...
}
```
Da das eine �bungsaufgabe ist, versuchen Sie, ohne hex auszukommen, wie Sie es etwa
mit der Zeile cout << hex << "0x" << 255 << �\n�; ausprobieren k�nnen.

```cpp
#include <cstdlib>          // f�r exit()
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
    cerr << Quelldateiname << " kann nicht ge�ffnet werden!\n";
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
Erweiterung zur vorigen Aufgabe: Erst 16 Buchstaben und dann die zugeh�rigen
16 Hex-Codes pro Zeile ausgeben.
```cpp
#include <cstdlib>          // f�r exit()
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
    cerr << Quelldateiname << " kann nicht ge�ffnet werden!\n";
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
Schreiben Sie ein Programm stat.cpp, das eine Statistik f�r eine Textdatei ausgibt,
deren Name eingegeben werden soll. Ein m�gliches Ergebnis:
Anzahl der Zeichen = 16437, Anzahl der Worte = 2526, Anzahl der Zeilen = 220
Ein Wort sei hier als ununterbrochene Folge von Buchstaben definiert, wobei Umlaute
hier nicht als Buchstaben z�hlen sollen, weil sie nicht Teil des ASCII-Zeichensatzes sind.
In der Anzahl der Zeichen soll die Zeilenendekennung nicht enthalten sein.
```cpp
//  Datei-Statistik
#include <cstdlib>          // f�r exit()
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
    cerr << Quelldateiname << " kann nicht ge�ffnet werden!\n";
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
    // Umlaute werden nicht ber�cksichtigt
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
      istWort = true;          // Wortanfang, oder c ist in einem Wort
    }
    else {
      if (istWort) {
        ++wortzahl;          // Wortende �berschritten
      }
      istWort = false;
    }
  }
  if (c != '\n') {          // Die letzte Zeile enth�lt kein abschlie�endes \n.
    ++zeilenzahl;           // trotzdem mitz�hlen
  }
  if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
    // das letzte Zeichen ist in einem Wort, das noch nicht mitgez�hlt wurde
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

A) Schreiben Sie ein Programm, das eine Datei dieser Struktur mit beliebig vielen Eintr�gen einliest. Dabei sollen ein Name und die dazugeh�rende Matrikelnummer ein struct
des Typs StudentIn bilden. Name und Matrikelnummer seien beide vom Typ string. Die
Daten sollen in einem Vektor des Typs vector<StudentIn> abgespeichert werden. Geben
Sie den Inhalt des Vektors zur Kontrolle aus.
B) Anschlie�end soll das Programm eine Matrikelnummer erfragen und daraufhin den
zugeh�rigen Namen ausgeben (bzw. die Meldung �nicht gefunden�). Die Abfrage soll
beliebig oft m�glich sein. Wird X oder x eingegeben, beendet sich das Programm.
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

### Repe PVA 1 Moodle
1. Gegeben ist folgendes Programm:
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

2. Gegeben ist folgendes Programm

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

3. GGT

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




```cpp


```




```cpp


```




```cpp


```




```cpp


```



