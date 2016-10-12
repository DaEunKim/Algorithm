//
//  main.cpp
//  Fibonacci
//
//  Created by 김다은 on 2016. 9. 28..
//  Copyright © 2016년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdio>

int fbn(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    
    return fbn(n-1) + fbn(n-2);
}
int main(void){
    FILE *fp = fopen("input.txt", "r");
    
    int T;
    fscanf(fp, "%d", &T);
    for(int i = 0; i<T; i++){
        int a;
        fscanf(fp, "%d", &a);
        int tmp=0;
        for(int j = 0;j<=a;j++){
            tmp = fbn(j);
            
        }
        printf("%d\n", tmp);
    }
}
