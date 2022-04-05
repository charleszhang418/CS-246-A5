#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include <vector>

#include "observer.h"

class Subject {
    std::vector<Observer*> obs;
  public:
    void notifyObservers();
    void attach(Observer *);
    void detach(Observer *);
    virtual ~Subject() = 0;
};
#endif

