/*
 * hw1.cpp
 *
 *  Created on: Jan 22, 2017
 *      Author: allen
 */

#include "hw1.hpp"
#include <cstdlib>
#include <stdlib.h>

using namespace std;

hw1::hw1(string num) {
	_num = num;


	unsigned short index;


	if (sign(num[0]) == 1){ // if negative
		num = num.substr(1, num.length() - 1);
	}

	if (num[0] == '.') num = '0' + num;



	if (num.find('.') == string::npos){
		index = num.length();
	}else{
	    index = num.find('.');
	}



	string e = num.substr(0, index);

	exp = getExp(atof(e.c_str()));

	cout << "this is binary " << exp << endl;


	string m = '0' + num.substr(index, num.length() - 1);
	 _mant = decToMantissa(atof(m.c_str()));
	 _newExp = decToExponent();
	 _si = sign(_num[0]);



//	cout << "mantissa:" << _mant << endl;
//	cout << "exponent:" <<  _newExp << endl;
//	cout << "sign:" << _si << endl;

}

string hw1::decToMantissa(float num){
	string binary = "";
	int i = 0;
	while(num > 0){
		num *= 2;

		if (num >= 1){
			num -= 1;
			binary += '1';
		}else{
			binary += '0';
		}
		i++;
		if (i == 23) num = 0; //avoid infinity loop
	}

	binary = exp.substr(1, exp.length() -1) + binary;

	if (binary.length() < 23){
		for(int i = binary.length(); i < 23; i++) binary += '0';
	}else{
		binary = binary.substr(0, 23);
	}

	return grouping(binary, true);
}


string hw1::decToExponent(){

	return grouping(getExp(127 + exp.length() - 1), false);
}

string hw1::grouping(string binary, bool mant){
	string b = "";
	int hex = 0;
	string hexCode("0123456789abcdef");
//	if (!mant) cout << "this is false" <<  binary << endl;

	for (int i = binary.length() - 1; i > 0; i -= 4){
		b = binary[i] + b;
		hex = pow(2, 0) * (binary[i] - '0');

		b = binary[i - 1] + b;
		hex += pow(2, 1) * (binary[i - 1] - '0');

		b = binary[i - 2] + b;
		hex += pow(2, 2) * (binary[i - 2] - '0');

		b = binary[i - 3] + b;


		if (i - 3 > 0) b = ' ' + b;

		if (i -3 >= 0) hex += pow(2, 3) * (binary[i - 3] -'0');

		if (mant)
			_mantHex = hexCode[hex] + _mantHex;
		else
			_expHex = hexCode[hex] + _expHex;
	}
//cout << "this is manHex " << _mantHex << endl;
	return b;
}


string hw1::getExp(long num){

	string binary = "";
		while(num > 0){
			if (num % 2 == 1){
				binary = '1' + binary;
			}else{
				binary = '0' + binary;
			}
			num /= 2;
		}
		if (binary == "") binary = '0';
		return binary;
}


int hw1::sign(char sign){
	if (isdigit(sign) || sign == '.'){
		return 0;
	}
	return 1;
}


ostream &operator<<(ostream &output, hw1 &arg){
	string base10 = arg._newExp +  " " + arg._mant;
	output << right << setw(12) << "mantissa: " << left << setw(2)
			<< "0x" << arg._mantHex <<  "\tor:\t\t" << arg._mant << endl;

	output << right << setw(12) << "exponent: " << left << setw(2)
			<< "0x" << arg._expHex << "\tor :  " << arg._newExp << endl;

	output << right << setw(12) << "sign: " << left << setw(9)
			<< '0' <<  "\tor: " << arg._si << endl;

	output << right << setw(12) <<  "in base 10: " << left << setw(2)
			<< fixed << setprecision(6)
		    << atof(arg._num.c_str())
			<< "\tor: " << arg._si << " " <<  base10<< endl;

	return output;
}




