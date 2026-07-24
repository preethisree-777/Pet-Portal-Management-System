#include "../include/Pet.h"
#include "../include/Validation.h"
#include <sstream>
#include <limits>
// =========================
// Default Constructor
// =========================

Pet::Pet()
{
    petID = "";
    petName = "";
    breed = "";
    gender = "";
    age = 0;
    color = "";
    weight = 0.0;
    vaccinated = false;
    uniqueFeatures = "";
    ownerName = "";
    phoneNumber = "";
    address = "";
    status = "Registered";
}

// =========================
// Parameterized Constructor
// =========================

Pet::Pet(string id,
         string name,
         string breed,
         string gender,
         int age,
         string color,
         float weight,
         bool vaccinated,
         string feature,
         string owner,
         string phone,
         string address,
         string status)
{
    petID = id;
    petName = name;
    this->breed = breed;
    this->gender = gender;
    this->age = age;
    this->color = color;
    this->weight = weight;
    this->vaccinated = vaccinated;
    uniqueFeatures = feature;
    ownerName = owner;
    phoneNumber = phone;
    this->address = address;
    this->status = status;
}

// =========================
// Getters
// =========================

string Pet::getPetID() const
{
    return petID;
}

string Pet::getPetName() const
{
    return petName;
}

string Pet::getBreed() const
{
    return breed;
}

string Pet::getGender() const
{
    return gender;
}

int Pet::getAge() const
{
    return age;
}

string Pet::getColor() const
{
    return color;
}

float Pet::getWeight() const
{
    return weight;
}

bool Pet::isVaccinated() const
{
    return vaccinated;
}

string Pet::getUniqueFeatures() const
{
    return uniqueFeatures;
}

string Pet::getOwnerName() const
{
    return ownerName;
}

string Pet::getPhoneNumber() const
{
    return phoneNumber;
}

string Pet::getAddress() const
{
    return address;
}

string Pet::getStatus() const
{
    return status;
}

// =========================
// Setters
// =========================

void Pet::setPetID(string id)
{
    petID = id;
}

void Pet::setPetName(string name)
{
    petName = name;
}

void Pet::setBreed(string breed)
{
    this->breed = breed;
}

void Pet::setGender(string gender)
{
    this->gender = gender;
}

void Pet::setAge(int age)
{
    this->age = age;
}

void Pet::setColor(string color)
{
    this->color = color;
}

void Pet::setWeight(float weight)
{
    this->weight = weight;
}

void Pet::setVaccinated(bool vaccinated)
{
    this->vaccinated = vaccinated;
}

void Pet::setUniqueFeatures(string feature)
{
    uniqueFeatures = feature;
}

void Pet::setOwnerName(string owner)
{
    ownerName = owner;
}

void Pet::setPhoneNumber(string phone)
{
    phoneNumber = phone;
}

void Pet::setAddress(string address)
{
    this->address = address;
}

void Pet::setStatus(string status)
{
    this->status = status;
}

// =========================
// Input Function
// =========================

void Pet::inputPet()
{
    cout << "\n========== Pet Registration ==========\n";

    cout << "Enter Pet ID: ";
    getline(cin, petID);

    do
    {
        cout << "Enter Pet Name: ";
        getline(cin, petName);

        if (!Validation::isValidName(petName))
            cout << "Pet Name cannot be empty.\n";

    } while (!Validation::isValidName(petName));

    cout << "Enter Breed: ";
    getline(cin, breed);

    do
    {
        cout << "Enter Gender (Male/Female): ";
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

    do
    {
        cout << "Enter Age: ";

        cin >> age;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input! Please enter numbers only.\n";
            continue;
        }

        if (!Validation::isValidAge(age))
        {
            cout << "Invalid Age! Enter between 1 and 30.\n";
        }

    } while (!Validation::isValidAge(age));

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    do
    {
        cout << "Enter Weight: ";

        cin >> weight;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input! Please enter numbers only.\n";
            continue;
        }

        if (!Validation::isValidWeight(weight))
        {
            cout << "Invalid Weight! Weight must be greater than 0.\n";
        }

    } while (!Validation::isValidWeight(weight));

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // cin.ignore();

    cout << "Enter Color: ";
    getline(cin, color);

    int choice;

    do
    {
        cout << "Vaccinated (1 = Yes / 0 = No): ";

        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input! Enter 1 or 0 only.\n";
            continue;
        }

        if (choice != 0 && choice != 1)
        {
            cout << "Please enter 1 or 0 only.\n";
            continue;
        }

        vaccinated = choice;

        break;

    } while (true);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // cin.ignore();

    cout << "Unique Features: ";
    getline(cin, uniqueFeatures);

    do
    {
        cout << "Owner Name: ";
        getline(cin, ownerName);

        if (!Validation::isValidName(ownerName))
            cout << "Owner Name cannot be empty.\n";

    } while (!Validation::isValidName(ownerName));

    do
    {
        cout << "Phone Number: ";
        getline(cin, phoneNumber);

        if (!Validation::isValidPhone(phoneNumber))
            cout << "Enter a valid 10-digit phone number.\n";

    } while (!Validation::isValidPhone(phoneNumber));

    cout << "Address: ";
    getline(cin, address);

    status = "Registered";
}

// =========================
// Display Function
// =========================

void Pet::displayPet() const
{
    cout << "\n========================================\n";
    cout << "Pet ID           : " << petID << endl;
    cout << "Pet Name         : " << petName << endl;
    cout << "Breed            : " << breed << endl;
    cout << "Gender           : " << gender << endl;
    cout << "Age              : " << age << endl;
    cout << "Weight           : " << weight << " kg" << endl;
    cout << "Color            : " << color << endl;
    cout << "Vaccinated       : " << (vaccinated ? "Yes" : "No") << endl;
    cout << "Unique Features  : " << uniqueFeatures << endl;
    cout << "Owner Name       : " << ownerName << endl;
    cout << "Phone Number     : " << phoneNumber << endl;
    cout << "Address          : " << address << endl;
    cout << "Status           : " << status << endl;
    cout << "========================================\n";
}
// =========================
// Convert Object to File String
// =========================

string Pet::toFileString() const
{
    stringstream ss;

    ss << petID << "|"
       << petName << "|"
       << breed << "|"
       << gender << "|"
       << age << "|"
       << color << "|"
       << weight << "|"
       << vaccinated << "|"
       << uniqueFeatures << "|"
       << ownerName << "|"
       << phoneNumber << "|"
       << address << "|"
       << status;

    return ss.str();
}

// =========================
// Convert File String to Object
// =========================

void Pet::fromFileString(const string &line)
{
    stringstream ss(line);
    string temp;

    getline(ss, petID, '|');
    getline(ss, petName, '|');
    getline(ss, breed, '|');
    getline(ss, gender, '|');

    getline(ss, temp, '|');
    age = stoi(temp);

    getline(ss, color, '|');

    getline(ss, temp, '|');
    weight = stof(temp);

    getline(ss, temp, '|');
    vaccinated = (temp == "1");

    getline(ss, uniqueFeatures, '|');
    getline(ss, ownerName, '|');
    getline(ss, phoneNumber, '|');
    getline(ss, address, '|');
    getline(ss, status);
}