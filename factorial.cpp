#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n = 0;
    long long unsigned int fac = 1;
    cin >> n;
    if(n <= 1 || n >= 21) {
        printf("No.\n");
        return -1;
    }
    for(int i = n; i > 1;i--) {
        fac *= i;
    }
    cout << fac << endl;
}