#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if(n==0)
        return 1;
    else
        return fact(n-1)*n;
}

int nCr(int n, int r)
{
    if(r==0||n==r)
        return 1;
    else
        return nCr(n-1,r-1) + nCr(n-1,r);
}

main()
{
    cout << nCr(4,2);
}