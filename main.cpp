#include <iostream>
#include "encounterGenerator.h"
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cassert>
#include <map>

using namespace std;

// prototype
void testEverything(void);


int main() {
    // This code is pretty basic, and is coded for these spesific monster names.
    // comment out the multiline comment to use this code. comment out the test method.
    /*
    cout << "Welcome to dungeons and dwagons!!!! You are about to meet some monsters." << endl;
    EncounterGenerator generator2;

    // add monsters
    // this part of the code can be modified as the user wishes, change the names and the weightages. note the number has to be between 0 and 10, and will be rounded to an int. the name will be taken as a string. special char are allowed like '.
    generator2.addMonster("bogdan", 5);
    generator2.addMonster("screamin' mimi", 2);
    generator2.addMonster("kill kitten", 2);
    generator2.addMonster("pokemonasaurus", 1);
    //generator.addMonster("oatBoy", 2); // you cannot add this as it would exceed the total weight of 10

    cout << "Today you might meet a Bogdan, Screamin' Mimi, Kill Kitten, or Pokemonasaurus." << endl;
    std::cout << "Press <enter> to find a foe. Type 'q' to quit.\n";
    std::string input;
    while (true) {
        std::getline(std::cin, input);
        if (input == "q") break;
        // since I am now throwing errors, using try catch blocks
        try {
            std::cout << "Encounter: " << generator2.getRandomEncounter() << "\n";
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }
    */
    
    testEverything(); // this is the test method. It checks to see the weightage is working fine. Do note there is no input checks here so ensure you enter an int
    // this test method is also hard coded for this number of monsters and their spesific names. the weightage can be changed though.
    return 0;
}

void testEverything() {
    EncounterGenerator generator;

    // add monsters
    generator.addMonster("bogdan", 5);
    generator.addMonster("screamin' mimi", 2);
    generator.addMonster("kill kitten", 2);
    generator.addMonster("pokemonasaurus", 1);

    
    cout << "Testing Encounter Generator\n";
    cout << "Enter an int number to run test that many times: " << endl;
    
    int runTest;

    int bogdanCount = 0;
    int screamin_mimiCount = 0;
    int kill_kittenCount = 0;
    int pokemonasaurusCount = 0;
    
    cin >> runTest;
    //map<int, string, int, int> testMap;
    for (int i = 0; i < runTest; i++) {
        string encounter = generator.getRandomEncounter();
        if (encounter == "bogdan") {
            bogdanCount++;
        } else if (encounter == "screamin' mimi") {
            screamin_mimiCount++;
        } else if (encounter == "kill kitten") {
            kill_kittenCount++;
        } else if (encounter == "pokemonasaurus") {
            pokemonasaurusCount++;
        }
    }
    
    cout << "Option 1: Weight: " << generator.getMonsterWeight(0) << " Name: " << generator.getMonsterName(0) << endl;//" Expected outcome: " << (generator.getMonsterWeight(0))*runTest/10 << " Actual outcome: " << bogdanCount << endl;
    cout << "Option 2: Weight: " << generator.getMonsterWeight(1) << " Name: " << generator.getMonsterName(1) << endl;//" Expected outcome: " << (generator.getMonsterWeight(1))*runTest/10 << " Actual outcome: " << screamin_mimiCount << endl;
    cout << "Option 3: Weight: " << generator.getMonsterWeight(2) << " Name: " << generator.getMonsterName(2) << endl;//" Expected outcome: " << (generator.getMonsterWeight(2))*runTest/10 << " Actual outcome: " << kill_kittenCount << endl;
    cout << "Option 4: Weight: " << generator.getMonsterWeight(3) << " Name: " << generator.getMonsterName(3) << endl;//" Expected outcome: " << (generator.getMonsterWeight(3))*runTest/10 << " Actual outcome: " << pokemonasaurusCount << endl;

    // hard coded output table
    cout << "Name:                  " << "Expected distribution: " << "Actual outcome: " << "Cumulative total: " << endl;
    cout << "Bogdan                 " << generator.getMonsterWeight(0)*runTest/10 << "                    " << bogdanCount << "                 " << bogdanCount << endl;
    cout << "Screamin' Mimi         " << generator.getMonsterWeight(1)*runTest/10 << "                    " << screamin_mimiCount << "                 " << bogdanCount + screamin_mimiCount << endl;
    cout << "Kill Kitten            " << generator.getMonsterWeight(2)*runTest/10 << "                    " << kill_kittenCount << "                 " << bogdanCount + screamin_mimiCount + kill_kittenCount << endl;
    cout << "Pokemonasaurus         " << generator.getMonsterWeight(3)*runTest/10 << "                    " << pokemonasaurusCount << "                 " << bogdanCount + screamin_mimiCount + kill_kittenCount + pokemonasaurusCount<< endl;
}
