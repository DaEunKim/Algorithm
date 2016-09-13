//
//  main.cpp
//  GoldbachConjecture
//
//  Created by 김다은 on 2016. 9. 11..
//  Copyright © 2016년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdio>

int minority(int num){
    if(num==1)
        return false;
    if(num==2)
        return true;
    
    for(int i = 2;i<num;i++){
        if(num%i==0)
            return false;
    }
    return true;
}


int main(void) {
    int T;
    scanf("%d",&T);
    
    for(int i = 0; i<T; i++){
        int n = 0;
        int minor;
        
        int tmp = 0;
        scanf("%d", &n);
 
        for(int j = 0;j<n;j++){
            
            if(minority(minor)){
                minor+=1;
                
                printf("%d\n", minor);
                
                tmp+=n;
                if(minor<n){
                    tmp += minor;
                }
                //if(tmp==n)
                    //printf("%d\n", tmp);
                
            }
        }
    }
}

