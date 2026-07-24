#include "../include/FileManager.h"

#include <fstream>
#include <iostream>

using namespace std;

//==========================================
// Save Pet
//==========================================

bool FileManager::savePet(const Pet &pet)
{
    ofstream file("database/pets.txt", ios::app);

    if (!file.is_open())
    {
        cout << "Error opening database/pets.txt\n";
        return false;
    }

    file << pet.toFileString() << endl;

    file.close();

    return true;
}

//==========================================
// Load Pets
//==========================================

vector<Pet> FileManager::loadPets()
{
    vector<Pet> pets;

    ifstream file("database/pets.txt");

    if (!file.is_open())
    {
        return pets;
    }

    string line;

    while (getline(file, line))
    {
        if (line.empty())
            continue;

        Pet pet;

        pet.fromFileString(line);

        pets.push_back(pet);
    }

    file.close();

    return pets;
}

bool FileManager::searchPet(const string &petID, Pet &foundPet)
{
    vector<Pet> pets = loadPets();

    for (const Pet &pet : pets)
    {
        if (pet.getPetID() == petID)
        {
            foundPet = pet;
            return true;
        }
    }

    return false;
}

//==========================================
// Check if Pet ID Exists
//==========================================

bool FileManager::petExists(const string &petID)
{
    vector<Pet> pets = loadPets();

    for (const Pet &pet : pets)
    {
        if (pet.getPetID() == petID)
        {
            return true;
        }
    }

    return false;
}