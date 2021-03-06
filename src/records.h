/*
Jacobo Soffer Levy
A01028653
Declaration of the Records class.
This class loads and stores the logs,
also handles log sorting and searching.
Modified: 19/03/21
*/
#ifndef RECORDS_H
#define RECORDS_H

#include <iostream>
#include <fstream>
#include <vector>
#include "record.h"

class Records {
  public:
    // Constructor. Loads and sorts the logs.
    // Params: file name where the records are stored (string)
    Records(std::string);
    // This method finds and prints records
    // between a pair of dates.
    // Params:
    // - from (DateTime): Date where the search begins.
    // - to (DateTime): Date where the search ends.
    // Both dates are inclusive. e € [from, to]
    void find(DateTime from, DateTime to);
  private:
    // Binary search algorithm.
    // Params:
    // date (DateTime): The date of the record that wants to be retrieved.
    // Return value: Index of the record, if not found -1.
    int search(DateTime);
    // Stores the records.
    std::vector<Record> records;
    // Quick Sort algorithm.
    // Params:
    // Define the extent of the vector that should be sorted.
    // l (int): Lower bound of the vector.
    // r (int): Upper bound of the vector.
    // Return value: Number of comparisons executed.
    int sort(int, int);
    // Auxiliary method used by sort()
    void partition(int, int, int[2]);
};

#endif