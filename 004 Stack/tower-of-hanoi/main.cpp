#include <bits/stdc++.h>

/* N: number_of_disks in fromPeg */
void towerOfHanoi(int32_t N, char& fromPeg, char& toPeg, char& auxPeg){
    /*If only one disk,make the move and return */
    if(N == 1){
        printf("Move top disk from peg %c to peg %c\n", fromPeg, toPeg);
    } else {
        /*Move top N-1 disks from fromPeg to auxPeg ,using toPeg */
        towerOfHanoi(N - 1, fromPeg, auxPeg, toPeg);

        /* Move remaining disk from fromPeg to toPeg */
        printf("Move top disk from peg %c to peg %c\n", fromPeg, toPeg);

        /*Move top N-1 disks from auxPeg to toPeg ,using fromPeg */
        towerOfHanoi(N - 1, auxPeg, toPeg, fromPeg);
    }
}

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    char fromPeg{'A'}, toPeg{'C'}, auxPeg{'B'};

    /* solve tower_of_hanoi problem */
    towerOfHanoi(3, fromPeg, toPeg, auxPeg);
    return 0;
}