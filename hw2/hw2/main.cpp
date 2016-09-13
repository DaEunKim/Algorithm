//
//  main.cpp
//  hw2
//
//  Created by 김다은 on 2016. 9. 6..
//  Copyright © 2016년 김다은. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(void) {
    
    FILE *fp = fopen("input.txt", "r");
    
    int T;
    fscanf(fp,"%d", &T);
    
    char arr[51];
    
    for(int i=0;i<T;i++){
        int count=0;
        fscanf(fp,"%s", arr);
    
        int size = (int)strlen(arr);
        
        for(int j=0; j<size; ++j){
            if(arr[j]=='('){
                count++;
            }
            if(arr[j]==')'){
                count--;
            }
            
            if(count==-1){
                printf("NO");
                break;
            }
        }
        
        if(count==0){
            printf("YES");
        }
        if(count>0){
            printf("NO");
        }
        puts("");
    }
}
