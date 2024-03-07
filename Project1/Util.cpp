#include <stdlib.h>
#include <string>

using namespace std;

void random_init_price(int** prices, int dealership_count, int car_count) {

	for (int i = 0; i < dealership_count; i++) {
		for (int j = 0; j < car_count; j++) {
			*(*(prices + i) + j) = rand() % 1000 * 100;
		}
	}
}

string convert(int** prices, int dealership_count, int car_count, string* names) {
	string msg = "";

	for (int i = 0; i < dealership_count; i++) {
		msg += names[i] + " - ";
		for (int j = 0; j < car_count; j++) {
			msg += to_string(*(*(prices + i) + j)) + " ";
		}
		msg += "\n";
	}

	return msg;
}