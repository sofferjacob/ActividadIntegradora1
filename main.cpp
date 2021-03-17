#include <iostream>
#include "record.h"

using namespace std;

int main() {
  Record record1("Sep 23 12:58:18 80.169.79.65:1150 Failed password for illegal user root");
  Record record2("Jul 09 16:19:58 142.248.253.242:2871 Illegal user");

  DateTime date1 = record1.getDate();

  cout << record1 << endl;
  cout << record2 << endl;
  cout << date1 << endl;
  cout << record2 << endl;
  cout << date1.getMonth() << endl;
  //cout << date2.getMonth() << endl;
  //cout << (date1 == date2) << endl;
  //cout << (date1 != date2) << endl;
  cout << (record1 > record2) << endl;
  cout << (record1 < record2) << endl;
}