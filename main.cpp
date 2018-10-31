//
//  main.cpp
//  Train App
//
//  Created by Tanjin Prity on 6/7/18.
//  Copyright © 2018 Tanjin Prity. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class CAR                                       // class for train cars
{
public:
    CAR();                              // constructor
    int getWeight();             // returns the weight of the car in pounds
    void loadCar(int);           // loads a cargo with parameter weight(setter)
    CAR *nextCar;                // Car pointer to the next car on the train
private:
    int cargoWeight;              // the weight of the trains cargo
};

class TRAIN                     // train class as a linked list of cars
{
private:
    int trainWeight;
public:
    TRAIN();                   //constructor
    int getWeight();           // returns the weight of the train
    void loadTrain();          // load train with initial cars
    void addCar_front(int);
    void addCar_end(int);      // THIS IS CODE YOU MUST WRITE//
    //~TRAIN();                   // destructor THIS IS CODE YOU MUST WRITE
    void displayTrainInfo();
    CAR *firstCar;
};

CAR::CAR ()
{
    cargoWeight = 75;
    nextCar = NULL;
}
int CAR::getWeight()
{
    return cargoWeight;
}
void CAR::loadCar (int cargo)
{
    cargoWeight = cargo;
}

TRAIN::TRAIN()
{
    trainWeight = 0;
    firstCar = NULL;
}
int TRAIN::getWeight() // returns the train weight
{
    return trainWeight;
}

void TRAIN::loadTrain() // load train with initial cars
{
    addCar_front(0); // add first car - easier to add to the front
    addCar_front(10);
    addCar_front(20);
    addCar_front(30);
    addCar_front(40);
    addCar_front(50);
    addCar_front(60);
    addCar_end(60);
    addCar_end(30);
    addCar_end(40);
}
void TRAIN::addCar_end (int cWeight)    // add car to end
{
    // YOU MUST WRITE THIS FUNCTION
    if(firstCar == NULL && cWeight == 0)
    {
        addCar_front(cWeight);
    }
    else            //find the end of the train(traverse the train)
    {
        CAR* current;
        for(current = firstCar; current->nextCar != NULL; current = current->nextCar);     //no body or use {} without ;
        
        current->nextCar = new CAR;
        current->nextCar->nextCar = NULL;
        current->nextCar->loadCar(cWeight);
    }
}
void TRAIN::addCar_front (int cWeight)  // add first car to train
{
    // YOU MUST WRITE THIS FUNCTION
    if(firstCar == NULL && cWeight == 0)
    {
        firstCar = new CAR;
        firstCar->nextCar = NULL;
        firstCar->loadCar(cWeight);
    }
    else
    {
        CAR* hold_front;
        hold_front = firstCar;
        firstCar = new CAR;
        firstCar->nextCar = hold_front;
        firstCar->loadCar(cWeight);
    }
}
//TRAIN::~TRAIN()

void TRAIN::displayTrainInfo()
{
    int cnt = 0;
    CAR* ptrCar;
    for (ptrCar = firstCar; ptrCar != NULL && ++cnt <13; ptrCar = ptrCar->nextCar)
        cout << "+-------+  ";
    cout << endl;
    cnt = 0;
    for (ptrCar = firstCar; ptrCar != NULL && ++cnt < 13; ptrCar = ptrCar->nextCar)
        cout << "|       |  ";
    cout << endl; cnt = 0;
    for (ptrCar = firstCar; ptrCar != NULL && ++cnt < 13; ptrCar = ptrCar->nextCar)
    {
        if ((*ptrCar).getWeight() < 10)
            cout << "|   " << (*ptrCar).getWeight() << "   |->";  else    cout << "|   " <<
                (*ptrCar).getWeight() << "  |->";
    }
    cout << endl; cnt = 0;
    for (ptrCar = firstCar; ptrCar != NULL && ++cnt < 13; ptrCar = ptrCar->nextCar)
        cout << "|       |  ";
    cout << endl;
    cnt = 0;
    for (ptrCar = firstCar; ptrCar != NULL && ++cnt < 13; ptrCar = ptrCar->nextCar)
        cout << "+-------+  ";
    cout << endl;
}

int main()
{
    TRAIN MetroLiner;
    cout << "PROGRAM OUTPUT:" << endl;
    MetroLiner.loadTrain();
    MetroLiner.addCar_front(100);
    MetroLiner.addCar_end(99);
    MetroLiner.displayTrainInfo();
    //system("pause");
    return 0;
}
/*
 PROGRAM OUTPUT:
 +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+
 |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |
 |   100  |->|   60  |->|   50  |->|   40  |->|   30  |->|   20  |->|   10  |->|   0   |->|   60  |->|   30  |->|   40  |->|   99  |->
 |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |
 +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+
*/


