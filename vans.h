#ifndef VANS_H
#define VANS_H
#include "packages.h"

const int MAX_LOAD = 8;
const int MAX_VANS = 10;

class tLoaded {
	private:
		string* ids;
		int counter;
		int size;

	public:
		tLoaded();
		~tLoaded();

		bool addPackage(const string& id);
		void showLoaded() const;
		void clear();
};

class tVan {
	private:
		int postalCode;
		tLoaded loadedPackages;

	public:
		tVan();
		void setPostalCode(int code);
		int getPostalCode() const;
		tLoaded& getLoaded();
		void showVan() const;
};

class tVans {
	private:
		tVan arrayVans[MAX_VANS];

		int searchVan(int code) const;

public:
		tVans();
		bool loadPostalCodes(ifstream& archivo);
		void showVans() const;
		void loadPackages(tPackages& packages);
};

#endif
