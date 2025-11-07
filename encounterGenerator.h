#ifndef ENCOUNTERGENERATOR_H
#define ENCOUNTERGENERATOR_H

#include <vector>
#include <string>
#include <random>
#include <utility>

/*
This code does throw exceptions. 

*/

class EncounterGenerator {
private:
    std::vector<std::string> monsters; // get get methods f0or these two private things.
    std::vector<int> cumulativeWeights;
    //bool hasSpecialCharacters(const std::string& str); // helper method to check if a string has special characters.

    int totalWeight;

public:
    //std::vector<std::string> monsters; // get get methods f0or these two private things.
    //std::vector<int> cumulativeWeights;

    // this method checks if a string has any special chars and throws exception if it does
    //void checkString(const std::string& str);
    // i have removed this method as I see mixed results as to the kind of characters dnd names have so I am ommiting this. still have to be a string cor cpp though.

    // this method returns the name of the monster at a spesific index
    // throws invalid argument error
    std::string getMonsterName(int index);

    // this emthod returns the weightage of the monster at a specific index
    // throws invalid argument error
    int getMonsterWeight(int index);

    // constructor.
    EncounterGenerator();

    // destructor.

    ~EncounterGenerator();

    // this method allows the user to add monsters with a weight. the name has to be a proper string and the weight is an int between 0 and 10.
    // this method throws invalid argument error if the weight is invalid or does not make sense, ie it exceed 100%.
    void addMonster(const std::string& name, int weight);
    

    // this generates a random number and uses it to generate a random encounter
    // throws runtime error if no monsters are added
    std::string getRandomEncounter();

    // this method returns the size of the monster vector.
    int getSize();
};

#endif // ENCOUNTERGENERATOR_H
