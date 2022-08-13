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
	//�������� ������� �������:
	// �� ���� ���� � ����� ��� ���������������
	//� �������� ������� ������ ����, ��� ��������� ���� ������ �� �����, � �� ������ ������.
	//�� ��������� ������ ���� �� �����, ���� ��� ����� �� �������� � ����.
	//��� ������ ����� � ���� ������������ ��� ������ name � id, ������� ���� ���� red ����� �� ����� �������, � ������ ��� ����� ������������.
	//���� � ����� 2 ���������� �����, ��������� ������ � �����
	//�� ���� ������ ������ ���������, ������� ��� ���� �������, ��������� �� ������ ���������� ���������� ��� �����.
	//
	Singleton::getInstance()->addColor("Jenya", 666);
	Singleton::getInstance()->printColors();
	std::string name;
	std::cout << "������� ��� �����: ";
	std::cin>>name;
	Singleton::getInstance()->textColor(hout,name);
	Singleton::getInstance()->deleteColor("Jenya");
	//
	//����� ��������
	// ���������� � ������� ������, ��� ������ �������� ��������� ����� ��� ���������� ������, � ������� ������ �������� ���
	// PS: ��, ����� �������� ����� ����������, ������� �� �����. �� ��� Ovcharka �������� ��, ��� ��������� ���� Ovcharka.txt
	//
	PrototypeClone* donor = new PrototypeClone();
	donor->setName("donor");
	int num;
	std::cout << "�������� �� �����: \n[1] ������ � �������\n[2] ��������� ����\n[3] ���� ����� �����������\n";
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