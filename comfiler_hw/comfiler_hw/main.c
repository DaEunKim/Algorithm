//
//  main.c
//  comfiler_hw
//
//  Created by 김다은 on 2016. 10. 10..
//  Copyright © 2016년 김다은. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "st_tab.h"

#define bool int
#define true 1
#define false 0


int count1;
int count2;
int count3 = 0;

char terminals[10];
char nonterminals[10];
char finalstate[10];

int trans(char ch){
    for(int i=0; i<count2; ++i)
        if(nonterminals[i] == ch)
            return i;
    return -1;
}

bool isFinal(int s){
    for(int i=0; i<count3; ++i)
        if(trans(finalstate[i]) == s) return true;
    return false;
}

int calIndex(char ch){
    if(nonterminals[0] == ch) return 0;
    if(nonterminals[1] == ch) return 1;
    return -1;
}

int main(void)
{
    FILE *fp = fopen("input.txt", "r");
    
    char ch;
    
    do{
        fscanf(fp, "%c", &ch);
    }
    while(ch!='=');
    do{
        fscanf(fp, "%c", &ch);
        terminals[count1++] = ch;
    }
    while(ch!='\n');
    --count1;
    
    do{
        fscanf(fp, "%c", &ch);
    }
    while(ch!='=');
    do{
        fscanf(fp, "%c", &ch);
        nonterminals[count2++] = ch;
    }
    while(ch!='\n');
    --count2;
    
    do{
        fscanf(fp, "%c", &ch);
    }
    while(ch!='=');
    do{
        fscanf(fp, "%c", &ch);
        finalstate[count3++] = ch;
    }
    while(ch!='\n');
    --count3;
    
    
    ST_TAB = (int**)malloc(sizeof(int*)*count2);
    for(int i = 0;i<count2;i++){
        ST_TAB[i] = (int*)malloc(sizeof(int*)*count1);
        
    }
    
    for(int i=0; i<count2; i++){
        fscanf(fp, "%c", &ch);
        fscanf(fp, "%c", &ch); // ' '
        fscanf(fp, "%c", &ch);
        ST_TAB[i][0] = trans(ch);
        fscanf(fp, "%c", &ch); // ' '
        fscanf(fp, "%c", &ch);
        ST_TAB[i][1] = trans(ch);
        fscanf(fp, "%c", &ch); // '\n'
    }
    for(int i=0; i<count2; i++){
        for(int j=0; j<2; j++)
            printf("%d ", ST_TAB[i][j]);
        puts("");
    }

    
    int cur_state = 0;
    ch = getchar();
    while (ch != '\n') {
        cur_state = ST_TAB[cur_state][ch-'a'];
        if (cur_state < 0) { puts("FAIL"); return 0; }
        ch = getchar();
    }
    
    if (isFinal(cur_state)) puts("OK");
    else puts("FAIL");
    
}
