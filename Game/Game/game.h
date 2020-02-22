#pragma once
class game
{
private:
	struct people
	{
		int population;
		int affected;
		int cured;
		int maybe;
	};
	struct nation
	{
		int money;
		int totalHospitalCapacity;
		int usableDoctor;
	};
	void move();
	void show();
};

