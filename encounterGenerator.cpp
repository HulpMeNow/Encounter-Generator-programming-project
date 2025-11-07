#include "encounterGenerator.h"
#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>

// constructor
EncounterGenerator::EncounterGenerator() : totalWeight(0) {}

// destructor
EncounterGenerator::~EncounterGenerator() {
    monsters.clear();
    cumulativeWeights.clear();
}

void EncounterGenerator::addMonster(const std::string& name, int weight) {
    // checks for needed conditions and throws exceptions for any invalid cases
    if (totalWeight == 10) throw std::invalid_argument("Error: maximum cumalative weight 100% or 10 reached");
    if (weight <= 0) throw std::invalid_argument("Error \"invalid_argument\", weight must be positive and greater than 0");
    if (weight > 10) throw std::invalid_argument("Error. Cannot have weight exceding 100% or 10.");
    
    monsters.push_back(name); // add to monsters vector
    totalWeight += weight;
    if (cumulativeWeights.empty())
        cumulativeWeights.push_back(weight);
    else
        cumulativeWeights.push_back(cumulativeWeights.back() + weight);
}

int EncounterGenerator::getSize() {
    return monsters.size();
}

std::string EncounterGenerator::getMonsterName(int index) {
    if (index < 0 || index >= monsters.size()) throw std::invalid_argument("Error: index out of bounds");
    return monsters[index];
}

int EncounterGenerator::getMonsterWeight(int index) {
    if (index < 0 || index >= monsters.size()) throw std::invalid_argument("Error: index out of bounds");
    if (index == 0) return cumulativeWeights[index];
    int returnWeight = cumulativeWeights[index];
    
    returnWeight = returnWeight - cumulativeWeights[index - 1];
    
    return returnWeight;
}
std::string EncounterGenerator::getRandomEncounter() {
    if (monsters.empty()) throw std::runtime_error("No monsters added to the encounter generator.");

    //random number code generously provided by professor Eric.
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, totalWeight - 1); // totalWeight-1 as should be able to work with less than 100% of the weight accounted for ? 
    int randomNum = dist(gen);
    //int index;
    /* //this is linear search
    for (int i = 0; i < monsters.size(); i++) {
        if (randomNum < cumulativeWeights[i]){
            return monsters[i];
        }
    }
    */
    // binary search
    int low = 0;
    int high = cumulativeWeights.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (randomNum < cumulativeWeights[mid]) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return monsters[low]; // we want the monster at the cumulative weight closest to the random number which is larger than the random number. 
    
    //return "Error has been achieved"; // this statement should never be reached. 
    

    // below is magic cpp code that makes 0 sense to me but works :)
    //auto it = std::upper_bound(cumulativeWeights.begin(), cumulativeWeights.end(), randomNum);
    //int index = std::distance(cumulativeWeights.begin(), it);
    //return monsters[index];
}
