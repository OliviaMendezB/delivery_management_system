#include "packages.h"

tPackage::tPackage() : id(""), postalCode(0), loaded(false) {}

tPackage::tPackage(string ID, int pc, bool load) : id(ID), postalCode(pc), loaded(load) {}

tPackage::tPackage(string ID, int pc) : id(ID), postalCode(pc), loaded(false) {}

string tPackage::getID() const { return id; }

int tPackage::getPostalCode() const { return postalCode; }

bool tPackage::isLoaded() const { return loaded; }

void tPackage::setLoaded(bool val) {
	loaded = val;
}

tPackages::tPackages() {
	counter = 0;
	for (int i = 0; i < MAX_PACKAGES; i++) {
		packages[i] = nullptr;
	}
}

tPackages::~tPackages() {
	for (int i = 0; i < MAX_PACKAGES; i++) {
		delete packages[i];
		packages[i] = nullptr;
	}
	counter = 0;
}

bool tPackages::loadPackages(ifstream& archivo) {
	if (archivo.is_open()) {
		int n;
		archivo >> n;
		if (n > MAX_PACKAGES) n = MAX_PACKAGES;
		counter = n;
		for (int i = 0; i < counter; i++) {
			string id_;
			int postalCode_;

			archivo >> id_ >> postalCode_;

			tPackage* p = new tPackage(id_, postalCode_);
			packages[i] = p;
		}

		return true;
	}
	return false;
}

void tPackages::showPackages() const {
	for (int i = 0; i < counter; i++) {
		cout << packages[i]->getID() << " is sent to " << packages[i]->getPostalCode() 
			<< " - loaded: ";
		if (packages[i]->isLoaded()) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	cout << '\n';
}

int tPackages::getCounter() const {
	return counter;
}

tPtrPackage tPackages::getPackage(int i) const {
	if (i >= 0 && i < counter) {
		return packages[i];
	}
	else return nullptr;
}

void tPackages::pickUpPackage() {

	string id;
	cout << "Enter package ID: ";
	cin >> id;

	for (int i = 0; i < counter; i++) {

		if (packages[i]->getID() == id) {

			if (packages[i]->isLoaded()) {
				cout << "Package already loaded in a van.\n";
				return;
			}

			delete packages[i];

			for (int j = i; j < counter - 1; j++) {
				packages[j] = packages[j + 1];
			}

			packages[counter - 1] = nullptr;
			counter--;

			cout << "Package collected successfully.\n";
			return;
		}
	}

	cout << "Package not found.\n";
}
