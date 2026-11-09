#include "Budget.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

int main() {
   Budget budget;
   std::string choice;
   std::cout << std::fixed << std::setprecision(2);

   while (true) {
      std::cout << "\n50/30/20 Budget\n"
                << "1. Enter monthly take-home income\n"
                << "2. View budget targets\n"
                << "3. Exit\n"
                << "Choose an option: ";

      if (!std::getline(std::cin, choice) || choice == "3") {
         break;
      }

      if (choice == "1") {
         std::cout << "Monthly take-home income in dollars: ";
         std::string line;
         if (!std::getline(std::cin, line)) {
            break;
         }

         std::istringstream input(line);
         double dollars;
         std::string extra;
         if (!(input >> dollars) || input >> extra ||
             !(dollars >= 0.0 && dollars <= 1000000000.0)) {
            std::cout << "Enter a dollar amount from 0 to 1000000000.\n";
         } else {
            budget.setIncomeCents(std::llround(dollars * 100));
            std::cout << "Income updated.\n";
         }
      } else if (choice == "2") {
         std::cout << "Monthly income: $" << budget.incomeCents() / 100.0 << '\n'
                   << "Needs (50%): $" << budget.needsCents() / 100.0 << '\n'
                   << "Wants (30%): $" << budget.wantsCents() / 100.0 << '\n'
                   << "Savings (20%): $" << budget.savingsCents() / 100.0 << '\n';
      } else {
         std::cout << "Choose 1, 2, or 3.\n";
      }
   }

   return 0;
}
