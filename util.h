#ifndef PI_UTIL_H
#define PI_UTIL_H

#include <iostream>
#include "date_time.h"
#include "invalid_date.h"

DateTime getDate(std::string prompt, bool& shouldBreak);

inline void leftTrim(std::string& str);
inline void rightTrim(std::string& str);
inline void trim(std::string& str);

#endif