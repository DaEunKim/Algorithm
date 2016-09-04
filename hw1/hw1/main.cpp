//
//  main.cpp
//  hw1
//
//  Created by 김다은 on 2016. 9. 4..
//  Copyright © 2016년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

bool func(int num, int p){
    int k=0;
    int i=0;
    
    int array[10000];
    
    while(num!=0){
        k = num%p;
        num/=p;
        array[i]=k;
        i++;
    }
    
    bool flag = true;
    for(int j=0;j<i/2;j++){
        if(array[j]!=array[i-j-1])
            flag = false;
    }
    return flag;
}


int main(void){
    FILE *fp = fopen("input.txt","r");
   
    int T;
    fscanf(fp,"%d",&T);
    
    int n;
    for(int i=0;i<T;i++){
        fscanf(fp,"%d",&n);
        
        bool check = false;
        for(int j=2;j<=64;j++){
            if(func(n,j)==true){
                check = true;
            }
        }
        if(check==true){
            printf("1\n");
        }
        else
            printf("0\n");
    }
}

