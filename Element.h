//
// Created by Karina Shin on 3/22/2022.
//

#ifndef STABLEMATCHING_ELEMENT_H
#define STABLEMATCHING_ELEMENT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Element {
private:
    string name;
    bool free;//do they have a partner?
    vector<Element> preferences;

public:
    Element();
    Element(string name);

    bool operator==(const Element& e);
    string getName();
    bool isFree();
    void changeFree();
    void addPreference(Element pref);
    int findPref(const string& name);//getting a name, return index of the element from the preference list
    void printPreferences();
    vector<Element> getPreferences();
};


#endif //STABLEMATCHING_ELEMENT_H
