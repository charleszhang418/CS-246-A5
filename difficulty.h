#ifndef __difficulty_H__
#define __difficulty_H__

#include <iostream>
#include <string>

class difficulty {
  public:
    virtual std::string getblock() = 0;
    virtual ~difficulty();
};



#endif