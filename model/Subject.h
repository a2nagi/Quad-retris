#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "State.h"
#include "Observer.h"

struct Info;

class Subject {
  std::vector<Observer *> observers;
  State state;
 protected:
  void setState(State newS);
 public:
  void attach(Observer *o);
  void notifyObservers();
  virtual Info getInfo() const = 0;
  State getState() const;
};
#endif
