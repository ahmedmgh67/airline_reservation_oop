#ifndef PLANE_H
#define PLANE_H

#define MAX_CHAR 80

#include "utilities.h"

using namespace std;

class Plane
{
  int rows;
  int width;
  int reserved;
  char ***passengers; // 2-dimensional
public:
  Plane();
  ~Plane();
  void addPassenger();
  void printPlane();
  bool checkRow(char *rowInput, int row);
  bool checkCol(int col, int row);
  void reservePassenger(char *name, int row, int col);
  char* extractPassenger(char *info, int &row, int &col);
  friend istream& operator >> (istream &is, Plane &plane);
  friend ostream& operator << (ostream& os, Plane &plane);
}; //class plane

#endif
