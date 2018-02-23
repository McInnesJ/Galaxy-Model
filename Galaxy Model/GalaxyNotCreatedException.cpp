#include "stdafx.h"
#include "GalaxyNotCreatedException.h"


GalaxyNotCreatedException::GalaxyNotCreatedException(ErrorMessage message, Galaxy *galaxy){

	switch (message){
	case ErrorMessage::hubbleType:
		this->errorMessage = "ERROR: Invalid Hubble Type provided - " + galaxy->getName() + " not created";
		break;
	case ErrorMessage::redShift:
		this->errorMessage = "ERROR: Unreasonable Redshift provided  - " + galaxy->getName() + " not created";
		break;
	case ErrorMessage::mass:
		this->errorMessage = "ERROR: Unreasonable Mass provided - " + galaxy->getName() + " not created";
		break;
	case ErrorMessage::stellarMassFraction:
		this->errorMessage = "ERROR: Unreasonable Stellar Mass Fraction provided - " + galaxy->getName() + " not created";
		break;
	default :
		this->errorMessage = "Unkown Error - " + galaxy->getName() + " not created";
	}
}
