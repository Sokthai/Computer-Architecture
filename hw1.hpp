/*
 * hw1.hpp
 *
 *  Created on: Jan 22, 2017
 *      Author: allen
 */

#ifndef HW1_HPP_
#define HW1_HPP_
//#include <ctype.h>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>
#include <iostream>
#include <sstream>
using namespace std;

class hw1 {
public:
	hw1(string num);
	string decToMantissa(float num);
	string decToExponent();
	int sign(char sign);
	friend ostream &operator<<(ostream &output, hw1 &arg);

private:
	string getExp(long num);
	string grouping(string binary, bool mant);
	string _num;
	string exp;
	string _mant, _mantHex;
	string _newExp, _expHex;

	int _si;
};

#endif /* HW1_HPP_ */
