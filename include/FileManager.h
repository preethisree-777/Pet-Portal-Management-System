#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <string>

#include "Pet.h"

using namespace std;

class FileManager
{
public:
    // Save one pet
    static bool savePet(const Pet &pet);

    // Load all pets
    static vector<Pet> loadPets();

    // Search Pet
    // static bool petExists(const string &petID);
    static bool searchPet(const string &petID, Pet &foundPet);

    // Update Pet
    static bool updatePet(const Pet &updatedPet);

    // Delete Pet
    static bool deletePet(const string &petID);

    static bool petExists(const string &petID);

    // Clear Database (Optional)
    static void clearDatabase();
};

#endif