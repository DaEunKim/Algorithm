//
//  main.cpp
//  coinExchange
//
//  Created by 김다은 on 2016. 11. 10..
//  Copyright © 2016년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdio>
#define MAX_CHANGE 10001

int coin[101]; //동전의 단위
int n;// 동전의 종류를 나타내는 정수.
int count[101];

void coinExchange(int coins[], int numDiffCoins, int change, int coinsUsed[], int lastCoin[]){
    int cents, j;
    
    coinsUsed[0] = lastCoin[0] = 0;
    
    for(cents = 1; cents <=change; cents++){
        int minCoins, newCoin;
        
        minCoins = cents;
        newCoin = 1;
        for(j=0; j<numDiffCoins; j++){
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
    if(change > 0){
        reconstruct(change-lastCoin[change], lastCoin);
        for(int i=0; i<n; i++){
            if(coin[i] == lastCoin[change]){
                count[i] += 1;
            }
        }
    }
}

int main(void){
    FILE * fp = fopen("input.txt", "r");
    int T;
    fscanf(fp, "%d", &T);
    
    while(T--){
        fscanf(fp,"%d", &n);
        int K;//거스름돈.
        int i;
        int coinUsed[MAX_CHANGE] = {0};
        int lastCoin[MAX_CHANGE] = {0};
        for(i = 0;i<n;i++)
        fscanf(fp, "%d", &coin[i]);
        
        fscanf(fp, "%d", &K);
        
        coinExchange(coin, n, K, coinUsed, lastCoin);
        printf("%d\n", coinUsed[K]);
        for(int i=0; i<101; i++)
        count[i] = 0;
        reconstruct(K, lastCoin);
        for(int i=0; i<n; i++)
        printf("%d ", count[i]);
        printf("\n");
        
        
        
        
    }
}
