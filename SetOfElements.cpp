//
// Created by 18476 on 3/22/2022.
//

#include "StableMatchSet.h"

StableMatchSet::StableMatchSet() {}

void StableMatchSet::determineMatches(SetOfElements a, SetOfElements b)
{
    int numFree = a.getSize();

    while (numFree > 0)//while there are still people who need a partner
    {
        int index;
        for (int i = 0; i < a.getSize(); i++){
            if (a.getElements().at(i).isFree()){//get the first person that needs a partner
                index = i;
                break;
            }
        }

        for(int i = 0; i < a.getSize() && a.getElements().at(index).isFree(); i++)
        {
            Element partner = b.getPerson(a.getElements().at(index).getPreferences().at(i).getName());
            if (partner.isFree())//if partner is free, make a match
            {
                (a.getElements().at(index)).changeFree();
                b.getPerson(partner.getName()).changeFree();//change status of both elements
                addMatch(a.getElements().at(index), b.getPerson(partner.getName()));
                numFree--;
            }
            else//does partner prefer curr over current partner?
            {
                Element currPartner = findPartner(partner);//find current partner of partner

                if (!prefers(partner.getPreferences(), a.getElements().at(index), currPartner))//prefers curr over currPartner
                {
                    deleteMatch(partner);//remove old pair from matches vector
                    (a.getElements().at(index)).changeFree();
                    addMatch(a.getElements().at(index), b.getPerson(partner.getName()));//add new pair
                    a.getPerson(currPartner.getName()).changeFree();//previous partner is now free again
                }
            }
        }
    }
}

void StableMatchSet::addMatch(Element a, Element b)//always in (element from setA, element from setB) format
{
    vector<Element> v;
    v.push_back(a);
    v.push_back(b);
    matches.push_back(v);
}

void StableMatchSet::deleteMatch(Element a)
{
    for (int i = 0; i < matches.size(); i++)
    {
        if (matches.at(i).at(0) == a || matches.at(i).at(1) == a){
            matches.erase(matches.begin() + i);
            return;
        }
    }
    std::cout << "No pair found" << std::endl;
}

bool StableMatchSet::matchesAreStable(SetOfElements a, SetOfElements b)
{
    for (int i = 0; i < matches.size(); i++)
    {
        Element curr = matches.at(i).at(0);
        Element partner = matches.at(i).at(1);
        int p = curr.findPref(partner.getName());//ranking of current partner
        for (int j = 0; j < p; j++)//for every element ranked higher than current partner
        {
            Element pref = curr.getPreferences().at(j);
            Element currPrefPartner = findPartner(pref);//find current partner for pref
            if (prefers(b.getPerson(pref.getName()).getPreferences(), currPrefPartner, curr))
            {//higher preference prefers someone else over their current partner = unstable
                return false;//match unstable
            }
        }
    }
    return true;
}

bool StableMatchSet::prefers(vector<Element> set, Element a, Element b)
{
    int indexA = -1;//pref. position of b
    int indexB = -1;//pref. position of b1

    for (int i = 0; i < set.size() || indexA == -1 || indexB == -1; i++)
    {//while the position of both elements have not been found
        string curr = set.at(i).getName();
        if (curr == a.getName())
            indexA = i;
        if (curr == b.getName())
            indexB = i;
    }

    //b has lower index = higher preference
    //b < a means a prefers b over a
    if (indexB < indexA){
        return true;
    }
    return false;
}

Element StableMatchSet::findPartner(Element& person)
{
    Element partner;
    for (int i = 0; i < matches.size(); i++)//go through each vector within the vector
    {
        auto iter = matches.at(i).begin();
        iter = ::find(matches.at(i).begin(), matches.at(i).end(), person);
        if (iter != matches.at(i).end()){//found the person's pair
            if (matches.at(i).at(0) == person){
                partner = matches.at(i).at(1);//partner is the other element in the vector
            }
            else{
                partner = matches.at(i).at(0);
            }
        }
    }

    return partner;
}

void StableMatchSet::printMatches()
{
    cout << "Stable Pairing: " << endl;
    for (int i = 0; i < matches.size(); i++)
    {
        cout << "(" << matches.at(i).at(0).getName() << ", " << matches.at(i).at(1).getName() << ")" << endl;
    }
}

