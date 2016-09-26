//
//  main.cpp
//  TwoNumbers
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

int Binary(int size, int target){
    int begin = 0;
    int end = size-1;
    int mid=0;
    while(begin < end){
        
        mid = begin+end;
        
        if(S[mid] < target){
            begin = mid+1;
        }
        else if(S[mid] > target){
            end = mid-1;
        }
        else
            break;
    }
    int min = 999;

    if(abs(S[mid+1] - target) < min){
        min = S[mid+1] - target;
        
    }
    if(abs(S[mid-1] - target) < min){
        min = S[mid-1] - target;
    }
    if(S[mid+1]==S[mid-1]){
        min = S[mid+1];
    }

    return min;
    
}

int main(void) {
    FILE *fp = fopen("input.txt", "r");
    
    int T;
    fscanf(fp,"%d", &T);
    
    for(int i=0; i<T;i++){
        int n;
        scanf("%d %d", &n, &K);
        
        int tmp=0;
        int min = 999;
        int cnt = 0;
        for(int j = 0;j<n;j++){
            int s;
            fscanf(fp, "%d", &s);
            S[j] = s;
        }
        
        std::sort(S, S+n);
        
        for(int j=0; j<n; ++j){
            tmp = Binary(n, K-S[j]);
            
            if(min == K - (tmp +S[j])){
                cnt++;
            }
            else if(K - (tmp +S[j]) < min ){
                min = K - (tmp +S[j]);
                cnt=1;
            }
            

        }
        printf("%d\n", cnt);
        
        
       
    }

}
