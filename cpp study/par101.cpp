#include <iostream>
#include "BitSet.h"
using namespace std;

int main(int argc, char *argv[]) {
    BitSet b1(132), b2(131);
    b1.insert(3);
    b1.insert(5);
    b1.insert(8);
    b2.insert(4);
    b2.insert(5);
    b2.insert(8);
    b2.insert(130);
    b1.print();
    b2.print();
    cout << "b1= " << b1 << endl;
    cout << "b2= " << b2 << endl;
    try {
        cout << "b1+b2= " << b1 + b2 << endl;
    }catch(IncompatibleException& e){
    std::cout << "In +operation, thie operands are not compatible." << std::endl;
    std::cout << "The size of the first BitSet is " << e.v1 << std::endl;
    std::cout << "The size of the first BitSet is " << e.v2 << std::endl;
    }
    return 0;
}