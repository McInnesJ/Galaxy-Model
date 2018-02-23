#include "stdafx.h"
#include <iostream>
#include "GalaxyNotCreatedException.h"
#include "ElipticalGalaxy.h"


ElipticalGalaxy::ElipticalGalaxy(HubbleType hubbleType, std::string name, double redShift, double mass, double stellarMassFraction, std::vector<Galaxy*> satellites){
	this->name = name;
	HubbleType type = HubbleType::E3;

	switch (hubbleType){
	case HubbleType::E0:
		this->hType = "E0";
		break;
	case HubbleType::E1:
		this->hType = "E1";
	case HubbleType::E2:
		this->hType = "E2";
		break;
	case HubbleType::E3:
		this->hType = "E3";
		break;
	case HubbleType::E4:
		this->hType = "E4";
		break;
	case HubbleType::E5:
		this->hType = "E5";
		break;
	case HubbleType::E6:
		this->hType = "E6";
		break;
	case HubbleType::E7:
		this->hType = "E7";
		break;
	default:
		throw GalaxyNotCreatedException(ErrorMessage::hubbleType, this);// "Invalid hubble type provided");
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

ElipticalGalaxy::ElipticalGalaxy(HubbleType hubbleType, std::string name, double redShift, double mass, double stellarMassFraction){
	this->name = name;

	switch (hubbleType){
	case HubbleType::E0:
		this->hType = "E0";
		break;
	case HubbleType::E1:
		this->hType = "E1";
		break;
	case HubbleType::E2:
		this->hType = "E2";
		break;
	case HubbleType::E3:
		this->hType = "E3";
		break;
	case HubbleType::E4:
		this->hType = "E4";
		break;
	case HubbleType::E5:
		this->hType = "E5";
		break;
	case HubbleType::E6:
		this->hType = "E6";
		break;
	case HubbleType::E7:
		this->hType = "E7";
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
}
void ElipticalGalaxy::printInfo(){
	std::cout << "Name:                                     " << getName() << std::endl;
	std::cout << "Hubble type classification:               " << getHubbleType() << std::endl;
	std::cout << "Redshift:                                 " << getRedShift() << std::endl;
	std::cout << "Mass (in terms of solar masses):          " << getMass() << std::endl;
	std::cout << "Stellar mass (in terms of solar masses):  " << getStellarMass() << std::endl;
	

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

void ElipticalGalaxy::setHubbleType(HubbleType hubbleType){

	switch (hubbleType){
	case HubbleType::E0:
		this->hType = "E0";
		break;
	case HubbleType::E1:
		this->hType = "E1";
		break;
	case HubbleType::E2:
		this->hType = "E2";
		break;
	case HubbleType::E3:
		this->hType = "E3";
		break;
	case HubbleType::E4:
		this->hType = "E4";
		break;
	case HubbleType::E5:
		this->hType = "E5";
		break;
	case HubbleType::E6:
		this->hType = "E6";
		break;
	case HubbleType::E7:
		this->hType = "E7";
		break;
	default:
		std::cout << "Ivalid hubble type provided - Hubble type is still " + this->hType << std::endl;
	}
}
void ElipticalGalaxy::addSatellite(Galaxy *satellite) {
	this->satellites.push_back(satellite);
}

std::string ElipticalGalaxy::getName(){
	return this->name;
}
std::string ElipticalGalaxy::getHubbleType(){
	return this->hType;
}
double ElipticalGalaxy::getStellarMass(){
	return stellarMassFraction*mass;
}
double ElipticalGalaxy::getMass(){
	return this->mass;
}
double ElipticalGalaxy::getRedShift(){
	return this->redShift;
}
double ElipticalGalaxy::getStellarMassFraction(){
	return this->stellarMassFraction;
}
std::vector<Galaxy*> ElipticalGalaxy::getSatellites(){
	return this->satellites;
}

void ElipticalGalaxy::deleteGalaxy(){
	this->~ElipticalGalaxy();
}

