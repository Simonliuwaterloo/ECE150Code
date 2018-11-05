#include<iostream>

bool is_vowel(char input);
int main();

int main(){

  return is_vowel('u');;
}

bool is_vowel(char input){
  char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
  for (int n = 0; n < 5; n = n + 1){
    if (input == vowels[n]){
      return true;
    }
  }
  std::cout << "this is not a vowel";
  return false;
}
