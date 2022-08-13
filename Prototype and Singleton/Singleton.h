#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>

class Singleton
{
public:
	Singleton(Singleton&other) = delete;
	void operator = (Singleton& other) = delete;
	static Singleton *getInstance();
	void printColors();
	
	void addColor(std::string name,int id)
	{
		std::ofstream colors("Colors.txt",std::ios::app);
		colors <<std::endl<< name + " ID = \"" << id<<"\"";
		colors.close();
	}
	void deleteColor(std::string color);
	
	void textColor(HANDLE hout, std::string name);
	
	int findColor(std::string name);

private:
	
	Singleton() { std::cout << "Сработал конструктор одиночки\n"; }
	static Singleton* singleton;
};
