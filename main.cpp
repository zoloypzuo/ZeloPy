#include "Zelo.h"

int main(int argc, char **argv) {
    if (argc <= 1) {
        printf("vm need a parameter: filename\n");
        return 0;
    }

    Interpreter L;
    dofile(&L, argv[1]);
    return 0;
}
