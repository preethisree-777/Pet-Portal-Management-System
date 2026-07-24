#ifndef PORTAL_H
#define PORTAL_H

class Portal
{
public:
    void run();

private:
    void showMenu();

    void registerPet();

    void viewAllPets();

    void searchPet();

    void updatePet();

    void deletePet();

    void showStatistics();

    void sortPets();
};

#endif