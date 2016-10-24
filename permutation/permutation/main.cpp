//
//  main.c
//  permutation
//
//  Created by 김다은 on 2016. 10. 17..
//  Copyright © 2016년 김다은. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <cstdio>

void swap(char *a, char *a1){
    char tmp;
    tmp = *a;
    *a = *a1;
    *a1 = tmp;
}

void permuteString(char *str, int begin, int end){
    int i;
    int range = end-begin;
    
    if(range==1)
        printf("%s\n", str);
    else{
        for(i = 0; i<range; i++){
            swap(&str[begin], &str[begin+i]);
            permuteString(str, begin+1, end);
            swap(&str[begin], &str[begin+i]);
        }
    }
}
void permute(char *str){
    permuteString(str, 0, strlen(str));
}

int main(void){
    char str[] = "abcd";
    permute(str);
}
