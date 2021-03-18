#include <iostream>
#include "records.h"
#include "invalid_date.h"
#include "util.h"

using namespace std;

int main() {
  cout << "Act. Integradora 1" << endl;
  Records registry("bitacora.txt");
  cout << "Logs loaded to registry." << endl;
  cout << "Ordered logs written to: ./bitacora_ordenada.txt" << endl;
  while (true) {
    bool shouldBreak = false;
    cout << "New search" << endl;
    DateTime from = getDate("Please enter start date: ", shouldBreak);
    if (shouldBreak) break;
    DateTime to = getDate("Please enter end date: ", shouldBreak);
    if (shouldBreak) break;
    cout << "=== SEARCH RESULTS ===" << endl;
    cout << "From: " << from.getDateString() << endl;
    cout << "To: " << to.getDateString() << endl;
    try {
      registry.find(from, to);
    } catch (InvalidDate e) {
      cout << "An error ocurred: " << e.what() << endl;
    }
    cout << "======================" << endl;
  }
}