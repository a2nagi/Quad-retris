#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "State.h"

class Observer;
struct Info;

class Subject {
  std::vector<Observer> observers;
  StateType state;
 protected:
  void setState(StateType newS);
 public:
  void attach(Observer *o);
  void notifyObservers();
  virtual Info getInfo() const = 0;
  StateType getState() const;
};

void Subject::attach(Observer *o) {
  observers.emplace_back(o);
}

void Subject::notifyObservers() {
  for (auto &ob : observers) ob->notify(*this);
}

void Subject::setState(StateType newS) { state = newS; }

StateType Subject::getState() const { return state; }
#endif
