//
//  main.cpp
//  Quicksort2
//
//  Created by 김다은 on 2016. 10. 26..
//  Copyright © 2016년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdio>
#define MAX_SIZE 10000

int partition(int a[], int low, int high){
    int i, j;
    int pivot, pivotPos, tmp;
    
    pivot = a[low];
    j = low;
    
    for(i=low+1; i<=high; i++){
        if(a[i]<pivot){
            j++;
            tmp = a[i]; a[i] = a[j]; a[j] = tmp;
        }
    }
    pivotPos = j;
    tmp = a[low]; a[low] = a[pivotPos]; a[pivotPos] = tmp;
    return pivotPos;
}

void quickSort(int v[], int low, int high)
{
    int pivotPos;
    if(high > low)
    {
        pivotPos = partition(v, low, high);
        quickSort(v, low, pivotPos-1);
        quickSort(v, pivotPos+1, high);
    }
}
    
int main(void){
    int T;
    FILE*fp = fopen("input.txt", "r");
    fscanf(fp, "%d", &T);
    while(T--){
        
        int num_test;
        fscanf(fp, "%d", &num_test);
        
        int v[MAX_SIZE];
        int i;
        for(i = 0; i<num_test; i++){
            fscanf(fp,"%d", &v[i]);
        }
        
        quickSort(v, 0, num_test-1);
        
        for(int i= 0; i < num_test; i++)
            printf("%d ", v[i]);
        puts("");
    }
}
