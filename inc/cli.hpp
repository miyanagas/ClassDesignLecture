#pragma once

#include <string>
#include <vector>

const int ARG_NUM = 4;

class CLI {
   public:
    CLI(int argc, char ***argv)
        : args(std::vector<std::string>(*argv, *argv + argc)){};

    auto exec() -> void {
        if (not validate()) {
            error();
        }

        if (args[1] == "+") {
            add();
        }
        if (args[1] == "-") {
            sub();
        }

        error();
    };

   private:
    // check error
    auto validate() -> bool {
        if (args.size() != ARG_NUM) {
            return false;
        }

        return true;
    };

    auto error() -> void {
        std::cout << "[Error] Usage: " << args[0] << " <+|->" << std::endl;
        std::exit(1);
    };

    auto add() -> void {
        x = stoi(args[2]);
        y = stoi(args[3]);
        std::cout << x + y << std::endl;
        std::exit(0);
    };

    auto sub() -> void {
        x = stoi(args[2]);
        y = stoi(args[3]);
        std::cout << x - y << std::endl;
        std::exit(0);
    };

   private:
    std::vector<std::string> args;
    int x, y;
};