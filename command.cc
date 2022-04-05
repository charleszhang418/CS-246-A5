#include "command.h"

#include <iostream>

using namespace std;

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
        cout << "Your new name for command " << old << " is too confusing" << endl;
        return;
    }

    for (size_t i = 0; i < command_list.size(); ++i) {
        if (command_list[i] == old) {
            short_command[i] = cur;
            return;
        }
    }
}

string Command::readcom(string in) {
    for (auto n : command_list) {
        if (n == in) {
            return n;
        }
    }
    for (size_t i = 0; i < short_command.size(); ++i) {
        if (short_command[i] == in) {
            return command_list[i];
        }
    }
    return "Not found";
}

void Command::output() {
    for (auto n : short_command) {
        cout << n << " ";
    }
}