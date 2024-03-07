#include <iostream>

using namespace std;

string convert(int** prices, int dealership_count, int car_count, string* names);
void random_init_price(int** prices, int dealership_count, int car_count);
int find_rich_dealership(int** prices, int dealership_count, int car_count);

int main() {

	string names[] = {"Super Dealer", "AutoHouse", "My Car", "SuperCar"};
	int count_of_dealership = 4;
	int count_of_car;

	do {
		system("cls");
		//cout << "Input number of car dealerships: " << endl;
		//cin >> count_of_dealership;
		cout << "Input number of car: " << endl;
		cin >> count_of_car;
	} while (count_of_dealership <= 0 || count_of_car <= 0);

	int** prices = new int* [count_of_dealership];
	for (int j = 0; j < count_of_dealership; j++){
		*(prices + j) = new int[count_of_car];
	}

	random_init_price(prices, count_of_dealership, count_of_car);

	cout << convert(prices, count_of_dealership, count_of_car, names) << endl;

	cout << "Name of rich dealership is " << *(names
		+ find_rich_dealership(prices, count_of_dealership, count_of_car)) << endl;

	for (int i = 0; i < count_of_dealership; i++) {
		delete[] *(prices + i);
	}

	delete[] prices;

	return 0;
}