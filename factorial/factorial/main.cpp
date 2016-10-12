//
//  main.cpp
//  factorial
//
//  Created by 김다은 on 2016. 9. 28..
//  Copyright © 2016년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdio>

int Factorial(int n){
    if(n==0)
        return 1;
    return n*Factorial(n-1);

}
int main(void){
    int T;
    FILE *fp = fopen("input.txt", "r");
    fscanf(fp, "%d", &T);
    int tmp=0;
    for(int i = 0;i<T;i++){
        int a;
        fscanf(fp, "%d", &a);
        tmp = Factorial(a);
        printf("%d\n", tmp);
    }
    
    
}
