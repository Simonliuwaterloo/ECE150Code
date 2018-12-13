// \0 is in the array length but not in the string length
//the string length is at least 1 less than array length
//ptr naming convention s_
#include<iostream>
//determine the length of a string
std::size_t string_length(char* s_string) {
  for (int index = 0; true; ++index) {
    if (s_string[index] == '\0') {
      return index;
    }
  }
}
//copy a string
char* string_copy(char* s_string) {
  std::size_t length = string_length(s_string);
  char* result = new char[length + 1];
  for (std::size_t index = 0; index <= length; ++index) {
    result[index] = s_string[index];
  }
  return result;
}
//concatenate two strings
char* string_concatenate(char* str1, char* str2) {
  std::size_t length1 = string_length(str1);
  std::size_t length2 = string_length(str2);
  char* result = new char[length1 + length2 + 1];
  int k = 0;
  for (std::size_t i = 0; i < length1; ++i, ++k ) {
    result[k] = str1[i];
  }
  for (std::size_t i = 0; i < length2; ++i, ++k) {
    result[k] = str2[i];
  }
  return result;
}
int main() {
  //two ways of initializing a character array
  char myWord1[] = {'H', 'e', 'l', 'l', 'o', '\0'};
  char myWord2[] = "world";
  std::cout << myWord1 << " " << myWord2 <<std::endl;
  myWord2[2] = '\0';
  std::cout << myWord1 << " " << myWord2 <<std::endl;
  //we can also use pointers pointing to char array
  char* s_str = "This";
  std::cout <<string_concatenate(s_str, myWord1) << std::endl;
  //std::cout treat char pointers special
  std::cout << s_str <<" " << reinterpret_cast<void *>(s_str)
            << std::endl;
  char *sentence = (char*)"Hello world."; //c-style cast
  //sentence[3] = '!'; //segmenmtation fault
  char * sentence_copy = string_copy(sentence);
  sentence_copy[3] = '!';
  std::cout << sentence_copy;
}
