// C++ program to implement
// the above approach
#include <bits/stdc++.h>

using namespace std;

class BigInt{
	string digits;
public:

	//Constructors:
	BigInt(unsigned long long n = 0);
	BigInt(string &);
	BigInt(const char *);
	BigInt(BigInt &);

	//Helper Functions:
	friend void divide_by_2(BigInt &a);
	friend bool Null(const BigInt &);
	friend int Lenght(const BigInt &);
	int operator[](const int)const;

			/* * * * Operator Overloading * * * */

	//Direct assignment
	BigInt &operator=(const BigInt &);

	//Post/Pre - Incrementation
	BigInt &operator++();
	BigInt operator++(int temp);
	BigInt &operator--();
	BigInt operator--(int temp);

	//Addition and Subtraction
	friend BigInt &operator+=(BigInt &, const BigInt &);
	friend BigInt operator+(const BigInt &, const BigInt &);
	friend BigInt operator-(const BigInt &, const BigInt &);
	friend BigInt &operator-=(BigInt &, const BigInt &);

	//Comparison operators
	friend bool operator==(const BigInt &, const BigInt &);
	friend bool operator!=(const BigInt &, const BigInt &);

	friend bool operator>(const BigInt &, const BigInt &);
	friend bool operator>=(const BigInt &, const BigInt &);
	friend bool operator<(const BigInt &, const BigInt &);
	friend bool operator<=(const BigInt &, const BigInt &);

	//Multiplication and Division
	friend BigInt &operator*=(BigInt &, const BigInt &);
	friend BigInt operator*(const BigInt &, const BigInt &);
	friend BigInt &operator/=(BigInt &, const BigInt &);
	friend BigInt operator/(const BigInt &, const BigInt &);

	//Modulo
	friend BigInt operator%(const BigInt &, const BigInt &);
	friend BigInt &operator%=(BigInt &, const BigInt &);

	//Power Function
	friend BigInt &operator^=(BigInt &,const BigInt &);
	friend BigInt operator^(BigInt &, const BigInt &);
	
	//Square Root Function
	friend BigInt sqrt(BigInt &a);

	//Read and Write
	friend ostream &operator<<(ostream &,const BigInt &);
	friend istream &operator>>(istream &, BigInt &);

	//Others
	friend BigInt Factorial(int n);
};

BigInt::BigInt(string & s){
	digits = "";
	int n = s.size();
	for (int i = n - 1; i >= 0;i--){
		if(!isdigit(s[i]))
			throw("ERROR");
		digits.push_back(s[i] - '0');
	}
}
BigInt::BigInt(unsigned long long nr){
	do{
		digits.push_back(nr % 10);
		nr /= 10;
	} while (nr);
}
BigInt::BigInt(const char *s){
	digits = "";
	for (int i = strlen(s) - 1; i >= 0;i--)
	{
		if(!isdigit(s[i]))
			throw("ERROR");
		digits.push_back(s[i] - '0');
	}
}
BigInt::BigInt(BigInt & a){
	digits = a.digits;
}

bool Null(const BigInt& a){
	if(a.digits.size() == 1 && a.digits[0] == 0)
		return true;
	return false;
}
int Lenght(const BigInt & a){
	return a.digits.size();
}
int BigInt::operator[](const int index)const{
	if(digits.size() <= index || index < 0)
		throw("ERROR");
	return digits[index];
}
bool operator==(const BigInt &a, const BigInt &b){
	return a.digits == b.digits;
}
bool operator!=(const BigInt & a,const BigInt &b){
	return !(a == b);
}
bool operator<(const BigInt&a,const BigInt&b){
	int n = Lenght(a), m = Lenght(b);
	if(n != m)
		return n < m;
	while(n--)
		if(a.digits[n] != b.digits[n])
			return a.digits[n] < b.digits[n];
	return false;
}
bool operator>(const BigInt&a,const BigInt&b){
	return b < a;
}
bool operator>=(const BigInt&a,const BigInt&b){
	return !(a < b);
}
bool operator<=(const BigInt&a,const BigInt&b){
	return !(a > b);
}

BigInt &BigInt::operator=(const BigInt &a){
	digits = a.digits;
	return *this;
}

BigInt &BigInt::operator++(){
	int i, n = digits.size();
	for (i = 0; i < n && digits[i] == 9;i++)
		digits[i] = 0;
	if(i == n)
		digits.push_back(1);
	else
		digits[i]++;
	return *this;
}
BigInt BigInt::operator++(int temp){
	BigInt aux;
	aux = *this;
	++(*this);
	return aux;
}

BigInt &BigInt::operator--(){
	if(digits[0] == 0 && digits.size() == 1)
		throw("UNDERFLOW");
	int i, n = digits.size();
	for (i = 0; digits[i] == 0 && i < n;i++)
		digits[i] = 9;
	digits[i]--;
	if(n > 1 && digits[n - 1] == 0)
		digits.pop_back();
	return *this;
}
BigInt BigInt::operator--(int temp){
	BigInt aux;
	aux = *this;
	--(*this);
	return aux;
}

BigInt &operator+=(BigInt &a,const BigInt& b){
	int t = 0, s, i;
	int n = Lenght(a), m = Lenght(b);
	if(m > n)
		a.digits.append(m - n, 0);
	n = Lenght(a);
	for (i = 0; i < n;i++){
		if(i < m)
			s = (a.digits[i] + b.digits[i]) + t;
		else
			s = a.digits[i] + t;
		t = s / 10;
		a.digits[i] = (s % 10);
	}
	if(t)
		a.digits.push_back(t);
	return a;
}
BigInt operator+(const BigInt &a, const BigInt &b){
	BigInt temp;
	temp = a;
	temp += b;
	return temp;
}

BigInt &operator-=(BigInt&a,const BigInt &b){
	if(a < b)
		throw("UNDERFLOW");
	int n = Lenght(a), m = Lenght(b);
	int i, t = 0, s;
	for (i = 0; i < n;i++){
		if(i < m)
			s = a.digits[i] - b.digits[i]+ t;
		else
			s = a.digits[i]+ t;
		if(s < 0)
			s += 10,
			t = -1;
		else
			t = 0;
		a.digits[i] = s;
	}
	while(n > 1 && a.digits[n - 1] == 0)
		a.digits.pop_back(),
		n--;
	return a;
}
BigInt operator-(const BigInt& a,const BigInt&b){
	BigInt temp;
	temp = a;
	temp -= b;
	return temp;
}

BigInt &operator*=(BigInt &a, const BigInt &b)
{
	if(Null(a) || Null(b)){
		a = BigInt();
		return a;
	}
	int n = a.digits.size(), m = b.digits.size();
	vector<int> v(n + m, 0);
	for (int i = 0; i < n;i++)
		for (int j = 0; j < m;j++){
			v[i + j] += (a.digits[i] ) * (b.digits[j]);
		}
	n += m;
	a.digits.resize(v.size());
	for (int s, i = 0, t = 0; i < n; i++)
	{
		s = t + v[i];
		v[i] = s % 10;
		t = s / 10;
		a.digits[i] = v[i] ;
	}
	for (int i = n - 1; i >= 1 && !v[i];i--)
			a.digits.pop_back();
	return a;
}
BigInt operator*(const BigInt&a,const BigInt&b){
	BigInt temp;
	temp = a;
	temp *= b;
	return temp;
}

BigInt Factorial(int n){
	BigInt f(1);
	for (int i = 2; i <= n;i++)
		f *= i;
	return f;
}

istream &operator>>(istream &in,BigInt&a){
	string s;
	in >> s;
	int n = s.size();
	for (int i = n - 1; i >= 0;i--){
		if(!isdigit(s[i]))
			throw("INVALID NUMBER");
		a.digits[n - i - 1] = s[i];
	}
	return in;
}

ostream &operator<<(ostream &out,const BigInt &a){
	for (int i = a.digits.size() - 1; i >= 0;i--)
		cout << (short)a.digits[i];
	return cout;
}

//Driver code with some examples
int main()
{
        int n = 0;
        cin >> n;
		BigInt fact;
		fact = Factorial(n);
        cout << fact << endl;

// This code is contributed
// by Gatea David
}
