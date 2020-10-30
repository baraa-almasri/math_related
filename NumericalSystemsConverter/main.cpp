#include <cstdio>
#include <cstring>
#include "SuperConverter.hpp"

int main(int argc, char *argv[]) {
    if(argc < 4) {
        puts("Not enough args!");
        return 1;
    }

    printf("(%s)%s => (%s)%s\n", argv[1], argv[2],
        SuperConverter::gerenralConvert(argv[1], atoi(argv[2]), atoi(argv[3])).c_str(),
        argv[3] 
    );

    return 0;
}