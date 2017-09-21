// Grace Seiche - PA5 - rational.cpp

#include <iostream>
#include <stdexcept>
#include "rational.h"
using std::ostream;
using std::istream;

extern bool error;

//takes a rational
//returns the numerator divided by the denominator in decimal form
double toDouble (const Rational& r){
	return r.num/((double) r.denom);
}//double toDouble (&Rational r);

//takes a large int and a smaller int
//computes the greatest common denominator of the ints
//returns the gcd
int gcd (long long int big, long long int small){
	if(small<0){
		small*=-1;
	}
	if(big<0){
		big *=-1;
	}
	if(big==small){
		return small;
	}else if (big<small){
		return gcd(small, big);
	}else {
		return gcd(big-small, small);
	}
}//int gcd(int big, int small);

//takes an int numerator and an int denominator
//constructs a rational number with given numerator and denominator
Rational::Rational (const int num, const int denom) : num(num), denom(denom){
}//Rational(const int num, const int denom);

//takes an int wholeNumber
//constructs the numerator to the wholeNumber and the denominator to 1
Rational::Rational (const int wholeNumber) : num(wholeNumber), denom(1){
}//Rational(const int wholeNumber);

//copy constructor
//takes a reference to Rational a
//constructs a rational object with the same numerator and denominator
Rational::Rational (const Rational &a): num(a.num), denom(a.denom){
//	num = a.num;
//	denom = a.denom;
	*this = this->normalize();
}//Rational(const Rational &a);

//takes no parameters
//constructs a numerator of 0 and a denominator of 1
Rational::Rational () : num(0), denom(1){
}//Rational();

//takes no parameters
//destructs the Rational object
Rational::~Rational (){
}//~Rational();

//takes no parameters
//reduces the rational number and moves the negative to the numerator
//returns the normalized rational
const Rational& Rational::normalize(){
	if(this->num == 0){
		return *(new Rational (0,1));
	}
	long long int GCD = gcd(this->num, this->denom);
	long long int a;
	long long int b;
	a = this->num/GCD;
	b = this->denom/GCD;
	if(b<0){
		b *= -1;
		a *= -1;
	}
	const Rational *r = new Rational (a, b);
	return *r;
}//Rational normalize ();
//maybe convert to void?

//operator overloads

//takes a rational
//returns true if it is equivalent to this and false if it is not
bool Rational::operator ==(const Rational& r){
	long long int a = this->num;
	long long int b = this->denom;
	long long int c = r.num;
	long long int d = r.denom;
	return (a*d == b*c);
}//bool operator ==(Rational& r);

//takes a rational
//returns true if it is not equivalent to this and false if it is
bool Rational::operator !=(const Rational& r){
	long long int a = this->num;
	long long int b = this->denom;
	long long int c = r.num;
	long long int d = r.denom;
	return (a*d != b*c);
}//bool operator !=(Rational& r);

//takes a rational
//returns true if this is less than the passed rational and false if it is not
bool Rational::operator <(const Rational& r){
	long long int a = this->num;
	long long int b = this->denom;
	long long int c = r.num;
	long long int d = r.denom;
	return (a*d < b*c);
}//bool operator <(Rational& r);

//takes a rational
//returns true if this is greater than the passed rational and false if it is not
bool Rational::operator >(const Rational& r){
	long long int a = this->num;
	long long int b = this->denom;
	long long int c = r.num;
	long long int d = r.denom;
	return (a*d > b*c);
}//bool operator >(Rational& r);

//takes a rational
//returns true if this is less than or equal to the passed rational and false if it is not
bool Rational::operator <=(const Rational& r){
	return !(*this>r);
}//bool operator <=(Rational& r);

//takes a rational
//returns true if this is greater than or equal to the passed rational and false if it is not
bool Rational::operator >=(const Rational& r){
	return !(*this<r);
}//bool operator >=(Rational& r);

//takes a rational
//adds the rationals
//returns the sum of the rationals as a rational
const Rational& Rational::operator +(const Rational& r){
	long long int a = this->num;
	long long int b = this->denom;
	long long int c = r.num;
	long long int d = r.denom;
	const Rational *s = new Rational(a*d+b*c, b*d);
	return *s;
}//Rational operator +(Rational& r);

//takes a rational
//subtracts the given rational from this
//returns the different of the rationals as a rational
const Rational& Rational::operator -(const Rational& r){
	long long int a = this->num;
	long long int b = this->denom;
	long long int c = r.num;
	long long int d = r.denom;
	const Rational *s = new Rational (a*d-b*c, b*d);
	return *s;
}//Rational operator -(Rational& r);

//takes a rational
//multiplies the rationals
//returns the product of the rationals as a rational
const Rational& Rational::operator *(const Rational& r){
	long long int a = this->num;
	long long int b = this->denom;
	long long int c = r.num;
	long long int d = r.denom;
	const Rational *s = new Rational (a*c, b*d);
	return *s;
}//Rational operator *(Rational& r);

//takes a rational
//divides this by the given rational
//returns the quotient of the rationals as a rational
const Rational& Rational::operator /(const Rational& r){
	long long int a = this->num;
	long long int b = this->denom;
	long long int c = r.num;
	long long int d = r.denom;
	const Rational *s = new Rational (a*d, b*c);
	return *s;
}//Rational operator /(Rational& r);

//takes no parameters
//returns the negated rational
const Rational& Rational::operator -(){
	long long int a = this->num;
	a *= -1;
	long long int b = this->denom;
	const Rational *r = new Rational (a, b);
	return *r;
}//Rational operator -();

//takes an output stream and a reference to a rational
//outputs the given rational to the given stream
//returns the output stream
ostream& operator << (ostream& outputStream, const Rational& r){
	outputStream << r.num << "/" << r.denom;
	return outputStream;
}//friend ostream& operator << (ostream& outputStream, Rational& r)

//takes an input stream and a reference to a rational
//reads the input steam and saves it as the given rational
//returns the input stream
istream& operator >> (istream& inputStream, Rational& r){
	char slash;
	int num;
	int denom;
	inputStream >> num;
	if(inputStream.fail()){
		return inputStream;
	}
	//std::cout << num;
	r.setNum(num);
	inputStream.get(slash);
	//std::cout <<slash;
	if(slash == '/'){
		inputStream >> denom;
		//std::cout << denom;
		r.setDenom(denom);
	} else if (slash == ' ' || slash == '+' || slash == '-' || slash == '*' || slash == '/' || slash == '<' || slash == '>' || slash == '!' || slash == '='){
		inputStream.putback(slash);
		r.setDenom(1);
	} else {
		//throw std::invalid_argument ("Error: Unknown Symbol");///Keep???
		inputStream.putback(slash);
		error = true;
		//std::cout << "Error: Unknown symbol " << slash << std::endl;
		return inputStream;
	}
	///std::cout << " ";
	return inputStream;
}//friend istream& operator >> (istream& inputStream, Rational& r)

//takes no parameters
//returns the numerator of the rational
int Rational::getNum(){
	return this->num;
}//int getNum();

//takes an int
//sets the rational's denominator as the int
//returns void
void Rational::setDenom(int d){
	this->denom=d;
}//void setDenom(int d);

//takes an int
//sets the rational's numerator as the int
//returns void
void Rational::setNum(int n){
	this->num=n;
}//void setNum (int n);
