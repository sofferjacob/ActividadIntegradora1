#ifndef INVALID_DATE_H
#define INVALID_DATE_H

#include <stdexcept>

class InvalidDate : public std::runtime_error {
  public:
    InvalidDate(const char*);
};

#endif