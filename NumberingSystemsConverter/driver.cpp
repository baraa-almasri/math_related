#include <cstdio>
#include <cstring>
#include "Converter.hpp"

int main(int argc, char *argv[]) {
    if(argc < 3) {
        puts("Not enough args!");
    }
    Converter *converter = Converter::getInstance();
    converter->convertToOthers(atof(argv[1]), atoi(argv[2]));

    return 0;
}