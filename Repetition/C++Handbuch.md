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
# Kapitel 4 - Die Grundbausteine von C++

```cpp


```
# Kapitel 4 - Die Grundbausteine von C++

```cpp


```
# Kapitel 4 - Die Grundbausteine von C++

```cpp


```
# Kapitel 4 - Die Grundbausteine von C++

```cpp


```
# Kapitel 4 - Die Grundbausteine von C++

```cpp


```
# Kapitel 4 - Die Grundbausteine von C++

```cpp


```
