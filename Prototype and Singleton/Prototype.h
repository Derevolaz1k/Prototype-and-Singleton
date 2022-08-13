#pragma once
#include <string>
#include <fstream>
class PrototypeDonor
{
public:
	virtual PrototypeDonor *clone()const = 0;
	virtual void setName(std::string name) {}
	virtual std::string getName()const = 0;
	virtual void printPhoto() = 0;
};

class PrototypeClone :public PrototypeDonor
{
public:
	PrototypeClone() {}
	void setName(std::string name)override
	{
		this->name = name;
	}
	std::string getName()const override
	{
		return name;
	}
	void printPhoto();
	
	PrototypeClone *clone()const
	{
		return new PrototypeClone(*this);
	}
private:
	PrototypeClone(PrototypeClone* other)
	{
		name = other->name;
	}
	std::string name;
};
