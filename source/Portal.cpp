#include "../include/Portal.h"
#include "../include/Pet.h"
#include "../include/FileManager.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

//==========================================
// Show Menu
//==========================================

void Portal::showMenu()
{
    cout << "\n=====================================================\n";
    cout << "           PET PORTAL MANAGEMENT SYSTEM\n";
    cout << "=====================================================\n";

    cout << "1. Register Pet\n";
    cout << "2. View All Pets\n";
    cout << "3. Search Pet\n";
    cout << "4. Update Pet\n";
    cout << "5. Delete Pet\n";
    cout << "6. Statistics\n";
    cout << "7. Sort Pets\n";
    cout << "8. Exit\n";

    cout << "\nEnter Choice : ";
}

//==========================================
// View All Pets
//==========================================

void Portal::viewAllPets()
{
    vector<Pet> pets = FileManager::loadPets();

    if (pets.empty())
    {
        cout << "\nNo pets found.\n";
        return;
    }

    cout << "\n==============================================================================================================\n";

    cout << left
         << setw(10) << "Pet ID"
         << setw(18) << "Pet Name"
         << setw(18) << "Breed"
         << setw(8) << "Age"
         << setw(12) << "Gender"
         << setw(10) << "Weight"
         << setw(20) << "Owner"
         << setw(15) << "Status"
         << endl;

    cout << "==============================================================================================================\n";

    for (const Pet &pet : pets)
    {
        cout << left
             << setw(10) << pet.getPetID()
             << setw(18) << pet.getPetName()
             << setw(18) << pet.getBreed()
             << setw(8) << pet.getAge()
             << setw(12) << pet.getGender()
             << setw(10) << fixed << setprecision(1) << pet.getWeight()
             << setw(20) << pet.getOwnerName()
             << setw(15) << pet.getStatus()
             << endl;
    }

    cout << "==============================================================================================================\n";
}

//==========================================
// Search Pet
//==========================================

void Portal::searchPet()
{
    string id;

    cout << "\n========== SEARCH PET ==========\n";
    cout << "Enter Pet ID : ";
    getline(cin, id);

    Pet pet;

    if (FileManager::searchPet(id, pet))
    {
        cout << "\nPet Found!\n\n";
        pet.displayPet();
    }
    else
    {
        cout << "\nPet not found.\n";
    }
}

//==========================================
// Update Pet
//==========================================

void Portal::updatePet()
{
    vector<Pet> pets = FileManager::loadPets();

    if (pets.empty())
    {
        cout << "\nNo pets found.\n";
        return;
    }

    string id;

    cout << "\n========== UPDATE PET ==========\n";
    cout << "Enter Pet ID : ";
    getline(cin, id);

    bool found = false;

    for (Pet &pet : pets)
    {
        if (pet.getPetID() == id)
        {
            found = true;

            cout << "\nPet Found!\n\n";
            pet.displayPet();

            string input;
            int age;
            float weight;
            bool vaccinated;

            cout << "\nEnter New Pet Name : ";
            getline(cin, input);
            pet.setPetName(input);

            cout << "Enter New Breed : ";
            getline(cin, input);
            pet.setBreed(input);

            string gender;

            do
            {
                cout << "Enter New Gender (Male/Female): ";
                getline(cin, gender);

                if (gender != "Male" &&
                    gender != "Female" &&
                    gender != "male" &&
                    gender != "female")
                {
                    cout << "Invalid Gender! Enter Male or Female.\n";
                }

            } while (gender != "Male" &&
                     gender != "Female" &&
                     gender != "male" &&
                     gender != "female");

            pet.setGender(gender);

            do
            {
                cout << "Enter New Age : ";

                while (!(cin >> age))
                {
                    cout << "Invalid Age! Enter numbers only: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }

                if (age < 0 || age > 50)
                    cout << "Age must be between 0 and 50.\n";

            } while (age < 0 || age > 50);

            pet.setAge(age);

            do
            {
                cout << "Enter New Weight : ";

                while (!(cin >> weight))
                {
                    cout << "Invalid Weight! Enter numbers only: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }

                if (weight <= 0 || weight > 200)
                    cout << "Weight must be between 1 and 200 kg.\n";

            } while (weight <= 0 || weight > 200);

            pet.setWeight(weight);

            cout << "Vaccinated (1=Yes 0=No) : ";
            cin >> vaccinated;
            pet.setVaccinated(vaccinated);

            cin.ignore();

            cout << "Enter New Color : ";
            getline(cin, input);
            pet.setColor(input);

            cout << "Enter Unique Features : ";
            getline(cin, input);
            pet.setUniqueFeatures(input);

            cout << "Enter Owner Name : ";
            getline(cin, input);
            pet.setOwnerName(input);

            cout << "Enter Phone Number : ";
            getline(cin, input);
            pet.setPhoneNumber(input);

            cout << "Enter Address : ";
            getline(cin, input);
            pet.setAddress(input);

            break;
        }
    }

    if (!found)
    {
        cout << "\nPet not found.\n";
        return;
    }

    ofstream file("database/pets.txt");

    for (const Pet &pet : pets)
    {
        file << pet.toFileString() << endl;
    }

    file.close();

    cout << "\nPet Updated Successfully!\n";
}

//==========================================
// Delete Pet
//==========================================

void Portal::deletePet()
{
    vector<Pet> pets = FileManager::loadPets();

    if (pets.empty())
    {
        cout << "\nNo pets found.\n";
        return;
    }

    string id;

    cout << "\n========== DELETE PET ==========\n";
    cout << "Enter Pet ID : ";
    getline(cin, id);

    bool found = false;

    vector<Pet> updatedPets;

    for (const Pet &pet : pets)
    {
        if (pet.getPetID() == id)
        {
            found = true;

            cout << "\nPet Found!\n";
            pet.displayPet();

            char confirm;

            cout << "\nDelete this pet? (Y/N): ";
            cin >> confirm;
            cin.ignore();

            if (confirm == 'Y' || confirm == 'y')
            {
                cout << "\nPet Deleted Successfully!\n";
                continue; // Skip writing this pet
            }
        }

        updatedPets.push_back(pet);
    }

    if (!found)
    {
        cout << "\nPet not found.\n";
        return;
    }

    ofstream file("database/pets.txt");

    for (const Pet &pet : updatedPets)
    {
        file << pet.toFileString() << endl;
    }

    file.close();
}

void Portal::registerPet()
{
    Pet pet;

    pet.inputPet();

    if (FileManager::petExists(pet.getPetID()))
    {
        cout << "\n=====================================\n";
        cout << " Pet ID already exists!\n";
        cout << " Registration Failed.\n";
        cout << "=====================================\n";

        return;
    }

    if (FileManager::savePet(pet))
    {
        cout << "\nPet Registered Successfully!\n";
    }
    else
    {
        cout << "\nUnable to Save Pet!\n";
    }
}

void Portal::showStatistics()
{
    vector<Pet> pets = FileManager::loadPets();

    if (pets.empty())
    {
        cout << "\nNo pets found.\n";
        return;
    }

    int vaccinated = 0;
    int notVaccinated = 0;
    int male = 0;
    int female = 0;

    float totalAge = 0;
    float totalWeight = 0;

    for (const Pet &pet : pets)
    {
        totalAge += pet.getAge();
        totalWeight += pet.getWeight();

        if (pet.isVaccinated())
            vaccinated++;
        else
            notVaccinated++;

        if (pet.getGender() == "Male" || pet.getGender() == "male")
            male++;
        else if (pet.getGender() == "Female" || pet.getGender() == "female")
            female++;
    }

    cout << "\n=====================================\n";
    cout << "         PET STATISTICS\n";
    cout << "=====================================\n";

    cout << "Total Pets       : " << pets.size() << endl;
    cout << "Vaccinated       : " << vaccinated << endl;
    cout << "Not Vaccinated   : " << notVaccinated << endl;
    cout << "Male Pets        : " << male << endl;
    cout << "Female Pets      : " << female << endl;
    cout << "Average Age      : " << totalAge / pets.size() << endl;
    cout << "Average Weight   : " << totalWeight / pets.size() << endl;

    cout << "=====================================\n";
}

void Portal::sortPets()
{
    vector<Pet> pets = FileManager::loadPets();

    if (pets.empty())
    {
        cout << "\nNo pets found.\n";
        return;
    }

    int choice;

    cout << "\n========== SORT PETS ==========\n";
    cout << "1. Sort by ID\n";
    cout << "2. Sort by Name\n";
    cout << "3. Sort by Age\n";
    cout << "Enter Choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:

        sort(pets.begin(), pets.end(),
             [](Pet a, Pet b)
             {
                 return a.getPetID() < b.getPetID();
             });

        break;

    case 2:

        sort(pets.begin(), pets.end(),
             [](Pet a, Pet b)
             {
                 return a.getPetName() < b.getPetName();
             });

        break;

    case 3:

        sort(pets.begin(), pets.end(),
             [](Pet a, Pet b)
             {
                 return a.getAge() < b.getAge();
             });

        break;

    default:
        cout << "\nInvalid Choice!\n";
        return;
    }

    cout << "\n=========================================================================================================\n";

    cout << left
         << setw(8) << "ID"
         << setw(15) << "Pet Name"
         << setw(15) << "Breed"
         << setw(8) << "Age"
         << setw(10) << "Gender"
         << setw(10) << "Weight"
         << setw(15) << "Owner"
         << setw(15) << "Status"
         << endl;

    cout << "=========================================================================================================\n";

    for (const Pet &pet : pets)
    {
        cout << left
             << setw(8) << pet.getPetID()
             << setw(15) << pet.getPetName()
             << setw(15) << pet.getBreed()
             << setw(8) << pet.getAge()
             << setw(10) << pet.getGender()
             << setw(10) << pet.getWeight()
             << setw(15) << pet.getOwnerName()
             << setw(15) << pet.getStatus()
             << endl;
    }

    cout << "=========================================================================================================\n";
}

//==========================================
// Run Portal
//==========================================

void Portal::run()
{
    int choice;

    do
    {
        showMenu();

        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            registerPet();
            break;

        case 2:
            viewAllPets();
            break;

        case 3:
            searchPet();
            break;

        case 4:
            updatePet();
            break;

        case 5:
            deletePet();
            break;

        case 6:
            showStatistics();
            break;

        case 7:
            sortPets();
            break;

        case 8:
            cout << "\nThank You for using Pet Portal!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 8);
}