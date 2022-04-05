#ifndef _COMMAND_H_
#define _COMMAND_H_

#include <string>
#include <utility>
#include <vector>

class Command {
    std::vector<std::string> command_list =  // Commands defined in design file
    {"left", "right", "down", "clockwise", "counterclockwise", "drop", "levelup", "leveldown",
    "norandom", "random", "sequence", "I", "L", "J", "O", "S", "Z", "T", "restart", "blind", "heavy", "force"};
    
    std::vector<std::string> macro_command; // User defined macro command
    
    std::vector<std::vector<std::string>> full_command; // Full commands for macros
    
    std::vector<std::string> short_command = // Vector for user-defined short command and the corresponding command index in command_list
    {"left", "right", "down", "clockwise", "counterclockwise", "drop", "levelup", "leveldown",
    "norandom", "random", "sequence", "I", "L", "J", "O", "S", "Z", "T", "restart", "blind", "heavy", "force"};
  
  public:
    void short_com(std::string old, std::string cur);
    std::string readcom(std::string in);
    void output();
    std::string n_com(std::string cmd);
    int n_count(std::string cmd);

};

#endif