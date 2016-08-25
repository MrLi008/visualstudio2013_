#pragma once
class Integer
{
public:
	Integer();
	Integer(int val);

	~Integer();
	void printInteger();

	//bool operator==(const Integer& anotherInteger)const;
	Integer* clone();
private:
	int value;
};

