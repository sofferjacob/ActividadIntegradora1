#include "record.h"

using namespace std;

Record::Record() {
  entry = "Jan 01 00:00:00 33.116.103.137:162 Failed password for illegal user guest";
  date = DateTime();
  ip = "33.116.103.137";
  port = "162";
  reason = "Failed password for illegal user guest";
}

Record::Record(string rec) :
  entry(rec),
  date(DateTime(rec.substr(0, 15))),
  ip(rec.substr(16, 12)),
  port(rec.substr(29, 4)),
  reason(rec.substr(34)) {}

DateTime Record::getDate() {
  return date;
}

string Record::getIp() {
  return ip;
}

string Record::getPort() {
  return port;
}

string Record::getEntry() {
  return entry;
}

string Record::getReason() {
  return reason;
}

/*Record& Record::operator=(Record& rec) {
  return rec;
}*/

bool Record::operator>(Record & other) {
  return (this->date > other.date);
}

bool Record::operator<(Record & other) {
  return (this->date < other.date);
}

bool Record::operator<=(Record & other) {
  return (this->date <= other.date);
}

ostream& operator<<(ostream& out, Record& rec) {
  return out << rec.entry;
}