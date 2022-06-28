# Kapitel 4 - Die Grundbausteine von C++

## Operatoren

### Arithmetische Operatoren
Grundrechenarten +, -, *, /, %

Gilt für alle Ganzzahl- und Fliesskommazahlen (Ausser Modulo). 

Mit Plus können z.B. auch Strings zusammengesetzt werden.

### Bitweise Arithmetik
Bitweise Verknüpfung mit |, &, ^, ~, >>, <<

|Operation|Binär|Dezimal 
|---|---| 
|a|1001|9 
|b|0011|3 
|a&b AND|0001|1 
|a\|b OR|1011|11 
|a^b XOR|1010|10 
|~b NICHT|1100|12

Umwandlung in dickem Buch Kapitel 4.11.4

### Zusammengesetzte Zuweisung

+=, -=, *=, /=, 

### Prä- und Postinkrement

++wert wird zuerst erhöht und danach verwendet, wert++ wird zuerst verwendet und danach erhöht. 

Postinkrement braucht mehr Speicher!

### Relationale Operatoren

==, !=, <, >, <=, >=

### Logische Operatoren

&&, ||, !

`if (x > 100 && x > 200)` ist dasselbe wie `if (x > 100) { if (x > 200) {}}`

### Pointer und Dereferenzierungsoperatoren

|Methoden | . | name.length()| 
|---|---| 
|Adresse Pointer |&|&a |
Wert Pointer|*|*a

Kurzform: `(*ptr).length()` = `ptr->length`

### Besondere Operatoren

ternärer Operator: `a > b ? a : b` -> if a > b,  a, else b

Sequenzoperator: wertet von links nach rechts aus, behält aber nur das letzte Ergebnis. -> Do NOT use!


## Eingebaute Datentypen

Ohne #include verwendbar. 


 * Ganzzahlen: int, short, long, long long -> (un-)signed
 * Fliesskomma: double, float, long double
 * Zeichen: char, char16_t, char32_t
 * Wahrheitswerte: boolean
 * Zeiger und C-Arrays

### Initialisieren
Wenn nicht initialisiert, nimmt es irgendeinen Wert an.

```cpp
int x{};		//Initialisiert mit 0
double y{};		//Initialisiert mit 0.0
std::string s{};	//Leerer String
```
### Alias Zahlentypen

Alias | Einsatz
---|---
size_t | Positive Grössen, bsp. Container
ptrdiff_t | Abstand zweier Adressen `ptrdiff_t d = &x - &y;`
time_t | aus \<ctime>, Sekunden seit 01.01.1970

# Kapitel 6 - Höhere Datentypen

## String

#include \<string> -> ist in Standardlibrary

Container für einzelne chars

### Initialisierung
```cpp
std::string name;
std::string name{};
std::string name{""};
std::string name("");
std::string name = "";
```

### Funktionen und Methoden
Funktion | Beschreibung
---|---
\+ | Aneinanderfügen zweier strings zu einem neuen
<< | Ausgabe eines strings
\>> | Lesen eines strings bis zum nächsten Whitespace
getline | Lesen in einen string bis zum nächsten Newline

    

Funktion | Beschreibung
---|---
length | Länge des Inhalts
at |(Sicheres) Holen eines einzelnen Zeichens
\[] |Holen eines einzelnen Zeichens ohne Prüfung
find |Suchen innerhalb des string
find_first_of |Suche erstes Zeichen aus einer Menge.
substr |Erzeuge neuen string aus einem Bereich.
compare |Vergleiche mit anderem string.
clear |Zurücksetzen auf den leeren string
append |Anhängen einer Zeichenfolge
\+= |Alternative Schreibweise für append
insert |Einfügen in den string
erase |Löschen eines Teils des strings
replace |Ersetzen eines Teils durch eine andere Zeichenfolge
starts_with |Prüfe, ob der der Anfang passt, seit C++20

Iterieren mit begin() und end(), finden mit find(), vergleichen mit compare()

## Streams

#include \<iostream>

* Standardeingabe cin >>
* Standardausgabe cout <<
* cerr und clog <<

cout ist gepuffert, cerr nicht

### getline

`std::getline(cin, name)` -> Liest bis zum Zeilenende, cin nur bis zum ersten Whitespace

### Ein- und Ausgabe in Dateien


```cpp
//Lesen aus Datei
#include <fstream>
int main(int argc, char* argv[]) {
    int wert = 0;
    std::ifstream meineEingabe{"input1.txt"};
    meineEingabe >> wert;
}
//Schreiben in Datei
#include <fstream>
int main(int argc, char* argv[]) {
    std::ofstream meineAusgabe{"output1.txt"};
    meineAusgabe << "Zeile 1\n";
    meineAusgabe << "Zeile 2\n";
}
```

## Behälter und Zeiger

### Container
Bestehen aus einem Haupttypen Bsp. `vector<int>`


### Array
Anzahl der Elemente ist im Voraus klar!

```cpp
#include <array>
#include <iostream>
using std::cout; using std::array; using std::string;
int main() {
  array<string,7> wotag = { "Montag", "Dienstag",           // definieren
      "Mittwoch", "Donnerstag", "Freitag", "Samstag", "Sonntag" };
  cout << "Die Woche beginnt mit " << wotag[0] << ".\n";    // Werte lesen
  cout << "Sie endet mit " << wotag.at(6) << ".\n";         // Werte sicher lesen
  wotag[5] = "Sonnabend";                                   // Werte verändern
}
```
Wenn die Anzahl aus einer Variable gelesen wird, muss es eine Konstante sein.

Memorylocation im Array:
```cpp
#include <iostream>
using namespace std;
 
int main() {
    // an array of 10 integers. 
    // If arr[0] is stored at
    // address x, then arr[1] is
    // stored at x + sizeof(int)
    // arr[2] is stored at x +
    // sizeof(int) + sizeof(int)
    // and so on.
    int arr[5], i;
 
    cout << "Size of integer in this compiler is "
         << sizeof(int) << "\n";
 
    for (i = 0; i < 5; i++)
        // The use of '&' before a variable name, yields
        // address of variable.
        cout << "Address arr[" << i << "] is " << &arr[i]
             << "\n";
    return 0;
}
```

Traversieren Array 
```cpp
#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int arr[6]={11,12,13,14,15,16};
    // Way 1
    for(int i=0;i<6;i++)
        cout<<arr[i]<<" ";
   
  cout<<endl;
      // Way 2
    cout<<"By Other Method:"<<endl;
    for(int i=0;i<6;i++)  
        cout<<i[arr]<<" ";
   
    cout<<endl;
 
    return 0;
}
```

Grösse mit sizeof();

### Vector
Dynamische Anzahl an Elementen
```cpp
#include <vector>

vector<int> quadrate{};                     //leer initialisieren
for (int index = 0; index < 100; ++index) { //iterieren
    quadrate.push_back(index*index);        //anfügen Element
}
```
Elemente liegen nacheinander im Speicher, das ist sehr schnell. Bei Anfügen eines Elements am Anfang oder der Mitte werden alle nachfolgenden Elemente verschoben, was viel Speicher brauchen kann!

#### Iteratoren

* begin() – Returns an iterator pointing to the first element in the vector
* end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector
* rbegin() – Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
* rend() – Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
* cbegin() – Returns a constant iterator pointing to the first element in the vector.
* cend() – Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
* crbegin() – Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
* crend() – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)

```cpp
#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    vector<int> g1;
 
    for (int i = 1; i <= 5; i++)
        g1.push_back(i);
 
    cout << "Output of begin and end: ";
    for (auto i = g1.begin(); i != g1.end(); ++i)
        cout << *i << " ";
 
    cout << "\nOutput of cbegin and cend: ";
    for (auto i = g1.cbegin(); i != g1.cend(); ++i)
        cout << *i << " ";
 
    cout << "\nOutput of rbegin and rend: ";
    for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
        cout << *ir << " ";
 
    cout << "\nOutput of crbegin and crend : ";
    for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir)
        cout << *ir << " ";
 
    return 0;
}
```
#### Capacity

* size() – Returns the number of elements in the vector.
* max_size() – Returns the maximum number of elements that the vector can hold.
* capacity() – Returns the size of the storage space currently allocated to the vector expressed as number of elements.
* resize(n) – Resizes the container so that it contains ‘n’ elements.
* empty() – Returns whether the container is empty.
* shrink_to_fit() – Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
* reserve() – Requests that the vector capacity be at least enough to contain n elements.
```cpp
#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    vector<int> g1;
 
    for (int i = 1; i <= 5; i++)
        g1.push_back(i);
 
    cout << "Size : " << g1.size();
    cout << "\nCapacity : " << g1.capacity();
    cout << "\nMax_Size : " << g1.max_size();
 
    // resizes the vector size to 4
    g1.resize(4);
 
    // prints the vector size after resize()
    cout << "\nSize : " << g1.size();
 
    // checks if the vector is empty or not
    if (g1.empty() == false)
        cout << "\nVector is not empty";
    else
        cout << "\nVector is empty";
 
    // Shrinks the vector
    g1.shrink_to_fit();
    cout << "\nVector elements are: ";
    for (auto it = g1.begin(); it != g1.end(); it++)
        cout << *it << " ";
 
    return 0;
}
```
#### Element access:

* reference operator [g] – Returns a reference to the element at position ‘g’ in the vector
* at(g) – Returns a reference to the element at position ‘g’ in the vector
* front() – Returns a reference to the first element in the vector
* back() – Returns a reference to the last element in the vector
* data() – Returns a direct pointer to the memory array used internally by the vector to store its owned elements.

```cpp
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    vector<int> g1;
 
    for (int i = 1; i <= 10; i++)
        g1.push_back(i * 10);
 
    cout << "\nReference operator [g] : g1[2] = " << g1[2];
 
    cout << "\nat : g1.at(4) = " << g1.at(4);
 
    cout << "\nfront() : g1.front() = " << g1.front();
 
    cout << "\nback() : g1.back() = " << g1.back();
 
    // pointer to the first element
    int* pos = g1.data();
 
    cout << "\nThe first element is " << *pos;
    return 0;
}
```
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
#include <bits/stdc++.h>
#include <vector>
using namespace std;
 
int main()
{
    // Assign vector
    vector<int> v;
 
    // fill the array with 10 five times
    v.assign(5, 10);
 
    cout << "The vector elements are: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
 
    // inserts 15 to the last position
    v.push_back(15);
    int n = v.size();
    cout << "\nThe last element is: " << v[n - 1];
 
    // removes last element
    v.pop_back();
 
    // prints the vector
    cout << "\nThe vector elements are: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
 
    // inserts 5 at the beginning
    v.insert(v.begin(), 5);
 
    cout << "\nThe first element is: " << v[0];
 
    // removes the first element
    v.erase(v.begin());
 
    cout << "\nThe first element is: " << v[0];
 
    // inserts at the beginning
    v.emplace(v.begin(), 5);
    cout << "\nThe first element is: " << v[0];
 
    // Inserts 20 at the end
    v.emplace_back(20);
    n = v.size();
    cout << "\nThe last element is: " << v[n - 1];
 
    // erases the vector
    v.clear();
    cout << "\nVector size after erase(): " << v.size();
 
    // two vector to perform swap
    vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(2);
    v2.push_back(3);
    v2.push_back(4);
 
    cout << "\n\nVector 1: ";
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";
 
    cout << "\nVector 2: ";
    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";
 
    // Swaps v1 and v2
    v1.swap(v2);
 
    cout << "\nAfter Swap \nVector 1: ";
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";
 
    cout << "\nVector 2: ";
    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";
}
```
# Kapitel 7 - Funktionen

## Deklaration und Definition


```cpp
//Definition
int addTwo(int a, int b) {
    return a + b;
}

//Deklaration -> im Header
int addTwo(int a, int b);       //a und b können weggelassen werden (int, int)

//Aufrufen
addTwo(3, 5);
```
## Parameter

### Call-by-Value

Kopiert den Wert und nutzt eine Kopie in der Funktion

```cpp
int add(int a, int b) {
    a += b;
    return a;
}

//a wird nicht verändert
```

### Call-by-Reference

Parameter als Referenz übergeben, dann wird die verändert.
```cpp
int add(int& a, int& b) {
    a += b;
    return a;
}

//a wird verändert
```

### Vorwärtsdeklaration

Funktion vorher deklarieren, damit sie schon bekannt ist. 

## Funktionen überladen

Mehrmalige Definition mit verschiedenen Datentypen.


```cpp
#include <iostream>

void print(int wert) { std::cout << "int-Wert: " << wert << "\n"; }
void print(double wert) { std::cout << "double-Wert: " << wert << "\n"; }
void print(int w1, double w2) { std::cout << "Werte: "<<w1<<", "<<w2<<"\n"; }

int    add(int n, int m) { return n + m; }
double add(double a, double b) { return a + b; }

int main() {
    print( add(3, 4) );        // add(int, int) und print(int)
    print( add(3.25f, 1.5f) ); // add( double, double) und print(double)
    print( 7, 3.25 );          // print(int, double)
}
```
## Default Parameter

Standardwerte für Parameter die überschrieben werden können.

```cpp
int add(int n=0, int m=0, int o=0, int p=0, int q=0) {
    return n+m+o+p+q;
}
int main() {
    std::cout << add(1,2,3,4,5) << "\n";
    std::cout << add(1,2,3,4) << "\n"; // wie add(1,2,3,4,0)
    std::cout << add(1,2,3) << "\n";   // wie add(1,2,3,0,0)
    std::cout << add(1,2) << "\n";     // wie add(1,2,0,0,0)
    std::cout << add(1) << "\n";       // wie add(1,0,0,0,0)
    std::cout << add() << "\n";        // wie add(0,0,0,0,0)
}
```
Damit braucht es nur eine add Variante, die bis zu 5 Parameter annehmen kann!

## Inline Funktion

Spart Rechenzeit bei kurzen Funktionen

```cpp
inline int func(double a, double b, double c);
```

## Generic functions

Use same code with different Datatypes.



```cpp
void Swap(int &a, in &b){
    int temp = a;
    int a = b;
    int b = temp;
}

int main() {

    int a = 5, b = 7;
    Swap(a,b);


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






# Kapitel 8 - Anweisungen im Detail

## if
```cpp
if (zahl < 5) {
    cout << "Kleiner 5";
} else if (zahl < 10) {
    cout "Kleiner 10";
}else {
    cout << "Grösser 10";
}
```

## while
```cpp
wile (zahl < 100){
    summe += zahl;
    zahl++;
}
```
## do-while
```cpp
int main() {
    std::string line;
    do {                            // mindestens einmal getline ausführen
       std::getline(std::cin, line);
       if(!std::cin) break;         // Fehler oder Dateiende
    } while(line != "quit");        // Ende bei bestimmter Eingabe
}
```
## for
```cpp
for (int i = 0; i < 100; i++){
    summe += i;
}
```
### range-based-for
`for(Ziel : Container) Anweisung`
```cpp
vector<int> primzahlen {2};

void testePrim(int n) {
    for(int zahl : primzahlen) {
        if(zahl*zahl > n) {
            return true;
        } if(n%teil == 0) {
            return false;
        }
    }return true;
}
```
## switch
```cpp
#include <string>
#include <vector>
#include <iostream>       // cout

void rechner(std::ostream& out, std::string input) {
    std::vector<int> stapel {};
    for(char c : input) {
        if(c>='0' && c<='9') {
            stapel.push_back( c-'0' ); // Zahlenwert des Zeichens
            continue;     // nächste Schleifeniteration
        }
        int top = 0;
        int second = 0;
        switch(c) {       // Bedingung auf zeichen
        case @'@+@'@:
            top = stapel.back(); stapel.pop_back();
            second = stapel.back(); stapel.pop_back();
            stapel.push_back(second + top);
            break;
        case @'@-@'@:
            top = stapel.back(); stapel.pop_back();
            second = stapel.back(); stapel.pop_back();
            stapel.push_back(second - top);
            break;
        case @'@*@'@:
            top = stapel.back(); stapel.pop_back();
            second = stapel.back(); stapel.pop_back();
            stapel.push_back(second * top);
            break;
        case @'@=@'@:
            for(int elem : stapel) { out << elem; }
            out << "\n";
            break;
        case @'@ @'@:
            break;
        default:
            out << "\n'" << c << "' verstehe ich nicht.\n";
        } /* switch */
    } /* for c */
}
int main(int argc, const char* argv[]) {
    if(argc > 1) {
        rechner(std::cout, argv[1]);
    } else {
        // 3 + 4 * 5 + 6 mit Punkt- vor Strichrechnung ergibt 29
        rechner(std::cout, "345*+6+=");
    }
}
```

## break
Aus Schleife springen, macht mit Anweisung nach dem Block weiter.

## continue

Rest des Schleifendurchlaufs abbrechen und mit nächster Interation weitermachen.


## return

Aus Funktion herausspringen.



## try-catch und throw
*Try* umschliesst Programmcode in dem ein Fehler erwartet wird, *catch* übernimmt die Fehlerbehandlung.
```cpp
#include <iostream>
int main() {
    try {                                        // Beginn des try-Blocks
        for(int n=1; ; n=n*2) {
            if(n < 0) {
                throw "Es gab einen Ueberlauf";  // Fehler auslösen
            }
        }
    }                                            // Ende des try-Blocks
    catch(const char *fehler) {                  // falls dieser Fehler auftritt, ...
      std::cout << "Fehler: " << fehler << "\n"; // ... behandle ihn so
    }
}
```

# Kapitel 10 - Fehlerbehandlung

Exception handling in C++ consists of three keywords: try, throw and catch:

* The *try* statement allows you to define a block of code to be tested for errors while it is being executed.
* The *throw* keyword throws an exception when a problem is detected, which lets us create a custom error.
* The *catch* statement allows you to define a block of code to be executed if an error occurs in the try block.

The try and catch keywords come in pairs

```cpp
#include <iostream>
using namespace std;
 
int main()
{
   int x = -1;
 
   // Some code
   cout << "Before try \n";
   try {
      cout << "Inside try \n";
      if (x < 0)
      {
         throw x;
         cout << "After throw (Never executed) \n";
      }
   }
   catch (int x ) {
      cout << "Exception Caught \n";
   }
 
   cout << "After catch (Will be executed) \n";
   return 0;
}
```

```cpp
#include <iostream>            // cout, cerr
#include <vector>
#include <string>
#include <fstream>             // ifstream
#include <stdexcept>           // invalid_argument
using std::vector; using std::string; using std::cout; using std::ifstream;
size_t zaehleWoerter(const string& filename) { // 0 oder größer
    std::ifstream file{};      // ungeöffnet erzeugen
    // anmelden für Exceptions:
    file.exceptions(ifstream::failbit | ifstream::badbit);
    file.open(filename);       // könnte eine Exception auslösen
    size_t count = 0;
    string wort;
    file.exceptions(ifstream::badbit); // EOF keine Exception mehr
    while(!file.eof()) {       // noch nicht am Ende?
        file >> wort;   ++count;
    }
    return count-1;            // @MINUS@1: am EOF wurde noch ein Wort gelesen
}
void process(const vector<string>& args) {
    if(args.size() == 0) {     // process erwartet Parameter
        throw std::invalid_argument{"Kommandozeilenarg. fehlt"}; // auslösen
    } else {
        for(const string filename : args) {
            cout << filename << ": " << zaehleWoerter(filename) << std::endl;
        }
    }
}
int main(int argc, const char* argv[]) {
    try {                                      // Block mit Fehlerbehandlungen
        process(
          vector<string>{argv+1, argv+argc} ); // const char*[] nach vector<string>
        return 0;
    } catch(std::exception &exc) {  // Fehlerbehandlung
        std::cerr << "Es trat ein Fehler auf: " << exc.what() << "\n";
        return 1;
    }
}
```

## Ausnahmen auslösen und behandeln

Throw löst eine Ausnahme aus. 

Instanz der Klasse std::invalid_argument erzeugen, die den Fehler repräsentiert.

```cpp
if(args.size() == 0) {     // process erwartet Parameter
        throw std::invalid_argument{"Kommandozeilenarg. fehlt"}; // auslösen
    } else {
        for(const string filename : args) {
            cout << filename << ": " << zaehleWoerter(filename) << std::endl;
        }
    }
```
open() wirft die Exception selber und räumt auch auf.

```cpp
file.open(filename);
```
Rohe Zeiger, die mit new erstellt werden, müssen manuell entsorgt werden.
## Aufrufstapel abwickeln

In Main wird innerhalb des try-Blocks jede geworfene Exception geprüft und die Befehle innerhalb des catch-Blocks der Reihe nach durchgearbeitet werden. 



```cpp
int main(int argc, const char* argv[]) {
    try {                                      // Block mit Fehlerbehandlungen
        process(
          vector<string>{argv+1, argv+argc} ); // const char*[] nach vector<string>
        return 0;
    } catch(std::exception &exc) {  // Fehlerbehandlung
        std::cerr << "Es trat ein Fehler auf: " << exc.what() << "\n";
        return 1;
    }
}
```
exc.what() gibt beispielsweise den Text der Fehlermeldung bei std::invalid_argument mit.

## Kleinere Fehlerbehandlung
Soll das Programm nicht abgebrochen werden, sondern mit der nächsten Datei weitergeführt werden, kommt die Fehlerbehandlung in die for-SChleife.

```cpp
for(const string filename : args) {
            cout << filename << ": ";
            try {
            cout << zaehleWoerter(filename) << std::endl;
            } catch (std::exception &exec) {
                cout << "Fehler: " << exc.what() << "\n";
            }
}
```
## rethrow

Innerhalb eines catch-Blocks ein throw ohne weiteres Argument nutzen, um gerade geworfene Exception unverändert weiterzuwerfen.

```cpp
for(const string filename : args) {
            cout << filename << ": ";
            try {
            cout << zaehleWoerter(filename) << std::endl;
            } catch (std::exception &exec) {
                cout << "Fehler: " << exc.what() << "\n";
                throw;
            }
}
```
## catch Reihenfolge
Der erste passende Handler wird ausgeführt. 
```cpp
try {
    //Code here
}catch(std::invalid_argument &exc){          //erster Handler
    cerr << "Ungültiges Argument: " << exc.what() << "\n";
    }catch(std::ios_base_failure &exc){      //zweiter Handler
    cerr << "Dateifehler: " << exc.what() << "\n";
    }catch(std::exception &exc){            //dritter Handler
    cerr << "Es trat ein Fehler auf: " << exc.what() << "\n";
    } catch(...) {                          //vierter und letzter Handler
        cerr << "Es trat ein Fehler auf \n";
    }
    return 1;
```
There is a special catch block called the ‘catch all’ block, written as catch(…), that can be used to catch all types of exceptions. For example, in the following program, an int is thrown as an exception, but there is no catch block for int, so the catch(…) block will be executed. 

```cpp
#include <iostream>
using namespace std;
 
int main()
{
    try  {
       throw 10;
    }
    catch (char *excp)  {
        cout << "Caught " << excp;
    }
    catch (...)  {
        cout << "Default Exception\n";
    }
    return 0;
}
```

## Exceptions in der Standardbibliothek
Exception | Beschreibung
---|---
bad_alloc |Exception thrown on failure allocating memory (class )
bad_cast|Exception thrown on failure to dynamic cast (class )
bad_exception|Exception thrown by unexpected handler (class )
bad_function_call |Exception thrown on bad call (class )
bad_typeid|Exception thrown on typeid of null pointer (class )
bad_weak_ptr |Bad weak pointer (class )
ios_base::failure|Base class for stream exceptions (public member class )
logic_error|Logic error exception (class )
runtime_error|Runtime error exception (class )


Hierarchie im Lehrbuch: Abbildung 7.1: Exception-Hierarchie in C++

## Exception Sicherheit

Ein Programm ist exception-sicher (englisch exception safe), wenn Laufzeitfehler keine
nachteiligen Auswirkungen haben. Um den Begriff zu präzisieren, gibt es verschiedene
Stufen:
1. Auf der niedrigsten Stufe gibt es keinerlei Zusicherungen, ob und wie sich Fehler
auswirken.
2. In dieser Stufe kann ein Programm zwar falsche Daten erzeugen, es soll aber weder
abstürzen noch Speicherlecks oder verwitwete Objekte hinterlassen.
3. Eine starke Exception-Sicherheit liegt vor, wenn eine Operation entweder vollständig oder, bei einem Fehler, gar nicht oder so ausgeführt wird, dass das betroffene
Objekt anschließend im selben Zustand wie vor der fehlerhaften Operation ist. Dies
entspricht einem Commit bzw. Rollback in der Datenbank-Terminologie. Ein Beispiel
ist die folgende Funktion zum Ablegen eines Elements auf einem Stack (Variante der
Funktion von Seite 291):

```cpp
template<typename T>
void SimpleStack<T>::push(const T& x)
{
if (full()) {
throw std::logic_error("Stack-Overflow!");
}
array[anzahl++] = x;
}
```
Wenn noch Platz auf dem Stack ist, hat push() die gewünschte Wirkung. Wenn nicht,
bleibt der Stack in seinem vorherigen Zustand.

4. In der sichersten Stufe wird garantiert, dass keine Fehler auftreten oder aber alle auftretenden Fehler abgefangen werden, sodass kein Fehler nachteilige Auswirkungen
hat. Möglicherweise auftretende Exceptions werden nicht zum Aufrufer durchgereicht.

# Kapitel 12 - Von der Struktur zur Klasse

## Struct
Bündelung mehrerer Datenfelder zu einem neuen Datentyp.

```cpp
#include <string>
#include <iostream>                      // cout
using std::string; using std::cout;
struct Person {                          // definiert den neuen Typ Person
    string name_;
    int alter_;
    string ort_;
};                                       // abschließendes Semikolon
void drucke(Person p) {                  // ganze Person als ein Parameter
    cout << p.name_ << " ("<< p.alter_<<") aus " // Zugriff per Punkt
        << p.ort_ << "\n";
}
int main() {
    Person otto {"Otto", 45, "Kassel" }; // Initialisierung
    drucke(otto);                        // Aufruf als Einheit
}
```

*Typendefinitionen wie Strukturen und Klassen mit Semikolon abschliessen!!*

## Initialisierung

Initialisierung mit geschweiften Klammern. Werden sie leer gelassen `Person Otto{};` werden die Werte mit ihren Defaultwerten (0, bzw. leere Strings) initialisiert. 

## Rückgabe eigener Werte
Selber erstellte Datentypen können genau so zurückgegeben werden. 
```cpp
// Ausschnitt
Person erzeuge(string name, int alter, string ort) {
    return Person{name, alter, ort};       // direkt zurückgegeben
    //Peron kann weggelassen werden (return {name, alter, ort};) wenn erzeuge nicht auto ist.
    //Auto verlangt auch Konstruktornamen
    //auto erzeuge(string name, int alter, string ort) {}
}
int main() {
    drucke(erzeuge("Otto", 45, "Kassel")); // Rückgabe direkt verwendet
}
```
##Methoden

Funktionen für einen bestimmten Datentypen.

```cpp
#include <string>
#include <iostream>
using std::string; using std::cout;
struct Person {
    string name_;
    int alter_;
    string ort_;
    void drucke();      // Funktion als Methode des Typs
};
void Person::drucke() { // Name der Methode wird um Person:: erweitert
    cout << name_       // in einer Methode können Sie direkt auf Felder zugreifen
        << " ("<< alter_<<") aus " << ort_ << "\n";
}
int main() {
    Person otto {"Otto", 45, "Kassel" };
    otto.drucke();      // Aufruf der Methode für eine Variable des Typs
}
```
Innerhalb der methode kann normal auf Datenfelder und Methoden der Klasse zugegriffen werden (name_ statt p.name_).

Dies wird intern vom Compiler als this-> interpretiert. Eine Methode hat den implizierten Parameter Typ* this. Der steht für die Speicheradresse der Instanz, auf die die Methode aufgerufen wird. 

```cpp
//Wird vom Compiler gemacht:
string Person::gruss(){
    return "Hallo " + this->name_ + "aus " + this->ort_;
}
```
Der this Parameter ändert sich beim Aufruf der Methoden von verschiedenen Objekten.

anna |  
---|---
[0] |name_ = "Anna"
[1] |alter_ = 33
[2] |ort_ = "Hof"

nina |  
---|---
[0] |name_ = "Nina"
[1] |alter_ = 25
[2] |ort_ = "Wyk"

```cpp
anna.gruss()
    this -> geht auf Tabelle Anna
    name_ : this+0
    ort_ : this+2
    
    nina.gruss()
    this -> geht auf Tabelle Nina
    name_ : this+0
    ort_ : this+2
```

Freie Funktion (nicht an Objekt gebunden)
```cpp
string gruss(Person * const p){
    return "Hallo " + p->name_ + "aus " + p->ort_;
}
```

## Bessere Datenausgabe

Wenn drucke() mit cout ist, kann es nur so ausgegeben werden. Was ist mit Errors? 

Bessere Variante:
```cpp
void Person::drucke(std::ostream& os) {     //Ziel der Ausgabe als Parameter
    os << name_ << " ("<< alter_<<") aus " << ort_;
}
int main() {
    Person karl {"Karl", 12, "Stetten"};
    karl.drucke(cout); // auf dem Bildschirm
    cout << "\n";
    std::ofstream datei {"personen.txt"};
    karl.drucke(datei);        // in eine Datei
    // automatischer Test:
    std::ostringstream oss{};  // schreibt in einen string
    karl.drucke(oss);
    if(oss.str() == "Karl (12) aus Stetten") {
        cout << "ok\n";
    } else {
        cout << "Fehler in Person::drucke!\n";
        return 1;              // Fehler nach außen weiterleiten
    }
}
```

## Methoden inline definieren

Kurze Methoden vor Ort definieren. 

```cpp
#include <string>
#include <iostream>    // ostream

using std::string; using std::ostream;

struct Person {
    string name_;
    int alter_;
    string ort_;
    ostream& drucke(ostream& os) {  // Methode inline definiert
        return os << name_ << " ("<< alter_<<") aus " << ort_;
    }
};
```
## Konstruktoren

Methode zur Initialisierung der Struktur

```cpp
struct Person {
    string name_;
    inr alter_;
    string ort_;
    Person();               //Deklaration Konstruktor
}

Person::Person()            //Definition Konstruktor
    : name_{"Kein Name"}    //Initialisierungswert name_
    , alter_{-1}            //Initialisierungswert alter_
    , ort_{"Kein Ort}       //Initialisierungswert ort_
    {}                      //leerer Funktionskörper


Person p{}                  //Initialisierung
```

Konstruktoren mit mehreren Argumenten:
```cpp
#include <string>
using std::string;

struct Person {
    string name_;
    int alter_;
    string ort_;
    Person();                          // Konstruktor ohne Argumente
    Person(string n, int a, string o); // Konstruktor mit drei Argumenten
    Person(string n, int a);           // Konstruktor mit zwei Argumenten
    Person(string n);                  // Konstruktor mit einem Argument
};

Person::Person() 
  : name_{"kein Name"}, alter_{-1}, ort_{"kein Ort"} { } 
Person::Person(string n, int a, string o) 
  : name_{n}, alter_{a}, ort_{o} { } 
Person::Person(string n, int a)
  : name_{n}, alter_{a}, ort_{"kein Ort"} { }
Person::Person(string n)
  : name_{n}, alter_{-1}, ort_{"kein Ort"} { }
```
### Default Werte

Dann müssen die Werte nicht im Konstruktor aufgenommen werden.

```cpp
#include <string>
using std::string;
struct Person {
    string name_ = "kein Name";
    int alter_ = -1;
    string ort_ = "kein Ort";
    Person() {}
    Person(string n, int a, string o)
      : name_{n}, alter_{a}, ort_{o} { }
    Person(string n, int a)
      : name_{n}, alter_{a} { }
    Person(string n)
      : name_{n} { }
};
```
### Konstruktor Delegation

Initialisierung der Werte an einen Konstruktor delegieren. Konstruktor mit der maximalen Anzahl an Argumenten implementieren und an diesen die anderen Initialisierungen delegieren.

Dabei lässt man den Körper des delegierenden Konstruktoren leer. 

```cpp
#include <string>
using std::string;

struct Person {
    string name_;
    int alter_;
    string ort_;

    Person(string n, int a, string o)          // delegierter Konstruktor
      : name_(n), alter_(a), ort_(o) { }       // ... ausimplementiert
    Person() : Person{"kein Name",-1,"kein Ort"} { }       // delegierend
    Person(string n, int a) : Person{n, a, "kein Ort"} { } // delegierend
    Person(string n) : Person{n, -1, "kein Ort"} { }       // delegierend
};
```
### Defaultwerte für Konstruktorparameter

```cpp
#include <string>
using std::string;

struct Person {
    string name_;
    int alter_;
    string ort_;

    Person(string n = "N.N.", int a = 18, string o = "Berlin")
      : name_(n), alter_(a), ort_(o) { }
};
```

## Struct vs. Klasse

Struct zum Halten von Daten mit wenig verhalten durch Methoden

Class bei Daten als Implementierungsdetails und das Verhalten wichtiger ist.




# Kapitel 13 - Namensräume und Qualifizierer
## Namensräume
In jedem Bereich kann ein Name nur für eine Entität stehen. Es kann also nicht zwei Variablen mit demselben Namen im selben Bereich geben. Mit Hilfe von Namespaces können wir zwei Variablen oder Memberfunktionen mit demselben Namen erstellen. 

Alles was in einen Namensraum kommt, wird in dessen Bereich (scope) gepackt.

```cpp
#include <string>
#include <iostream>                    // ostream, cout
namespace plant {
    class Baum {
        std::string name_;
    public:
        explicit Baum(const std::string& name) : name_{name} {}
        void print(std::ostream& os) const { os << name_; }
    };
    std::ostream& operator<<(std::ostream& os, const Baum& arg)
        { arg.print(os); return os; }
    using NadelBaum = Baum;            // für spätere Erweiterungen ...
    using LaubBaum = Baum;             // ... vorsorgen
    namespace beispielnamen {          // eingebetteter Namensraum
        std::string eicheName = "Eiche";
        std::string bucheName = "Buche";
        std::string tanneName = "Tanne";
    } // Ende namespace beispielnamen
} // Ende namespace plant

int main() {                           // main darf nicht in einem Namespace stehen
    using namespace plant::beispielnamen; // alle Beispielnamen verfügbar machen
    plant::NadelBaum tanne{ tanneName };
    plant::LaubBaum eiche{ eicheName };
    tanne.print(std::cout); std::cout << "\n";
    using plant::operator<<;           // ohne geht 'cout << eiche' nicht
    std::cout << eiche << "\n";
}
```
* eingener Datentyp Baum `plant::baum`
* Freie Funktion `operator<<`
* Typaliase `nadelBaum` und `laubBaum`
* Eingebetteter Namensraum `beispielnamen`

Main muss ausserhalb eines Namensraums stehen. 

Verwendung in main()
```cpp
//Variante 1
using plant::NadelBaum; using plant::LaubBaum;
NadelBaum tanne{tanneName;}
LaubBaum eiche{eicheName;}

//Variante 2
using namespace plant;
NadelBaum tanne{tanneName;}
LaubBaum eiche{eicheName;}
```
Verwendung Operator<<

* `using plant::operator<<;` -> Nur den Operator holen
* `using namespace plant;` -> gesamter Namensraum holen


```cpp
using namespace plant;
cout << baum << "\n";
```

```cpp
// Here we can see that more than one variables
// are being used without reporting any error.
// That is because they are declared in the
// different namespaces and scopes.
#include <iostream>
using namespace std;
 
// Variable created inside namespace
namespace first
{
    int val = 500;
}
 
// Global variable
int val = 100;
 
int main()
{
    // Local variable
    int val = 200;
 
    // These variables can be accessed from
    // outside the namespace using the scope
    // operator ::
    cout << first::val << '\n';
 
    return 0;
}
```


```cpp
// Let us see how namespace scope the entities including variable and functions:
 
#include <iostream>
using namespace std;
 
// first name space
namespace first_space
{
   void func()
   {
      cout << "Inside first_space" << endl;
   }
}
 
// second name space
namespace second_space
{
   void func()
   {
      cout << "Inside second_space" << endl;
   }
}
 
int main ()
{
    // Calls function from first name space.
   first_space::func();
    // Calls function from second name space.
   second_space::func();
   return 0;
}
 
// If we compile and run above code, this would produce the following result:
// Inside first_space
// Inside second_space
```


```cpp

// A C++ program to demonstrate use of class
// in a namespace
#include<iostream>
using namespace std;
 
namespace ns
{
    // A Class in a namespace
    class geek
    {
    public:
        void display()
        {
            cout<<"ns::geek::display()"<<endl;;
        }
    };
}
 
int main()
{
    // Creating Object of geek Class
    ns::geek obj;
 
    obj.display();
 
    return 0;
}
```
Define Methods Outside Namespace

```cpp
// A C++ code to demonstrate that we can define
// methods outside namespace.
#include <iostream>
using namespace std;
 
// Creating a namespace
namespace ns
{
    void display();
    class geek
    {
    public:
       void display();
    };
}
 
// Defining methods of namespace
void ns::geek::display()
{
    cout << "ns::geek::display()\n";
}
void ns::display()
{
    cout << "ns::display()\n";
}
 
// Driver code
int main()
{
    ns::geek obj;
    ns::display();
    obj.display();
    return 0;
}
```
Namespace Extension

```cpp

// C++ program to demonstrate namespace extension
#include <iostream>
using namespace std;
 
// first name space
namespace first
{
   int val1 = 500; 
}
 
// rest part of the first namespace
namespace  first
{
   int val2 = 501; 
}
 
int main()
{
   cout << first::val1 <<"\n";       
   cout << first::val2 <<"\n";
   return 0;
}
```

### Unnamed Namespaces / Anonym 
* They are directly usable in the same program and are used for declaring unique identifiers.
* In unnamed namespaces, name of the namespace in not mentioned in the declaration of namespace.
* The name of the namespace is uniquely generated by the compiler.
* The unnamed namespaces you have created will only be accessible within the file you created it in.
* Unnamed namespaces are the replacement for the static declaration of variables.
```cpp

// C++ program to demonstrate working of unnamed
// namespaces
#include <iostream>
using namespace std;
 
// unnamed namespace declaration
namespace
{
   int rel = 300;
}
 
int main()
{
   cout << rel << "\n"; // prints 300
   return 0;
}
```

### Different ways to access namespace

#### "Normal Way"

```cpp
// C++ program to demonstrate accessing of variables
// in normal way, i.e., using "::"
#include <iostream>
using namespace std;
  
namespace geek
{
    int rel = 300; 
}
  
int main()
{
    // variable ‘rel’ accessed 
    // using scope resolution operator
    cout << geek::rel << "\n";  // prints 300
  
    return 0;
}
```
#### Using

```cpp
// C++ program to demonstrate accessing of variables
// in normal way, i.e., using "using" directive
#include <iostream>
using namespace std;
  
namespace geek
{
    int rel = 300; 
}
  
// use of ‘using’ directive
using namespace geek;
  
int main()
{
   // variable ‘rel’ accessed 
   // without using scope resolution variable
   cout << rel << "\n";        //prints 300
    
   return 0;
}
```

### Nested Namespaces

```cpp

// C++ program to demonstrate nesting of namespaces
#include <iostream>
using namespace std;
  
// Nested namespace
namespace out
{
  int val = 5; 
  namespace in
  {
      int val2 = val;    
  }
}
  
// Driver code
int main()
{
  cout << out::in::val2;   // prints 5
  return 0;
}
```
### Namespace Aliasing

```cpp
#include <iostream>

namespace name1
{
	namespace name2
	{
		namespace name3
		{
			int var = 42;
		}
	}
}

// Aliasing
namespace alias = name1::name2::name3;

int main()
{
	std::cout << alias::var << '\n';
}
```
## static macht dauerhaft

Name der Vaiabeln oder Funktion ist nur innerhalb des Moduls sichtbar.

Variable bleibt bei Austritt aus Gültigkeitsbereich bestehen. 
```cpp
#include <iostream>                     // cout
class Keyboard {
    Keyboard(const Keyboard&) = delete; // keine Kopie
    const size_t nr_;                   // aktuelle Nummer
public:
    static inline size_t count_ = 0;    // zählt erzeugte Instanzen
    explicit Keyboard() : nr_{count_++} {
        std::cout << "  Keyboard().nr:"<<nr_<<"\n";
    }
};
Keyboard& getKeyboard() {
    std::cout << "  getKeyboard()\n";
    static Keyboard keyboard{};         // statische lokale Variable
    return keyboard;
}
void func() {
    std::cout << "kbFunc...\n";
    Keyboard& kbFunc = getKeyboard();
}
int main() {
    std::cout << "kbA...\n";
    Keyboard& kbA = getKeyboard();
    func();
    std::cout << "kbB...\n";
    Keyboard& kbB = getKeyboard();
    std::cout << "count:" << Keyboard::count_ << "\n";
}
```
### Overview

Sprachelement | Beschreibung
---|---
namespace *xyz* \{...} | neuer Namensraum *xyz*
namespace \{...} | anonymer Namensraum; alle Bezeichner Dateilokal
inline namespace *xyz* \{...} | eingebetteter Namensraum
*static* globale Variable| dateilokale Variable
*static* freie Funktion| dateilokale Funktion
*static* Datenfeld| wird zwischen allen Instanzen der Klasse geteilt
*static* Methode| Metdoke die ohne konkrete Instanz aufgerufen wird
*static* lokale Variable| eine den bereich überdauernde Variable 
using namespace *xyz* | alle Bezeichner aus dem Namensraum *xyz* importieren
using *xyz:abc* |  Bezeichner *abc* aus dem Namensraum *xyz* importieren
using *neu = alt*; | Typalias *neu* für den Typ *alt* einführen


## const

* mit static eine Konstante definieren `static const int MAX = 100;`
* Rückgabewert nicht verändern `const string& getName();`
* Parameter in der Funktion nicht ändern `void print(const string& msg)`
* Methode verändert Objekt nicht `void Widget::drawYourself() const;`

### Const mit Pointern und Referenzen

* der int-Wert val ist unveränderbar `int const val`
* Alle Datefelder und Methoden der Klasse MyClass von denen obj ein Objekt ist, sind unveränderbar `MyClass const &obj`
* int Wert auf den Pointer zeigt ist unveränderbar `int const * ptr`
* Der Pointer ist unveränderbar, der Wert nicht `int * const ptr`
* inhalt und Pointer sind unveränderbar `char const * const cstring`

#### Recap:

* Address-of operator: `cout << &x;`
* Pointer declarations: `int *p; or int* p;`
* Assign Address to Pointer: `int* p; int var = 5; p = &var` (Pointer p hat Adresse von var)
* Access value from Pointer: `cout << *p;`
* Change value of Pointer: `*p = 15;`
* Make a reference: `int x = 10; int& ref = x;`
* Change value of refernce: `ref = 20;`

*Das const markiert die Entität als unveränderbar, hinter der es steht!!*

-> Bei der Notation mit const am Anfang, muss das führende const eins nach rechts (Bsp. Dickes Buch S. 329)

#### const Paramter

Parameter mit const markieren (Call by Reference) 
```cpp
void print(const vector<int> &primes) {
    for(auto prime : primes) {
        cout << prime << "\n";
    }
}
```
Der Parameter primes kann nun nicht mehr verändert werden.

#### const Methoden

Wie erkennt der Compiler, welche Methoden mit const aufgerufen werden dürfen, bzw das Objekt nicht verändern?

```cpp
void print (const vector <int> &primes){
    if (primes.size() > 100) {      //das geht
        return;
    }
    for(auto prime : primes) {      //geht auch
        cout << prime << "\n";
    }
    primes.push_back(4);            //geht nicht
}
```
Methode `size()` von vector hat ein nachgestelltes const: `size_t vector<int>::size() const;`. Dadurch weiss der Compiler, das dieser Methodenaufruf erlaubt ist. 

Beispiel an eingenem Datentyp "Widget":

```cpp
class Widget {
    unsigned x = 0, y = 0, w = 0, h = 0; // zum Beispiel
public:
    unsigned getLeft() const;
    unsigned getTop() const;
    unsigned getRight() const;
    unsigned getBottom() const;
    void setWidth(unsigned w);
    void setHeight(unsigned h);
};
```
Die get-Methoden können nun aufgerufen werden:

```cpp
void show(const Widget& widget){
    drawBox(
        widget.getLeft(), widget.getTop(),
        widget.getRight(), widget.getBottom()
    );
}
```
setWidth() hingegen löst eine Fehlermeldung aus, da es nicht als const markiert ist.

#### const Variablen

Lokale Variablen in einer Funktion oder globale Variablen für Datenfelder eienr Klasse können mit const markiert werden. Sie können nur noch Initialisiert werden, können aber nciht verändert werden. 

```cpp
class Widget {
        const int id;
    public:
        explicit Widget(int id_) : ind(id_) {}
        Widget() : id(0) {}
        void reset();
};

void Widget::reset() {              //verboten
    id = 36;
}

const Widget widget_a = Widget{12};

widget_a = Widget{24};              //geht nicht
```
widget_a kann nach der Initialisierung nicht mehr verändert werden.

Wirksamer SChutz vor Veränderungen:

```cpp
#include <vector>
namespace {                   // anonymer Namensraum für Konstanten
    const unsigned DATA_SIZE = 100; /* Anzahl Elemente in Data */
    const double LIMIT = 999.999; /* Maxwert bei Initialisierung */
};
std::vector<int> createData() {
    std::vector<int> result(DATA_SIZE);
    double currVal = 1.0;
    for(auto &elem : result) {
        elem = currVal;
        currVal *= 2;         // nächster Wert ist größer
        if(currVal > LIMIT) {
            currVal = LIMIT;  // kein Wert darf größer sein
        }
    }
    return result;
}
```
#### const mit statiac

* **Const im anonymen Namensraum - MAX_A** Konstante ist nur in dieser Datei bekannt, von aussen nicht zugreifbar.
* **static im globalen Namensraum - MAX_B** Ältere Schreibweise -> Anonymer Namensraum empfohlen
* **static const als Datenfeld - SIZE** Alle Variablen vom Typ Data teilen siche in einziges SIZE, durch const ist es unveränderbar.
* **static const als lokale Variable - LIMIT** Variable behält ihren Wert wenn die FUnktion verlassen wird durch static, sie wird nur beim ersten Passieren initialisiert. Mit const zusammen wird die Konstante nur bei Bedarf initialisiert.


```cpp
namespace {
    const int MAX_A = 12;       // das Gleiche wie MAX_B, aber kein static nötig
}

static const int MAX_B = 10;    // im globalen Namensraum

struct Data {
    static const int SIZE = 14; // als Datenfeld in einer Klasse
}

void func() {
    static const int LIMIT =16; // als lokale Konstante
}
```

#### constexpr

Konstante die schon zur Compilezeit verwendbar ist. Beispielsweise Anlegen eines Arrays mit bestimmter Grösse:


```cpp
#include <array>
int main() {
    std::array<int, 5> arr5{};     // Literal und somit ein konstanter Ausdruck
    std::array<int, 2+3> arr23{};  // 2+3 kann der Compiler auswerten
    const size_t SIZE = 5;         // definiert eine Konstante
    std::array<int, SIZE> arrSC{}; // kann der Compiler verwenden - oft
    size_t size = 7;
    std::array<int,size> arrVar{}; // eine Variable können Sie nicht verwenden
}
```
Const: "Darf nicht zur Laufzeit verändert werden" != "Muss der Compiler zur Übersetzungszeit berechnen können"

Geht nicht:

```cpp
#include <array>
struct Data {
    static const size_t SPAET;            // Konstante deklarieren
    static const size_t FRUEH;            // Konstante deklarieren
};

void func() {
    int x = Data::SPAET;                  // Konstante verwenden
}

const size_t Data::FRUEH = 10;            // Konstante definieren

std::array<int, Data::FRUEH> arrFRUEH {}; // Konstante verwenden
std::array<int, Data::SPAET> arrSPAET {}; // Konstante verwenden - geht nicht
const size_t Data::SPAET = 10;            // Konstante definieren - nach Verwendung

int main() {
    func();
}
```

Mit constexpr prüft der Compiler, ob er es zur Übersetzungszeit berechnen kann. 

```cpp
struct Data {
    static constexpr size_t SPAET; // klappt nicht ohne direkte Initialisierung
    static constexpr size_t FRUEH = 10;
};
constexpr size_t Data::SPAET = 10; // bei constexpr geht Definition nicht wie bei const
```

Nicht deklarieren ohne es auch direkt zu defineiren!

#### un-const mit mutable

Nur in Ausnahmefällen zur Analyse verwenden!

```cpp
#include <iostream>
class Data {
    int value_;
    mutable size_t getCount_{0};
  public:
    explicit Data(int v) : value_{v} { }
    ~Data() {
        std::cout << "get wurde " << getCount_ << "-mal benutzt\n";
    }
    int get() const {
        ++getCount_;
        return value_;
    }
};
int main() {
    Data d{42};
    for(int i=0; i<10; ++i) { d.get(); }
} // Ausgabe: get wurde 10-mal benutzt
```
# Kapitel 15 - Vererbung

## Beziehungen

### Hat-ein-Komposition
Objekt das aus mehreren Onjekten besteht. Das Objekt besitzt seine Komponenten, ist für deren Konstruktion und Destruktion verantwortlich. Ihre Lebensdauer ist durch diese des Objekts beschränkt.
```cpp
class Auto {
    Lenkrad lenkrad;
    std:vector<Rad> räder;
};
```
### Hat-ein-Aggregation
Dinge stehen in Beziehung mit dem Objekt, gehören ihm aber nicht. Die Lebenszeit ist unabhänging.

```cpp
class Auto {
    Garage& garage;
    Person& eigentümer;
};
```
### Ist-ein-Vererbung

Bsp. VwBulli ist-ein Auto
* Der Bulli hat alle Eigenschaften die ein Auto hat
* Auf jedes Objekt auf das die BEschreibung eines Bullis passt, passt auch die eines Autos
* Die Beschreibung (Spezifikation) des Autos ist *schwächer*, die des Bullis ist *genauer*
* Alle Bullis sind Autos aber nicht alle Autos sind Bullis!

## Vererbung in C++

`class Unterklasse : public Basisklasse`

```cpp
class Auto {        //Basis- oder Superklasse
    public:
        Lenkrad lenkrad;
        std:vector<Rad> räder;
};

class VWBulli : public Auto {   //Unter- oder Subklasse
    public:
        Dekoration blümchen;
}
```
Alle Datenfelder und MEthoden der Superklasse hat auchd ie Subklasse
```cpp
VWBulli vw{};
vw.lenkrad;     //geht
vw.blümchen;    //geht auch
auto.blümchen;  //geht nicht
```

### Gemeinsamkeiten finden

Mehr in 15.4

```cpp
//
#include <iostream>  // ostream
#include <iomanip>   // setfill, setw
using std::ostream; using std::setfill; using std::setw;
class Value {
protected: // nicht öffentlich, nur für den eigenen und abgeleiteten Gebrauch
    int value_;
    const unsigned width_;
    Value(int v, unsigned w) // Konstruktor mit zwei Argumenten
      : value_{v}, width_{w} {}
public:
    ostream& print(ostream& os) const;
};
ostream& operator<<(ostream& os, const Value& rechts) {
    return rechts.print(os);
}
ostream& Value::print(ostream& os) const {
    return os << setfill( '0' ) << setw(width_) << value_;
}


class Year : public Value {               // von Klasse Value ableiten
public:
    explicit Year(int v) : Value{v, 4} {} // Basisklasse initialisieren
};
class Month : public Value {
public:
    explicit Month(int v) : Value{v, 2} {}
};
struct Day : public Value {               // class-public entspricht struct
    explicit Day(int v) : Value{v, 2} {}
};


class Date {
    Year year_;
    Month month_ {1};
    Day day_ {1};
public:
    explicit Date(int y) : year_{y} {} // year-01-01
    Date(Year y, Month m, Day d) : year_{y}, month_{m}, day_{d} {}
    ostream& print(ostream& os) const;
};

ostream& Date::print(ostream& os) const {
    return os << year_ << "-" << month_ << "-"  << day_;
}
ostream& operator<<(ostream& os, const Date& rechts) {
    return rechts.print(os);
}
int main() {
    using std::cout;
    Date d1 { Year{2013}, Month{15}, Day{19} };
    cout << d1 << "\n"; // Ausgabe: 2013-15-19
}
```

### Abgeleitete Typen erweitern

Erweitern von Year, dass Ostern dabei ist. 

```cpp
class Date;  // Vorwärtsdeklaration
class Year : public Value {
public:
    explicit Year(int v) : Value{v, 4} {}
    Date ostern() const;            // neue Methode deklarieren
};
// Hier Month, Day und Date deklarieren. Dann:
Date Year::ostern() const {         // neue Methode definieren
    const int y = value_;
    int a = value_/100*1483 - value_/400*2225 + 2613;
    int b = (value_%19*3510 + a/25*319)/330%29;
    b = 148 - b - (value_*5/4 + a - b)%7;
    return Date{Year{value_}, Month{b/31}, Day{b%31 + 1}};
}
int main() {
    using std::cout;
    Year year{2014};
    cout << year.ostern() << "\n";  // Ausgabe: 2014-04-20
}
```
### Methoden überschreiben

Methode so nennen, wie in der Basisklasse und sie somit überschreiben.

### Methoden

* `Basis ba{}; ba.print(cout);` – Basisaufruf
In Basis sind die beiden Methoden print und wert direkt definiert. Hier ist noch keine
andere Klasse beteiligt. wert liefert also acht_ zurück, und 8 wird ausgegeben.
* `Print pr{}; pr.print(cout);` – print überschrieben
In Print ist die Methode print überschrieben. Für pr wird Print::print aufgerufen. Dort
wird wert benötigt. Diese Methode wurde von Basis geerbt. Und Basis::wert liefert
acht_ zurück – also wird 8 ausgegeben.
* `Wert we{}; we.print(cout)` – print aus Basis
we.print muss auf die ererbte Methode Basis::print zurückgreifen. Dort wird nun
die Methode wert() benötigt. Obwohl es die Methode Wert::wert gibt, ist sie in Basis::print aber noch nicht bekannt! **In einer Methode der Basisklasse werden auch
nur Methoden der Basisklasse verwendet**, hier also Basis::wert, was acht_ zurückgibt
und zur Ausgabe von 8 führt.
* `Beides be{}; be.print(cout);` – alles überschrieben
Hier ist es wieder einfach: Es gibt ein Beides::print, das aufgerufen wird. Der Aufruf
von wert greift in der eigenen Methode Beides::wert auf elf_ zurück. Es wird 11 ausgegeben.

```cpp
#include <iostream>
struct Basis {
    int acht_ = 8;
    int wert() const { return acht_; }
    void print(std::ostream& os) const { os << wert() << "\n"; }
};
struct Print : public Basis {
    int neun_ = 9;
    void print(std::ostream& os) const { os << wert() << "\n"; }
};
struct Wert : public Basis {
    int zehn_ = 10;
    int wert() const { return zehn_; }
};
struct Beides : public Basis {
    int elf_ = 11;
    int wert() const { return elf_; }
    void print(std::ostream& os) const { os << wert() << "\n"; }
};

int main() {
    Basis ba{}; ba.print(std::cout);   // Basisaufruf
    Print pr{}; pr.print(std::cout);   // print überschrieben
    Wert we{}; we.print(std::cout);    // print aus Basis
    Beides be{}; be.print(std::cout);  // alles überschrieben
}
```

#### Virtuelle Methoden

Compiler entscheidet zur Laufzeit welche Verion einer Methode gültig ist. 

```cpp
#include <iostream>

using std::ostream; using std::cout;
struct Basis2 {
    int acht_ = 8;
    virtual int wert() const          // virtuelle Methode
        { return acht_; }
    void print(ostream& os) const
        { os << wert() << "\n"; }
};

struct Wert2 : public Basis2 {
    int zehn_ = 10;
    virtual int wert() const override // überschreiben
        { return zehn_; }
};

int main() {
    Wert2 we2{}; we2.print(cout);     // verwenden
}
```
Aufruf von Wert ist nun ein virtueller Methodenaufruf.
-> Override nicht vergessen!

## Konstruktoren in Klassenheirarchien

Vererbung ist nicht wie bei Methoden!



```cpp
class Base {
public:
    Base() {}                 // null-Argument-Konstruktor
    explicit Base(int i) {}   // ein Argument
    Base(int i, int j) {}     // zwei Argumente
    void func() {};           // Methode
};

class Derived : public Base { // kein eigener Konstruktor
};
int main() {
    Base b0{};                // okay, null-Argument-Konstruktor
    Base b1{12};              // okay, ein Argument
    Base b2{6,18};            // okay, zwei Argumente
    Derived d0{};             // okay, Compiler generiert Defaultkonstruktor
    d0.func();                // okay, Methode wird geerbt
    Derived d1{7};            // Fehler: kein Konstruktor für ein Argument definiert
    Derived d2{3,13};         // Fehler: kein Konstruktor für zwei Argumente definiert
}
```

Will man die Konstruktoren der Superklasse explizit vererben nützt man using.

```cpp
class Base {
public:
    Base() {}
    explicit Base(int i) {}
    Base(int i, int j) {}
    void func() {};           // Methode
};
class Derived : public Base {
public:
    using Base::Base;         // Importieren aller Konstruktoren der Elternklasse
};
int main() {
    Derived d0{};             // okay, importiert, nicht mehr generiert
    Derived d1{7};            // okay, wurde importiert
    Derived d2{3,13};         // okay, wurde importiert
}
```
Damit werden alle Kosntruktoren vererbt.


# Kapitel 16 - Der Lebenszyklus von Klassen

## Erzeugung und Zerstörung

Eine Klasseninstand beginnt die Lebenszeit mit der definition und verliert ihre Gültigkeit, wenn ihr Scope verlassen wird. 

Welche Variabeln können eingesetzt werden?
```cpp
struct MeinWert { /* irgendwas */ };
MeinWert globalWert{};                    // globale Klasseninstanz

void funktion(const MeinWert &paramRef) {
    if( /*...*/ ) funktion( /*x1?*/ );    // irgendeine Funktion aufrufen
    MeinWert lokalWert{};                 // lokale Klasseninstanz
}                                         // Ende der Funktion

int main() {
    MeinWert mwert1{};
    funktion( /*x2?*/ );
    funktion( MeinWert{} );               // temporärer Wert
    {
        MeinWert mwert2{};
        funktion( /*x3?*/ );
        MeinWert mwert3{};
    }                                     // Ende des inneren Blocks
    funktion( /*x4?*/ );
    MeinWert mwert4{};
    funktion( /*x5?*/ );
} 
```
* Variable `globalWert` wird beim Verlassen von `main` zerstört
* Variable `paramRef` wird beim Verlassen von `funktion` zerstört
* Variable `lokalWert` wird beim Verlassen von `funktion` zerstört
* Variable `mwert1` wird beim Verlassen von `main` zerstört
* Variable `mwert2` wird beim Verlassen vom `inneren Block` zerstört
* Variable `mwert3` wird beim Verlassen vom `inneren Block` zerstört
* Variable `mwert4` wird beim Verlassen von `main` zerstört
* Variable `MeinWert{}` wird beim `;` am Ende der Zeile zerstört

Wann können welche Variablen in function() verwendet werden?

Variable | x1 | x2 | x3 | x4 | x5
---|---|---|---|---|---
globalWer | ja | ja | ja | ja | ja
paramRef | ja |  |  |  | 
lokalWert |  |  |  |  | 
mwert1 |  | ja | ja | ja | ja
mwert2 |  |  | ja |  | 
mwert3 |  |  |  |  | 
mwert4 |  |  |  |  | ja

### Rvalue und Lvalue
“l-value” refers to a memory location that identifies an object. “r-value” refers to the data value that is stored at some address in memory. References in C++ are nothing but the alternative to the already existing variable. They are declared using the ‘&’ before the name of the variable.

#### lvalue
lvalue simply means an object that has an identifiable location in memory (i.e. having an address).

* In any assignment statement “lvalue” must have the capability to store the data.
* lvalue cannot be a function, expression (like a+b) or a constant (like 3 , 4 , etc.).
 
L-value: “l-value” refers to memory location which identifies an object. l-value may appear as either left hand or right hand side of an assignment operator(=). l-value often represents as identifier. Expressions referring to modifiable locations are called “modifiable l-values“. A modifiable l-value cannot have an array type, an incomplete type, or a type with the const attribute. For structures and unions to be modifiable lvalues, they must not have any members with the const attribute. The name of the identifier denotes a storage location, while the value of the variable is the value stored at that location. An identifier is a modifiable lvalue if it refers to a memory location and if its type is arithmetic, structure, union or pointer. For example, if ptr is a pointer to a storage region, then *ptr is a modifiable l-value that designates the storage region to which ptr points. In C, the concept was renamed as “locator value”, and referred to expressions that locate (designate) objects. The l-value is one of the following:

1. The name of the variable of any type i.e. , an identifier of integral, floating, pointer, structure, or union type.
2. A subscript (\[ ]) expression that does not evaluate to an array.
3. A unary-indirection (*) expression that does not refer to an array
4. An l-value expression in parentheses.
5. A const object (a nonmodifiable l-value).
6. The result of indirection through a pointer, provided that it isn’t a function pointer.
7. The result of member access through pointer(-> or .)

#### r-value
r-value simply means, an object that has no identifiable location in memory (i.e. having an address).

* Anything that is capable of returning a constant expression or value.
* Expression like a+b will return some constant.
R-value: r-value” refers to data value that is stored at some address in memory. A r-value is an expression, that can’t have a value assigned to it, which means r-value can appear on right but not on left hand side of an assignment operator(=). 

#### Verschiebesemantik
Rvalue-Verweise unterstützen die Implementierung der Bewegungssemantik, die die Leistung Ihrer Anwendungen erheblich erhöhen kann. Mithilfe der Verschiebesemantik können Sie Code schreiben, der Ressourcen (wie dynamisch zugeordneten Speicher) von einem Objekt zu einem anderen überträgt. Verschieben der Semantik funktioniert, da die Übertragung von Ressourcen aus temporären Objekten ermöglicht wird: Auf diese, auf die nicht an anderer Stelle im Programm verwiesen werden kann.

Zum Implementieren der Verschiebungssemantik stellen Sie in der Regel einen Konstruktor für Verschiebungen und optional einen Zuweisungsoperator (operator=) für Ihre Klasse bereit. Kopier- und Zuordnungsvorgänge, deren Quellen rvalues sind, nutzen dann automatisch die Verschiebesemantik. Im Gegensatz zum Standardkopiekonstruktor stellt der Compiler keinen Standardverschiebungskonstruktor bereit. Weitere Informationen zum Schreiben und Verwenden eines Konstruktors finden Sie unter Move-Konstruktoren und Verschieben von Zuordnungsoperatoren.




## Destruktor

Destructor is an instance member function which is invoked automatically whenever an object is going to be destroyed. Meaning, a destructor is the last function that is going to be called before an object is destroyed.

* Destructor is also a special member function like constructor. Destructor destroys the class objects created by constructor. 
* Destructor has the same name as their class name preceded by a tiled (~) symbol.
* It is not possible to define more than one destructor. 
* The destructor is only one way to destroy the object create by constructor. Hence destructor can-not be overloaded.
* Destructor neither requires any argument nor returns any value.
* It is automatically called when object goes out of scope. 
* Destructor release memory space occupied by the objects created by constructor.
* In destructor, objects are destroyed in the reverse of an object creation.

```cpp
//Syntax for defining the destructor within the class
~ <class-name>(){}

//Syntax for defining the destructor outside the class
<class-name>:: ~ <class-name>(){}
```

```cpp
#include <string>
#include <iostream>
#include <iomanip>   // setw
using std::cout; using std::setw; using std::string;
struct MeinWert {
    static int zaehler;              // static: existiert nur einmal für alle Instanzen
    int nummer_;                     // Einrücktiefe dieser Instanz für die Ausgabe
    string name_;                    // Name dieser Instanz für die Ausgabe
    explicit MeinWert(string name)
        : nummer_{++zaehler}         // Zähler für Einrücktiefe pro Instanz hochzählen
        , name_{name}                // Name des Objekts für Ausgabe merken
    {
        cout << setw(nummer_) << " " // nummer_ verwenden für Einrücktiefe
             << "Konstruktor " << name_ << "\n"; // Instanzname ausgeben        }
    ~MeinWert() {                    // Destruktor
        cout << setw(nummer_) << " " << "Destruktor " << name_ << "\n";
    }
};
int MeinWert::zaehler = 0;           // Initialisierung der statischen Klassenvariablen



void funktion(const MeinWert &paramRef) {
    MeinWert lokalWert{"lokal"};
}

int main() {
    MeinWert mwert1{"mwert1"};
    funktion( MeinWert{"temp"} );
    funktion( mwert1 );
    {
        MeinWert mwert2{"mwert2"};
    }
}

Ausgabe:
Konstruktor mwert1
    Konstruktor temp
        Konstruktor lokal
        Destruktor lokal
    Destruktor temp
        Konstruktor lokal
        Destruktor lokal
            Konstruktor mwert2
            Destruktor mwert2
Destruktor mwert1
```
Normalerweise ist kein Destruktor nötig. Einige Ressourcen müssen aber weggeräumt werden, wie Rohe Zeiger und C-Datentypen.

Beispiel DB-Zugriff

```cpp
#include <iostream>                // cout
#include "database.hpp"            // Einbinden der fremden Programmierschnittstelle
class Database {
    db_handle_t db_;               // eingepackte Ressource
public:
    Database(const char* filename);
    ~Database();
    int execute(const char* query);
};
Database::Database(const char* filename)
    : db_{db_open(filename)}       // Anfordern der Ressource
    { }
Database::~Database() {
    db_close(db_);                 // Freigeben der Ressource
}
int Database::execute(const char* query) {
    return db_execute(db_, query); // Nutzen der Ressource
}
int main() {
    Database db{ "kunden.dat" };   // Erzeugen des Wrappers
    std::cout << "Anzahl: "<< db.execute("select * from kunden") << "\n";
}  
```
Wird während des Konstruktors eine Exception geworfen, wird der Destruktor nicht aufgerufen!!

When do we need to write a user-defined destructor? 
If we do not write our own destructor in class, compiler creates a default destructor for us. The default destructor works fine unless we have dynamically allocated memory or pointer in class. When a class contains a pointer to memory allocated in class, we should write a destructor to release memory before the class instance is destroyed. This must be done to avoid memory leak.

Can a destructor be virtual? 
Yes, In fact, it is always a good idea to make destructors virtual in base class when we have a virtual function. See virtual destructor for more details. 

## CopyConstructor

A copy constructor is a member function that initializes an object using another object of the same class. A copy constructor has the following general function prototype: 

`ClassName (const ClassName &old_obj);` 

* Copy constructor is used to initialize the members of a newly created object by copying the members of an already existing object.
* Copy constructor takes a reference to an object of the same class as an argument.

          Sample(Sample &t) {id=t.id;}
* The process of initializing members of an object through a copy constructor is known as copy initialization.
* It is also called member-wise initialization because the copy constructor initializes one object with the existing object, both belonging to the same class on a member by member copy basis.
* The copy constructor can be defined explicitly by the programmer. If the programmer does not define the copy constructor, the compiler does it for us.


```cpp
struct MeinWert {
   static int zaehler;
   int nummer_;
   string name_;
   explicit MeinWert(string name) // wie zuvor
      : nummer_{++zaehler} , name_{name}
      { cout << setw(nummer_) << '_'  << "Konstruktor " << name_ << "\n"; }
   MeinWert(const MeinWert &orig) // neuer Kopierkonstruktor
      : nummer_{++zaehler} , name_{orig.name_ + "-Kopie"}
      { cout << setw(nummer_)<<" " << "Kopierkonstruktor " << name_ << "\n"; }
   ~MeinWert() { // wie zuvor
      cout << setw(nummer_)<<" " << "Destruktor " << name_ << "\n";
   }
};
int MeinWert::zaehler = 0;
```



```cpp
// C++ program to demonstrate the working
// of a COPY CONSTRUCTOR
#include <iostream>
using namespace std;
 
class Point {
private:
    int x, y;
 
public:
    Point(int x1, int y1)
    {
        x = x1;
        y = y1;
    }
 
    // Copy constructor
    Point(const Point& p1)
    {
        x = p1.x;
        y = p1.y;
    }
 
    int getX() { return x; }
    int getY() { return y; }
};
 
int main()
{
    Point p1(10, 15); // Normal constructor is called here
    Point p2 = p1; // Copy constructor is called here
 
    // Let us access values assigned by constructors
    cout << "p1.x = " << p1.getX()
         << ", p1.y = " << p1.getY();
    cout << "\np2.x = " << p2.getX()
         << ", p2.y = " << p2.getY();
 
    return 0;
}
//Output
//p1.x = 10, p1.y = 15
//p2.x = 10, p2.y = 15
```



```cpp
// Example: Implicit copy constructor
 
#include<iostream>
using namespace std;
 
class Sample
{         
      int id;
    public:
    void init(int x)
    {
        id=x;   
    }   
    void display()
    {
        cout<<endl<<"ID="<<id;
    }
};
 
int main()
{
    Sample obj1;
    obj1.init(10);
    obj1.display();
     
    Sample obj2(obj1); //or obj2=obj1;
    obj2.display();
    return 0;
}
//Output
//ID=10
//ID=10
```


```cpp
// Example: Explicit copy constructor
 
#include<iostream>
using namespace std;
 
class Sample
{
    int id;
    public:
    void init(int x)
    {
        id=x;   
    }   
    Sample(){}  //default constructor with empty body
     
    Sample(Sample &t)   //copy constructor
    {
        id=t.id;
    }
    void display()
    {
        cout<<endl<<"ID="<<id;
    }
};
int main()
{
    Sample obj1;
    obj1.init(10);
    obj1.display();
     
    Sample obj2(obj1); //or obj2=obj1;    copy constructor called
    obj2.display();
    return 0;
}
//Output
//ID=10
//ID=10
```
When is a user-defined copy constructor needed? 

If we don’t define our own copy constructor, the C++ compiler creates a default copy constructor for each class which does a member-wise copy between objects. The compiler-created copy constructor works fine in general. We need to define our own copy constructor only if an object has pointers or any runtime allocation of the resource like file handle, a network connection, etc.

The default constructor does only shallow copy
![](https://media.geeksforgeeks.org/wp-content/uploads/copy-constructor.png)

Deep copy is possible only with a user-defined copy constructor. In a user-defined copy constructor, we make sure that pointers (or references) of copied objects point to new memory locations.  

![](https://media.geeksforgeeks.org/wp-content/uploads/copy-constructor1.png)

## Zuweisungsoperator
Copy constructor and Assignment operator are similar as they are both used to initialize one object using another object. But, there are some basic differences between them:

Copy constructor |	Assignment operator
---|---
It is called when a new object is created from an existing object, as a copy of the existing object	| This operator is called when an already initialized object is assigned a new value from another existing object. 
It creates a separate memory block for the new object.	|It does not create a separate memory block or new memory space.
It is an overloaded constructor.	|It is a bitwise operator. 
C++ compiler implicitly provides a copy constructor, if no copy constructor is defined in the class.	| A bitwise copy gets created, if the Assignment operator is not overloaded. 
Syntax: className(const className &obj) {// body } | Syntax: className obj1, obj2; obj2 = obj1;

```cpp

// CPP Program to demonstrate the use of copy constructor
// and assignment operator
#include <iostream>
#include <stdio.h>
using namespace std;
 
class Test {
public:
    Test() {}
    Test(const Test& t)
    {
        cout << "Copy constructor called " << endl;
    }
 
    Test& operator=(const Test& t)
    {
        cout << "Assignment operator called " << endl;
        return *this;
    }
};
 
// Driver code
int main()
{
    Test t1, t2;
    t2 = t1;
    Test t3 = t1;
    getchar();
    return 0;
}
//Output
//Assignment operator called 
//Copy constructor called 
```

## Bewegungskonstruktoren und Bewegungszuweisungsoperatoren

In diesem Thema wird beschrieben, wie Sie einen Konstruktor und einen Verschiebungszuweisungsoperator für eine C++-Klasse schreiben. Ein Konstruktor zum Verschieben ermöglicht es den Ressourcen, die einem rvalue-Objekt gehören, in einen lvalue zu verschieben, ohne zu kopieren. Weitere Informationen zur Verschiebungssemantik finden Sie unter Rvalue Reference Declarator: &&.

Die Kopiersteuerung der Klasse definiert die Kernfunktionen, die erforderlich sind, um festzulegen, was passiert, wenn das Klassenobjekt kopiert, verschoben, zugewiesen oder zerstört wird. Diese Funktionen haben eine spezielle C++-Nomenklatur, wie die Kopierkonstruktor- und Bewegungskonstruktor-Funktionen definieren, wie ein Objekt mit einem anderen Objekt desselben Typs initialisiert wird. Kopierzuweisungs- und Verschiebezuweisungsfunktionen definieren, wie das Objekt demselben Objekttyp zugewiesen wird. Destructor behandelt die Routine, die ausgeführt wird, wenn das Objekt den Gültigkeitsbereich verlässt. Einige dieser Funktionen werden höchstwahrscheinlich vom Benutzer definiert, aber wenn nicht, erstellt der Compiler selbst die Standardprototypen.

Wenn das Klassenobjekt den dynamischen Speicher verwaltet und die Daten ziemlich groß sind, können die Kopiervorgänge ziemlich rechenintensiv sein. Sie können erhebliche Ressourcen verbrauchen, die die Leistung beeinträchtigen. Daher verwenden sie häufig einen Bewegungskonstruktor, um dynamische Daten neu zuzuweisen, ohne sie an die neue Speicherstelle zu kopieren. Dies wird erreicht, indem die Zeiger des alten Objekts den entsprechenden Mitgliedern des neu initialisierten oder zugewiesenen Objekts zugewiesen werden. Beachten Sie, dass das folgende Beispiel den move-Konstruktor nicht enthält und mehrere Aufrufe des Kopierkonstruktors verursacht, der an den Standardkonstruktor delegiert.
```cpp
#include <iostream>
#include <vector>

using std::cout; using std::endl;
using std::vector; using std::cin;

class MyClass {
private:
    int* data;

public:
    explicit MyClass(int d) {
        data = new int;
        *data = d;
        cout << "Constructor 1 is called" << endl;
    };

    MyClass(const MyClass& source): MyClass(*source.data) {
        cout << "Copy Constructor is called " << endl;
    }

    int getData() const {
        return *data;
    }

    ~MyClass() {
        delete data;
        cout << "Destructor is called" << endl;
    }

};

void printVec(const vector<MyClass> &vec) {

    for (const auto & i : vec) {
        cout << i.getData() << " ";
    }
    cout << endl;
}

int main() {
    vector<MyClass> vec;

    vec.push_back(MyClass(10));
    vec.push_back(MyClass(11));
    printVec(vec);
    cout << "------------------" << endl;

    return EXIT_SUCCESS;
}
//Ausgabe:
//
//Constructor 1 is called
//Constructor 1 is called
//Copy Constructor is called
//Destructor is called
//Constructor 1 is called
//Constructor 1 is called
//Copy Constructor is called
//Constructor 1 is called
//Copy Constructor is called
//Destructor is called
//Destructor is called
//10 11
//------------------
//Destructor is called
//Destructor is called
```
Sobald wir einen Bewegungskonstruktor definieren, der im Allgemeinen eine r-Wert-Referenz als erstes Argument annehmen sollte (mit &&-Notation gekennzeichnet), wird die Vektorinitialisierung effizienter, wenn die neuen Elemente vom Typ MyClass hinzugefügt werden. Da der Move-Konstruktor keinen neuen Speicher zuweist und die Position des übergebenen Objekts übernimmt, muss man den Membern des vorherigen Objekts nullptr zuweisen. Andernfalls versucht der Destruktor, denselben Speicherort zweimal freizugeben, und löst den Laufzeitfehler aus.


```cpp
#include <iostream>
#include <vector>

using std::cout; using std::endl;
using std::vector; using std::cin;

class MyClass {
private:
    int* data;

public:
    explicit MyClass(int d) {
        data = new int;
        *data = d;
        cout << "Constructor 1 is called" << endl;
    };

    MyClass(const MyClass& source): MyClass(*source.data) {
        cout << "Copy Constructor is called " << endl;
    }

    MyClass(MyClass&& source) noexcept : data(source.data) {
        source.data = nullptr;
        cout << "Move Constructor is called" << endl;
    }

    int getData() const {
        return *data;
    }

    ~MyClass() {
        delete data;
        cout << "Destructor is called" << endl;
    }

};

void printVec(const vector<MyClass> &vec) {

    for (const auto & i : vec) {
        cout << i.getData() << " ";
    }
    cout << endl;
}

int main() {
    vector<MyClass> vec;

    vec.push_back(MyClass(10));
    vec.push_back(MyClass(11));
    printVec(vec);
    cout << "------------------" << endl;

    return EXIT_SUCCESS;
}
//Ausgabe:
//
//Constructor 1 is called
//Move Constructor is called
//Destructor is called
//Constructor 1 is called
//Move Constructor is called
//Move Constructor is called
//Destructor is called
//Destructor is called
//10 11
//------------------
//Destructor is called
//Destructor is called
```
## Was der Compiler generiert

* **Strandardkontruktor:** `C()` wird generiert, wenn kein Konstruktor deklariert ist
* **Der Destruktor:** `~C()` wird generiert, wenn kein Destruktor deklariert ist
* **Der Kopierkonstruktor** `C(const C&)` wird generiert, wenn keine Verschiebeoperation deklariert ist
* **Die Kopierzuweisung** `C& operator=(const c&)` wird generiert, wenn keine Verschiebeoperation deklariert ist
* **Der Verschiebekonstruktor** `C(C&&)` wird generiert, wenn keine Kopieroperation deklariert ist und alle Elemente verschoben werden können
* **Der Verschiebeoperator** `C& operator=(C&&)` wird generiert, wenn keine Kopieroperation deklariert ist und alle Elemente verschoben werden können

## Überladen von Operatoren

In C++, we can make operators work for user-defined classes. This means C++ has the ability to provide the operators with a special meaning for a data type, this ability is known as operator overloading. For example, we can overload an operator ‘+’ in a class like String so that we can concatenate two strings by just using +. Other example classes where arithmetic operators may be overloaded are Complex Numbers, Fractional Numbers, Big Integer, etc.

Operator overloading is a compile time polymorphism. It is an idea of giving special meaning to an existing operator in C++ without changing their original meaning.



```cpp
class A{
};

int main(){
      A   a1,a2,a3;
      a3= a1 + a2;
      return 0;
}
```
In this example, we have 3 variables “a1”, “a2” and “a3” of type “class A”. Here we are trying to add two objects “a1” and “a2”, which are of user defined type i.e. of type “class A” using “+” operator. This is not allowed, because addition operator “+” is predefined to operate only on built-in data types. But here, “class A” is a user defined type, so compiler generate an error. This is where, the concept of “Operator overloading” comes in. 
Now, if the user wants to make the operator “+” to add two class objects, the user has to redefine the meaning of “+” operator such that it adds two class objects. This is done by using the concept “Operator overloading”. So the main idea behind “Operator overloading” is to use c++ operators with class variables or class objects. Redefining the meaning of operators really does not change their original meaning; instead they have been given additional meaning along with their existing ones.


```cpp
#include<iostream>
using namespace std;
 
class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i = 0) {real = r;   imag = i;}
     
    // This is automatically called when '+' is used with
    // between two Complex objects
    Complex operator + (Complex const &obj) {
         Complex res;
         res.real = real + obj.real;
         res.imag = imag + obj.imag;
         return res;
    }
    void print() { cout << real << " + i" << imag << '\n'; }
};
 
int main()
{
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2;
    c3.print();
}
```
What is the difference between operator functions and normal functions? 
Operator functions are the same as normal functions. The only differences are, the name of an operator function is always the operator keyword followed by the symbol of the operator and operator functions are called when the corresponding operator is used. 

### Operator s that can be overloaded
We can overload

* Uniary operators
* Binary operators
* Special operators ( [ ], () etc)
 
### Operators that cannot be overloaded 

They are

* Scope resolution operator ::
* Member selection operator                               
* Member selection through *                               
 
Pointer to member variable

* Conditional operator ? :
* Sizeof operator sizeof()
 
**Operator that can be overloaded**

1. Binary Arithmetic     ->     +, -, *, /, %
2. Unary Arithmetic     ->     +, -, ++, —
3. Assignment     ->     =, +=,*=, /=,-=, %=
4. Bit- wise      ->     & , | , << , >> , ~ , ^
5. De-referencing     ->     (->)
6. Dynamic memory allocation and De-allocation     ->     New, delete 
7. Subscript     ->     \[ ]
8. Function call     ->     ()
9. Logical      ->     &,  | |, !
10. Relational     ->     >, < , = =, <=, >=

Why can’t the above-stated operators be overloaded?

1. sizeof – This returns the size of the object or datatype entered as the operand. This is evaluated by the compiler and cannot be evaluated during runtime. The proper incrementing of a pointer in an array of objects relies on the sieof operator implicitly. Altering its meaning using overloading would cause a fundamental part of the language to collapse.

2. typeid: This provides a CPP program with the ability to recover the actual derived type of the object referred to by a pointer or reference. For this operator, the whole point is to uniquely identify a type. If we want to make a user-defined type to ‘look’ like another type, polymorphism can be used but the meaning of the typeid operator must remain unaltered, or else serious issues could arise.

3. Scope resolution (::): This helps identify and specify the context to which an identifier refers by specifying a namespace. It is completely evaluated at runtime and works on names rather than values. The operands of scope resolution are note expressions with data types and CPP has no syntax for capturing them if it were overloaded. So it is syntactically impossible to overload this operator.

4. Class member access operators (.(dot), .* (pointer to member operator)): The importance and implicit use of class member access operators can be understood through the following example:

```cpp
#include <iostream>
using namespace std;

class ComplexNumber{
private:
int real;
int imaginary;
public:
ComplexNumber(int real, int imaginary){
	this->real = real;
	this->imaginary = imaginary;
}
void print(){
	cout<<real<<" + i"<<imaginary;
}
ComplexNumber operator+ (ComplexNumber c2){
	ComplexNumber c3(0,0);
	c3.real = this->real+c2.real;
	c3.imaginary = this->imaginary + c2.imaginary;
	return c3;
}
};
int main() {
	ComplexNumber c1(3,5);
	ComplexNumber c2(2,4);
	ComplexNumber c3 = c1 + c2;
	c3.print();
	return 0;
}
```
The statement ComplexNumber c3 = c1 + c2; is internally translated as ComplexNumber c3 = c1.operator+ (c2); in order to invoke the operator function. The argument c1 is implicitly passed using the ‘.’ operator. The next statement also makes use of the dot operator to access the member function print and pass c3 as an argument. Thus, in order to ensure a reliable and non-ambiguous system of accessing class members, the predefined mechanism using class member access operators is absolutely essential. Besides, these operators also work on names and not values and there is no provision (syntactically) to overload them.

5. Ternary or conditional (?:): The ternary or conditional operator is a shorthand representation of an if-else statement. In the operator, the true/false expressions are only evaluated on the basis of the truth value of the conditional expression. 

conditional statement ? expression1 (if statement is TRUE) : expression2 (else)

A function overloading the ternary operator for a class say ABC using the definition

ABC operator ?: (bool condition, ABC trueExpr, ABC falseExpr);

would not be able to guarantee that only one of the expressions was evaluated. Thus, ternary operator cannot be overloaded.

#### Important points about operator overloading 
1) For operator overloading to work, at least one of the operands must be a user-defined class object.
2) Assignment Operator: Compiler automatically creates a default assignment operator with every class. The default assignment operator does assign all members of the right side to the left side and works fine in most cases (this behaviour is the same as the copy constructor). See this for more details. 
3) Conversion Operator: We can also write conversion operators that can be used to convert one type to another type. 

## Besondere Klassenformen

### Abstrakte Klassen und Methoden

Methoden ohne Implementierung

```cpp
#include <string>
#include <iostream>
using std::string; using std::ostream;

class Shape {
    string color_;
public:
    virtual double calcArea() const = 0; // pur virtuelle Methode
    string getColor() const { return color_; }
    void setColor(const string& color) { color_ = color; }
    virtual ~Shape() {}
};

class Square : public Shape {
    double len_;
public:
    explicit Square(double len) : len_{len} {}
    double calcArea() const override { return len_*len_; }
};

class Circle : public Shape {
    double rad_;
public:
    explicit Circle(double rad) : rad_{rad} {}
    double calcArea() const override { return 3.1415*rad_*rad_; }
};

struct Calculator {
    Shape& shape_;
    Calculator(Shape& shape) : shape_{shape} { }
    void run(ostream& os) const {
        os << "The area of the shape is " << shape_.calcArea() << "\n";
    }
};

int main() {
    Square quadrat {5.0};
    Calculator ti { quadrat };
    ti.run(std::cout); // Ausgabe: The area of the shape is 25
}
```
Basisklasse Shape weiss das mit calcArea die Flächen von Formen berechnet werden, weiss aber nicht wie. Daher ist sie pur virtuell und mit =0 markiert.

Klassen mit mindestens einer pur virtuellen Methode sind abstrakte Klassen.
Klassen die von einer abstrakten erben, können nur instanziert werden, wenn alle virtuellen Methoden überschrieben werden.

## Enum

```cpp
enum class Ampelfarbe {
    ROT, GELB, GRÜN
};
```
# Kapitel 18 - Spezielles für Klassen

## friend Klassen

Ausnahmeregel für bestimmte Klassen


```cpp
#include <iostream>
class Schrauber;
class Ding {
    int value_; // privat
public:
    explicit Ding(int value) : value_{value} {}
    void inc() { ++value_; }
    std::ostream& print(std::ostream& os) const { return os<<value_; }
    friend class Schrauber;
};
class Schrauber {
    const Ding &ding_;
public:
    explicit Schrauber(const Ding &ding) : ding_{ding} {}
    auto dingWert() const {
        return ding_.value_;                   // Zugriff auf Privates aus Ding
    }
};
int main() {
    Ding ding{45};
    ding.print(std::cout) << '\n';             // Ausgabe: 45
    Schrauber schrauber{ding};
    ding.inc(); // internen Wert verändern
    std::cout << schrauber.dingWert() << '\n'; // Ausgabe: 46
}
```
Zu beachten:
* Namensraum muss vorher bekannt sein
* Freundschaft vererbt sich nicht.

## Non public Vererbung


```cpp
class Base {
public:
    int xPublic = 1;
protected:
    int xProtected = 2;
private:
    int xPrivate = 3;
};
class DerivedPublic : public Base {
    // xPublic wird 'public'
    // xProtected wird 'protected'
    // xPrivate ist hier nicht sichtbar
};
class DerivedProtected : protected Base {
    // xPublic wird 'protected'
    // xProtected wird 'protected'
    // xPrivate ist hier nicht sichtbar
};
class DerivedPrivate : private Base { // oder wenn nichts angegeben
    // xPublic wird 'private'
    // xProtected wird 'private'
    // xPrivate ist hier nicht sichtbar
};
```

-> Die Sichtbarkeit kann so weiter eingeschränkt werden.

## Signaturklassen

Klasse mit nur virtuellen Methoden, wie Interfaces in Java. 


```cpp
struct Driver {
    virtual void init() = 0;
    virtual void done() = 0;
    virtual bool send(const char* data, unsigned len) = 0;
};


#include <iostream>
using std::cout;

struct KeyboardDriver : public Driver {
    void init() override { cout << "Init Keyboard\n"; }
    void done() override { cout << "Done Keyboard\n"; }
    bool send(const char* data, unsigned int len) override {
        cout << "sending " << len << " bytes\n";
        return true;
    }
};

struct Computer {
    Driver &driver_;
    explicit Computer(Driver &driver) : driver_{driver} {
        driver_.init();
    }
    void run() {
        driver_.send("Hello", 5);
    }
    ~Computer() {
        driver_.done();
    }
    Computer(const Computer&) = delete;
};

int main() {
    KeyboardDriver keyboard {};
    Computer computer(keyboard); // Ausgabe: Init Keyboard
    computer.run();              // Ausgabe: sending 5 bytes
}                                // Ausgabe: Done Keyboard
```

* Bei multipler Vererbung

## Multiple Vererbung

Mit Vorsicht nutzen!

```cpp
using std::cout;
class Saeugetier {
public:
    void gebaere() { cout << "Geburt!\n"; }
};
class Fliegend {
public:
    void fliege() { cout << "Flug!\n"; }
};
class Fledermaus: public Saeugetier, public Fliegend {
public:
    void rufe() { cout << "Ultraschall!\n"; }
};
int main() {
    Fledermaus bruce{};
    bruce.gebaere();       // Ausgabe: Geburt!
    bruce.fliege();        // Ausgabe: Flug!
    bruce.rufe();          // Ausgabe: Ultraschall!
}
```
-> Achtung bei Pointern 18.4.2



# Kapitel 20 - Zeiger

Pointers store an address

```cpp
int n = 5;
int *ptr = &n;  //Give ptr addres of n

//Dereference
*ptr;       //value of n

//Change value
*ptr = 15;
```

To access address of a variable to a pointer, we use the unary operator & (ampersand) that returns the address of that variable. For example &x gives us address of variable x. 


```cpp
int main(){
    int x;
    printf("%p", &x);       // Prints address of x
    return 0;
}
```
One more operator is unary * (Asterisk) which is used for two things : 

To declare a pointer variable: When a pointer variable is declared in C/C++, there must be a * before its name. 
```cpp
int main() {
    int x = 10;
    int *ptr; 
    // & operator before x is used to get address
    // of x. The address of x is assigned to ptr.
    ptr = &x;
    return 0;
}
```
To access the value stored in the address we use the unary operator (*) that returns the value of the variable located at the address specified by its operand. This is also called Dereferencing.
```cpp
#include <iostream>
using namespace std;
 
int main() {
    // A normal integer variable
    int Var = 10;
 
    // A pointer variable that holds address of var.
    int *ptr = &Var;
 
    // This line prints value at address stored in ptr.
    // Value stored is value of variable "var"
    cout << "Value of Var = "<< *ptr << endl;
 
    // The output of this line may be different in different
    // runs even on same machine.
    cout << "Address of Var = " <<  ptr << endl;
 
    // We can also use ptr as lvalue (Left hand
    // side of assignment)
    *ptr = 20; // Value at address is now 20
 
    // This prints 20
    cout << "After doing *ptr = 20, *ptr is "<< *ptr << endl;
 
    return 0;
}
 
//Output : 
//Value of Var = 10
//Address of Var = 0x7fffa057dd4
//After doing *ptr = 20, *ptr is 20
```

![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/How-Pointer-Works-In-C.png)

```cpp
#include <vector>
#include <iostream>
using std::vector; using std::cout; using std::ostream;
ostream& printVector(ostream& os, const vector<int> &arg) { // Hilfsfunktion
    for(int w : arg) os << w << " "; return os;
}
int main() {
    vector<int> werte{ };
    werte.reserve(50);                      // Platz für 50 Werte garantieren
    int *groesstes = nullptr;               // mit besonderem Wert initialisieren
    for(int w : { 20, 2, 30, 15, 81, 104, 70, 2, }) {
        werte.push_back(w);
        if(!groesstes || *groesstes < w ) { // dereferenzieren zum Wert
            groesstes = &(werte.back());    // neue Adresse merken; deshalb nicht '*'
        }
    }
    printVector(cout, werte) << "\n";       // Ausgabe: 20 2 30 15 81 104 70 2
    // groesstes enthält nun die Adresse der 104:
    *groesstes = -999;                      // dereferenzieren; also Wert überschreiben
    printVector(cout, werte) << "\n";       // Ausgabe: 20 2 30 15 81 @MINUS@999 70 2
}
```
## Pointer Expressions and Pointer Arithmetic 
A limited set of arithmetic operations can be performed on pointers. A pointer may be: 
 
* incremented ( ++ )
* decremented ( —- )
* an integer may be added to a pointer ( + or += )
* an integer may be subtracted from a pointer ( – or -= )
* 
Pointer arithmetic is meaningless unless performed on an array. 
Note : Pointers contain addresses. Adding two addresses makes no sense, because there is no idea what it would point to. Subtracting two addresses lets you compute the offset between these two addresses.


```cpp
// C++ program to illustrate Pointer Arithmetic
// in C/C++
#include <bits/stdc++.h>
 
// Driver program
int main() {
    // Declare an array
    int v[3] = {10, 100, 200};
 
    // Declare pointer variable
    int *ptr;
 
    // Assign the address of v[0] to ptr
    ptr = v;
 
    for (int i = 0; i < 3; i++) {
        printf("Value of *ptr = %d\n", *ptr);
        printf("Value of ptr = %p\n\n", ptr);
 
        // Increment pointer ptr by 1
        ptr++;
    }
}

//Output:
//Value of *ptr = 10
//Value of ptr = 0x7ffcae30c710
//Value of *ptr = 100
//Value of ptr = 0x7ffcae30c714
//Value of *ptr = 200
//Value of ptr = 0x7ffcae30c718
```
### Array Name as Pointers 
An array name acts like a pointer constant. The value of this pointer constant is the address of the first element. 
For example, if we have an array named val then val and &val[0] can be used interchangeably. 

### Pointers and Multidimensional Arrays 
Consider pointer notation for the two-dimensional numeric arrays. consider the following declaration 
 

`int nums[2][3]  =  { {16, 18, 20}, {25, 26, 27} };`

In general, `nums[i][j]` is equivalent to `*(*(nums+i)+j)`

 

Pointer Notation	|Array Notation	|Value
---|---|---
*(*nums)	|nums[0][0]|16
*(*nums + 1)	|nums[0][1]|	18
*(*nums + 2)	|nums[0][2]	|20
*(*(nums + 1))|	nums[1][0]|	25
*(*(nums + 1) + 1)	|nums[1][1]|	26
*(*(nums + 1) + 2)|	nums[1][2]|	27

## Nullpointer
Initialisieren mit "Zeigt nirgendwo hin"

`int* grössterWert = nullprt;`

## Heap

Dynamische Erzeugung eines Objekts. 

Schlüsselwort *new* liefert einen rohen Zeiger. -> In smarten Pointer packen!
Muss explizit mit *delete* gelöscht werden.

### Geeks for Geeks
Heap data structure can be implemented in a range using STL which allows faster input into heap and retrieval of a number always results in the largest number i.e. largest number of the remaining numbers is popped out each time. Other numbers of the heap are arranged depending upon the implementation.

Operations on heap :

1. make_heap() :- This function is used to convert a range in a container to a heap.

2. front() :- This function displays the first element of heap which is the maximum number.

```cpp
// C++ code to demonstrate the working of
// make_heap(), front()
#include<bits/stdc++.h>
using namespace std;
int main(){
	
	// Initializing a vector
	vector<int> v1 = {20, 30, 40, 25, 15};
	
	// Converting vector into a heap
	// using make_heap()
	make_heap(v1.begin(), v1.end());
	
	// Displaying the maximum element of heap
	// using front()
	cout << "The maximum element of heap is : ";
	cout << v1.front() << endl;
	
	return 0;
}
```
3. push_heap() :- This function is used to insert elements into heap. The size of the heap is increased by 1. New element is placed appropriately in the heap.

4. pop_heap() :- This function is used to delete the maximum element of the heap. The size of heap is decreased by 1. The heap elements are reorganised accordingly after this operation.

```cpp
// C++ code to demonstrate the working of
// push_heap() and pop_heap()
#include<bits/stdc++.h>
using namespace std;
int main(){
	
	// Initializing a vector
	vector<int> v1 = {20, 30, 40, 25, 15};
	
	// Converting vector into a heap
	// using make_heap()
	make_heap(v1.begin(), v1.end());
	
	// Displaying the maximum element of heap
	// using front()
	cout << "The maximum element of heap is : ";
	cout << v1.front() << endl;
	
	// using push_back() to enter element
	// in vector
	v1.push_back(50);
	
	// using push_heap() to reorder elements
	push_heap(v1.begin(), v1.end());
	
	// Displaying the maximum element of heap
	// using front()
	cout << "The maximum element of heap after push is : ";
	cout << v1.front() << endl;
	
	// using pop_heap() to delete maximum element
	pop_heap(v1.begin(), v1.end());
	v1.pop_back();
	
	// Displaying the maximum element of heap
	// using front()
	cout << "The maximum element of heap after pop is : ";
	cout << v1.front() << endl;
	
	return 0;
}
```
5. sort_heap() :- This function is used to sort the heap. After this operation, the container is no longer a heap.


```cpp
// C++ code to demonstrate the working of
// sort_heap()
#include<bits/stdc++.h>
using namespace std;
int main(){
	
	// Initializing a vector
	vector<int> v1 = {20, 30, 40, 25, 15};
	
	// Converting vector into a heap
	// using make_heap()
	make_heap(v1.begin(), v1.end());
	
	// Displaying heap elements
	cout << "The heap elements are : ";
	for (int &x : v1)
	cout << x << " ";
	cout << endl;
	
	// sorting heap using sort_heap()
	sort_heap(v1.begin(), v1.end());
	
	// Displaying heap elements
	cout << "The heap elements after sorting are : ";
	for (int &x : v1)
	cout << x << " ";
	
	return 0;
}
```
6. is_heap() :- This function is used to check whether the container is heap or not. Generally, in most implementations, the reverse sorted container is considered as heap. Returns true if container is heap else returns false.

7. is_heap_until() :- This function returns the iterator to the position till the container is the heap. Generally, in most implementations, the reverse sorted container is considered as heap.


```cpp
// C++ code to demonstrate the working of
// is_heap() and is_heap_until()
#include<bits/stdc++.h>
using namespace std;
int main(){
	
	// Initializing a vector
	vector<int> v1 = {40, 30, 25, 35, 15};
	
	// Declaring heap iterator
	vector<int>::iterator it1;
	
	// Checking if container is heap
	// using is_heap()
	is_heap(v1.begin(), v1.end())?
	cout << "The container is heap ":
	cout << "The container is not heap";
	cout << endl;
	
	// using is_heap_until() to check position
	// till which container is heap
	auto it = is_heap_until(v1.begin(), v1.end());
	
	// Displaying heap range elements
	cout << "The heap elements in container are : ";
	for (it1=v1.begin(); it1!=it; it1++)
	cout << *it1 << " ";
	
	return 0;
}
```

## Smarte Pointer

Vollwertige Klassen mit Konstruktor und Destruktor.

* auto_ptr -> Deprecated
* unique_ptr: Besitzt den rohen Zeiger, nicht kopierbar, verschiebbar
* shared_ptr: besitzt den rohen Zeiger, nicht unbedingt alleine, kopieren ergibt zwei shared pointer die denselben rohen Zeiger verwalten, beim Entfernen des letzten shared prt wird der rohe Zeiger entfernt.
* weak_ptr: kleiner Bruder von shared ptr

### auto_ptr
This class template is deprecated as of C++11. unique_ptr is a new facility with a similar functionality, but with improved security.
auto_ptr is a smart pointer that manages an object obtained via new expression and deletes that object when auto_ptr itself is destroyed.
An object when described using auto_ptr class it stores a pointer to a single allocated object which ensures that when it goes out of scope, the object it points to must get automatically destroyed. It is based on exclusive ownership model i.e. two pointers of the same type can’t point to the same resource at the same time. As shown in the below program, copying or assigning of pointers changes the ownership i.e. source pointer has to give ownership to the destination pointer.

```cpp
// C++ program to illustrate the use of auto_ptr
#include <iostream>
#include <memory>
using namespace std;

class A {
public:
	void show() { cout << "A::show()" << endl; }
};

int main(){
	// p1 is an auto_ptr of type A
	auto_ptr<A> p1(new A);
	p1->show();

	// returns the memory address of p1
	cout << p1.get() << endl;

	// copy constructor called, this makes p1 empty.
	auto_ptr<A> p2(p1);
	p2->show();

	// p1 is empty now
	cout << p1.get() << endl;

	// p1 gets copied in p2
	cout << p2.get() << endl;

	return 0;
}

Output:

A::show()
0x1b42c20
A::show()
0          
0x1b42c20
```
The copy constructor and the assignment operator of auto_ptr do not actually copy the stored pointer instead they transfer it, leaving the first auto_ptr object empty. This was one way to implement strict ownership so that only one auto_ptr object can own the pointer at any given time i.e. auto_ptr should not be used where copy semantics are needed.

Why is auto_ptr deprecated?
It takes ownership of the pointer in a way that no two pointers should contain the same object. Assignment transfers ownership and resets the rvalue auto pointer to a null pointer. Thus, they can’t be used within STL containers due to the aforementioned inability to be copied.

### unique_ptr

* Eindeutiger Besitzer zu jedem Zeitpunkt. 
* Verlässt nie den Gültigkeitsbereich in dem er definiert wurde

```cpp
#include <memory>                        // unique_ptr
#include <string>
#include <iostream>
using std::unique_ptr; using std::string;
class Component { };                     // Dummy-Fensterhierarchie
class Label : public Component { };
class Textfield : public Component { };
class Button : public Component {
public:
    int id_; // ID zur Unterscheidung der Buttons
    explicit Button(int id) : id_{id} {}
};
class Window { };
class MyDialog : public Window {        //Unique_ptr Datenfelder gehören der Klasse MyDialog und 
    string title_;                      //werden beim Zerstören von dialog in showDialog entfernt.
    unique_ptr<Label> lblVorname_{new Label{}};         // lauter Datenfelder
    unique_ptr<Textfield> txtVorname_{new Textfield{}}; // ... an die Lebensdauer
    unique_ptr<Label> lblNachname_{new Label{}};        // ... der Klasse gebunden
    unique_ptr<Textfield> txtNachname_{new Textfield{}};
    unique_ptr<Button> btnOk_{new Button{1}};
    unique_ptr<Button> btnAbbrechen_{new Button{2}};
public:
    explicit MyDialog(const string& title) : title_{title} {}
    unique_ptr<Button> showModal()         //gibt bestehenden Wert zurück
        { return std::move(btnOk_); }    // Platzhalter-Code; OK gedrückt, move -> ja Compiler,d as ist ein temp Wert
};
unique_ptr<MyDialog> createDialog() {
    return unique_ptr<MyDialog>{ // temporärer Wert, unique Pointer wird verschoben, bzw sein Inhalt
                                 //transferiert rohen Zeiger des erzeugtenTempwertes (innen) in unique_ptr<MyDialog> (aussen)
        new MyDialog{"Bitte Namen eingeben"}};
}
int showDialog() {
    unique_ptr<MyDialog> dialog = createDialog();       // lokale Variable
    unique_ptr<Button> gedrueckt = dialog->showModal(); // Rückgabewert, bestehender Wert
    return gedrueckt->id_;
}
int main() {
    int gedrueckt_id = showDialog();
    if(gedrueckt_id == 1) {
        std::cout << "Danke, dass Sie OK gedrueckt haben\n";
    }
}
```

* Funktion kann unique_ptr als Wert zurückliefern, das verpackte Objekt mit *new* innerhalb der Funktion erzeugen "Factory"
* Referenz auf unique_ptr nur zurückgeben, wenn er schon existiert



#### std::move
Verschiebt selber nicht, erlaubt nur, dass verschoben werden kann.


#### Geeks for Geeks

std::unique_ptr was developed in C++11 as a replacement for std::auto_ptr.
unique_ptr is a new facility with similar functionality, but with improved security (no fake copy assignments), added features (deleters) and support for arrays. It is a container for raw pointers. It explicitly prevents copying of its contained pointer as would happen with normal assignment i.e. it allows exactly one owner of the underlying pointer.

So, when using unique_ptr there can only be at most one unique_ptr at any one resource and when that unique_ptr is destroyed, the resource is automatically claimed. Also, since there can only be one unique_ptr to any resource, so any attempt to make a copy of unique_ptr will cause a compile-time error.
```cpp
 unique_ptr<A> ptr1 (new A);

 // Error: can't copy unique_ptr
 unique_ptr<A> ptr2 = ptr1;  
```
But, unique_ptr can be moved using the new move semantics i.e. using std::move() function to transfer ownership of the contained pointer to another unique_ptr.
```cpp
// Works, resource now stored in ptr2
unique_ptr<A> ptr2 = move(ptr1); 
```
So, it’s best to use unique_ptr when we want a single pointer to an object that will be reclaimed when that single pointer is destroyed.

```cpp
// C++ program to illustrate the use of unique_ptr
#include <iostream>
#include <memory>
using namespace std;

class A {
public:
	void show()
	{
		cout << "A::show()" << endl;
	}
};

int main()
{
	unique_ptr<A> p1(new A);
	p1->show();

	// returns the memory address of p1
	cout << p1.get() << endl;

	// transfers ownership to p2
	unique_ptr<A> p2 = move(p1);
	p2->show();
	cout << p1.get() << endl;
	cout << p2.get() << endl;

	// transfers ownership to p3
	unique_ptr<A> p3 = move(p2);
	p3->show();
	cout << p1.get() << endl;
	cout << p2.get() << endl;
	cout << p3.get() << endl;

	return 0;
}

Output:

A::show()
0x1c4ac20
A::show()
0          // NULL
0x1c4ac20
A::show()
0          // NULL
0          // NULL
0x1c4ac20
```
The below code returns a resource and if we don’t explicitly capture the return value, the resource will be cleaned up. If we do, then we have exclusive ownership of that resource. In this way, we can think of unique_ptr as safer and better replacement of auto_ptr.
```cpp
unique_ptr<A> fun()
{
    unique_ptr<A> ptr(new A);

    /* ...
       ... */

    return ptr;
}
```
#### When to use unique_ptr?

Use unique_ptr when you want to have single ownership(Exclusive) of the resource. Only one unique_ptr can point to one resource. Since there can be one unique_ptr for single resource its not possible to copy one unique_ptr to another.

### shared_ptr

Teilt Objekt das er besitzt mit anderen shared und weak_ptr. Das verpackte Objekt existiert nur ein mal.

```cpp
#include <vector>
#include <iostream>
#include <memory>                    // shared_ptr
#include <random>                    // uniform_int_distribution, random_device
namespace {                          // Beginn des anonymen Namensraums
using std::shared_ptr; using std::make_shared;
using std::vector; using std::cout;

struct Asteroid {
    int points_ = 100;
    int structure_ = 10;
};
struct Ship {
    shared_ptr<Asteroid> firedLastOn_{};
    int score_ = 0;
    int firepower = 1;
    bool fireUpon(shared_ptr<Asteroid> a);
};

struct GameBoard {
    vector<shared_ptr<Asteroid>> asteroids_;
    explicit GameBoard(int nAsteroids);
    bool shipFires(Ship& ship);
};

// Implementierung Ship
bool Ship::fireUpon(shared_ptr<Asteroid> a) {
    if(!a) return false;             // ungültiger Asteroid
    a->structure_ -= firepower;
    if(a.get() == firedLastOn_.get())
        firepower *= 2 ;             // Schaden vergrößern
    else
        firepower = 1;               // zurücksetzen
    firedLastOn_ = a;
    return a->structure_ <= 0;       // kaputt?
}

// Implementierung GameBoard
GameBoard::GameBoard(int nAsteroids)
    : asteroids_{}
{   // einige Standard-Asteroiden
    for(int idx=0; idx<nAsteroids; ++idx)
        asteroids_.push_back( make_shared<Asteroid>() );
}
int wuerfel(int min, int max) {
    /* static std::default_random_engine e{}; */     // Pseudo-Zufallsgenerator
    static std::random_device e{};                          // Zufallsgenerator
    return std::uniform_int_distribution<int>{min, max}(e); // würfeln
}

bool GameBoard::shipFires(Ship &ship) {
    int idx = wuerfel(0, asteroids_.size()-1);
    bool kaputt = ship.fireUpon(asteroids_[idx]);
    if(kaputt) {
        ship.score_ += asteroids_[idx]->points_;
        asteroids_.erase(asteroids_.begin()+idx);           // entfernen
    }
    return asteroids_.size() == 0;                          // alles kaputt
}

} // Ende des anonymen Namensraums

int main() {
    GameBoard game{10};                                     // 10 Asteroiden
    Ship ship{};
    for(int idx = 0; idx < 85; ++idx) {                     // 85 Schüsse
        if(game.shipFires(ship)) {
            cout << "Der Weltraum ist nach " << idx+1 << " Schuessen leer. ";
            break;
        }
    }
    cout << "Sie haben " << ship.score_ << " Punkte erreicht.\n";
}
```

## Video Smart Pointer

### Shared Pointer
Container or Wrapper for a raw Pointer. 
Deallocate Memory automatically -> Destructor

#include \<memory> nicht vergessen!

```cpp
#include <iostream>
#include <memory>

//Create
unique_ptr<int>unPtr1=make_unique<int>(25);
//what<Datatype>nameOfPtr=pleaseMakePtr<Datatype>(WhatToStore)

//Dereference
cout << unPtr1; //Address
cout << *unPtr1; //Value stored on address

//can't be shared
unique_ptr<int>unPtr2=unPtr1;       //Error because unPtr1 already owns the Address

//Move ownership of ptr
unique_ptr<int>unPtr2=move(unPtr1);     //becomes owner of this address
//Previous owner besomes a nullpointer -> Nullpointer Exception
```

Pointer to class

```cpp
#include <iostream>
#include <memory>

class MyClass {
   public:
        MyClass() {
            cout << "Constructor invoked\n";
        }
        ~MyClass() {
            cout << "Destructor invoked\n";
        }
};

int main() {

    //Pointer to object of MyClass
    unique_ptr<MyClass>uniquePtr1=make_unique<MyClass>();       //Will be destroyed at end of Scope

}
```
### Shared Pointer

Can be shared between multiple owners

```cpp
#include <iostream>
#include <memory>

class MyClass {
   public:
        MyClass() {
            cout << "Constructor invoked\n";
        }
        ~MyClass() {
            cout << "Destructor invoked\n";
        }
};

int main() {

    //Create Shared Pointer
    shared_ptr<MyClass>shPtr1=make_shared<MyClass>();       //Has a counter of all owners (References to that Pointer)

    //Access Count
    cout << "Shared count: " << shPtr1.useCount() << "\n";

    //Additional owner
    shared_ptr<MyClass>shPtr2=shPtr1;

}
```

Memory will be deallocated when every owner is destroyed.

### Weak Pointer

Does not increase the number of the owners -> Observe Objects in memory without keeping it alive

```cpp
#include <iostream>
#include <memory>

int main() {

    //Create Weak Pointer
    weak_ptr<MyClass>wePtr1;

    {
        shared_ptr<int>shPtr1=make_shared<int>(25);
        //Assign to weak
        wePtr1 = shPtr1;
    }
}
```

## Rohe Zeiger

Im Gegensatz zu Referenzen können Zeiger neu zugewiesen werden. `wert = 42; int &ref = wert;` bei `ref = 99;` wird auch wert auf 99 gesetzt. `*ptr = &wert; *ptr = &neu;` Ptr zeigt nun auf neu und nicht mehr auf Wert.

Referenzen können nicht in Containern gespeichert werden!

```cpp
#include <vector>
#include <numeric>   // iota
#include <iostream>
using std::vector; using std::cout;
struct Zahl {        // stellvertretend für ein großes, teures Objekt
    unsigned long val_;
    Zahl(unsigned long val) : val_{val} {}
    Zahl() : val_{0} {}
};
/* ermittelt anhand bisheriger Primzahlen, ob z eine Primzahl ist */
bool isPrim(const Zahl& z, const vector<Zahl*> prims) {
    for(Zahl* p : prims) {
        if((p->val_*p->val_) > z.val_) return true;   // zu groß
        if(z.val_ % p->val_ == 0) return false;       // ist Teiler
    }
    return true;
}
int main() {
    vector<Zahl> alleZahlen(98);   // 98 mit null initialisierte Elemente
    std::iota(begin(alleZahlen), end(alleZahlen), 3); // 3..100
    /* alleZahlen enthält jetzt {3..100} */
    vector<Zahl*> prims{};         // bekommt ermittelte Primzahlen
    Zahl zwei{2};
    prims.push_back(&zwei);        // die 2 wird gebraucht
    for(Zahl &z : alleZahlen) {    // über alle Zahlen iterieren, z ist Referenz auf Zahl
        if(isPrim(z, prims)) {
            prims.push_back( &z ); // speichere Adresse von z
        }
    }
    /* Rest ausgeben */
    for(Zahl* p : prims)
        cout << p->val_ << " ";
    cout << "\n";
}
```

## C-Arrays

Roher Zeiger mit Grössenangabe, zeigt auf Anfang mehrerer hintereinanderliegender Werte.

```cpp
int wert = 42;
int* zeiger = &wert;        //Zeigt auf einzelnen Int

int carray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}        //Carray mit 10 Werten
//Carray hat Typ in[10]

//Iterieren
for(int val : carray) {cout << val;}

int x = carray[4];
carray[7] = 12;

//Carray in Zeiger desselben Typs umwandel
int* ptr = carray;

//ptr zeigt auf carray[0]
*ptr = 99;          //carray[0] wird zu 99
```

## Rechnen mit Zeigern


```cpp
#include <iostream>

int main() {
    int carray[10] = { 1,1 };               // initialisiert zu { 1,1,0,0,0,0,0,0,0,0 }
    int* ende = carray+10;                  // Zeiger  hinter das letzte Element

    for(int* p =carray+2; p != ende; ++p) {
        *p = *(p-1) + *(p-2);               // addiert die vorigen beiden Zahlen
    }

    for(int const * p=carray; p != ende; ++p)
        std::cout << *p << " ";
    std::cout << "\n";
}
```

## Verfall von C-Arrays

```cpp
#include <iostream>
void fibonacci(int data[], int* ende) {
    for(int* p = data+2; p != ende; ++p) {
        *p = *(p-1) + *(p-2);
    }
}
std::ostream& print(std::ostream &os, int data[], int* ende) {
    for(int const * p=data; p != ende; ++p)
        std::cout << *p << " ";
    return os;
}
int main() {
    int carray[10] = { 1,1 }; // initialisiert zu { 1,1,0,0,0,0,0,0,0,0 }
    fibonacci(carray, carray+10);
    print(std::cout, carray, carray+10) << "\n";
}
```

## Dynamische C-Arrays

```cpp
void calc(size_t sz) {
    int carray[10];
    int darray[10]      //Falsch keine Konstante
}

//Besser
void calc (size_t sz) {
    int[] darray = new int[sz];     //anlegen
    //....
    delete[] darray;                //löschen
}
```

```cpp
#include <memory>      // unique_ptr
#include <iostream>    // cout

std::unique_ptr<int[]> createData(size_t sz) {
    return std::unique_ptr<int[]>(new int[sz]);
}

void fibonacci(int data[], int* ende) {
    for(int* p = data+2; p != ende; ++p) {
        *p = *(p-1) + *(p-2);
    }
}

std::ostream& print(std::ostream &os, int data[], int* ende) {
    for(int const* p= data; p != ende; ++p)
        std::cout << *p << " ";
    return os;
}
int main() {
    std::unique_ptr<int[]> data { createData(10) };
    data[0] = 1; // setzen Sie Werte im Array durch den unique_ptr
    data[1] = 1;
    fibonacci(data.get(), data.get()+10); // holen Sie sich den C-Array-Zeiger mit get()
    print(std::cout, data.get(), data.get()+10) << "\n";
}
```

## C-String



```cpp
#include <string>
#include <iostream>                    // cout
using std::string; using std::cout;
string greet(string name) {
    return name + "!";                 // string operator+(string, const char*)
}

int main() {
    string name{ "Havaloc Vetinari" }; // explizit: string(const char*)
    cout << "Angua";                   // ostream& operator<<(ostream&, const char*)
    cout <<                            // ostream& operator<<(ostream&, string)
      greet("Carrot Ironfoundersson"); // implizit: string(const char*)
}
```

## Iteratoren
Anfang mit Methode begin() holen, bei freien Funktionen end(container), Ende mit end() oder end(container). Funktioniert für alle Standardcontainer.



```cpp
#include <vector>
#include <iostream> // cout
using std::vector;
int main() {
    vector data{ 5,4,3,2,1 };
    vector<int>::const_iterator ende = data.end(); // oder end(data)
    for(vector<int>::const_iterator it = data.begin(); it!=ende; ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}
```
Iterator mit ++ inkrementieren, Überprüfung mit it(erator) != data(end)

Grösse mit end(date)-begin(data) bestimmen oder difference aus \<iterator>. 
### Zeiger als Iteratoren


```cpp
#include <iostream>   // cout
#include <iterator>   // ostream_iterator
#include <algorithm>  // copy

int main () {
  int data[6] = { 1, 2, 3, 7, 9, 10 };
  std::ostream_iterator<int> out_it (std::cout,", ");
  std::copy(data, data+6, out_it);           // Zeiger als Iteratoren
  std::cout << "\n";                         // Ausgabe: 1, 2, 3, 7, 9, 10
}
```
## Function Pointers

Stores Address of a Function

```cpp
int getNumber() {
    return 5;
}

int add(int a, int b){
    return a + b;
}

int main() {
    cout << getNumber();    //Output 5
    cout << getNumber;      //Output Address of Function


    //Function Pointer
    int(*funcPtr)();            //Can Point to any int function
    int(*funcPtr)() = getNumber;
    //returntype(*namePtr)(Params);

    cout << funcPtr();      //Calls function

    //Again with function which uses Parameters
    int(*funcPtr)(int, int) = add;  

    cout << add(2, 4);
    cout << funcPtr(3,4);
}
```

### Purpose of function pointer:

Pass a Function as an Agrument to another function



```cpp
#include <iostream>
#include<vector>
using namespace std;

bool ascendingCompare(int a, int b) {
	return a < b;
}
bool descendingCompare(int a, int b) {
	return a > b;
}
//Sort vector in ascending number
void sortAscending(vector<int>& numbersVector)
{
	for (int startIndex = 0; startIndex < numbersVector.size(); startIndex++)
	{
		int bestIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < numbersVector.size(); currentIndex++)
		{
			// We are doing comparison here
			if (ascendingCompare(numbersVector[currentIndex], numbersVector[bestIndex]))
				bestIndex = currentIndex;
		}

		swap(numbersVector[startIndex], numbersVector[bestIndex]);
	}
}
void sortDescending(vector<int>& numbersVector)
{
	for (int startIndex = 0; startIndex < numbersVector.size(); startIndex++)
	{
		int bestIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < numbersVector.size(); currentIndex++)
		{
			// We are doing comparison here
			if (descendingCompare(numbersVector[currentIndex], numbersVector[bestIndex]))
				bestIndex = currentIndex;
		}

		swap(numbersVector[startIndex], numbersVector[bestIndex]);
	}
}


void customSort(vector<int>& numbersVector, bool(*compareFunctionPtr)(int, int))
{
	for (int startIndex = 0; startIndex < numbersVector.size(); startIndex++)
	{
		int bestIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < numbersVector.size(); currentIndex++)
		{
			// We are doing comparison here
			if (compareFunctionPtr(numbersVector[currentIndex], numbersVector[bestIndex]))
				bestIndex = currentIndex;
		}

		swap(numbersVector[startIndex], numbersVector[bestIndex]);
	}
}


void printNumbers(vector<int>& numbersVector) {
	for (int i = 0; i < numbersVector.size(); ++i)
		cout << numbersVector[i] << ' ';
}

int main()
{
	vector<int> numbersVector = { 4,2,1,3,6,5 };
	//sortAscending(numbersVector);
	//sortDescending(numbersVector);

	bool (*funcPtr)(int, int) = descendingCompare;
	customSort(numbersVector, funcPtr);
	printNumbers(numbersVector);

	system("pause>0");
}
```


```cpp


```






# Kapitel 4 - Die Grundbausteine von C++

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






# Kapitel 4 - Die Grundbausteine von C++

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






# Kapitel 4 - Die Grundbausteine von C++

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






# Kapitel 4 - Die Grundbausteine von C++

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




