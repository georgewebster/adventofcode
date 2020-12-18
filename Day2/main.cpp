//

#include <iostream>
#include <fstream>
#include <string>




void part_one() {

	//Open file
	std::ifstream password_input;
	password_input.open("input.txt", std::ios::in);

	if (password_input.is_open()) {

		std::string line;
		int valid_passwords = 0;

		//Get each line of the input
		while (getline(password_input, line)) {
			
			int lower_range = std::stoi(line.substr(0, line.find_first_of('-')));
			int upper_range = std::stoi(line.substr(line.find_first_of('-') + 1, line.find_first_of(' ')));
			char given_letter = line.substr(line.find_first_of(' ') + 1, 1)[0];
			std::string password = line.substr(line.find_last_of(' ') + 1);


			int count = 0;
			//Iterate through the password, increment the count if the given letter appears
			for (char c : password) {
				if (given_letter == c) {
					count++;
				}
			}
			// Increment the number of valid passwords if the count falls between the range
			if (count >= lower_range && count <= upper_range) {
				valid_passwords++;
			}

		}
		std::cout << "Part 1: There are " << valid_passwords << " valid passwords\n";

	}
	else {
		std::cout << "Part 1 Failed: File could not be opened\n";
	}
}

void part_two() { 

	//Open file
	std::ifstream password_input;
	password_input.open("input.txt", std::ios::in);

	if (password_input.is_open()) {

		std::string line;
		int valid_passwords = 0;

		//Get each line of the input
		while (getline(password_input, line)) {

			int lower_range = std::stoi(line.substr(0, line.find_first_of('-')));
			int upper_range = std::stoi(line.substr(line.find_first_of('-') + 1, line.find_first_of(' ')));
			char given_letter = line.substr(line.find_first_of(' ') + 1, 1)[0];
			std::string password = line.substr(line.find_last_of(' ') + 1);

			if ((password.at(lower_range - 1) == given_letter || password.at(upper_range - 1) == given_letter) &&
				!(password.at(lower_range - 1) == given_letter && password.at(upper_range - 1) == given_letter)) {
				valid_passwords++;
			}			
		}
		std::cout << "Part 2: There are " << valid_passwords << " valid passwords\n";

	}
	else {
		std::cout << "Part 2 Failed: File could not be opened\n";
	}
}



int main()
{

	part_one();
	part_two();
}

