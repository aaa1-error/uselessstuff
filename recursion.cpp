#include <iostream>
#include <iomanip>
#include <stack>
#include <cmath>

using namespace std;

int getPriority(char operatorr) {
    switch(operatorr) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        case '(':
            return 228;
    }
    return -1;
}

struct lexem {
    char type;
    double value;
};

long double calculate(stack <lexem> & stack_numbers,stack <lexem> stack_operations, lexem & item) {
    long double result;
    switch(stack_operations.top().type) {
        case '+':
            break;
        case '-':
            break;
        case '*':
            break;
        case '/':
            break;
        case '%':
            break;
        case '^':
            break;
        default:
            break;
    }
    return result;
}

int main() {
    char input;
    long double value = 0.;

    stack <lexem> stack_numbers;
    stack <lexem> stack_operations;

    lexem item, temp;
    //input = cin.peek();
    cout << std::setprecision(30);
    
    /*while(1) {
        if(input == '\n') {
            break;
        }
        if (input == ' ') {
            continue;
        } else if(input >= '0' && input <= '9') { // если число
            cin >> value;
            item.type = '0';
            item.value = value;
            cout << value << endl;
            stack_numbers.push(item);
            continue;
        } else if(input == '+' || input == '-' || input == '*' || input == '/' || input  == '^' || input == '%' ) {
            item.type = input;
            item.value = 0;
            stack_operations.push(item);
            cin.ignore();
            continue;
        }
        if(input == '\n') {
            break;
        }
    }
    */
    while(1) {
    input = cin.peek();
    switch(input) { 
            case 10:
            goto loopbreak;
            break;

            case ' ':
                cin.ignore();
                break;  

            case '0' ... '9':
                cin >> value;
                item.type = '0';
                item.value = value;
                //cout << value << endl;
                stack_numbers.push(item);
                    break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                item.type = input;
                item.value = 0;
                stack_operations.push(item);
                cin.ignore();
                break;
            case ')':
            case '(':
                item.type = input;
                item.value = 0;
                stack_operations.push(item);
                cin.ignore();
                break;
            default:
                cout << input << endl;
                cin.ignore();
                break;
        }
    }
    loopbreak:;
    
}