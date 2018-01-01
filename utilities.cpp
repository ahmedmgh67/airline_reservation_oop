#include <iostream>

#include "utilities.h"

using namespace std;

int getChoice()
{
  char input[80], buffer[80];
  int choice = 2;

  while (true)
  {
    cout << "\nECS Flight Reservation Menu\n0. Exit\n1. Add Passenger.\n" << endl;

    while (true) // loop until 0 or 1
    {
      cout << "Please enter your choice: ";
      cin.getline(input, 80);

      if (NotDigit(input))
        cout << "Your number is invalid." << endl;

      else
      {
        choice = charToInt(input);

        if (choice > 1 || choice < 0)
          cout << choice << " is not an available choice." << endl;

        else // valid
          break;
      }

      cout << "Please try again.\n" << endl;
    }

    if (choice == 0)
      return 0;

    else
      return 1;
  }

} // getNumber()


bool NotDigit(char *c)
{
  int length = strlen(c);

  for (int i = 0; i < length; ++i)
  {
    if (! isdigit(c[i]))
      return true;
  }

  return false;
} // checkDigit()


void flushBuffer()
{
  char c;
  while ((c = getchar()) && c!= '\n' && c!= '\r');
} // flushBuffer()


int charToInt(char* c)
{
  int result = 0;

  for (int i = 0; c[i] != '\0'; ++i)
    result = result * 10 + c[i] - '0';

  return result;
} // charToInt()
