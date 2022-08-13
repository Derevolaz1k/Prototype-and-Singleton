#include "Singleton.h"
Singleton *Singleton::getInstance()
{
	if (singleton == nullptr)
	{
		singleton = new Singleton;
	}
	return singleton;
}
void Singleton::deleteColor(std::string color)
{
	std::vector < std::string> colorsStr;
	std::ifstream colors("Colors.txt", std::ios::app);
	std::string str;
	while (std::getline(colors, str))
	{
		if (str.find(color) == std::string::npos)
		{
			colorsStr.push_back(str);
		}
	}
	colors.close();
	std::ofstream colorsOut("Colors.txt");
	for (const auto it : colorsStr)
	{
		if (it != "")
			colorsOut << it << std::endl;
	}
	colorsOut.close();
}
void Singleton::textColor(HANDLE hout, std::string name)
{
	int temp = findColor(name);
	if (temp != -1)
	{
		SetConsoleTextAttribute(hout, temp);
	}
	else
	{
		std::cerr << "÷вет не найден в базе\n";
	}
}
int Singleton::findColor(std::string name)
{
	std::ifstream colors("Colors.txt");
	std::string str;
	while (std::getline(colors, str))
	{
		if (str.find(name) != std::string::npos)
		{
			int id = 0;
			auto it = std::find_if(str.begin(), str.end(), isdigit);

			if (it != str.end())
			{
				id = std::atoi(str.c_str() + (it - str.begin()));
				return id;
			}
		}
	}
	return -1;
}
void Singleton::printColors()
{
	std::ifstream colors("Colors.txt");
	std::string tmp;
	while (std::getline(colors, tmp))
	{
		if(tmp!="")
		std::cout << tmp << std::endl;
	}
	colors.close();
}