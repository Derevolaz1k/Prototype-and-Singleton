#include <iostream>
#include <string>
#include <fstream>
#include "Prototype.h"
#include "Singleton.h"
#include <Windows.h>

Singleton* Singleton::singleton = nullptr;
HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	setlocale(LC_ALL, "Russian");
	//ОДИНОЧКА КРАТКИЙ ЭКСКУРС:
	// НЕ ЗНАЮ КУДА И ЗАЧЕМ ТУТ МНОГОПОТОЧНОСТЬ
	//В принципе главная задача была, это доставать цвет именно из файла, а не откуда попало.
	//Не получится ввести цвет от балды, если его ранее не заносили в файл.
	//При заносе цвета в базу пользователь САМ вводит name и id, поэтому если цвет red будет по факту зеленым, я считаю это виной пользователя.
	//Если в файле 2 одинаковых цвета, выберется первый в файле
	//Не стал делать другие настройки, принцип мне стал понятен, остальное на основе сделанного доработать уже легко.
	//
	Singleton::getInstance()->addColor("Jenya", 666);
	Singleton::getInstance()->printColors();
	std::string name;
	std::cout << "Введите имя цвета: ";
	std::cin>>name;
	Singleton::getInstance()->textColor(hout,name);
	Singleton::getInstance()->deleteColor("Jenya");
	//
	//КЛАСС ПРОТОТИП
	// Реализовал с помощью свитча, при выборе картинки создается копия уже созданного класса, в которой просто меняется имя
	// PS: То, какая картинка будет напечатана, зависит от имени. Тк имя Ovcharka означает то, что откроется файл Ovcharka.txt
	//
	PrototypeClone* donor = new PrototypeClone();
	donor->setName("donor");
	int num;
	std::cout << "Картинка на выбор: \n[1] Собака в кожанке\n[2] Президент мира\n[3] Язык эпохи просвящения\n";
	std::cin >> num;
	switch (num)
	{
	case 1:
	{
		PrototypeClone* prototype = donor->clone();
		prototype->setName("Ovcharka");
		prototype->printPhoto();
	}break;
	case 2:
	{
		PrototypeClone* prototype = donor->clone();
		prototype->setName("Putin");
		prototype->printPhoto();
	}break;
	case 3:
	{
		PrototypeClone* prototype = donor->clone();
		prototype->setName("C++");
		prototype->printPhoto();
	}break;
	default:
		break;
	}
	return 0;
}