#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

#define ASSERT(b) if (!(b)) throw ""

double evalrpn(stack<string> & tks) {
  ASSERT(!tks.empty());
  double x,y;
  auto tk = tks.top(); tks.pop();
  auto n = tk.size();
  if (n==1 && string("+-*/").find(tk)!=string::npos) {
    y = evalrpn(tks);
    x = evalrpn(tks);
    if      (tk[0]=='+')  x += y;
    else if (tk[0]=='-')  x -= y;
    else if (tk[0]=='*')  x *= y;
    else                  x /= y;
  }  else {
    unsigned i;  x = stod(tk,&i);  ASSERT(i==n);
  }
  return x;
}

int main() {
  string s;
  while (getline(cin,s)) {
    stack<string> tks;
    istringstream sstr(s);
    string tk;
    while (sstr >> tk) tks.push(tk);
    if (!tks.empty())
      try {
        auto z = evalrpn(tks);
        ASSERT(tks.empty());
        cout << z << endl;
      } catch (...) {cout << "error\n";}
  }
  return 0;
}