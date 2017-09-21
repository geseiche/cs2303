// Grace Seiche - PA5 - rational.h

#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {

public:
	//constructors
	Rational (const int num, const int denom);
	Rational (const int wholeNumber);
	Rational (const Rational &a);//copy constructor
	Rational ();

	//destructor
	~Rational ();

	//functions
	const Rational& normalize();//maybe convert to void?

	//operator overloads
	bool operator ==(const Rational& r);
	bool operator !=(const Rational& r);
	bool operator <(const Rational& r);
	bool operator >(const Rational& r);
	bool operator <=(const Rational& r);
	bool operator >=(const Rational& r);
	const Rational& operator +(const Rational& r);
	const Rational& operator -(const Rational& r);
	const Rational& operator *(const Rational& r);
	const Rational& operator /(const Rational& r);
	const Rational& operator -();
	//Rational unreduce (int foo);
	friend std::ostream& operator << (std::ostream& outputStream, const Rational& r);
	friend std::istream& operator >> (std::istream& inputStream, Rational& r);
	friend double toDouble (const Rational& r);

//	//getters
	int getNum();
//	int getDenom();
	void setDenom(int d);
	void setNum(int n);

private:
	//members
	int num;
	int denom;
};

//not a member function
int gcd (long long int big, long long int small);

#endif
