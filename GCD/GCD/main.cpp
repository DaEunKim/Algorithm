//
//  main.cpp
//  GCD
//
//  Created by 김다은 on 2016. 9. 28..
//  Copyright © 2016년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdio>


int gcd(int a, int b){
   
    if(b==0){
        return a;
    }

    return gcd(b, a%b);
    
}

int main(void){
    FILE *fp = fopen("input.txt", "r");
    int T;
    fscanf(fp, "%d", &T);
    
    for(int i = 0;i<T;i++){
        int m, n;
        fscanf(fp, "%d %d", &m, &n);
        
        int tmp=0;
        
        
        if(m>n){
            tmp = gcd(m,n);
        }
        else
            tmp = gcd(n,m);
        
        printf("%d\n", tmp);
    }
}
