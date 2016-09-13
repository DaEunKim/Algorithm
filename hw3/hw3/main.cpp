//
//  main.cpp
//  hw3
//
//  Created by 김다은 on 2016. 9. 8..
//  Copyright © 2016년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int abs(int num){
    if(num<0){
        return -num;
    }
    else
        return num;
}

int main(void) {
    int T;
    
    FILE *fp = fopen("input.txt", "r");
    
    fscanf(fp, "%d",&T);
    for(int i=0;i<T;i++){
        int n;
        int arr1[20];
        int arr2[20];
        
        fscanf(fp,"%d",&n);
        
        for(int j=0;j<n;j++)
            fscanf(fp,"%d",&arr1[j]);
        
        bool check;
        for(int k = 0; k < 1000; k++){
            
            for(int j=0; j<n-1; j++){
                arr2[j] = abs(arr1[j] - arr1[j+1]);
                
            }
            arr2[n-1] = abs(arr1[n-1] - arr1[0]);
            
            for(int j=0; j<n; j++){
                arr1[j] = arr2[j];
            }
            check = true;
            
            for(int j=0;j<n;j++){
                if(arr2[j]!=0){
                    check = false;
                }
            }
            
            if(check == true){
                printf("ZERO\n");
                break;
            }
            
         
        }
        if(check == false)
            printf("LOOP\n");
        
        
        
    }
    
}
