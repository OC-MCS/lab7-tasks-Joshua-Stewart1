#include <iostream>
#include <iomanip>
using namespace std;
#include "Die.h"
// client code to use the Die class goes here

void displayPct(int array[], int size);

int main()
{
	const int REGULAR_SIZE = 6;
	const int SPECIAL_SIZE = 12;
	
	Die regularDie(REGULAR_SIZE);
	Die specialDie(SPECIAL_SIZE);
	int regularArray[REGULAR_SIZE + 1] = {0};
	int specialArray[SPECIAL_SIZE + 1] = {0};

	for (int i = 0; i < 1000000; i++)
	{
		regularDie.roll();
		regularArray[regularDie.getValue()]++;
		specialDie.roll();
		specialArray[specialDie.getValue()]++;
	}

	displayPct(regularArray, REGULAR_SIZE + 1);
	displayPct(specialArray, SPECIAL_SIZE + 1);

	return 0;
}

void displayPct(int array[], int size)
{
	float percent;
	
	cout << "Stats for " << size - 1 << " sided die:" << endl;
	cout << fixed << showpoint << setprecision(2);
	
	for (int i = 1; i < size; i++)
	{
		percent = static_cast<float>(array[i])/10000;
		cout << "Side " << i << ": "  << percent << endl;
	}
	cout << endl;
}