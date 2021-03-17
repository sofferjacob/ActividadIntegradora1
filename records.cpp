#include "records.h"

using namespace std;

Records::Records(string filename) {
  ifstream file(filename);
  string currentLine;
  while (getline(file, currentLine)) {
    records.push_back(Record(currentLine));
  }
  file.close();
  sort(0, records.size() - 1);
  for (int i = 0; i < records.size(); i++) {
    cout << records[i] << endl;
  }
}

int Records::sort(int low, int high) {
  if (low >= high) return 0;
    int partRes[2] = {-1, -1};
    partition(low, high, partRes); 
    // [low...pi-1]
    int c1 = sort(low, partRes[0] - 1); 
    // [pi+1...high]
    int c2 = sort(partRes[0] + 1, high);
    return partRes[1] + c1 + c2;
}

void Records::partition(int low, int high, int res[2]) {
  int comps = 0;
    Record pivot = records[high];
    int i = (low - 1); 
 
    for (int j = low; j <= high - 1; j++) { 
      comps++;
        // If current element is smaller than the pivot 
        if (records[j] < pivot) { 
            i++; // increment index of smaller element
            Record tmp = records[i];
            records[i] = records[j];
            records[j] = tmp;
        } 
    }
   Record temp = records[high];
    records[high] = records[i+1];
    records[i+1] = temp;
    res[0] = i+1;
    res[1] = comps;
}