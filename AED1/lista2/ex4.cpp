#include <random>
#include <iostream>
#include "world.hpp"
#include <unistd.h>

int main(){
    int x = 0;

    while(1){
        x = std::rand();

        std::cout << x;
    }


    return 0;
}