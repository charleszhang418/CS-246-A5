#include "command.h"

#include <iostream>

using namespace std;

// Used for rename command: change old into cur
void Command::short_com(string old, string cur) {
    int find = 0; // find indicates number of commands in command_list that may cause confusing to the new command
    // Check validness of the new name of command
    for (auto n : command_list) {
        if (n == cur) {
            cout << "You cannot rename commands with existing command names" << endl;
            return;
        }
        if (n.find(cur) != string::npos) {
            find += 1;
        }
    }

    if (find > 1) {
        cout << "Your new name for command " << old << " is established already" << endl;
        return;
    }

    for (size_t i = 0; i < command_list.size(); ++i) {
        if (command_list[i] == old) {
            short_command[i] = cur;
            return;
        }
    }
}

// Reads command and returns the corresponding command
string Command::readcom(string in) {
    int find = 0;
    int pos = -1;
    for (size_t i = 0; i < command_list.size(); ++i) {
        if (command_list[i] == in) {
            return command_list[i];
        }
        if (command_list[i].find(in) != string::npos) {
            find += 1;
            pos = i;
        }
    }
    if (find == 1) {
        return command_list[pos];
    }
    for (size_t i = 0; i < short_command.size(); ++i) {
        if (short_command[i] == in) {
            return command_list[i];
        }
    }   
    return "Your command is not valid, please enter again";
}

// Reads command and returns the corresponding command running times
string Command::n_com(string com) {
    if (isdigit(com[0])) {
        com = com.substr(1, com.size());
    }
    return com;
}

int Command::n_count(string com) {
    if (isdigit(com[0])) {
        return com[0] - '0';
    }
    return 0;
}