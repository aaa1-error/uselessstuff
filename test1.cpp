#include <iostream>
#include <string>

using namespace std;

int main() {
	bool hasDot = false;
	string inD = "";
    inD = inD + ".2";
    cout << inD[0] << endl;
	/*for(size_t i = 0; i < inD.length(); i++) {
		if(hasDot == true && inD[i] == '.') inD.erase(inD.begin() + i);
		if(inD[i] == '.') hasDot = true;
		if((inD[i] < 48 || inD[i] > 57) && inD[i] != '.') inD.erase(inD.begin() + i);
	}
	*/
    cout << stod(inD) << endl;
    cout << sizeof(inD) << endl;
}
