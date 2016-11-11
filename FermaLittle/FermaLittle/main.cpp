//
//  main.cpp
//  FermaLittle
//
//  Created by 김다은 on 2016. 11. 10..
//  Copyright © 2016년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdio>

long long mul(long long x, long long y, long long p) {
    long long ans = 1;
    while (y > 0) {
        if (y%2 != 0) {
            ans *= x;
            ans %= p;
        }
        x *= x;
        x %= p;
        y/=2;
    }
    return ans;
}

int main(void) {
    FILE * fp = fopen("input.txt", "r");
    int T;
    fscanf(fp,"%d", &T);
    while(T--){
        long long n,r,p;
        fscanf(fp, "%lld %lld", &n, &r);

        p = 10007LL;
        long long ans = 1;
        long long t1 = 1;
        long long t2 = 1;
        for (long long i=1; i<=n; i++) {
            t1 *= i;
            t1 %= p;
        }
        for (long long i=1; i<=r; i++) {
            t2 *= i;
            t2 %= p;
        }
        for (long long i=1; i<=n-r; i++) {
            t2 *= i;
            t2 %= p;
        }
        long long t3 = mul(t2,p-2,p);
        t3 %= p;
        ans = t1*t3;
        ans %= p;
        
        printf("%lld\n", ans);
    }
    return 0;
}
