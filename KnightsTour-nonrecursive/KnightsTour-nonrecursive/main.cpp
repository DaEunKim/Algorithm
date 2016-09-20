//
//  main.cpp
//  KnightsTour-nonrecursive
//
//  Created by 김다은 on 2016. 9. 16..
//  Copyright © 2016년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

class point{
public:
    int x, y, d;
    point(int x, int y, int d){
        this->x = x; this->y = y; this->d = d;
    }
};

stack<point> st;

int main(void){
    int T;
    FILE *fp = fopen("input.txt", "r");
    
    fscanf(fp, "%d", &T);
    for(int k=0; k<T;k++){
        
        int init_m, init_n;
        fscanf(fp, "%d %d", &init_m, &init_n);
        
        int arr[9][9];
        for(int i = 0 ; i<9;i++){
            for(int j = 0;j<9;j++){
                arr[i][j] = 0;
            }
        }
        
        
        int x, y, d=0;
        fscanf(fp, "%d %d" , &y, &x);
        
        int direction[8][2] = {{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
        
        int count=1;
        int tmp=0;
        arr[x][y] = count++;
        
        bool check = true;
        
        bool daeun = false;
        while(count<=init_m*init_n){
            
            tmp = count;
            for(int i=(daeun)? d: 0; i<8;i++){
                daeun = false;

                if(x+direction[i][0]>0 && x+direction[i][0] <=init_n  && y+direction[i][1]>0 && y+direction[i][1] <=init_m && arr[x+direction[i][0]][y+direction[i][1]]==0){
                    
                    st.push(point(x, y, i));
                    x = x+direction[i][0];
                    y = y+direction[i][1];
                    arr[x][y] = count++;
                    
                    break;
                }
                
            }
            
            if(tmp == count){
                if(st.size()==0){
                    cout << "0" <<endl;
                    check = false;
                    break;
                }
                 arr[x][y] = 0;
                --count;
                daeun = true;
                x = st.top().x;
                y = st.top().y;
                d = st.top().d+1;
                st.pop();
            }
            
            
        }
        
        if(check == true){
            
            
                cout<< "1" <<endl;
             
            for(int i = 1; i <= init_m; i++){
                for(int j = 1; j <= init_n; j++){
                    cout<< arr[j][i] << " ";
                }
                cout << endl;
            }
        }
        
        
        
    }
}