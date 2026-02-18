#include "vans.h"

tLoaded::tLoaded() {
	counter = 0;
	size = MAX_LOAD;
	ids = new string[size];
}

tLoaded::~tLoaded() {
	delete[] ids;
	ids = nullptr;
	counter = 0;
	size = 0;
}

bool tLoaded::addPackage(const string& id) {
	if (counter >= size) return false;
	ids[counter++] = id;
	return true;
}

void tLoaded::showLoaded() const {
	if (counter == 0) {
		cout << "No assigned packages";
		return;
	}

	for (int i = 0; i < counter; i++) {
		cout << ids[i] << " ";
	}
}

void tLoaded::clear() {
	counter = 0;
}

tVan::tVan() : postalCode(0) {}

void tVan::setPostalCode(int code) {
	postalCode = code;
}

int tVan::getPostalCode() const {
	return postalCode;
}

tLoaded& tVan::getLoaded() {
	return loadedPackages;
}

void tVan::showVan() const {
	cout << postalCode << " - Assigned packages : ";
	loadedPackages.showLoaded();
	cout << '\n';
}

tVans::tVans() {}

bool tVans::loadPostalCodes(ifstream& archivo) {
	if (!archivo.is_open()) return false;

	int cp;
	int i = 0;

	while (i < MAX_VANS && archivo >> cp) {
		arrayVans[i].setPostalCode(cp);
		arrayVans[i].getLoaded().clear();
		i++;
	}

	return (i == MAX_VANS);
}


void tVans::showVans() const {
	for (int i = 0; i < MAX_VANS; i++) {
		cout << "Van " << i + 1 << " delivers at ";
		arrayVans[i].showVan();
	}
}

int tVans::searchVan(int code) const {
	int left = 0, right = MAX_VANS - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		int midCode = arrayVans[mid].getPostalCode();
		if (midCode == code) return mid;
		else if (midCode < code) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}

void tVans::loadPackages(tPackages& packages) {
	for (int i = 0; i < packages.getCounter(); i++) {
		tPtrPackage p = packages.getPackage(i);

		if (p && !p->isLoaded()) {
			int idxVan = searchVan(p->getPostalCode());

			if (idxVan != -1) {
				bool success = arrayVans[idxVan]
					.getLoaded()
					.addPackage(p->getID());

				if (success) {
					p->setLoaded(true);
				}
			}
		}
	}
}
