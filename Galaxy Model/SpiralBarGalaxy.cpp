#include "stdafx.h"
#include <iostream>
#include "GalaxyNotCreatedException.h"
#include "SpiralBarGalaxy.h"


SpiralBarGalaxy::SpiralBarGalaxy(HubbleType hubbleType, std::string name, double redShift, double mass, double stellarMassFraction, std::vector<Galaxy*> satellites){
	this->name = name;

	switch (hubbleType){
	case HubbleType::SBa:
		this->hType = "SBa";
		break;
	case HubbleType::SBb:
		this->hType = "SBb";
		break;
	case HubbleType::SBc:
		this->hType = "SBc";
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

SpiralBarGalaxy::SpiralBarGalaxy(HubbleType hubbleType, std::string name, double redShift, double mass, double stellarMassFraction){
	this->name = name;

	switch (hubbleType){
	case HubbleType::SBa:
		this->hType = "SBa";
		break;
	case HubbleType::SBb:
		this->hType = "SBb";
		break;
	case HubbleType::SBc:
		this->hType = "SBc";
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

void SpiralBarGalaxy::printInfo(){
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

void SpiralBarGalaxy::setHubbleType(HubbleType hubbleType){
	switch (hubbleType){
	case HubbleType::SBa:
		this->hType = "SBa";
		break;
	case HubbleType::SBb:
		this->hType = "SBb";
		break;
	case HubbleType::SBc:
		this->hType = "SBc";
		break;
	default:
		std::cout << "Ivalid hubble type provided - Hubble type is still " + this->hType << std::endl;
	}
}
void SpiralBarGalaxy::addSatellite(Galaxy *satellite){
	this->satellites.push_back(satellite);
}

std::string SpiralBarGalaxy::getName(){
	return this->name;
}
std::string SpiralBarGalaxy::getHubbleType(){
	return this->hType;
}
double SpiralBarGalaxy::getStellarMass(){
	return stellarMassFraction*mass;
}
double SpiralBarGalaxy::getMass(){
	return this->mass;
}
double SpiralBarGalaxy::getRedShift(){
	return this->redShift;
}
double SpiralBarGalaxy::getStellarMassFraction(){
	return this->stellarMassFraction;
}
std::vector<Galaxy*> SpiralBarGalaxy::getSatellites(){
	return this->satellites;
}

void SpiralBarGalaxy::deleteGalaxy(){
	this->~SpiralBarGalaxy();
}