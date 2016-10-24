//
//  main.cpp
//  FullBinaryTress
//
//  Created by 김다은 on 2016. 10. 23..
//  Copyright © 2016년 김다은. All rights reserved.
//
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#define Maxn 2100000
using namespace std;

int n, k, A;
int tree[Maxn];


int tmp(int num) {
    if (num*2 >= A) return 0;
    int t1 = tree[num*2] + tmp(num*2+1);
    int t2 = tree[num*2+1] + tmp(num*2+2);
    
    if(t1>t2){
        tree[num*2+1] += t1-t2;
    }
    else
        tree[num*2] += t2-t1;
    
    return max(t1, t2);
}

int main(void){
    FILE* fp = fopen("input.txt", "r");

    int T; fscanf(fp, "%d", &T);
    while(T--){
        int n; fscanf(fp, "%d", &n);
        int i;
        for (i = 0; i < (1<<(n+1))-2; ++i)
            fscanf(fp, "%d", tree+i);
        A = i;
        
        tmp(0);
        
        int sum = 0;
        for (int j=0; j<A; j++)
            sum += tree[j];

        printf("%d\n", sum);
    }
}
