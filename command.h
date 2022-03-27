#ifndef _COMMAND_H_
#define _COMMAND_H_

#include <string>
#include <utility>
#include <map>
#include <vector>

class Command {
    std::vector<std::string> command_list; // Commands defined in design file
    std::vector<std::string> macro_command; // User defined macro command
    std::vector<std::vector<std::string>> full_command; // Full commands for macros
    std::map<std::string, int> short_command; // Map for user-defined short command and the corresponding command index in command_list

  public:
    std::vector<std::string> Macro(std::string);
    std::string short_com(std::string);
};

#endif