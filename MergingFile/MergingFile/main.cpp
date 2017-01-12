//
//  main.cpp
//  MergingFile
//
//  Created by 김다은 on 2016. 11. 14..
//  Copyright © 2016년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdio>
#define MAX 501

int sum[MAX];

int Search(int n, int M[][MAX], int x, int y){
    int min = 20135179;
    
    
    for(int i=1; i<=x-y; ++i){
        int tmp = M[y][i+y-1]+M[y+i][x] + sum[x] - sum[y-1];
        if(min > tmp){
            min = tmp;
        }
    }
    return min;
}

void Min(int n, int data[MAX]){

   // int n;
    int M[MAX][MAX] = {0, };
    
    int y, x;
    for(int i = 1;i<=n;i++)
        M[i][i] = data[i];
    

    //값을 더한거
    for(int i=1; i<n; ++i){
        M[i][i+1] = M[i][i] + M[i+1][i+1];
    }
    
    
    for(int i = 1;i<=n;i++)
        M[i][i] = 0;

    for(int i = 3; i<=n; i++){
        for(int j = i; j<=n; j++){
            M[j-i+1][j] = Search(n, M, j, j-i+1);
            
        }
        
    }
    printf("%d\n", M[1][n]);
    
    
    
}


int main(void){
    
    FILE*fp = fopen("input.txt","r");
    int T;
    fscanf(fp,"%d", &T);
    while(T--){
        int K;
        fscanf(fp,"%d", &K);
        
        int value[MAX];
        
        for(int i = 1;i<=K; i++){
            fscanf(fp,"%d", &value[i]);
            sum[i] = sum[i-1]+value[i];
        }
        Min(K, value);

    }
}
