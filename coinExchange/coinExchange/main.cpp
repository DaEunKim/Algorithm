//
//  main.cpp
//  coinExchange
//
//  Created by 김다은 on 2016. 11. 10..
//  Copyright © 2016년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdio>

void coinExchange(int coins[], int numDiffCoins, int change, int coinsUsed[], int lastCoin[]){
    int cents, j;
    
    coinsUsed[0] = lastCoin[0] = 0;
    
    for(cents = 1; cents <=change; cents++){
        int minCoins, newCoin;
        
        minCoins = cents;
        newCoin = 1;
        for(j=0; j<numDiffCoins;j++){
            if(coins[j] > cents)
            continue;
            if(coinsUsed[cents-coins[j]] + 1 <minCoins){
                minCoins = coinsUsed[cents-coins[j]] +1;
                newCoin = coins[j];
            }
        }
        coinsUsed[cents] = minCoins;
        lastCoin[cents] = newCoin;
    }
}

void reconstruct(int change, int lastCoin[]){
    if(change >0){
        reconstruct(change-lastCoin[change], lastCoin);
        printf("%d\n", lastCoin[change]);
    }
}

int main(void){
    FILE * fp = fopen("input.txt", "r");
    int T;
    fscanf(fp, "%d", &T);
    while(T--){
        int n[]={0, };// 동전의 종류를 나타내는 정수.
        int k;//거스름돈
        
        for(int i = 0;i<10;i++){
            fscanf(fp, "%d", &n[i]);
        }
        for(int i = 0;i<10;i++){
            
        }
    }
}
