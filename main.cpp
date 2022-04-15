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
    cout << "Set A contains: " << endl;
    setA.printSet();
    input.close();

    input.open(argv[2]);
    if (!input.is_open())
        cout << "not open";
    SetOfElements setB(input);
    cout << "Set B contains: " << endl;
    setB.printSet();
    input.close();

    StableMatchSet match;
    match.determineMatches(setA, setB);
    match.printMatches();

    cout << "Result of verification function: ";
    if (match.matchesAreStable(setA, setB))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
