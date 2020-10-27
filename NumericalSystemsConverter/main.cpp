#include <cstdio>
#include <cstring>
#include "NumericalSystemsConverter.hpp"

int main(int argc, char *argv[]) {
    if(argc < 3) {
        puts("Not enough args!");
        return 1;
    }
    NumericalSystemsConverter *converter = NumericalSystemsConverter::getInstance();
    converter->convertToOthers(argv[1], atoi(argv[2]));

    return 0;
}