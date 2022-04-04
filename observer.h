#ifndef _OBSERVER_H_
#define _OBSERVER_H_
class Observer {
  public:
    virtual ~Observer();
    virtual void notify() = 0;
};

#endif