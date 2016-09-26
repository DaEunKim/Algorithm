//
//  main.cpp
//  Eureka
//
//  Created by 김다은 on 2016. 9. 22..
//  Copyright © 2016년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>

int main(void){
    FILE *fp = fopen("input.txt", "r");
    
    int T;
    fscanf(fp, "%d", &T);
    
    int K[1001];//삼각수
    bool arr[1001];
    
    
    for(int j = 0; j<1001;j++){
        arr[j] = false;
    }
    
    for(int j = 1; j<50;j++){
        K[j] = j*(j+1)/2;
    }
    
    for(int j = 1;j<50; j++){
        for(int r = j; r<50; r++){
            for(int k = r; k<50; k++){
                
                if(K[k] + K[r] + K[j]<1001)
                    arr[K[k] + K[r] + K[j]] = true;
                
            }
        }
        
    }
    
    for(int i = 0; i<T; i++){
        int N;
        fscanf(fp, "%d", &N);
        
        
       
        if(arr[N] == true)
            printf("1\n");
        else
            printf("0\n");
        
    }
}
