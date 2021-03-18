#ifndef RECORDS_H
#define RECORDS_H

#include <iostream>
#include <fstream>
#include <vector>
#include "record.h"

class Records {
  public:
    Records(std::string);
    void find(DateTime from, DateTime to);
  private:
    int search(DateTime);
    std::vector<Record> records;
    int sort(int, int); // QuickSort
    int merge(int, int, int);
};

#endif