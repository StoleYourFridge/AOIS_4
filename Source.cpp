#include "AOIS_4.h"

int main()
{
	int choice;
	cout << "1)Tests :: 2)Lab_output" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1: tests();
		break;
	case 2: Lab_tasks();
		break;
	default: cout << "Enter something posible to work with!!" << endl;
		break;
	}
	return 0;
}