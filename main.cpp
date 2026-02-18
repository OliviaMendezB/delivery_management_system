#include <iostream>
#include <fstream>
#include "packages.h"
#include "vans.h"

using namespace std;

int main() {

    ifstream filePackages("packages.txt");
    ifstream fileVans("vans.txt");

    if (!filePackages.is_open()) {
        cout << "Error opening packages file.\n";
        return -1;
    }

    if (!fileVans.is_open()) {
        cout << "Error opening vans file.\n";
        return -1;
    }

    tPackages packages;
    tVans vans;

    packages.loadPackages(filePackages);
    vans.loadPostalCodes(fileVans);

    filePackages.close();
    fileVans.close();


    cout << "INITIAL PACKAGES:\n";
    packages.showPackages();

    cout << "\nINITIAL VANS:\n";
    vans.showVans();

    vans.loadPackages(packages);

    cout << "\n--- PACKAGES AFTER LOADING INTO VANS ---\n";
    packages.showPackages();

    cout << "\n--- VANS AFTER LOADING VANS PACKAGES ---\n";
    vans.showVans();
 
    cout << "\n--- COLLECT PACKAGE ---\n";
    packages.pickUpPackage();

    cout << "\nFINAL PACKAGES:\n";
    packages.showPackages();

    cout << "\nFINAL VANS:\n";
    vans.showVans();

    return 0;
}
