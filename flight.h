#ifndef FLIGHT_H
#define FLIGHT_H

#include "plane.h"

using namespace std;

class Flight
{
  int flightNum;
  char origin[20];
  char destination[20];
  Plane *plane;

public:
  Flight();
  ~Flight();
  void addPassenger();
  void printFlightInfo();
  bool operator == (int rhs);
  friend istream& operator >> (istream &is, Flight &flight);
  friend ostream& operator << (ostream& os, Flight &flight);
}; // class Flight



#endif
