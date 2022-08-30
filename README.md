# Stable_Matching_Project
This program implements the Gale-Shapley algorithm to produce a list of stable matches.<br />
The program is given two files of unique names and each names' partner prefernces.<br />
EX: File1: {"Alex: Devin, Frank, Erik", "Bob: Frank, Erik, Devin", "Charles: Devin, Erik, Frank"}<br />
File2: {"Devin: Charles, Bob, Alex", "Erik: Bob, Charles, Alex", "Frank: Bob, Alex, Charles"}<br />
Preferences are listed from left to right. In this case, Alex prefers to be partnered with Devin the most and Erik the least.<br />
Once given two files in this format, the algorithm will begin to pair each person.<br />
A match is considered stable if there are no two pairs (a, b) and (a’, b’) such that a’ is higher preference for b than a,
and b is higher preference for a’ than b’. (There are no two pairs where two people in different pairs prefer each other more than their current partners.)<br />
For the lists above, a stable matching would be the following:<br />
Alex + Erik, Bob + Frank, Charles + Devin<br />
Although Alex and Erik prefer each other the least, since no other person prefers them over their current partner, the matches are still considered stable.
