#include <iostream>
#include "date_time.h"

class Record {
  public:
    Record(std::string);
    DateTime getDate();
    std::string getIp();
    std::string getPort();
    std::string getReason();
    std::string getEntry();

    // For convenience
    bool operator>(Record&);
    bool operator<(Record&);
    //Record& operator=(Record&);
    friend std::ostream& operator<<(std::ostream&, Record&);
  private:
    std::string ip;
    std::string port;
    std::string reason;
    std::string entry;  // The full entry
    DateTime date;
};