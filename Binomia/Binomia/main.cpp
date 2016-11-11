//
//  main.cpp
//  Binomia
//
//  Created by 김다은 on 2016. 11. 10..
//  Copyright © 2016년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdio>

#define MAX 1000
#define MIN(a,b) ((a)<(b)?(a):(b))

int binCoeff(int n, int k){
    int i, j;
    int B[MAX][MAX];
    int a;
    for (i=0;i<=n;i++)
        for(j=0;j<= MIN(i,k);j++)
            if(j==0 || j==i)
                B[i][j] = 1;
            else
                B[i][j] = B[i-1][j-1]+B[i-1][j];

    if(B[n][k]!=0 && B[n][k]%10007 !=0)
        a = B[n][k]%10007;
    return a;
}
int main(void){
    FILE *fp = fopen("input.txt", "r");
    
    int T;
    fscanf(fp, "%d", &T);
    while(T--){
        int N, K;
        fscanf(fp, "%d %d", &N, &K);
        if(N>=1 && K>=0){
            printf("%d\n", binCoeff(N, K));
        }
    }


}
