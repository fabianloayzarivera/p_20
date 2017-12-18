// 04Practica_4.cpp : Defines the entry point for the console application.
//
//
#include "stdafx.h"
#include <stdio.h>
#include "consola.h"
#include "Practica.h"


using namespace std;

struct TEntity;
typedef void(*funcEntity)(TEntity *);
typedef void(*functionEntity)();

// ***************************************************************************************
// ENTIDAD
// ***************************************************************************************
struct TEntity
{
	int m_ix;
	int m_iy;
	int m_speed_x;
	int m_speed_y;
	char m_graphic;
	int m_distance;
	int m_life;
	funcEntity *m_funcs;
	TEntity(funcEntity *funcs, int x, int y, int speed_x, int speed_y, char graphic, int life)
	{
		m_ix = x;
		m_iy = y;
		m_speed_x = speed_x;
		m_speed_y = speed_y;
		m_funcs = funcs;
		m_graphic = graphic;
		m_distance = 0;
		m_life = life;
	}
};


// ***************************************************************************************
// MAIN
// ***************************************************************************************
unsigned int uKey;
void generateNewEntity();
funcEntity functionsJaguar[] = { paintJaguarEntity, moveJaguarEntity };
funcEntity functionsDeer[] = { paintDeerEntity, moveDeerEntity };
funcEntity functionsPig[] = { paintPigEntity, movePigEntity };
funcEntity functionsDonkey[] = { paintDonkeyEntity, moveDonkeyEntity };

void main(int argc, char* argv[])
{
	// THIS IS AN ANIMAL RACE!	

	std::list<TEntity*>::iterator it;
	while (true) {		

		cout << "---------------------ANIMALS RELEASED!---------------------";

		it = animalsList.begin();
		while (it != animalsList.end())
		{
			funcEntity paint = *(*it)->m_funcs[0];
			funcEntity move = *(*it)->m_funcs[1];
			paint(*it);
			move(*it);
			it._Ptr->_Myval->m_life--;
			if (it._Ptr->_Myval->m_life <= 0)
			{
				animalsList.erase(it++);
			}
			else
				it++;
		}

		if (animalsList.size() < 5) {
			generateNewEntity();
		}

		Sleep(10);
		clear();
		hidecursor();
		
		
	}
	
	getchar();
	
}

void generateNewEntity() {
	int life = rand() % 100;
	int type = rand() % 4;

	if (type == 0) {
		TEntity *jaguar = new TEntity(functionsJaguar, 0, 5, JAGUAR_SPEED_X, JAGUAR_SPEED_Y, '>', life);
		animalsList.push_back(jaguar);
	}
	if (type == 1) {
		TEntity *deer = new TEntity(functionsDeer, 0, 10, DEER_SPEED_X, DEER_SPEED_Y, '8', life);
		animalsList.push_back(deer);
	}
	if (type == 2) {
		TEntity *pig = new TEntity(functionsPig, 0, 15, PIG_SPEED_X, PIG_SPEED_Y, 'o', life);
		animalsList.push_back(pig);
	}
	if (type == 3) {
		TEntity *donkey = new TEntity(functionsDonkey, 0, 20, DONKEY_SPEED_X, DONKEY_SPEED_Y, 'D', life);
		animalsList.push_back(donkey);
	}

}

void paintJaguarEntity(TEntity *animal) {

	gotoxy(animal->m_ix, animal->m_iy);
	cout << animal->m_graphic<<endl;
	gotoxy(animal->m_ix +2, animal->m_iy);
	cout << animal->m_graphic << endl;
	gotoxy(animal->m_ix -2, animal->m_iy);
	cout << animal->m_graphic << endl;
	gotoxy(animal->m_ix -4, animal->m_iy);
	cout << "=" << endl;
	gotoxy(animal->m_ix -2, animal->m_iy+1);
	cout << "L" << endl;
	gotoxy(animal->m_ix +2, animal->m_iy + 1);
	cout << "L" << endl;
	gotoxy(animal->m_ix + 4, animal->m_iy);
	cout << "B>" << endl;
}

void paintPigEntity(TEntity *animal) {

	gotoxy(animal->m_ix, animal->m_iy);
	cout << animal->m_graphic << endl;
	gotoxy(animal->m_ix + 2, animal->m_iy);
	cout << animal->m_graphic << endl;
	gotoxy(animal->m_ix - 2, animal->m_iy);
	cout << animal->m_graphic << endl;
	gotoxy(animal->m_ix - 4, animal->m_iy);
	cout << "-" << endl;
	gotoxy(animal->m_ix - 2, animal->m_iy + 1);
	cout << "P" << endl;
	gotoxy(animal->m_ix + 2, animal->m_iy + 1);
	cout << "P" << endl;
	gotoxy(animal->m_ix + 4, animal->m_iy);
	cout << "O=" << endl;

}

void paintDeerEntity(TEntity *animal) {

	gotoxy(animal->m_ix, animal->m_iy);
	cout << animal->m_graphic << endl;
	gotoxy(animal->m_ix + 2, animal->m_iy);
	cout << animal->m_graphic << endl;
	gotoxy(animal->m_ix - 2, animal->m_iy);
	cout << animal->m_graphic << endl;
	gotoxy(animal->m_ix - 4, animal->m_iy);
	cout << "/" << endl;
	gotoxy(animal->m_ix - 2, animal->m_iy + 1);
	cout << "L" << endl;
	gotoxy(animal->m_ix + 2, animal->m_iy + 1);
	cout << "L" << endl;
	gotoxy(animal->m_ix + 4, animal->m_iy);
	cout << "{o" << endl;

}

void paintDonkeyEntity(TEntity *animal) {

	gotoxy(animal->m_ix, animal->m_iy);
	cout << animal->m_graphic << endl;
	gotoxy(animal->m_ix + 2, animal->m_iy);
	cout << animal->m_graphic << endl;
	gotoxy(animal->m_ix - 2, animal->m_iy);
	cout << animal->m_graphic << endl;
	gotoxy(animal->m_ix - 4, animal->m_iy);
	cout << "/" << endl;
	gotoxy(animal->m_ix - 2, animal->m_iy + 1);
	cout << "|" << endl;
	gotoxy(animal->m_ix + 2, animal->m_iy + 1);
	cout << "|" << endl;
	gotoxy(animal->m_ix + 4, animal->m_iy);
	cout << "|>>" << endl;

}

void moveJaguarEntity(TEntity *animal) {

	animal->m_ix += animal->m_speed_x;
	animal->m_iy += animal->m_speed_y;
	animal->m_distance += static_cast<int>((pow(animal->m_speed_x, 2) + pow(animal->m_speed_y, 2)));
}

void movePigEntity(TEntity *animal) {

	animal->m_ix += animal->m_speed_x;
	animal->m_iy += animal->m_speed_y;
	animal->m_distance += static_cast<int>((pow(animal->m_speed_x, 2) + pow(animal->m_speed_y, 2)));

	if ((animal->m_distance > 30) && (animal->m_distance < 60)) {
		animal->m_speed_x = -1;
		animal->m_speed_y = 1;
	}
	if ((animal->m_distance > 60) && (animal->m_distance < 80))
		animal->m_speed_y = -1;
	if ((animal->m_distance > 80) && (animal->m_distance < 100))
		animal->m_speed_x = 1;
	if ((animal->m_distance > 100)) {
		animal->m_distance = 0;
		animal->m_speed_x = 1;
		animal->m_speed_y = 1;
	}	
	
}

void moveDeerEntity(TEntity *animal) {

	animal->m_ix += animal->m_speed_x;
	animal->m_iy += animal->m_speed_y;
	animal->m_distance += static_cast<int>((pow(animal->m_speed_x, 2) + pow(animal->m_speed_y, 2)));

	if ((animal->m_distance > 30) && (animal->m_distance < 60))
		animal->m_speed_y = 1;
	if ((animal->m_distance > 60) && (animal->m_distance < 80))
		animal->m_speed_y = -1;
	if ((animal->m_distance > 80) && (animal->m_distance < 100))
		animal->m_speed_y = 1;		
	if ((animal->m_distance > 100)) {
		animal->m_distance = 0;		
		animal->m_speed_y = -1;
	}
}

void moveDonkeyEntity(TEntity *animal) {

	animal->m_ix += animal->m_speed_x;
	animal->m_iy += animal->m_speed_y;
	animal->m_distance += static_cast<int>((pow(animal->m_speed_x, 2) + pow(animal->m_speed_y, 2)));

	if ((animal->m_distance > 30) && (animal->m_distance < 80))
		animal->m_speed_y = 1;
	if ((animal->m_distance > 80) && (animal->m_distance < 100 )) {
		animal->m_speed_y = -1;
		animal->m_speed_x = 0;
	}
	if ((animal->m_distance > 100) && (animal->m_distance < 150)) {
		animal->m_speed_y = 1;
		animal->m_speed_x = 1;
	}
	if ((animal->m_distance > 150)) {
		animal->m_distance = 0;
		animal->m_speed_y = -1;
		animal->m_speed_x = 0;
	}

}