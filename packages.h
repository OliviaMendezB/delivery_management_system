#ifndef PACKAGES_H
#define PACKAGES_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

const int MAX_PACKAGES = 50;

class tPackage {
	private:
		string id;
		int postalCode;
		bool loaded;

	public:
		tPackage();
		tPackage(string ID, int pc, bool load);
		tPackage(string ID, int pc);

		string getID() const;
		int getPostalCode() const;
		bool isLoaded() const;

		void setLoaded(bool val);
};

typedef tPackage* tPtrPackage;

class tPackages {
	private:
		tPtrPackage packages[MAX_PACKAGES];
		int counter;

	public:
		tPackages();
		~tPackages();

		bool loadPackages(ifstream& archivo);
		void showPackages() const;

		int getCounter() const;
		tPtrPackage getPackage(int i) const;

		void pickUpPackage();
};

#endif