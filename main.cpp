#include "flight.h"

using namespace std;

void addPassenger(Flight* flights, int numFlights);
bool compareFlight(int input, int numFlights, Flight* flights);
void writeNewFile(Flight *flights, int numFlights);

int main()
{
  int numFlights = 0;

  ifstream inf("reservations.txt");
  inf >> numFlights;

  Flight* flights = new Flight[numFlights];

  for (int i = 0; i < numFlights; ++i) // read flights
    inf >> flights[i];

  while (getChoice() != 0) // pormot users
    addPassenger(flights, numFlights);
  cout << "Goodbye." << endl;

  writeNewFile(flights, numFlights); // write update
  inf.close();

} // main()


void writeNewFile(Flight *flights, int numFlights)
{
  ofstream outf("reservationUpdate.txt");

  outf << numFlights << endl;
  for (int i = 0; i < numFlights; ++i)
    outf << flights[i];

  outf.close();
} // WriteNewFile()


void addPassenger(Flight* flights, int numFlights)
{
  char input[80];
  int num;

  for (int i = 0; i < numFlights; ++i)
    flights[i].printFlightInfo();

  cout << "\nFlight number (0 = exit): ";
  cin.getline(input, 80);
  num = charToInt(input);

  while (! compareFlight(num, numFlights, flights))
  {

    if (num == 0)
      return;

    cout << "We do not have a flight number " << input
      << "\nPlease try again.\n" << endl;

    cout << "Flight number (0 = exit): ";
    cin.getline(input, 80);
    num = charToInt(input);
  } // promp user

  for (int i = 0; i < numFlights; ++i) // find flight, add passenger
    if (flights[i] == num)
      flights[i].addPassenger();

} // addPassenger()


bool compareFlight(int input, int numFlights, Flight* flights)
{
  for (int i = 0; i < numFlights; ++i)
    if (flights[i] == input)
      return true;

  return false;
} // compareFlight()
