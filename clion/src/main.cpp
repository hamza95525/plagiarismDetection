//
// Created by khamza on 22.12.2019.
//
#include "../includes/Includes.h"
#include "../headers/simpleCompare.h"

int main(int argc, char* argv[]) {

    if( argc < 2 ) {
        perror("Wrong number of parameters!\n");
        return -1;
    }

    simpleCompare s{};

    float res = s.compare(argv[1], argv[2]);

    std::cout<<"Percentage of repetition(without passing commonly used words): " << res << "%\n";

    return 0;
}
