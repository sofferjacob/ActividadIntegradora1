#include <chrono>
#include <time.h>
#include "records.h"
#include "invalid_date.h"

using namespace std;

Records::Records(string filename) {
  ifstream file(filename);
  string currentLine;
  while (getline(file, currentLine)) {
    records.push_back(Record(currentLine));
  }
  file.close();
  auto startTime = chrono::high_resolution_clock::now();
  int comps = sort(0, records.size() - 1);
  auto endTime = chrono::high_resolution_clock::now();
  auto totalTime = endTime - startTime;
  cout << "comparisons: " << comps << endl;
  cout << "Tiempo total de ejecución: " << totalTime/chrono::milliseconds(1) << " ms." << endl;
  ofstream orderedFile("bitacora_ordenada.txt");
  for (int i = 0; i < records.size(); i++) {
    orderedFile << records[i] << endl;
  }
  orderedFile.close();
}

int Records::sort(int low, int high) {
  if (low >= high) {
    return 0;
  }
  int m = low + ((high - low)/2);
  int c1 = sort(low, m);
  int c2 = sort(m+1, high);
  return merge(low, m, high) + c1 + c2;
}

int Records::merge(int low, int m, int high) {
  int comps = 0;
  int n1 = m - low + 1;
  int n2 = high - m;
  Record L[n1];
  Record R[n2];
  for (int i = 0; i < n1; i++) {
    L[i] = records[low+i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = records[j+m+1];
  }
  int k = low;
  int i = 0;
  int j = 0;
  while (i < n1 && j < n2) {
    comps++;
    if (L[i] <= R[j]) {
      records[k] = L[i];
      i++;
    } else {
      records[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    records[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    records[k] = R[j];
    j++;
    k++;
  }
  return comps;
}

int Records::search(DateTime target) {
  int n = records.size();
  int left = 0;
  int right = n - 1;
  while (left <= right) {
    int m = (left + right) / 2;
    DateTime val = records[m].getDate();
    if (val == target) { 
      return m; 
    } else if (target < val) {
      right = m - 1;
    } else {
      left = m + 1;
    }
  }
  return -1;
}

void Records::find(DateTime from, DateTime to) {
  int l = search(from);
  if (l == -1) {
    throw InvalidDate("Start date not found on registry");
  }
  int r = search(to);
  if (r == -1) {
    throw InvalidDate("End date not found on registry");
  }
  for (; l <= r; l++) {
    cout << records[l] << endl;
  }
}