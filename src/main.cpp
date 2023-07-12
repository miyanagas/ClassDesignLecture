#include <iostream>
#include <string>
#include <vector>

#include "cli.hpp"

auto main(int argc, char *argv[]) -> int {
    CLI cli(argc, &argv);

    cli.exec();

    return 0;
}