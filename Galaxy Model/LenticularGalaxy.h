#pragma once
#include "Galaxy.h"
#include "HubbleType.h"

class LenticularGalaxy : public Galaxy {

public:
	LenticularGalaxy(std::string name, double redShift, double mass, double stellarMassFraction, std::vector<Galaxy*> satellites);
	LenticularGalaxy(std::string name, double redShift, double mass, double stellarMassFraction);

	void printInfo() override;
	void addSatellite(Galaxy *satellite) override;

	std::string getName() override;
	double getStellarMass() override;
	std::string getHubbleType() override;
	double getRedShift() override;
	double getMass() override;
	double getStellarMassFraction() override;
	std::vector<Galaxy*> getSatellites() override;
	void setHubbleType(HubbleType hubbleType) override;
	void deleteGalaxy() override;

	~LenticularGalaxy(){}
};

