//
// Created by 18476 on 3/22/2022.
//

#ifndef STABLEMATCHING_SETOFELEMENTS_H
#define STABLEMATCHING_SETOFELEMENTS_H

#include "Element.h"
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;
class SetOfElements {
private:
    vector<Element> elementsInSet;
    int setSize = 0;

public:
    SetOfElements();
    SetOfElements(ifstream& input);

    void addElement(Element e);
    Element& getPerson(string name);//get a specific element using the given name
    vector<Element>& getElements();
    int getSize();
    void printSet();
};


#endif //STABLEMATCHING_SETOFELEMENTS_H
