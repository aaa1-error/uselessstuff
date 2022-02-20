#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string input;
	vector<char> uniques;
	bool isUnique = true;

	getline(cin, input);

	for(size_t i = 0; i < input.length(); i++) {
		isUnique = true;
		for(size_t j = 0; j < uniques.size();j++) {
			if(input[i] == uniques[j]) {
				input[i] = 0;
				isUnique = false;
				break;
			}
		}
		if(isUnique) {
			uniques.push_back(input[i]);
		}
	}
	cout << input << endl;
}
