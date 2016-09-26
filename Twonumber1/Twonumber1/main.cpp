//
//  main.cpp
//  Twonumber1
//
//  Created by 김다은 on 2016. 9. 21..
//  Copyright © 2016년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

int S[1000001];
int K;

int abs(int num){
    if(num<0)
        return -num;
    else
        return num;
}


int main(void) {
    FILE *fp = fopen("input.txt", "r");
    
    int T;
    fscanf(fp,"%d", &T);
    
    for(int i=0; i<T;i++){
        int n;
        fscanf(fp, "%d %d", &n, &K);
        
        int min = 2013517900;
        int cnt = 0;
        int begin=0, end=n-1;
        for(int j = 0;j<n;j++){
            int s;
            fscanf(fp, "%d", &s);
            S[j] = s;
        }
        
        std::sort(S, S+n);
        
        while(begin < end){
            if(S[begin] + S[end] <K){
                if(min == abs(K-(S[begin]+S[end])))
                    cnt++;
                else if(abs(K - (S[begin]+S[end]))<min){
                    cnt = 1;
                    min = abs(K-(S[begin]+S[end]));
                }
                begin++;
            }
            else if(S[begin] + S[end] >= K){
                if(min == abs(K-(S[begin]+S[end])))
                    cnt++;
                else if(abs(K - (S[begin]+S[end]))<min){
                    cnt = 1;
                    min = abs(K-(S[begin]+S[end]));
                }
                end--;
            }
        }
        
        printf("%d\n", cnt);
        
        
        
    }
    
}
