//
//  main.cpp
//  stack_easy
//
//  Created by 김다은 on 2017. 1. 2..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

stack<int> s;
int arr[100000]={0,};

int main(void){
    int T;
    int n;
    
    scanf("%d", &T);
    
    for(int i=1;i<=T;i++){
        scanf("%d", &arr[i]);
    }
    
    for(int j=1;j<=T;j++){
    for(int i=j;i<=T;i++){
        s.push(i);
        int tmp = s.top();
        tmp++;
        //printf("%d \n", tmp);
        if(s.top()<arr[i]){
            printf("+\n");
        }
        else if(s.top()==arr[i]){
            s.pop();
        }
        else if(s.top()>arr[i]){
            
            printf("-\n");
        }
        else
            printf("NO\n");
       
    }
    }
    
    

    
    
    
}
