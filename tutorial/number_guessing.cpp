#include <iostream>

int main();
int main(){
  bool guess_is = false;
  int quantity_guess = 1;
  int upper_bound = 255;
  int lower_bound = 1;
  int number_guess = (upper_bound + lower_bound)/2;
  std::string user_hint;
  while (guess_is == false || quantity_guess <= 8){
    std::cout << "Is your number" << number_guess << " ?" << std::endl;
    std::cin >> user_hint;
    if (user_hint == "Y") {
      guess_is = true;
      std::cout << "Hppray, I correctly guessed your secret number (21) in "
                << quantity_guess << " guesses!" << std::endl;
      
    }
    else {
      if (user_hint == "H"){
        lower_bound = number_guess + 1;
        number_guess = (upper_bound + lower_bound)/2;
      }
      else if (user_hint == "L"){
        upper_bound = number_guess - 1;
        number_guess = (upper_bound + lower_bound)/2;
      }
    }
    ++quantity_guess;
  }
}
