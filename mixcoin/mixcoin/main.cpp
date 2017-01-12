//
//  main.cpp
//  mixcoin
//
//  Created by 김다은 on 2016. 11. 13..
//  Copyright © 2016년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdio>
#define MAX_COINS 101
#define MAX_CHANGE 1001

int countCoinExchange(int coins[], int numDiffCoins, int change)
{
    int i, j, numComb;
    int N[MAX_COINS][MAX_CHANGE] = {0};

    for(i = 1; i <= numDiffCoins; i++)
        N[i][0] = 1;
    for(i = 1; i <= change; i++)
        N[0][i] = 0;
    
    for(i = 1; i <= numDiffCoins; i++)
    for(j = 1; j <= change; j++)
    {
        if (j-coins[i] < 0) /* base case */
            numComb = 0;
        else
            numComb = N[i][j-coins[i]];
        N[i][j] = N[i-1][j] + numComb;
        
    }
    
    return N[numDiffCoins][change];
    
}

int main(void){
    FILE *fp = fopen("input.txt", "r");
    int T;
    fscanf(fp,"%d", &T);
    while(T--){
        int n;
        fscanf(fp, "%d", &n);
        
        int coin[MAX_COINS];
        int K;
        int i;
        
        for(i = 1; i <= n; i++){
            fscanf(fp,"%d", &coin[i]);
            //printf("coin : %d\n", coin[i]);
        }
        
        fscanf(fp,"%d", &K);
        
        printf("%d\n", countCoinExchange(coin, n, K));
        
    }
}



