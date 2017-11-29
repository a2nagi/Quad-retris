#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "State.h"

class Observer;
struct Info;

class Subject {
  std::vector<Observer> observers;
  State state;
 protected:
  void setState(State newS);
 public:
  void attach(Observer *o);
  void notifyObservers();
  virtual Info getInfo() const = 0;
  State getState() const;
};

void Subject::attach(Observer *o) {
  observers.emplace_back(o);
}

void Subject::notifyObservers() {
  for (auto &ob : observers) ob->notify(*this);
}

void Subject::setState(State newS) { state = newS; }

State Subject::getState() const { return state; }
#endif
