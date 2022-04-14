#include <iostream>

#include "Element.h"
#include "StableMatchSet.h"
#include "SetOfElements.h"

using namespace std;
int main(int argc, char** argv) {
    ifstream input;
    input.open(argv[1]);
    if (!input.is_open())
        cout << "not open";
    SetOfElements setA(input);
    input.close();

    input.open(argv[2]);
    if (!input.is_open())
        cout << "not open";
    SetOfElements setB(input);
    input.close();

//    setA.printSet();
//    setB.printSet();
//    Element a("Tom");
//    if (a.isFree())
//        std::cout << "a is free" << std::endl;
//    else
//        std::cout << "a is not free" << std::endl;
//    a.changeFree();
//    if (a.isFree())
//        std::cout << "a is free" << std::endl;
//    else
//        std::cout << "a is not free" << std::endl;
//    a.changeFree();
//    if (a.isFree())
//        std::cout << "a is free" << std::endl;
//    else
//        std::cout << "a is not free" << std::endl;


    StableMatchSet match;
    match.determineMatches(setA, setB);
//    match.matchesAreStable();
    match.printMatches();
    return 0;
}
