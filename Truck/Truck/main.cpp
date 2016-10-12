//
//  main.cpp
//  Truck
//
//  Created by 김다은 on 2016. 10. 6..
//  Copyright © 2016년 김다은. All rights reserved.
//


#include <cstdio>

int load;
int n, w, L;
int arr[1001];
int arr1[1001];

void bridge(void){
    load -= arr[0];
    
    for(int i = 1; i < w; ++i)
        arr[i-1] = arr[i];
    
    arr[w-1] = 0;
    
}
void add(int p){
    
    bridge();
    load += p;
    arr[w-1] = p;
}

int main(void){
    FILE *fp = fopen("input.txt", "r");
    int T;
    fscanf(fp, "%d", &T);
    
    for(int k = 0; k < T; ++k){
        
        fscanf(fp, "%d %d %d", &n, &w, &L);
        load = 0;
        int count = 0;
        
        for(int i = 0; i < 1001; ++i)
            arr[i] = 0;
            
        for(int i = 0; i < n; ++i)
            fscanf(fp, "%d", &(arr1[i]) );
        
        for(int i = 0; i < n; ++i)
            if(load + arr1[i] - arr[0] <= L){
                add(arr1[i]);
                count++;
            }
            else{
                bridge();
                count++;
                --i;
            }
        
        printf("%d\n", count+w);
    }
}
