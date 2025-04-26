// C++ Program that Remove Identicals Characters from a String:
#include<iostream>
#include <cstring>
using namespace std;
void remove_identical_characters(char string[], const int string_length);
char to_Lowercase(char character);
int main()
{
  char string[50];
  // Taking Input: 
  cout << "Enter a String to Remove Identical Characters: ";
  cin.getline(string, 50);
  int string_length = strlen(string); // To find length of the string.
  remove_identical_characters(string, string_length);
  return 0;
}
// Function to remove Identical characters:
void remove_identical_characters(char string[], const int string_length)
{
  cout << "\nAfter removing identical characters from the string: " << endl;
  for (int i = 0; i < string_length; i++)
  {
    int character_count = 0;
    char current = to_Lowercase(string[i]);
    for (int j = 0; j < string_length; j++)
    {
      if (to_Lowercase(string[j]) == current)
      {
        character_count++;
      }
    }
    if (character_count == 1)// To check if the character occurs only once in the given string.
    {
      cout << string[i];
    }
  }
}
// To convert into lowercase characters:
char to_Lowercase(char character)
{
  if (character >= 'A' && character <= 'Z')
  {
    return character + 32;
  }
  return character;
}