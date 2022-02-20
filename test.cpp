#include <iostream>
#include <string>

using namespace std;
int rec(int iter) {
    switch(input[iter]) {
            case 'E':
            case 'e':
            case 'Y':
            case 'y':
            case 'U':
            case 'u':
            case 'O':
            case 'o':
            case 'I':
            case 'i':
            case 'A':
            case 'a':
            input[iter] = '!';
            break;
            default:
            break;
        }
    return 0;
}

int main() {
    char input[256];
    
    cin >> input;
    rec(0);
}