//
//  main.cpp
//  Algoritm
//
//  Created by 김다은 on 2016. 8. 30..
//  Copyright © 2016년 김다은. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main(void) {
    FILE *fp = fopen("input.txt","r");

    int T;
    fscanf(fp,"%d", &T);

    int n;//number of team
    int m;//number of game
    
    for(int z=0;z<T;z++){
        int S[1001] = {0, };//총 득점.
        int A[1001] = {0, };//총 실점.

        double max=0;
        double min=20135179;
        int a=0, b=0, p, q;
        
        fscanf(fp,"%d %d", &n, &m);
        
        
        for(int i=0;i<m;i++){
            fscanf(fp,"%d %d %d %d", &a, &b, &p, &q);
            S[a] +=p;
            A[a] +=q;
            S[b] +=q;
            A[b] +=p;
        }
        
        for(int i=1;i<=n;i++){
            if(!S[i] && !A[i]){
                min=0;
                continue;
            }
            
            double s = S[i] * S[i];
            double k = A[i] * A[i];
            double w = (s*1000)/(s+k);
            
            if(max<w){
                max = w;
            }
            
            if(min>w){
                min = w;
            }
            
        }
        printf("%d\n%d\n", (int)max, (int)min);

    }
}
