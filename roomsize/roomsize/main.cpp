//
//  main.cpp
//  roomsize
//
//  Created by 김다은 on 2016. 9. 28..
//  Copyright © 2016년 김다은. All rights reserved.
//

#include <cstdio>
#include <algorithm>

int size[101];
int fullsize[101];
char pic[100][100];
int count;

void Fill(int a, int b){
    size[count]++;
    pic[a][b] = '+';
    
    if(pic[a+1][b] == '.'){
        Fill(a+1, b);
    }
    if(pic[a-1][b] == '.'){
        Fill(a-1, b);
    }
    if(pic[a][b+1] == '.'){
        Fill(a, b+1);
    }
    if(pic[a][b-1] == '.'){
        Fill(a, b-1);
    }
    
}

int rev(int a, int b){
    return a > b;
} // 내림차순 정렬을 위한 비교 함수

int main(void){
    int T;
    FILE *fp = fopen("input.txt", "r");
    fscanf(fp, "%d", &T);
    
    for(int i = 0; i < T; i++){
        int m, n;
        fscanf(fp, "%d %d", &m, &n);
        
        for(int j=0; j < n; j++)
            fscanf(fp, "%s", pic[j]);
        
        // 다음 계산을 위한 변수들 초기화
        count=0;
        for(int j=0; j<101; ++j)
            size[j] = 0;
        
        for(int j=1; j < n-1; j++){
            for(int k = 1; k < m-1; k++){
                if(pic[j][k] == '.'){
                    Fill(j, k);
                    count++;
                }
            }
        }
        
        
        std::sort(size, size+count, rev); // 그동안 센 방의 크기들 내림차순으로 정렬
        printf("%d\n", count); // 방 개수 출력
        for(int j = 0;j<count;j++){ // 각 방의 크기 출력
            printf("%d ", size[j]);
        }
        puts(""); // 다음 출력을 위한 줄바꿈
    }
}
