#include "stdafx.h"
#include <iostream>
#include "GalaxyNotCreatedException.h"
#include "IrregularGalaxy.h"


IrregularGalaxy::IrregularGalaxy(HubbleType hubbleType, std::string name, double redShift, double mass, double stellarMassFraction, std::vector<Galaxy*> satellites){
	this->name = name;

	switch (hubbleType){
	case HubbleType::Irr_I:
		this->hType = "Irr_I";
		break;
	case HubbleType::Irr_II:
		this->hType = "Irr_II";
		break;
	default:
		throw GalaxyNotCreatedException(ErrorMessage::hubbleType, this);//"Invalid hubble type provided");
	}

	if (redShift > 0 && redShift <= 10){
		this->redShift = redShift;
	}
	else throw GalaxyNotCreatedException(ErrorMessage::redShift, this);//"Unreasonable redshift value provided");

	if (mass >= 10e7 && mass <= 10e12){
		this->mass = mass;
	}
	else throw GalaxyNotCreatedException(ErrorMessage::mass, this);//"Unreasonable mass provided");

	if (stellarMassFraction > 0 && stellarMassFraction <= 0.05){
		this->stellarMassFraction = stellarMassFraction;
	}
	else throw GalaxyNotCreatedException(ErrorMessage::stellarMassFraction, this);//"Unreasonable stellar mass fraction provided");

	if (satellites.size() > 0){
		for (Galaxy *galaxy : satellites){
			this->satellites.push_back(galaxy); 
		}
	}
}

IrregularGalaxy::IrregularGalaxy(HubbleType hubbleType, std::string name, double redShift, double mass, double stellarMassFraction){
	this->name = name;

	switch (hubbleType){
	case HubbleType::Irr_I:
		this->hType = "Irr_I";
		break;
	case HubbleType::Irr_II:
		this->hType = "Irr_II";
	default:
		throw GalaxyNotCreatedException(ErrorMessage::hubbleType, this);//"Invalid hubble type provided");
	}

	if (redShift > 0 && redShift <= 10){
		this->redShift = redShift;
	}
	else throw GalaxyNotCreatedException(ErrorMessage::redShift, this);//"Unreasonable redshift value provided");

	if (mass >= 10e7 && mass <= 10e12){
		this->mass = mass;
	}
	else throw GalaxyNotCreatedException(ErrorMessage::mass, this);//"Unreasonable mass provided");

	if (stellarMassFraction > 0 && stellarMassFraction <= 0.05){
		this->stellarMassFraction = stellarMassFraction;
	}
	else throw GalaxyNotCreatedException(ErrorMessage::stellarMassFraction, this);//"Unreasonable stellar mass fraction provided");
}

void IrregularGalaxy::printInfo(){
	std::cout << "Name:										" << getName() << std::endl;
	std::cout << "Hubble type classification:				" << getHubbleType() << std::endl;
	std::cout << "Redshift:									" << getRedShift() << std::endl;
	std::cout << "Mass (in terms of solar masses):			" << getMass() << std::endl;
	std::cout << "Stellar mass (in terms of solar masses):	" << getStellarMass() << std::endl;


	if (this->satellites.size() == 0){
		std::cout << "No satellites." << std::endl;
	}
	else{
		std::cout << this->satellites.size() << " Satellites: " << std::endl;

		for (Galaxy *galaxy : this->satellites){
			std::cout << std::endl;
			galaxy->printInfo();
			std::cout << std::endl;
		}
	}
}

void IrregularGalaxy::setHubbleType(HubbleType hubbleType){

	switch (hubbleType){
	case HubbleType::Irr_I:
		this->hType = "Irr_I";
		break;
	case HubbleType::Irr_II:
		this->hType = "Irr_II";
	default:
		std::cout << "Ivalid hubble type provided - Hubble type is still " + this->hType << std::endl;
	}

}
void IrregularGalaxy::addSatellite(Galaxy *satellite){
	this->satellites.push_back(satellite);
}

std::string IrregularGalaxy::getName(){
	return this->name;
}
std::string IrregularGalaxy::getHubbleType(){
	return this->hType;
}
double IrregularGalaxy::getStellarMass(){
	return stellarMassFraction*mass;
}
double IrregularGalaxy::getMass(){
	return this->mass;
}
double IrregularGalaxy::getRedShift(){
	return this->redShift;
}
double IrregularGalaxy::getStellarMassFraction(){
	return this->stellarMassFraction;
}
std::vector<Galaxy*> IrregularGalaxy::getSatellites(){
	return this->satellites;
}

void IrregularGalaxy::deleteGalaxy(){
	this->~IrregularGalaxy();
}