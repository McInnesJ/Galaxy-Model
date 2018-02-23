#include "stdafx.h"
#include <iostream>
#include "GalaxyNotCreatedException.h"
#include "LenticularGalaxy.h"


LenticularGalaxy::LenticularGalaxy(std::string name, double redShift, double mass, double stellarMassFraction, std::vector<Galaxy*> satellites){
	//hubble type always S0
	this->name = name;
	this->hType = "S0";


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

LenticularGalaxy::LenticularGalaxy(std::string name, double redShift, double mass, double stellarMassFraction){
	//hubble type always S0
	this->name = name;
	this->hType = "S0";


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

void LenticularGalaxy::printInfo(){
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

void LenticularGalaxy::setHubbleType(HubbleType){
	std::cout << "Lenticular Galaxies can only have hubble type 'S0'. Hubble type unchanged" <<std::endl;
}

void LenticularGalaxy::addSatellite(Galaxy *satellite){
	this->satellites.push_back(satellite);
}

std::string LenticularGalaxy::getName(){
	return this->name;
}
std::string LenticularGalaxy::getHubbleType(){
	return this->hType;
}
double LenticularGalaxy::getStellarMass(){
	return stellarMassFraction*mass;
}
double LenticularGalaxy::getMass(){
	return this->mass;
}
double LenticularGalaxy::getRedShift(){
	return this->redShift;
}
double LenticularGalaxy::getStellarMassFraction(){
	return this->stellarMassFraction;
}
std::vector<Galaxy*> LenticularGalaxy::getSatellites(){
	return this->satellites;
}

void LenticularGalaxy::deleteGalaxy(){
	this->~LenticularGalaxy();
}