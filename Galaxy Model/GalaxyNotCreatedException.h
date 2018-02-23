#pragma once
#include <exception>
#include <string>
#include "Galaxy.h"
#include "ErrorMessage.h"

class GalaxyNotCreatedException : public std::exception {

private:
	std::string errorMessage;

public:

	virtual const char* what() const throw(){

		return errorMessage.c_str();
	}

	GalaxyNotCreatedException(ErrorMessage message, Galaxy *galaxy);
	~GalaxyNotCreatedException(){}
};

