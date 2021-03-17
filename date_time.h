// Abstract dates with a proper type
#include <time.h>
#include <iostream>
#include <unordered_map>

class DateTime {
  public:
    DateTime(std::string);
    int getSeconds();
    int getMinutes();
    int getHour();
    int getMonth();
    int getDate();  // Day of the month
    const std::string dateString;  // Date in a human-readable form

    bool operator ==(const DateTime&);
    bool operator !=(const DateTime&);
    bool operator >(const DateTime&);
    bool operator <(const DateTime&);
    friend std::ostream& operator <<(std::ostream&, DateTime&);
  private:
    struct tm dateStruct;
    time_t date;
    static const std::unordered_map<std::string, int> months;
};