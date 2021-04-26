#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <map>

using namespace std;

class Catalogue;

class Catalogue {
public:
	Catalogue() { }

	Catalogue* getCatalogue(string const filename) {
		if (catalogueContent.find(filename) != catalogueContent.end()) {
			return catalogueContent[filename];
		}
		else {
			catalogueContent[filename] = new Catalogue();
			return catalogueContent[filename];
		}
	}

	void traverse(string currTabs) {
		string tabs = " ";
		tabs += currTabs;

		map<string, Catalogue*> orderedContent(catalogueContent.begin(), catalogueContent.end());

		for (auto it = orderedContent.begin(); it != orderedContent.end(); it++) {
			cout << currTabs << it->first << endl;	// print key
			it->second->traverse(tabs);				// traverse value
		}
	}

private:
	unordered_map< string, Catalogue* > catalogueContent;

};

int main() {
	size_t count;
	cin >> count;

	Catalogue* root = new Catalogue();

	string str;

	for (size_t i = 0; i <= count; i++) {
		getline(cin, str);
		stringstream path(str);

		Catalogue* current_catalog = root;

		while (getline(path, str, '\\')) {
			current_catalog = current_catalog->getCatalogue(str);
		}
	}

	root->traverse("");

	return 0;
}
