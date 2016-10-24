//
//  main.cpp
//  Qindex
//
//  Created by 김다은 on 2016. 10. 22..
//  Copyright © 2016년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int T;
int n;
int k[1001];

int main(void){
    FILE *fp = fopen("input.txt", "r");
    fscanf(fp, "%d", &T);
    for(int i = 0; i < T;i++){
        fscanf(fp, "%d", &n);
        for(int j = 1; j <= n; j++){
            fscanf(fp, "%d", k+j);
        }
        
        sort(k+1, k+n+1, greater<int>());

        
        for(int j = n; j>=0; j--){
            if(k[j] >= j){
                printf("%d\n", j);
                break;
            }
        }        
    }
    
}
