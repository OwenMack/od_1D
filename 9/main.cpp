/*
 * main.cpp
 *
 *  Created on: Mar 22, 2015
 *      Author: MackO
 */

#include <iostream>
#include <iterator>
#include "SkipMap.h"
using namespace std;

int main(){

//	18 Laguna Niguel
//	18 Mission Viejo
//	22 Lake Forest
//	44 Irvine
//	44 San Clemente
//	32 San Diego
//	49 Anaheim
//	Delete key 22
//	73 Los Angeles
//	17 Orange
//	32 Palm Springs
//	26 Riverside
//	Delete key 49
//	19 Brea
//	60 Santa Ana
//	35 Tustin
//	52 Oceanside
//	11 La Jolla
//	18 Del Mar
//	22 Aliso Viejo
//	49 Laguna Beach

	SkipMap<string> test(50);
	test.insert(18, "Laguna Niguel");
	test.insert(18 ,"Mission Viejo");
	test.insert(22,"Lake Forest");
	test.insert(44, "Irvine");
	test.insert(44, "San Clemente");
	test.insert(32, "San Diego");
	test.insert(49, "Anaheim");
	test.remove(22);
	test.insert(73, "Los Angeles");
	test.insert(17, "Orange");
	test.insert(22,"Lake Forest");
	test.insert(32, "Palm Springs");
	test.insert(26, "Riverside");
	test.remove(49);
	test.insert(19, "Brea");
	test.insert(35 ,"Tustin");
	test.insert(52, "Oceanside");
	test.insert(11, "La Jolla");
	test.insert(18, "Del Mar");
	test.insert(44, "Irvine");
	test.insert(22, "Aliso Viejo");
	test.insert(49, "Laguna Beach");

	cout << "PrintAll" << endl << endl;
	test.printAll();

	cout << endl << test.search(18);
	return 0;
}


