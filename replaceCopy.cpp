#include <iostream>
#include <string>
#include <vector>

using namespace std;

string replace(string input, string replace, string to) {
    input += " "; //какое же костылище я выдал

    enum modes {
        justRead, spotted
    };

    modes mode = modes::justRead;

    size_t replaceBegin = 0, replaceEnd = 0;

    for(size_t i = 0; i < input.length();i++) {
        switch (mode) {

            case justRead:
                if(input[i] == replace[0]) {
                    mode = spotted;
                    i--;
                }
                break;

            case spotted:
                replaceBegin = i;
                size_t j = 0;
                for (j = 0; j < replace.length(); j++) {
                    if (input[i + j] != replace[j]) {
                        mode = justRead;
                        
                        replaceEnd = j;
                        break;
                    }
                }
                if(input[j+i] == ' ' && input[i-1] == ' ') {
                    if (mode == justRead) {
                        //cout << "bryak" << endl;
                        break;
                    } else if(mode != justRead) {
                    replaceEnd = replaceBegin + replace.length();
                    input.erase(input.begin() + replaceBegin, input.begin() + replaceEnd);
                    input.insert(i, to);
                    break;
                    }
                }
        }
    }
    input.erase(input.length() - 1); //костылище
    return(input);
}

int main() {
    cout << replace("aboba + abobus = nice", "abobus", "(a)");
    cout << endl;
}