//
//  main.cpp
//  Hanoi
//
//  Created by 김다은 on 2016. 10. 17..
//  Copyright © 2016년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdio>

void Hanoi(int n, int a, int b, int c){
    if(n>0){
        Hanoi(n-1, a, c, b);
        printf("Move disk from %d to %d", a, c);
        Hanoi(n-1, b, a, c);
    }
}

int main(void){
    int numDisks = 4;
    printf("Number of disks to move : %d\n", numDisks);
    Hanoi(numDisks, 1, 2, 3);
    return 0;
}
