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
    string operatorr;
    operatorr = "0";

	string input = "";
    vector <string> solution;

	getline(cin,input);

    input = rsp(input);
    input += "";

    for(int i = 0; i < input.length(); i++) {
        if((input[i] < 40 || input[i] > 57) && (input[i] == ',' || input[i] != '%') && input[i] != ' ') {
            cout << input << endl;
            for(int j = 0; j < i; j++) {
                cout << " ";
            }
            printf("^\nsyntax error\n");
            if(input[i] == ',') {
                printf("Я запрещаю использовать запятые.\n");
            }
            return 993;
        }
    }

    long double result = 0., value = 0.;
    string temp = "";
    bool hasDot = false, isFirstNumber = false;

    for(int i = 0; i < input.length(); i++) {
        switch(mode) {
            case onNumber:
                switch(input[i]) {
                    case 48:
                    case 49:
                    case 50:
                    case 51:
                    case 52:
                    case 53:
                    case 54:
                    case 55:
                    case 56:
                    case 57:
                    case 58:
                        temp += input[i];
                        break;
                    case '.':
                        if(hasDot == true) {
                            cout << input << endl;
                            for(int j = 0; j < i; j++) {
                                cout << " ";
                        }
                            printf("^\nsyntax error\n");
                            return 993;
                        } else if (hasDot == false) {
                            hasDot = true;
                            temp += input[i];
                        }
                        break;
                    case '/':
                    case '+':
                    case '-':
                    case '*':
                    case '%':
                        if((input[i-1] != '/' && input[i-1] != '+' && input[i-1] != '-' && input[i-1] != '*' && input[i-1] != '%') || (input[i-1] == '.' && input[i] >= '0' && input[i] <= '9')) {
                        solution.push_back(temp);
                        temp = "";
                        operatorr = input[i];
                        solution.push_back(operatorr);
                        operatorr = "";
                        hasDot = false;
                        break;
                        } else {
                            cout << input << endl;
                            for(int j = 0; j < i; j++) {
                                cout << " ";
                        }
                            printf("^\nsyntax error\n");
                            return 993;
                        }
                }
                break;
        }
    }

    for(int i = 0; i < solution.size(); i++) {
        cout << solution[i] << endl;
    }
}
