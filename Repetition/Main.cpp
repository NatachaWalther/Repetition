#include <vector>
#include <iostream>
#include <algorithm>



int main() {

    struct {
        void operator() (int x) {   //Overwrite Operator
            std::cout << x << "\n";
        }
    }something;

    //[capture clause](parameters){definition of lambda function}
    std::vector <int> v{ 2, 3, 7, 14, 23 };
    std::for_each(v.begin(), v.end(), something);
    //[]() {}

}