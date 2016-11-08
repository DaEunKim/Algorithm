//
//  main.cpp
//  Quicksort
//
//  Created by 김다은 on 2016. 10. 26..
//  Copyright © 2016년 김다은. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#define MAX_SIZE 10001

int icompare(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int main(void){
    FILE *fp= fopen("input.txt", "r");
    int T;
    fscanf(fp, "%d", &T);
    
    while(T--){
        int i;
        int n;
        fscanf(fp, "%d", &n);
        int ints[MAX_SIZE];
        
        for(i=0; i < n; i++){
            fscanf(fp,"%d", &ints[i]);
        }
        qsort(ints, n, sizeof(int), icompare);
       
        for (i=0; i < n; i++){
            printf("%d ", ints[i]);
        }
        puts("");
    }
}

