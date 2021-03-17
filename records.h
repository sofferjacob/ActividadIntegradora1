#include <iostream>
#include <fstream>
#include <vector>
#include "record.h"

class Records {
  public:
    Records(std::string);
    void find(int, int);
  private:
    std::vector<Record> records;
    int sort(int, int); // QuickSort
    void partition(int, int, int[2]);
};