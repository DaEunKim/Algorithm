//
//  main.cpp
//  Hotel
//
//  Created by 김다은 on 2016. 9. 22..
//  Copyright © 2016년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdio>

int main(void){
    FILE *fp = fopen("input.txt", "r");
    
    int T;
    fscanf(fp, "%d", &T);
    
    for(int i = 0; i<T;i++){
        int H, W, N;//H:층, W:최대 호수, N: 손님수
        fscanf(fp, "%d %d %d", &H, &W, &N);
        int tmp, tmp1, room;
        tmp = N%H;
        
        if(tmp==0){
            tmp = H;
        }
        
        if(N%H!=0){
            tmp1=N/H+1;
        }
        else
            tmp1=N/H;
        
        room = tmp*100+tmp1;
        printf("%d\n", room);

    }
}
