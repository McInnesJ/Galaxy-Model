#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include "HubbleType.h"


class Galaxy
{
protected: 
	std::string name;
	std::string hType;
	double redShift;
	//double distance;
	double mass; //in terms of solar masses
	double stellarMassFraction;
	std::vector<Galaxy*> satellites;

	//virtual void setDistance(double redShift) = 0;

public:
	//Galaxy(double redShift, double mass, double stellarMassFraction, std::vector<Galaxy> satellites);

	virtual void printInfo() = 0;
	virtual void addSatellite(Galaxy *satellite) = 0;			//consider adding uniqueness check

	virtual std::string getName() = 0;
	virtual double getStellarMass() = 0;
	virtual std::string getHubbleType() = 0;
	virtual double getRedShift() = 0;
	virtual double getMass() = 0;
	virtual double getStellarMassFraction() = 0;
	virtual std::vector<Galaxy*> getSatellites() = 0;
	virtual void setHubbleType(HubbleType hubbleType) = 0;
	virtual void deleteGalaxy() = 0;
};

