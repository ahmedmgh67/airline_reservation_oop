#include "plane.h"


Plane::Plane() : rows(0), width(0), reserved(0), passengers(NULL)
{} // constructor

Plane::~Plane()
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < width; j++)
    {
      delete [] passengers[i][j]; // delete char*
    }
  }

  delete [] passengers; // delete matrix
} // destructor

istream& operator >> (istream &is, Plane &plane)
{
  char info[MAX_CHAR], *token, *passenger;
  int i, j, row, col;

  is.getline(info, 80);

  token = strtok(info, " ");
  plane.rows = atoi(token);

  token  = strtok(NULL, " ");
  plane.width = atoi(token);

  token = strtok(NULL, "\n");
  plane.reserved = atoi(token);

  plane.passengers = new char ** [plane.rows];

  for (i = 0; i < plane.rows; ++i)
  {
    plane.passengers[i] = new char* [plane.width];

    for (j = 0; j < plane.width; ++j)
      plane.passengers[i][j] = NULL;
  } // set all to NULL


  for (i = 0; i < plane.reserved; ++i)
  {
    is.getline(info, 80);
    passenger = plane.extractPassenger(info, row, col);
    plane.passengers[row][col] = new char [strlen(passenger) + 1];
    strcpy(plane.passengers[row][col], passenger);
  } // read in passengers

  return is;
} // operator >>


ostream& operator << (ostream& os, Plane &plane)
{
  int i, j;
  char name[80];
  os << plane.rows << ' ' << plane.width << ' ' << plane.reserved << endl;

  for (i = 0; i < plane.rows; ++i)
    for (j = 0; j < plane.width; ++j)
      if (plane.passengers[i][j])
      {
        os << i + 1 << (char)(j + 65) << ' ';
        strcpy(name, plane.passengers[i][j]);
        os << name << endl;
      }

  return os;
} // operator <<


void Plane::addPassenger()
{
  char name[80], rowInput[80], colInput[80];
  int row, col;

  cout << "Please enter the name of the passenger: ";
  cin.getline(name, 80);

  printPlane();

  do
  {
    cout << "\nPlease enter the row of the seat you wish to reserve: ";
    cin.getline(rowInput, 80);
    row = charToInt(rowInput);

    if (checkRow(rowInput, row)) // check col
    {
      cout << "Please enter the seat letter you wish to reserve: ";
      cin.getline(colInput, 80);
      col = colInput[0] - 64; // A = 65

      if (checkCol(col, row))
        break;
    }

    cout << "Please try again." << endl;

  } while (true);

  reservePassenger(name, row, col);

} // addPassenger()


void Plane::reservePassenger(char *name, int row, int col)
{
  ++ reserved;

  passengers[row - 1][col - 1] = new char [strlen(name) + 1];
  strcpy(passengers[row - 1][col - 1], name);
} // reservePassenger()


bool Plane::checkRow(char *rowInput, int row)
{

  if (NotDigit(rowInput))
    cout << "That is an invalid row number." << endl;

  else
    if (row < 1 || row > rows)
      cout << "There is no row #" << row << " on this flight." << endl;
    else
      return true;

  return false;

} // checkRowInput()


bool Plane::checkCol(int col, int row)
{
  if (col < 1 || col > width || passengers[row - 1][col - 1])
    cout << "That seat is already occupied." << endl;
  else
    return true;

  return false;
} // checkCol


void Plane::printPlane()
{
  int i, j;
  int col = 65;

  cout << "ROW# ";

  for (i = 0; i < width; ++i)
    cout << (char)col++;
  cout << endl;

  for (i = 0; i < rows; ++i)
  {
    if (i + 1 < 10) // 0-9
      cout << " " << i + 1 << "   ";
    else if (i + 1 >= 10 && i + 1 < 100) // 10-99
      cout << " " << i + 1 << "  ";
    else
      cout << " " << i + 1 << " ";

    for (j = 0; j < width; ++j) // print col
      if (passengers[i][j])
        cout << 'X';
      else
        cout << '-';
    cout << endl;
  } // print row
  cout << "\nX = reserved." << endl;
} // printPlane()


char* Plane::extractPassenger(char *info, int &row, int &col)
{
  char *token;
  token = strtok(info, " ");

  col = token[strlen(token) - 1] - 64; // get col
  row = 0; // reset  row

  for (int i = 0; i < strlen(token) - 1; ++i) // get row
    row = row * 10 + token[i] - '0';

  -- row;
  -- col; // set in bound

  return strtok (NULL, "\n"); // get name
} // extractPassenger()
