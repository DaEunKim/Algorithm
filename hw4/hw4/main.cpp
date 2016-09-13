//
//  main.cpp
//  hw4
//
//  Created by 김다은 on 2016. 9. 9..
//  Copyright © 2016년 김다은. All rights reserved.
//

#include <cstdio>

int main(void) {
    
    FILE *fp = fopen("input.txt", "r");
    
    int T;
    
    fscanf(fp, "%d", &T);
    for(int i=0;i<T;i++){
        int a,b;
        int x1=0;
        
        fscanf(fp, "%d %d", &a, &b);
        
        for(int j = 2; j<=2147483647;j++){
            
            if(b <= a*j){
                a = a*j -b;
                b = b*j;
            }
            x1=j;
            if(a==0){
                break;
            }
        }
        printf("%d\n", x1);
        
    }
}
