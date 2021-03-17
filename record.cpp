#include "record.h"

using namespace std;

Record::Record(string rec) :
  entry(rec),
  date(DateTime(rec.substr(0, 15))),
  ip(rec.substr(16, 12)),
  port(rec.substr(29, 4)),
  reason(rec.substr(34)) {}

DateTime Record::getDate() {
  return date;
}

bool Record::operator>(Record & other) {
  return (this->date > other.date);
}

bool Record::operator<(Record & other) {
  return (this->date < other.date);
}

ostream& operator<<(ostream& out, Record& rec) {
  return out << rec.entry;
}