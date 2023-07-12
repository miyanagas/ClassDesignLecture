#pragma once

#include <string>
#include <vector>

class CLI {
   public:
    CLI(int argc, char ***argv)
        : args(std::vector<std::string>(*argv, *argv + argc)){};

    auto exec() -> void {
        if (not validate()) {
            error();
        }

        if (args[1] == "foo") {
            foo();
        }
        if (args[1] == "bar") {
            bar();
        }
        if (args[1] == "baz") {
            baz();
        }

        error();
    };

   private:
    // check error
    auto validate() -> bool {
        if (args.size() != 2) {
            return false;
        }

        return true;
    };

    auto error() -> void {
        std::cout << "[Error] Usage: " << args[0] << " <foo|bar|baz>"
                  << std::endl;
        std::exit(1);
    };

    auto foo() -> void {
        std::cout << "foofoofoo" << std::endl;
        std::exit(0);
    };

    auto bar() -> void {
        std::cout << "barbarbar" << std::endl;
        std::exit(0);
    };

    auto baz() -> void {
        std::cout << "bazbazbaz" << std::endl;
        std::exit(0);
    };

   private:
    std::vector<std::string> args;
};