//
// Created by 18476 on 3/22/2022.
//

#include "SetOfElements.h"

SetOfElements::SetOfElements() {}

SetOfElements::SetOfElements(ifstream& input)
{
    string line;
    getline(input, line);
    int num = stoi(line);

    for (int i = 0; i < num; i++)
    {
        getline(input, line);
        int colon = line.find(':');
        string name = line.substr(0, colon);
        line = line.substr(colon + 1);
        Element e(name);

        int comma = line.find(',');
        while (comma != -1)
        {
            e.addPreference(line.substr(0, comma));
            line = line.substr(comma + 1);
            comma = line.find(',');
        }
        e.addPreference(line.substr(0, comma));
        addElement(e);
    }
}

void SetOfElements::addElement(Element e)
{
    elementsInSet.push_back(e);
    setSize++;
}

Element& SetOfElements::getPerson(string name)
{
    for (int i = 0; i < elementsInSet.size(); i++)
    {
        if (elementsInSet.at(i).getName() == name)
            return elementsInSet.at(i);
    }
    cout << "element not found in set" << endl;
}

vector<Element>& SetOfElements::getElements()
{
    return elementsInSet;
}

int SetOfElements::getSize()
{
    return setSize;
}

void SetOfElements::printSet()
{
    for (int n = 0; n < elementsInSet.size(); n++){
        cout << elementsInSet.at(n).getName() << ": ";
        elementsInSet.at(n).printPreferences();
    }
    cout << endl;
}
