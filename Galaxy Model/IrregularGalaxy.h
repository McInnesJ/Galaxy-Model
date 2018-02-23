#pragma once
#include "Galaxy.h"
#include "HubbleType.h"

class IrregularGalaxy :	public Galaxy {

public:
	IrregularGalaxy(HubbleType hubbleType, std::string name, double redShift, double mass, double stellarMassFraction, std::vector<Galaxy*> satellites);
	IrregularGalaxy(HubbleType hubbleType, std::string name, double redShift, double mass, double stellarMassFraction);

	virtual void printInfo() override;
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

	~IrregularGalaxy(){}
};

