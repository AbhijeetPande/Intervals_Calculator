//============================================================================
// Name        : Intervals.cpp
// Author      : Abhijeet
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

  int main();
void print_method(double low, double high);
void con(bool INIT);

struct memory { // MANNER IN WHICH MEMORY IS STORED
  double a;
  double b;
};
struct multiplier { // USED IN ORDER TO KEEP TRACK OF INTERVALS WHEN MULTIPLYING
  double ac;
  double ad;
  double bc;
  double bd;
};
struct c_int { // USED IN ORDER TO KEEP TRACK OF INTERVALS WHEN FINDING CARTESIAN INTEGERS
  int xfirst;
  int xlast;
  int yfirst;
  int ylast;
};
int main() {
  memory current; // REPRESENTS ACTIVE MEMORY
  memory saved; // REPRESENTS SAVED MEMORY
  memory operate; // REPRESENTS INPUTTED MEMORY WHICH PERFORMS AN OPERATION WITH THE ACTIVE MEMORY
  multiplier multi;
  c_int note;
  bool confirm_initialization = false; // CONFIRMS WHETHER CURRENT MEMORY IS ACTIVE
  bool confirm_saved = false; // CONFIRMS WHETHER SAVED MEMORY IS ACTIVE
  bool invalid_entry = true; // CONFIRMS ONLY VALID ENTERIES ARE PASSED
  double scalar;
  std::string input;

  while (input != "exit") { // WHEN USER WANTS TO EXIT, IT BREAKS THE WHILE LOOP
    invalid_entry = true;
    std::cout << "input :> ";
    std::cin >> input;

    if (input == "exit") { // EXITS THE PROGRAM
      invalid_entry = false;
      std::cout << "Bye bye: Terminating interval calculator program." << std::endl;
    }
    if (input == "enter") { // ENTERS AN INTERVAL
      invalid_entry = false;
      double lower, higher;
      std::cin >> lower;
      std::cin >> higher;
      if (lower > higher) {
        std::cout << "Error: invalid interval as " << lower << " > " << higher << std::endl;
        con(confirm_initialization);
        if (confirm_initialization == true) {
          print_method(current.a, current.b);
        }
      } else if (higher >= lower) {
        confirm_initialization = true;
        current.a = lower;
        current.b = higher;
        print_method(current.a, current.b);
      } else {
        std::cout << "Invalid entry. Please try again";
      }
    }
    if (input == "negate") { // TURNS IT THE INTERVAL INTO A NEGATIVE VERSION OF ITSELF
      invalid_entry = false;
      con(confirm_initialization);
      if (confirm_initialization == true) {
        double tmp = 0;
        current.a = -1 * current.a;
        current.b = -1 * current.b;
        tmp = current.b;
        current.b = current.a;
        current.a = tmp;
        print_method(current.a, current.b);
      }
    }
    if (input == "invert") { // RECIPROCATES EACH OF THE VALUES OF THE INTERVAL
      invalid_entry = false;
      if (((current.a == 0 || current.b == 0) && confirm_initialization == true) || (current.a < 0 && current.b > 0)) {
        std::cout << "Error: division by zero" << std::endl;
        confirm_initialization = false;
      }
      con(confirm_initialization);
      if (confirm_initialization == true && current.a != 0 && current.b != 0) {
        double tmp = 0;
        current.a = (1 / current.a);
        current.b = (1 / current.b);
        tmp = current.a;
        current.a = current.b;
        current.b = tmp;
        print_method(current.a, current.b);
      }

    }
    if (input == "ms") { // INPUTS CURRENT MEMORY INTO SAVED MEMORY
      invalid_entry = false;
      con(confirm_initialization);
      if (confirm_initialization == true) {
        saved.a = current.a;
        saved.b = current.b;
        confirm_saved = true;
        print_method(current.a, current.b);
      }
    }
    if (input == "mr") { // RETURNS SAVED MEMORY AND PUTS IT INTO CURRENT MEMORY
      invalid_entry = false;
      if (confirm_saved == false && confirm_initialization == false) {
        std::cout << "--";
      }
      if (confirm_saved == false && confirm_initialization == true) {
        print_method(current.a, current.b);
      }
      if (confirm_initialization == true && confirm_saved == true) {
        current.a = saved.a;
        current.b = saved.b;
        print_method(current.a, current.b);
      }
    }
    if (input == "mc") { //CLEANS THE SAVED MEMORY
      invalid_entry = false;
      con(confirm_initialization);
      if (confirm_saved == false && confirm_initialization == true) {
        print_method(current.a, current.b);
      }
      if (confirm_initialization == true && confirm_saved == true) {
        confirm_saved = false;
        saved.a = 0;
        saved.b = 0;
        print_method(current.a, current.b);
      }
    }
    if (input == "m+") { // ADDS THE SAVED MEMORY AND THE CURRENT MEMORY
      invalid_entry = false;
      con(confirm_initialization);
      if (confirm_saved == false && confirm_initialization == true) {
        print_method(current.a, current.b);
      }
      if (confirm_initialization == true && confirm_saved == true) {
        saved.a = saved.a + current.a;
        saved.b = saved.b + current.b;
        print_method(current.a, current.b);
      }
    }
    if (input == "m-") { // SUBTRACTS THE SAVED MEMORY AND THE CURRENT MEMORY
      invalid_entry = false;
      con(confirm_initialization);
      if (confirm_saved == false && confirm_initialization == true) {
        print_method(current.a, current.b);
      }
      if (confirm_initialization == true && confirm_saved == true) {
        saved.a = saved.a - current.a;
        saved.b = saved.b - current.b;
        print_method(current.a, current.b);
      }
    }
    if (input == "scalar_add") { // ADDS THE CURRENT MEMORY BY A SCALAR
      std::cin >> scalar;
      invalid_entry = false;
      con(confirm_initialization);
      if (confirm_initialization == true) {
        current.a = current.a + scalar;
        current.b = current.b + scalar;
        print_method(current.a, current.b);
      }
    }
    if (input == "scalar_subtract") { // SUBTRACTS THE CURRENT MEMORY BY A SCALAR
      std::cin >> scalar;
      invalid_entry = false;
      con(confirm_initialization);
      if (confirm_initialization == true) {
        current.a = current.a - scalar;
        current.b = current.b - scalar;
        print_method(current.a, current.b);
      }
    }
    if (input == "scalar_multiply") { // MULTIPLIES THE CURRENT MEMORY BY A SCALAR
      std::cin >> scalar;
      invalid_entry = false;
      con(confirm_initialization);
      if (confirm_initialization == true && scalar >= 0) {
        current.a = current.a * scalar;
        current.b = current.b * scalar;
        print_method(current.a, current.b);
      }
      if (confirm_initialization == true && scalar < 0) {
        current.a = current.a * scalar;
        current.b = current.b * scalar;
        double tmp = 0;
        tmp = current.a;
        current.a = current.b;
        current.b = tmp;
        print_method(current.a, current.b);
      }
    }
    if (input == "scalar_divide") { // DIVIDES THE CURRENT MEMORY BY A SCALAR
      std::cin >> scalar;
      invalid_entry = false;
      if (confirm_initialization == false && scalar == 0) {
        std::cout << "Error: division by zero" << std::endl;
        std::cout << "--";
        confirm_initialization = false;
      }
      if (confirm_initialization == false && scalar != 0) {
        std::cout << "--";
      }
      if (confirm_initialization == true && scalar > 0) {
        current.a = current.a / scalar;
        current.b = current.b / scalar;
        print_method(current.a, current.b);
      }
      if (confirm_initialization == true && scalar < 0) {
        current.a = current.a / scalar;
        current.b = current.b / scalar;
        double tmp = 0;
        tmp = current.a;
        current.a = current.b;
        current.b = tmp;
        print_method(current.a, current.b);
      }
      if (confirm_initialization == true && scalar == 0) {
        std::cout << "Error: division by zero" << std::endl;
        std::cout << "--";
        confirm_initialization = false;
      }
    }
    if (input == "scalar_divided_by") { // A SCALAR VALUE GETS DIVIDED BY THE INTERVAL
      std::cin >> scalar;
      invalid_entry = false;
      con(confirm_initialization);
      if ((confirm_initialization == true && (current.a == 0 || current.b == 0)) || (current.a <= 0 && current.b >= 0)) {
        std::cout << "Error: division by zero" << std::endl;
        std::cout << "--";
        confirm_initialization = false;
      }
      if (confirm_initialization == true && scalar > 0) {
        current.a = scalar / current.a;
        current.b = scalar / current.b;
        double tmp = 0;
        tmp = current.a;
        current.a = current.b;
        current.b = tmp;
        print_method(current.a, current.b);
      }
      if (confirm_initialization == true && scalar <= 0) {
        current.a = scalar / current.a;
        current.b = scalar / current.b;
        print_method(current.a, current.b);
      }
    }
    if (input == "interval_add") { // ADDS TWO INTERVALS TOGETHER (INPUT AND ACTIVE)
      invalid_entry = false;
      std::cin >> operate.a;
      std::cin >> operate.b;
      if (operate.a > operate.b) {
        std::cout << "Error: invalid interval as " << operate.a << " > " << operate.b << std::endl;
        if (confirm_initialization == true) {
          print_method(current.a, current.b);
        } else {
          con(confirm_initialization);
        }
      }
      if (operate.a <= operate.b && confirm_initialization == true) {
        current.a = current.a + operate.a;
        current.b = current.b + operate.b;
        print_method(current.a, current.b);
      }
      if (operate.a <= operate.b && confirm_initialization == false) {
        std::cout << "--";
      }
    }
    if (input == "interval_subtract") { // SUBTRACTS TWO INTERVALS TOGETHER (INPUT AND ACTIVE)
      invalid_entry = false;
      std::cin >> operate.a;
      std::cin >> operate.b;
      if (operate.a > operate.b) {
        std::cout << "Error: invalid interval as " << operate.a << " > " << operate.b << std::endl;
        if (confirm_initialization == true) {
          print_method(current.a, current.b);
        } else {
          con(confirm_initialization);
        }
      }
      if (operate.a <= operate.b && confirm_initialization == true) {
        current.a = current.a - operate.b;
        current.b = current.b - operate.a;
        print_method(current.a, current.b);
      }
      if (operate.a <= operate.b && confirm_initialization == false) {
        std::cout << "--";
      }
    }
    if (input == "interval_multiply") { // MULTIPLIES TWO INTERVALS TOGETHER (ACTIVE AND INPUT)
      invalid_entry = false;
      std::cin >> operate.a;
      std::cin >> operate.b;
      if (operate.a > operate.b) {
        std::cout << "Error: invalid interval as " << operate.a << " > " << operate.b << std::endl;
        if (confirm_initialization == true) {
          print_method(current.a, current.b);
        } else {
          con(confirm_initialization);
        }
      }
      if (operate.a <= operate.b && confirm_initialization == true) {
        multi.ac = current.a * operate.a;
        multi.ad = current.a * operate.b;
        multi.bc = current.b * operate.a;
        multi.bd = current.b * operate.b;
        current.a = std::min(std::min(multi.ac, multi.ad), std::min(multi.bc, multi.bd));
        current.b = std::max(std::max(multi.ac, multi.ad), std::max(multi.bc, multi.bd));
        print_method(current.a, current.b);
      }
      if (operate.a <= operate.b && confirm_initialization == false) {
        std::cout << "--";
      }
    }
    if (input == "interval_divide") { // DIVIDES TWO INTERVALS (ACTIVE AND INPUT)
      invalid_entry = false;
      std::cin >> operate.a;
      std::cin >> operate.b;
      if (operate.a == 0 || operate.b == 0 || (operate.a < 0 && operate.b > 0)) {
        std::cout << "Error: division by zero" << std::endl;
        confirm_initialization = false;
        con(confirm_initialization);
      }
      if (operate.a > operate.b && (operate.a != 0 && operate.b != 0)) {
        std::cout << "Error: invalid interval as " << operate.a << " > " << operate.b << std::endl;
        if (confirm_initialization == true) {
          print_method(current.a, current.b);
        } else {
          con(confirm_initialization);
        }
      }
      if (operate.a <= operate.b && confirm_initialization == true) {
        multi.ac = current.a / operate.a;
        multi.ad = current.a / operate.b;
        multi.bc = current.b / operate.a;
        multi.bd = current.b / operate.b;
        current.a = std::min(std::min(multi.ac, multi.ad), std::min(multi.bc, multi.bd));
        current.b = std::max(std::max(multi.ac, multi.ad), std::max(multi.bc, multi.bd));
        print_method(current.a, current.b);
      }
      if (operate.a <= operate.b && confirm_initialization == false && operate.a != 0 && operate.b != 0) {
        std::cout << "--";
      }
    }
    if (input == "intersect") { // RETURNS THE INTERSECTED INTERVAL BETWEEN INPUT AND CURRENT MEMORY INTERVALS
      invalid_entry = false;
      std::cin >> operate.a;
      std::cin >> operate.b;
      if (operate.a > operate.b) {
        std::cout << "Error: invalid interval as " << operate.a << " > " << operate.b << std::endl;
        if (confirm_initialization == true) {
          print_method(current.a, current.b);
        }
      }
      con(confirm_initialization);
      if ((operate.a > current.b || operate.b < current.a) && confirm_initialization == true) {
        confirm_initialization = false;
        con(confirm_initialization);
      }
      if (operate.a <= operate.b && confirm_initialization == true) {
        if (operate.a > current.a) {
          current.a = operate.a;
        }
        if (operate.b < current.b) {
          current.b = operate.b;
        }
        print_method(current.a, current.b);
      }
    }
    if (input == "integers") {
      invalid_entry = false;
      con(confirm_initialization);
      if (confirm_initialization == true) {
        int first = (int) current.a;
        int last = (int) current.b;
        if (current.a / (double) first > 1) {
          first = first + 1;
        }
        while (first <= last) {
          std::cout << first;
          if (first != last) {
            std::cout << ", ";
          }
          ++first;
        }
        std::cout << std::endl;
        print_method(current.a, current.b);
      }
    }
    if (input == "cartesian_integers") { //RETURNS THE 4 CARTESIAN INTEGERS CREATED
      invalid_entry = false;
      std::cin >> operate.a;
      std::cin >> operate.b;
      if (operate.a > operate.b) {
        std::cout << "Error: invalid interval as " << operate.a << " > " << operate.b << std::endl;
      }
      con(confirm_initialization);

      if ((int) operate.a <= (int) operate.b && confirm_initialization == true) {
        note.xfirst = (int) current.a;
        note.xlast = (int) current.b;
        note.yfirst = (int) operate.a;
        note.ylast = (int) operate.b;
        if ((current.a / (double) note.xfirst) > 1 && current.a > 0) {
          note.xfirst = note.xfirst + 1;
        }
        if ((operate.b / (double) note.yfirst) > 1 && operate.b > 0) {
          note.yfirst = note.yfirst + 1;
        }
        if ((current.b / (double) note.xlast) > 1 && current.b < 0) {
          note.xlast = note.xlast - 1;
        }
        if ((operate.a / (double) note.ylast) > 1 && operate.a < 0) {
          note.ylast = note.ylast - 1;
        }
        if (operate.a == operate.b) {
          std::cout << "(" << note.xfirst << ", " << note.yfirst << ")";
        }
        if ((int) operate.a < (int) operate.b && confirm_initialization == true) {
          for (int i = note.xfirst; i <= note.xlast; i++) {
            for (int j = note.yfirst; j <= note.ylast; j++) {
              std::cout << "(" << i << ", " << j << ")";
              if (i != note.xlast || j != note.ylast) {
                std::cout << ", ";
              }
            }
          }
        }
        std::cout << std::endl;
      }
      if (confirm_initialization == true) {
        print_method(current.a, current.b);
      }

    }
    if (invalid_entry == true) { // RUNS IF NONE OF THE ABOVE COMMANDS ARE TRIGGERED
      std::cout << "Error: illegal command";
    }
    std::cout << std::endl;
  }
}

void print_method(double low, double high) { // MANNER IN WHICH INTERVALS ARE PRINTED
  std::cout << "[" << low << ", " << high << "]";
}
void con(bool INIT) { // PRINTS -- IF THERE IS NOTHING TO PRINT
  if (INIT == false) {
    std::cout << "--";
  }
}
