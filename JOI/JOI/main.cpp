//
//  main.cpp
//  JOI
//
//  Created by 김다은 on 2016. 9. 27..
//  Copyright © 2016년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(void){
    string T[10001] = {"1","2"};
    string t;
    int count1 = 0;
    int count2 = 0;
    
    for(int i = 0;i<10;i++){
        cin >> t ;
        T[i] = t;
    }
    for(int i = 0;i<10;i++){
        if(T[i] == "J"){
            if(T[i+1] == "O"){
                if(T[i+2]=="I")
                    count1++;
            }
        }
            count1++;
        if(T[i]=="IOI")
            count2++;
    }
    
}
