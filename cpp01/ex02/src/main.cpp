#include <iostream>

int main(void)
{
  std::string testString("HI THIS IS BRAIN");
  std::string* stringPtr = &testString;
  std::string& stringRef = testString;
  std::cout << &testString << '\n';
  std::cout << stringPtr << '\n';
  std::cout << &stringRef << '\n';
  std::cout << testString << '\n';
  std::cout << *stringPtr << '\n';
  std::cout << stringRef << '\n';
  return (0);
}
