#include <cassert>

#include "Vehicle.h"
#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include "Motorcycle.h"
#include "Sedan.h"
#include "Trailer.h"
#include "UBoat.h"
#include "DeusExMachina.h"
#include "Person.h"
#include "iostream"
#include "cmath"

using namespace assignment2;

int main()
{

	unsigned int sum;
	unsigned int speed;
	int qwe;
	double logx;
	double sum2;
	sum = static_cast<double>(20);
	qwe = (static_cast<double>(sum) / 15);
	//qwe = exp((400 - sum) / 70);
	logx = log((150 + static_cast<double>(sum)) / 150);
	sum2 = 500 * logx + 30;
	speed = static_cast<unsigned int>(sum2 + 0.5);
	std::cout << qwe << std::endl;
	Person* p = new Person("Bob", 85);

	assert(p->GetName() == std::string("Bob"));
	assert(p->GetWeight() == 85);

	Person* p2 = new Person("James", 75);
	Person* p3 = new Person("Tina", 52);

	Person* p4 = new Person("Peter", 78);
	Person* p5 = new Person("Jane", 48);
	Person* p6 = new Person("Steve", 88);

	//Airplane a(5);
	//a.AddPassenger(p);
	//a.AddPassenger(p2);
	//a.AddPassenger(p3);
	//Airplane a2=a;
	//std::cout << a2.GetPassenger(2)->GetName() << std::endl;
	//assert(a2.GetMaxPassengersCount() == 5);
	//assert(a2.GetPassengersCount() == 3);
	//assert(a.GetPassenger(1) == p2);
	//assert(a2.GetFlySpeed() == 648);
	////std::cout << a.GetDriveSpeed();
	//assert(a.GetDriveSpeed() == 59);
	//assert(a.GetMaxSpeed() == 648);

	//Boat b(5);
	//b.AddPassenger(p4);
	//b.AddPassenger(p5);
	//b.AddPassenger(p6);
	//Boatplane bp = b + a;
	//Boatplane bp2(2);
	//bp2 = bp;
	//std::cout << bp.GetPassengersCount();
	//std::cout << bp2.GetPassenger(0)->GetName();
	//std::cout << bp2.GetPassenger(1)->GetName();
	//std::cout << bp2.GetPassenger(2)->GetName();
	//std::cout << bp.GetPassengersCount();
	//assert(bp.GetPassengersCount() == 6);
	//assert(bp.GetMaxPassengersCount() == 10);

	//assert(a.GetPassengersCount() == 0);
	//assert(b.GetPassengersCount() == 0);

	//DeusExMachina* deusExMachina1 = DeusExMachina::GetInstance();
	//DeusExMachina* deusExMachina2 = DeusExMachina::GetInstance();

	//bool bSame = deusExMachina1 == deusExMachina2;
	//assert(bSame);

	//Airplane* airplane = new Airplane(5);
	//Boat* boat = new Boat(5);
	//Boatplane* boatplane = new Boatplane(5);
	//Motorcycle* motorcycle = new Motorcycle();
	//Sedan* sedan = new Sedan();
 //	Sedan* sedan2 = new Sedan();
	//UBoat* uboat = new UBoat();

	//bool bAdded = sedan2->AddTrailer(new Trailer(50));
	//assert(bAdded);

	//bAdded = sedan2->AddTrailer(new Trailer(60));
	//assert(!bAdded);

	//bAdded = deusExMachina1->AddVehicle(airplane);
	//assert(bAdded);

	//deusExMachina1->AddVehicle(boat);
	//deusExMachina1->AddVehicle(boatplane);
	//deusExMachina1->AddVehicle(motorcycle);
	//deusExMachina1->AddVehicle(sedan);
	//deusExMachina1->AddVehicle(sedan2);
	//deusExMachina1->AddVehicle(uboat);
	//deusExMachina1->AddVehicle(new Airplane(5));
	//deusExMachina1->AddVehicle(new Airplane(5));
	//deusExMachina1->AddVehicle(new Airplane(5));

	//bAdded = deusExMachina1->AddVehicle(new Airplane(5));

	//assert(!bAdded);

	//deusExMachina1->RemoveVehicle(9);
	//deusExMachina1->RemoveVehicle(8);
	//bool bRemoved = deusExMachina1->RemoveVehicle(7);
	//assert(bRemoved);

	//bRemoved = deusExMachina1->RemoveVehicle(9);
	//assert(!bRemoved);
	//
	//deusExMachina1->Travel(); // 모든 운송 수단이 이동
	//deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan, UBoat가 이동
	//deusExMachina1->Travel(); // Motorcycle, 두 Sedan이 이동
	//deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
	//deusExMachina1->Travel(); // UBoat만 빼고 전부 이동
	//deusExMachina1->Travel(); // 어떤 운송 수단도 움직이지 않음
	//deusExMachina1->Travel(); // Boat, Motorcycle, 트레일러 안 달린 Sedan, UBoat가 이동
	//deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan, UBoat가 이동
	//deusExMachina1->Travel(); // Airplane, Boatplane, Motorcycle, 두 Sedan이 이동
	//deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
	//deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
	//deusExMachina1->Travel(); // 트레일러 달린 Sedan만 이동
	//deusExMachina1->GetFurthestTravelled();
	////assert(deusExMachina1->GetFurthestTravelled() == boat);

	return 0;
}