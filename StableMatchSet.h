//
// Created by 18476 on 3/22/2022.
//

#ifndef STABLEMATCHING_STABLEMATCHSET_H
#define STABLEMATCHING_STABLEMATCHSET_H

#include <vector>
#include <algorithm>
#include "Element.h"
#include "SetOfElements.h"

using namespace std;
class StableMatchSet {
private:
    vector<vector<Element>> matches;//contains vectors of 2 Elements that signify a partner pair

public:
    StableMatchSet();
    void determineMatches(SetOfElements a, SetOfElements b);
    void addMatch(Element a, Element b);
    bool matchesAreStable();
    bool prefers(vector<Element> set, Element a, Element b);//returns true if element prefers b over a
    Element findPartner(Element& person);
    void printMatches();
};


#endif //STABLEMATCHING_STABLEMATCHSET_H
