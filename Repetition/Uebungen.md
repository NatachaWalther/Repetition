# Übungen Buch

## PVA 1

1.15 Berechnen Sie die Summe aller natürlichen Zahlen von n1 bis n2 mit a) einer forSchleife, b) einer while-Schleife, c) einer do while-Schleife, d) ohne Schleife. Es sei n2 =
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

1.17 Schreiben Sie eine Struktur (struct) namens Person, die Vorname, Nachname und
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

1.18 Gegeben sei eine Zeichenkette des Typs string, die eine natürliche Zahl darstellen
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
1.19 Etwas schwierig und nur für Knobelfreunde: Schreiben Sie ein Programm, das eine
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

1.20 Schreiben Sie ein Programm, das beliebig viele Zahlen im Bereich von -99 bis
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

1.21 Das folgende Problem ist klassisch und es haben sich schon viele Menschen damit
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