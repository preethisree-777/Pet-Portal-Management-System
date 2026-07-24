#include "../include/Validation.h"

#include <cctype>

using namespace std;

//==============================
// Validate Name
//==============================

bool Validation::isValidName(const string &name)
{
    return !name.empty();
}

//==============================
// Validate Age
//==============================

bool Validation::isValidAge(int age)
{
    return age > 0 && age <= 30;
}

//==============================
// Validate Weight
//==============================

bool Validation::isValidWeight(float weight)
{
    return weight > 0;
}

//==============================
// Validate Phone Number
//==============================

bool Validation::isValidPhone(const string &phone)
{
    if (phone.length() != 10)
        return false;

    for (char c : phone)
    {
        if (!isdigit(c))
            return false;
    }

    return true;
}