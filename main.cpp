#include <iostream>
#include "date_time.h"

using namespace std;

int main() {
  DateTime date1("Sep 23 12:58:18");
  DateTime date2("Jul 09 16:19:58");

  cout << date1 << endl;
  cout << date2 << endl;
  cout << date1.getMonth() << endl;
  cout << date2.getMonth() << endl;
  cout << (date1 == date2) << endl;
  cout << (date1 != date2) << endl;
  cout << (date1 > date2) << endl;
  cout << (date1 < date2) << endl;
}