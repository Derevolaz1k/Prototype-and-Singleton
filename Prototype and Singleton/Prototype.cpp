#pragma once
#include <iostream>
#include "Prototype.h"

void PrototypeClone::printPhoto()
{
	std::ifstream photo;
	photo.open(name + ".txt");
	std::string photo_print;
	if (photo.is_open())
	{
		while (!photo.eof())
		{
			std::getline(photo, photo_print);
			std::cout << photo_print << std::endl;
		}
	}
	else
	{
		std::cout << "Name photo not found!\n";
	}
	photo.close();
}