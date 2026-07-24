#ifndef PET_H
#define PET_H

#include <iostream>
#include <string>

using namespace std;

class Pet
{
private:
    string petID;
    string petName;
    string breed;
    string gender;

    int age;

    string color;

    float weight;

    bool vaccinated;

    string uniqueFeatures;

    string ownerName;

    string phoneNumber;

    string address;

    string status;

public:
    // Constructor
    Pet();

    // Parameterized Constructor
    Pet(string id,
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
        string status);

    // ======================
    // Getters
    // ======================

    string getPetID() const;
    string getPetName() const;
    string getBreed() const;
    string getGender() const;
    int getAge() const;
    string getColor() const;
    float getWeight() const;
    bool isVaccinated() const;
    string getUniqueFeatures() const;
    string getOwnerName() const;
    string getPhoneNumber() const;
    string getAddress() const;
    string getStatus() const;

    // ======================
    // Setters
    // ======================

    void setPetID(string);
    void setPetName(string);
    void setBreed(string);
    void setGender(string);
    void setAge(int);
    void setColor(string);
    void setWeight(float);
    void setVaccinated(bool);
    void setUniqueFeatures(string);
    void setOwnerName(string);
    void setPhoneNumber(string);
    void setAddress(string);
    void setStatus(string);

    // ======================
    // File Handling
    // ======================

    string toFileString() const;
    void fromFileString(const string &line);

    // ======================
    // Functions
    // ======================

    void inputPet();
    void displayPet() const;
};

#endif