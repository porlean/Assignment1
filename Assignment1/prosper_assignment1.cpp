/* File Name: prosper.assignment1.cpp
   Author: Orlean Prosper
   Email: oprosper2022@fau.edu
   Assignment Number: 1
   Descrition: A program that will give the amount of coins possible given a dollar amount inputted by the user
			   and given the amount of coins will give a dollar amount
   Last changed: 05/30/2023
*/
#include <cstdlib>
#include <iostream>
using namespace std;

//Function prototypes
void coins_despenser();
void bills_despenser();

//Global variable constants
const int QUARTER = 25;
const int DIME = 10;
const int NICKEL = 5;
const int PENNY = 1;

int main() {
	
	int menu_option;

	//User menu implementation
	do
	{
		cout <<"\n\n--------------------------------------------------\n"
			 << "Please select an option from the menu below\n"
			 << "(1)Coin Despenser\n"
			 << "(2)Bill Despenser\n"
			 << "(3)Quit\n"
			 << "Your option: ";
		cin >> menu_option;

		//Using "switch" for the menu options
		switch (menu_option)
		{
			case 1:
				coins_despenser();
				break;
			case 2:
				bills_despenser();
				break;
			case 3:
				cout << "\nEnding program. Have a nice day!\n";
				break;
			default:
				cout << "\nPlease enter a valid menu option\n";
		}
	} while (menu_option != 3);

	return 0;

}

//Function for the first program
void coins_despenser()
{

	int quarter_count=0, dime_count=0, nickel_count=0, penny_count=0, remainder=0, cents;
	double value = 0.00;

	cout <<"\n\n------------------------------------------------------\n"
		 << "Please enter the amount you would like to convert(from $0.00 - $99.99):$";
	cin >> value;

	//Checks to make sure that the inputted value is withen range
	if (value < 0 || value >= 100)
	{
		cout << "Please only enter values between $0.00 and $99.99\n"
			 << "...Aborting program";
		exit(1);
	}

	cents = (int)(value * 100.00);

	//Calculations and conditions for the coin amount
	if (cents >= QUARTER) 
	{

		quarter_count = cents / QUARTER;
		remainder = cents % QUARTER;
		dime_count = remainder / DIME;
		remainder %= DIME;
		nickel_count = remainder / NICKEL;
		remainder %= NICKEL;
		penny_count = remainder / PENNY;
	}
	else if (cents >= DIME) 
	{

		dime_count = cents / DIME;
		remainder = cents % DIME;
		nickel_count = remainder / NICKEL;
		remainder %= NICKEL;
		penny_count = remainder / PENNY;
	}
	else if (cents >= NICKEL) 
	{

		nickel_count = cents / NICKEL;
		remainder = cents % NICKEL;
		penny_count = remainder / PENNY;
	}
	else penny_count = cents / PENNY;


	cout << "Value: $" << value << endl;
	cout << "Quater: " << quarter_count << endl;
	cout << "Dime: " << dime_count << endl;
	cout << "Nickel: " << nickel_count << endl;
	cout << "Penny: " << penny_count << endl;
}

void bills_despenser() 
{

	int quarter_count = 0, dime_count = 0, nickel_count = 0, penny_count = 0, remainder = 0;
	double value = 0.00;

	cout <<"\n\n------------------------------------------------------\n"
		 << "Amount of quarters: ";
	cin >> quarter_count;
	cout << "Amount of dimes: ";
	cin >> dime_count;
	cout << "Amount of nickels: ";
	cin >> nickel_count;
	cout << "Amount of pennies: ";
	cin >> penny_count;

	//Getting the whole number value for the coins
	quarter_count *= QUARTER;
	dime_count *= DIME;
	nickel_count *= NICKEL;
	penny_count *= PENNY;

	//Getting the dollar value
	value = (quarter_count + dime_count + nickel_count + penny_count) / 100.0;

	//Truncating the amount at 2 decimal places
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << "$" << value << endl;
}