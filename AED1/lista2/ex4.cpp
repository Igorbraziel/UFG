#include <iostream>
#include "world.hpp"

int main(){
    World * w1;
    World * w2;
    //World * war;
    int i, j, n, f, e;

    w1 = newWorld(2, 2);
    w2 = newWorld(2, 2);

    addBacterium(w1, 1, 39, 60);
    addBacterium(w1, 3, 99, 27);
    addBacterium(w1, 4, 2, 54);
    addBacterium(w1, 2, 38, 49);

    addBacterium(w2, 5, 25, 6);
    addBacterium(w2, 6, 100, 7);
    addBacterium(w2, 7, 5, 77);
    addBacterium(w2, 8, 38, 79);

    //killBacterium(w1, 4);

    //war = warWorlds(w1, w2);

    showWorld(w1);

    freeWorld(w1);
    freeWorld(w2);
    //freeWorld(war);

    return 0;
}