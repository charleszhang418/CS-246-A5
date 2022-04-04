#include "observer.h"
#include "subject.h"
#include <vector>
#include <algorithm>

using namespace std;

void Subject::notifyObservers() {
  for (auto &p : obs) {
    p->notify();
  }
}

void Subject::attach(Observer *p) {
  obs.emplace_back(p);
}

void Subject::detach(Observer *p) {
  obs.erase(find(obs.begin(), obs.end(), p));
}

Subject::~Subject() {}

