#include <iostream>
#include <string>
#include <vector>

#include "removeAllSpaces.h"

using namespace std;

int main() {
    enum modes {
        onNumber, onSpace, onCommand, onOperator //хз, зачем я впихнул сюда onOperator
    };

    modes mode = modes::onNumber;

	string input = "", temp = "";

	getline(cin,input);

    for(int i = 0; i < input.length(); i++) {
        if(((input[i] < 'A' || input[i] > 'Z') && (input[i] < 'a' || input[i] > 'z')) &&
           ((input[i] < 37 || input[i] > 58) || (input[i] == 44 || input[i] == 39 || input[i] == 38)) && input[i] != ' ') {
            for(int j = 0; j < i; j++) {
                cout << " ";
            }

            printf("^\nsyntax error\n");
            return 993;
        }
    }

    input = rsp(input);

    double result = 0., value = 0.;

    for(int i = 0; i < input.length(); i++) {
        switch(mode) {
            case onNumber:

                break;

            case onSpace:

                break;

            case onCommand:

                break;

            case onOperator:

                break;

            default:

                break;
        }
    }
}
