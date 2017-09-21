//Grace Seiche - PA5 - PA5.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>
#include "rational.h"
#include "stack.h"

bool error = false;
bool result = false;
char c = ' ';
char ch = ' ';
Stack *rationals;// = new Stack ();

void readLine (std::stringstream& ss){
	Rational *r = new Rational();
	Rational r1;
	Rational r2;
	rationals = new Stack();
	ss.get(c);
	while (c!= '\n' && /*!ss.eof() && */!ss.fail() && error==false){
		ch = ' ';
		if(isdigit(c) || (c=='-' && isdigit(ss.peek()))){
			ss.putback(c);
			ss >> *r;
			rationals->addItem(*r);
		} else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '<' || c == '>' || c == '!' || c == '='){
			//std::cout << c;
			if(rationals->isEmptyStack()){
				error = true;
				//std::cout << "Error: Empty Stack" << std::endl;
				return;
				break;
			} else {
				r2 = rationals->removeHead();
				if (rationals->isEmptyStack()){
					error = true;
					return;
					//std::cout << "Error: Empty Stack" << std::endl;
					break;
				} else {
					r1 = rationals->removeHead();
				}
			}
			switch (c){
			case '+' :
				rationals->addItem(r1+r2);
				break;
			case '-' :
				rationals->addItem(r1-r2);
				break;
			case '*' :
				rationals->addItem(r1*r2);
				break;
			case '/' :
				if(r2.getNum() !=0){
					rationals->addItem(r1/r2);
				} else {
					error = true;
					return;
				}
				break;
			case '!' :
				ss.get(ch);
				//std::cout << ch;
				if (ch == '='){
					result = (r1 != r2);
				} else {
					error = true;
					return;
				}
				break;
			case '=' :
				ss.get(ch);
				//std::cout << ch;
				if (ch == '='){
					result = (r1 == r2);
				} else {
					error = true;
					return;
				}
				break;
			case '<' :
				ss.get(ch);
				//std::cout <<ch;
				if (ch == '='){
					result = (r1 <= r2);
				} else if (ch == ' ' || ch == '\t' || ch == '\n' || ss.fail()) {
					result = (r1 < r2);
				} else {
					error = true;
					return;
				}
				break;
			case '>' :
				ss.get(ch);
				//std::cout <<ch;
				if (ch == '='){
					result = (r1 >= r2);
				} else if (ch == ' ' || ch == '\t' || ch == '\n' || ss.fail()) {
					result = (r1 > r2);
				} else {
					error = true;
					return;
				}
				break;
			}
			//std::cout << ' ';
			//ch = c;
		}
		if(c == '<' || c == '>' || c == '!' || c == '='){
			ss.get(ch);
			if(!ss.fail()){
				error = true;
				return;
			}
			break;
		}
		ss.get(c);
		//rationals->printStack();
		//std::cout << ch << std::endl;
		//std::cout << *r << std::endl;
		//std::cout << "c==" << c <<std::endl;
	}

}

void readFile (char *file, std::ifstream& ifs){
	ifs.open(file, std::ifstream::in);
	char stream [200];
	ifs.getline(stream, 200);
	while (/*!ifs.eof()*/ !ifs.fail()){
		std::cout << stream;
		std::string myStream (stream);
		std::stringstream ss;
		ss << myStream;
		readLine(ss);
			//rationals->printStack();
			//std::cout << ch << std::endl;
			//std::cout << *r << std::endl;
			//std::cout << "c==" << c <<std::endl;
		//}//end of while
		if(error){
			std::cout << "\t: invalid expression" << std::endl;
			error = false;
		} else if(c == '<' || c == '>' || c == '!' || c == '='){
			std::cout << "\t: " << (result ? "true" : "false") << std::endl;
		} else if(rationals->stackSize()==1){
			std::cout << "\t: " << rationals->getHead() << " (double " << toDouble(rationals->getHead()) << ")" << std::endl;
			rationals->removeHead();
		} else if(!ifs.fail()){
			std::cout << "\t: invalid expression" << std::endl;
		}
		ifs.getline(stream, 200);
	}//end of outer while
	ifs.close();
	std::cout << std::endl;
}

int main (int argc, char *argv[]){
	std::ifstream ifs;
	for (int i = 1; i<argc; i++){
		std::cout << argv[i] << std::endl;
		readFile (argv[i], ifs);
	}
	return 1;
}

/*
 * Rational r = *(new Rational (2, 3));
	Rational s = *(new Rational (1, 4));
	Rational t = *(new Rational (3));
	Rational u = *(new Rational (4));
	Rational v = *(new Rational ());
	//std::cout << "check" << std::endl;
	//std::cout << (s/v);


 */
