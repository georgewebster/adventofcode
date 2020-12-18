//

#include <iostream>
#include <fstream>
#include <string>




void part_one() {

	//Open file
	std::ifstream map_input;
	map_input.open("input.txt", std::ios::in);

	if (map_input.is_open()) {

		const char TREE = '#';
		const int Y_MOVEMENT{ 1 };
		const int X_MOVEMENT{ 3 };

		int toboggan_x_position{};
		int toboggan_y_position{};

		std::string map_x;
		int trees_encountered{};;

		while (getline(map_input, map_x)) {

			// Decide if we need to move over this line on the y
			if ((toboggan_y_position % Y_MOVEMENT == 0) && toboggan_y_position != 0) {

				//Move to along the x
				toboggan_x_position += X_MOVEMENT;

				//Check we're in bounds of the map
				if (toboggan_x_position > map_x.size() - 1)
					toboggan_x_position -= map_x.size();

				//Check for a TREE in our current position
				if (map_x.at(toboggan_x_position) == TREE)
					trees_encountered++;
			}

			//Increment the y
			toboggan_y_position++;
		}

		std::cout << "Part 1: You encountered " << trees_encountered << " trees \n";

	}
	else {
		std::cout << "Part 1 Failed: File could not be opened\n";
	}
}

void part_two() {

	//Open file
	std::ifstream map_input;
	map_input.open("input.txt", std::ios::in);

	if (map_input.is_open()) {

		const int X_AXIS = 0;
		const int Y_AXIS = 1;
		const char TREE = '#';
		const int SLOPE_COUNT{ 5 };
		const int MOVEMENTS[][2]{ {1,1}, {3,1}, {5,1}, {7,1}, {1,2} };

		std::string map_x;
		int toboggan_x_position{};
		int toboggan_y_position{};
		int trees_encountered{};
		long long result{ 1 };


		for (int i = 0; i < SLOPE_COUNT; i++) {
			while (getline(map_input, map_x)) {

				// Decide if we need to move over this line on the y, we never need the first line
				if ((toboggan_y_position % MOVEMENTS[i][Y_AXIS] == 0) && toboggan_y_position != 0) {

					//Move to along the x
					toboggan_x_position += MOVEMENTS[i][X_AXIS];

					//Check we're in bounds of the map
					if (toboggan_x_position > map_x.size() - 1)
						toboggan_x_position -= map_x.size();

					//Check for a TREE in our current position
					if (map_x.at(toboggan_x_position) == TREE)
						trees_encountered++;
				}

				//Increment the y
				toboggan_y_position++;
			}

			//Reset to the top of the file for the remaining slopes
			if (map_input.eof()) {
				map_input.clear();
				map_input.seekg(0);

				// Multiply the result with the number of trees encountered
				result *= trees_encountered;

				//Zero out vars for the next slope
				toboggan_x_position = 0;
				toboggan_y_position = 0;
				trees_encountered = 0;

				//std::cout << "Part 2: On slope " << i + 1 << " you encountered " << trees_encountered[i] << " trees \n";
			}
			else
			{
				std::cout << "Part 2 Failed: Enexpected error, input didn't reach EoF\n";
				return;
			}
		}
		std::cout << "Part 2: The result is " << result;
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

