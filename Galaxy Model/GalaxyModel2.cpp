// GalaxyModel2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "HubbleType.h"
#include "GalaxyNotCreatedException.h"
#include "ElipticalGalaxy.h"
#include "LenticularGalaxy.h"
#include "SpiralGalaxy.h"
#include "SpiralBarGalaxy.h"
#include "IrregularGalaxy.h"

using namespace std;

Galaxy * setUp(){//maybe worth passing in values here, using a map key set up to run test on each class quickly. That said, probably not worth the time cost at this point

	Galaxy *sat1 = new ElipticalGalaxy(HubbleType::E1, "sat1", 0.00093, 10e9, 0.01);
	Galaxy *sat2 = new ElipticalGalaxy(HubbleType::E7, "sat2", 0.00072, 6.5e9, 0.04);
	vector<Galaxy*> satellites;

	satellites.push_back(sat1);
	satellites.push_back(sat2);

	Galaxy *main1 = new SpiralGalaxy(HubbleType::Sa, "main1", 0.004, 10e11, 0.005, satellites);

	return main1;
}

void testGalaxy(Galaxy *test){
	//create extra galaxy to add to satellites
	//add to satellites
	test->printInfo();
}

void cleanUp(Galaxy *test){

	test->deleteGalaxy();
}

int main(){

	//abourt called when creating a galaxy - puzzling huh
	try{
		Galaxy *test = setUp();
		testGalaxy(test);
		test->setHubbleType(HubbleType::E0);
		testGalaxy(test);
		test->setHubbleType(HubbleType::Sb);
		testGalaxy(test);

		Galaxy *sat3 = new LenticularGalaxy("sat3", 0.0042, 8e9, 0.003);
		test->addSatellite(sat3);
		testGalaxy(test);

		cleanUp(test);
	}
	catch (GalaxyNotCreatedException &e){
		cout << e.what() << endl;
		e.~GalaxyNotCreatedException();
		return EXIT_FAILURE;
	}
	//It is one of my errors, being called by eliptical - probably all of them since code copy/pasted.
	//*********************************
	//error message not printing out correctly - check into incorect use of string stream/overriden constructor.
	//*********************************
	//try reverting to generic error message and default constructor
	//check logic - probably always thowing.
	//double check inputs but doubt this is source of problem
	return EXIT_SUCCESS;
}