# Kapitel 4 - Die Grundbausteine von C++

## Operatoren

### Arithmetische Operatoren
Grundrechenarten +, -, *, /, %

Gilt f�r alle Ganzzahl- und Fliesskommazahlen (Ausser Modulo). 

Mit Plus k�nnen z.B. auch Strings zusammengesetzt werden.

### Bitweise Arithmetik
Bitweise Verkn�pfung mit |, &, ^, ~, >>, <<

|Operation|Bin�r|Dezimal 
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

### Pr�- und Postinkrement

++wert wird zuerst erh�ht und danach verwendet, wert++ wird zuerst verwendet und danach erh�ht. 

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

tern�rer Operator: `a > b ? a : b` -> if a > b,  a, else b

Sequenzoperator: wertet von links nach rechts aus, beh�lt aber nur das letzte Ergebnis. -> Do NOT use!


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
size_t | Positive Gr�ssen, bsp. Container
ptrdiff_t | Abstand zweier Adressen `ptrdiff_t d = &x - &y;`
time_t | aus \<ctime>, Sekunden seit 01.01.1970

# Kapitel 6 - H�here Datentypen

## String

#include \<string> -> ist in Standardlibrary

Container f�r einzelne chars

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
\+ | Aneinanderf�gen zweier strings zu einem neuen
<< | Ausgabe eines strings
\>> | Lesen eines strings bis zum n�chsten Whitespace
getline | Lesen in einen string bis zum n�chsten Newline

    

Funktion | Beschreibung
---|---
length | L�nge des Inhalts
at |(Sicheres) Holen eines einzelnen Zeichens
\[] |Holen eines einzelnen Zeichens ohne Pr�fung
find |Suchen innerhalb des string
find_first_of |Suche erstes Zeichen aus einer Menge.
substr |Erzeuge neuen string aus einem Bereich.
compare |Vergleiche mit anderem string.
clear |Zur�cksetzen auf den leeren string
append |Anh�ngen einer Zeichenfolge
\+= |Alternative Schreibweise f�r append
insert |Einf�gen in den string
erase |L�schen eines Teils des strings
replace |Ersetzen eines Teils durch eine andere Zeichenfolge
starts_with |Pr�fe, ob der der Anfang passt, seit C++20

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

## Beh�lter und Zeiger

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
  wotag[5] = "Sonnabend";                                   // Werte ver�ndern
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

Gr�sse mit sizeof();

### Vector
Dynamische Anzahl an Elementen
```cpp
#include <vector>

vector<int> quadrate{};                     //leer initialisieren
for (int index = 0; index < 100; ++index) { //iterieren
    quadrate.push_back(index*index);        //anf�gen Element
}
```
Elemente liegen nacheinander im Speicher, das ist sehr schnell. Bei Anf�gen eines Elements am Anfang oder der Mitte werden alle nachfolgenden Elemente verschoben, was viel Speicher brauchen kann!

#### Iteratoren

* begin() � Returns an iterator pointing to the first element in the vector
* end() � Returns an iterator pointing to the theoretical element that follows the last element in the vector
* rbegin() � Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
* rend() � Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
* cbegin() � Returns a constant iterator pointing to the first element in the vector.
* cend() � Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
* crbegin() � Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
* crend() � Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)

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

* size() � Returns the number of elements in the vector.
* max_size() � Returns the maximum number of elements that the vector can hold.
* capacity() � Returns the size of the storage space currently allocated to the vector expressed as number of elements.
* resize(n) � Resizes the container so that it contains �n� elements.
* empty() � Returns whether the container is empty.
* shrink_to_fit() � Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
* reserve() � Requests that the vector capacity be at least enough to contain n elements.
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

* reference operator [g] � Returns a reference to the element at position �g� in the vector
* at(g) � Returns a reference to the element at position �g� in the vector
* front() � Returns a reference to the first element in the vector
* back() � Returns a reference to the last element in the vector
* data() � Returns a direct pointer to the memory array used internally by the vector to store its owned elements.

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

* assign() � It assigns new value to the vector elements by replacing old ones
* push_back() � It push the elements into a vector from the back
* pop_back() � It is used to pop or remove elements from a vector from the back.
* insert() � It inserts new elements before the element at the specified position
* erase() � It is used to remove elements from a container from the specified position or range.
* swap() � It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
* clear() � It is used to remove all the elements of the vector container
* emplace() � It extends the container by inserting new element at position
* emplace_back() � It is used to insert a new element into the vector container, the new element is added to the end of the vector

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
int addTwo(int a, int b);       //a und b k�nnen weggelassen werden (int, int)

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

//a wird nicht ver�ndert
```

### Call-by-Reference

Parameter als Referenz �bergeben, dann wird die ver�ndert.
```cpp
int add(int& a, int& b) {
    a += b;
    return a;
}

//a wird ver�ndert
```

### Vorw�rtsdeklaration

Funktion vorher deklarieren, damit sie schon bekannt ist. 

## Funktionen �berladen

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

Standardwerte f�r Parameter die �berschrieben werden k�nnen.

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

# Kapitel 8 - Anweisungen im Detail

## if
```cpp
if (zahl < 5) {
    cout << "Kleiner 5";
} else if (zahl < 10) {
    cout "Kleiner 10";
}else {
    cout << "Gr�sser 10";
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
    do {                            // mindestens einmal getline ausf�hren
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
            continue;     // n�chste Schleifeniteration
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

Rest des Schleifendurchlaufs abbrechen und mit n�chster Interation weitermachen.


## return

Aus Funktion herausspringen.



## try-catch und throw
*Try* umschliesst Programmcode in dem ein Fehler erwartet wird, *catch* �bernimmt die Fehlerbehandlung.
```cpp
#include <iostream>
int main() {
    try {                                        // Beginn des try-Blocks
        for(int n=1; ; n=n*2) {
            if(n < 0) {
                throw "Es gab einen Ueberlauf";  // Fehler ausl�sen
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
size_t zaehleWoerter(const string& filename) { // 0 oder gr��er
    std::ifstream file{};      // unge�ffnet erzeugen
    // anmelden f�r Exceptions:
    file.exceptions(ifstream::failbit | ifstream::badbit);
    file.open(filename);       // k�nnte eine Exception ausl�sen
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
        throw std::invalid_argument{"Kommandozeilenarg. fehlt"}; // ausl�sen
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

## Ausnahmen ausl�sen und behandeln

Throw l�st eine Ausnahme aus. 

Instanz der Klasse std::invalid_argument erzeugen, die den Fehler repr�sentiert.

```cpp
if(args.size() == 0) {     // process erwartet Parameter
        throw std::invalid_argument{"Kommandozeilenarg. fehlt"}; // ausl�sen
    } else {
        for(const string filename : args) {
            cout << filename << ": " << zaehleWoerter(filename) << std::endl;
        }
    }
```
open() wirft die Exception selber und r�umt auch auf.

```cpp
file.open(filename);
```
Rohe Zeiger, die mit new erstellt werden, m�ssen manuell entsorgt werden.
## Aufrufstapel abwickeln

In Main wird innerhalb des try-Blocks jede geworfene Exception gepr�ft und die Befehle innerhalb des catch-Blocks der Reihe nach durchgearbeitet werden. 



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
Soll das Programm nicht abgebrochen werden, sondern mit der n�chsten Datei weitergef�hrt werden, kommt die Fehlerbehandlung in die for-SChleife.

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

Innerhalb eines catch-Blocks ein throw ohne weiteres Argument nutzen, um gerade geworfene Exception unver�ndert weiterzuwerfen.

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
Der erste passende Handler wird ausgef�hrt. 
```cpp
try {
    //Code here
}catch(std::invalid_argument &exc){          //erster Handler
    cerr << "Ung�ltiges Argument: " << exc.what() << "\n";
    }catch(std::ios_base_failure &exc){      //zweiter Handler
    cerr << "Dateifehler: " << exc.what() << "\n";
    }catch(std::exception &exc){            //dritter Handler
    cerr << "Es trat ein Fehler auf: " << exc.what() << "\n";
    } catch(...) {                          //vierter und letzter Handler
        cerr << "Es trat ein Fehler auf \n";
    }
    return 1;
```
There is a special catch block called the �catch all� block, written as catch(�), that can be used to catch all types of exceptions. For example, in the following program, an int is thrown as an exception, but there is no catch block for int, so the catch(�) block will be executed. 

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
nachteiligen Auswirkungen haben. Um den Begriff zu pr�zisieren, gibt es verschiedene
Stufen:
1. Auf der niedrigsten Stufe gibt es keinerlei Zusicherungen, ob und wie sich Fehler
auswirken.
2. In dieser Stufe kann ein Programm zwar falsche Daten erzeugen, es soll aber weder
abst�rzen noch Speicherlecks oder verwitwete Objekte hinterlassen.
3. Eine starke Exception-Sicherheit liegt vor, wenn eine Operation entweder vollst�ndig oder, bei einem Fehler, gar nicht oder so ausgef�hrt wird, dass das betroffene
Objekt anschlie�end im selben Zustand wie vor der fehlerhaften Operation ist. Dies
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
Wenn noch Platz auf dem Stack ist, hat push() die gew�nschte Wirkung. Wenn nicht,
bleibt der Stack in seinem vorherigen Zustand.

4. In der sichersten Stufe wird garantiert, dass keine Fehler auftreten oder aber alle auftretenden Fehler abgefangen werden, sodass kein Fehler nachteilige Auswirkungen
hat. M�glicherweise auftretende Exceptions werden nicht zum Aufrufer durchgereicht.

# Kapitel 12 - Von der Struktur zur Klasse

## Struct
B�ndelung mehrerer Datenfelder zu einem neuen Datentyp.

```cpp
#include <string>
#include <iostream>                      // cout
using std::string; using std::cout;
struct Person {                          // definiert den neuen Typ Person
    string name_;
    int alter_;
    string ort_;
};                                       // abschlie�endes Semikolon
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

## R�ckgabe eigener Werte
Selber erstellte Datentypen k�nnen genau so zur�ckgegeben werden. 
```cpp
// Ausschnitt
Person erzeuge(string name, int alter, string ort) {
    return Person{name, alter, ort};       // direkt zur�ckgegeben
    //Peron kann weggelassen werden (return {name, alter, ort};) wenn erzeuge nicht auto ist.
    //Auto verlangt auch Konstruktornamen
    //auto erzeuge(string name, int alter, string ort) {}
}
int main() {
    drucke(erzeuge("Otto", 45, "Kassel")); // R�ckgabe direkt verwendet
}
```
##Methoden

Funktionen f�r einen bestimmten Datentypen.

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
    cout << name_       // in einer Methode k�nnen Sie direkt auf Felder zugreifen
        << " ("<< alter_<<") aus " << ort_ << "\n";
}
int main() {
    Person otto {"Otto", 45, "Kassel" };
    otto.drucke();      // Aufruf der Methode f�r eine Variable des Typs
}
```
Innerhalb der methode kann normal auf Datenfelder und Methoden der Klasse zugegriffen werden (name_ statt p.name_).

Dies wird intern vom Compiler als this-> interpretiert. Eine Methode hat den implizierten Parameter Typ* this. Der steht f�r die Speicheradresse der Instanz, auf die die Methode aufgerufen wird. 

```cpp
//Wird vom Compiler gemacht:
string Person::gruss(){
    return "Hallo " + this->name_ + "aus " + this->ort_;
}
```
Der this Parameter �ndert sich beim Aufruf der Methoden von verschiedenen Objekten.

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
        return 1;              // Fehler nach au�en weiterleiten
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
    {}                      //leerer Funktionsk�rper


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

Dann m�ssen die Werte nicht im Konstruktor aufgenommen werden.

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

Dabei l�sst man den K�rper des delegierenden Konstruktoren leer. 

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
### Defaultwerte f�r Konstruktorparameter

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




# Kapitel 13 - Namensr�ume und Qualifizierer

## std



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
# Kapitel 4 - Die Grundbausteine von C++

```cpp


```
