#include <iostream>
#include "date_time.h"

class Record {
  public:
    Record(std::string);
    const std::string ip;
    const std::string port;
    const std::string reason;
    const std::string entry;  // The full entry
    
    DateTime getDate();

    // For convenience
    bool operator>(Record&);
    bool operator<(Record&);
    friend std::ostream& operator<<(std::ostream&, Record&);
  private:
    DateTime date;
};