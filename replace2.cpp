#include <iostream>
#include <string>
#include <vector>

using namespace std;

string replace(string input, string replace, string to) {
    enum modes {
        justRead, spotted
    };
    modes mode = modes::justRead;
    int replaceBegin = 0, replaceEnd = 0;
    int inlen = input.length(), replen = replace.length();
    for (size_t i = 0; i < inlen;i++) {
        switch (mode) {

        case justRead:
            if (input[i] == replace[0]) {
                mode = spotted;
                i--;
            }
            break;

        case spotted:
            replaceBegin = i;
            size_t j = 0;
            for (j = 0; j < replen; j++) {
                if (input[i + j] != replace[j]) {
                    mode = justRead;

                    replaceEnd = j;
                    break;
                }
            }
            if (mode == justRead) break;
            replaceEnd = replaceBegin + replen;
            input.erase(input.begin() + replaceBegin, input.begin() + replaceEnd);
            input.insert(i, to);
            break;
        }
    }
    return(input);
}

int main() {
    ;
    cout << replace("hello big world big big", "world", "a") << endl;
    ;
}