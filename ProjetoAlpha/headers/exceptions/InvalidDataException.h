/*
 * InvalidDateException.h
 *
 *  Created on: 16/04/2021
 *      Author: pbs
 */

#ifndef HEADERS_EXCEPTIONS_INVALIDDATAEXCEPTION_H_
#define HEADERS_EXCEPTIONS_INVALIDDATAEXCEPTION_H_

#include <exception>
#include <string>
using namespace std;

class InvalidDataException :public exception{
private:
	string data;
public:
	InvalidDataException(string data);
	//override what function
	const char* what();
};




#endif /* HEADERS_EXCEPTIONS_INVALIDDATAEXCEPTION_H_ */
