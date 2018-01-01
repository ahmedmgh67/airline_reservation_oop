#include "flight.h"

using namespace std;


Flight::Flight() : plane(NULL)
{} // constructor

Flight::~Flight()
{
  delete plane;
} // destructor


istream& operator >> (istream &is, Flight & flight)
{
  char buffer[20];

  is >> flight.flightNum;
  is.getline(buffer, 20); // read in \n \r
  is.getline(flight.origin, 20);
  is.getline(flight.destination, 20);

  flight.plane = new Plane();
  is >> *flight.plane;

  return is;
} // operator >>


ostream& operator << (ostream& os, Flight & flight)
{
  os << flight.flightNum << endl;
  os << flight.origin << endl;
  os << flight.destination << endl;
  os << *flight.plane;

  return os;
} // operator <<


void Flight::addPassenger()
{
  plane->addPassenger();
} // addPassenger()


bool Flight::operator == (int rhs)
{
  return rhs == flightNum;
} // operator ==


void Flight::printFlightInfo()
{
  // the system is broken on this
  cout << "\nFlt# " << flightNum << endl;
  cout << " Origin: " << origin << endl;
  cout << " Destination: " << destination << endl;
  // cout << left << setw(5) << flightNum << ' '
  //   << setw(21) << origin << ' '  << destination << endl;

  // Flt# Origin               Destination
  // 230  Reno                 Los Angeles
  // 463  Stockton             Los Angeles
  // 770  Sacramento           San Francisco
  // 221  Reno                 Davis
} // printFlight()
