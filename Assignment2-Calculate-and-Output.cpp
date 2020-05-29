/*
assignment2 - chocolate
EEL3834
By: Taylor Rembos
*/

/* 
This program outputs how many chocolate bars and coupons you can collect given an input of number of dollars
*/

#include<iostream>
using namespace std;

int main()
{
	char input = 'y';
	int money;
	int coupons = 0;
	int total = 0;

	while(input=='y' || input =='Y')  // while the user would like to use this program
	{
		// user enters number of dollars to buy chocolate
		cout << "how much would you like to spend on chocolates?";
		cin >> money;

		total = money;
		coupons = money;

		while(coupons > 6)
		// 7 coupons adds one more chocolate bar onto total chocolate bars
		// coupons leftover is however many coupons out of 7 were not used for an additional bar
		{
			total += coupons / 7;
			coupons = (coupons / 7) + (coupons % 7);
		}

		cout << "You can buy " << total << " chocolates" << endl;
		cout << "You will have " << coupons << " leftover coupons" << endl;
		cout << "Would you like to use this program again? (y/n)";
		cin >> input;
	}
	return 0;
}