//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


void part_one() {

    const int target_value = 2020;

    //Open file
    std::ifstream expense_input;
    expense_input.open("input.txt", std::ios::in);

    if (expense_input.is_open()) {

        //iterate file lines into array
        std::vector<int> expense_arr;
        std::copy(
            std::istream_iterator<int>(expense_input),
            std::istream_iterator<int>(),
            std::back_inserter(expense_arr));

        // loop through until
        for (size_t i = 0; i < expense_arr.size(); i++) {

            for (size_t j = i + 1; j < expense_arr.size(); j++) {

                if (expense_arr[i] + expense_arr[j] == target_value) {

                    std::cout << "1) Expense report: " << expense_arr[i] << " + " << expense_arr[j] << " = " << target_value << "\n";
                    std::cout << "1) Correct answer: " << expense_arr[i] * expense_arr[j] << "\n";
                    break;
                }
            }
        }
    }
    else {
        std::cout << "Part 1 Failed: File could not be opened\n";
    }
}

void part_two() {

    const int target_value = 2020;

    //Open file
    std::ifstream expense_input;
    expense_input.open("input.txt", std::ios::in);

    if (expense_input.is_open()) {
        std::vector<int> expense_arr;

        std::copy(
            std::istream_iterator<int>(expense_input),
            std::istream_iterator<int>(),
            std::back_inserter(expense_arr));

        for (size_t i = 0; i < expense_arr.size(); i++) {

            for (size_t j = i + 1; j < expense_arr.size(); j++) {

                for (size_t k = j + 1; k < expense_arr.size(); k++) {

                    if (expense_arr[i] + expense_arr[j] + expense_arr[k] == target_value) {

                        std::cout << "2) Expense report: " << expense_arr[i] << " + " << expense_arr[j] << " + " << expense_arr[k] << " = " << target_value << "\n";
                        std::cout << "2) Correct answer: " << expense_arr[i] * expense_arr[j] * expense_arr[k];
                        break;
                    }
                }
            }
        }
    }
    else {
        std::cout << "Part 2 Failed: File could not be opened";
    }
}



int main()
{

    part_one();
    part_two();
}

