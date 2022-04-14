//
// Created by 18476 on 3/22/2022.
//

#include "StableMatchSet.h"

StableMatchSet::StableMatchSet()
{

}

void StableMatchSet::determineMatches(SetOfElements a, SetOfElements b)
{
    int numFree = a.getSize();

    while (numFree > 0)//while there are still people who need a partner
    {
        std::cout << "while loop" << std::endl;
        Element curr;//everything is happening to a temp variable, not actually changing isfree value
        int index;
        for (int i = 0; i < a.getSize(); i++)
            if (a.getElements().at(i).isFree()){//get the first person that needs a partner
//                curr = a.getElements().at(i);
//                std::cout << "current (free) person: " << a.getElements().at(i).getName() << std::endl;
                index = i;
                break;
            }
        std::cout << a.getElements().at(index).getName() << std::endl;

        for(int i = 0; i < a.getSize() && a.getElements().at(index).isFree(); i++)
        {
            std::cout << "for loop" << std::endl;
            Element partner = a.getElements().at(index).getPreferences().at(i);
            if (partner.isFree())//if partner is free, make a match
            {
                std::cout << "if is running" << std::endl;
                (a.getElements().at(index)).changeFree();
                b.getPerson(partner.getName()).changeFree();//change status of partner too
                addMatch(a.getElements().at(index), partner);
                if (a.getElements().at(index).isFree())
                    std::cout << a.getElements().at(index).getName() << " is free" << std::endl;
                numFree--;
            }
            else//does partner prefer curr over current partner?
            {
                std::cout << "else is running?" << std::endl;
                Element currPartner = findPartner(partner);//find current partner of partner

                if (!prefers(partner.getPreferences(), a.getElements().at(index), currPartner))//prefers curr over currPartner
                {
                    addMatch(curr, partner);
                    a.getElements().at(index).changeFree();
                    currPartner.changeFree();
                }
            }
        }
    }
}

void StableMatchSet::addMatch(Element a, Element b)
{
    std::cout << "add match" << std::endl;
    vector<Element> v;
    v.push_back(a);
    v.push_back(b);
    matches.push_back(v);
}

bool StableMatchSet::matchesAreStable()
{
    for (int i = 0; i < matches.size(); i++)
    {
        Element curr = matches.at(i).at(0);
        Element partner = matches.at(i).at(1);
        int p = curr.findPref(partner.getName());//ranking of current partner
        for (int j = 0; j < curr.getPreferences().size(); j++)
        {
            Element pref = curr.getPreferences().at(j);
            Element p = findPartner(pref);//find current partner for pref
            if (prefers(pref.getPreferences(), p, curr))//prefers someone else over their current partner
            {
                std::cout << "Unstable match found" << std::endl;
                return false;//match unstable
            }
        }
    }
    std::cout << "All matches are stable!" << std::endl;
    return true;
}

bool StableMatchSet::prefers(vector<Element> set, Element a, Element b)
{
    std::cout << "prefers method" << std::endl;
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

    std::cout << "index of a: " << indexA << std::endl;
    std::cout << "index of b: " << indexB << std::endl;
    //b has lower index = higher preference
    //b < a means a prefers b over a
    if (indexB < indexA){
        std::cout << "Prefers " << b.getName() << " over " << a.getName() << std::endl;
        return true;
    }
    std::cout << "Prefers " << a.getName() << " over " << b.getName() << std::endl;
    return false;
}

Element StableMatchSet::findPartner(Element& person)
{
    std::cout << "person object is " << person.getName() << std::endl;
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

    if (partner.getName() == "")//not initialized
        std::cout << "no partner found" << std::endl;
    else
        std::cout << "Found partner name: " << partner.getName() << std::endl;
    return partner;
}

void StableMatchSet::printMatches()
{
    std::cout << matches.size() << std::endl;
    for (int i = 0; i < matches.size(); i++)
    {
        cout << "(" << matches.at(i).at(0).getName() << ", " << matches.at(i).at(1).getName() << ")" << endl;
    }
}

