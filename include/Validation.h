#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>

using namespace std;

class Validation
{
public:
    static bool isValidName(const string &name);
    static bool isValidAge(int age);
    static bool isValidWeight(float weight);
    static bool isValidPhone(const string &phone);
};

#endif