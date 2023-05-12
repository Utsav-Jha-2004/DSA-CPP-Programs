#include <bits/stdc++.h>
using namespace std;

double e(double x, double n)
{
    double s=1;
    for(;n>0;n--)
        s=1+x/n*s;
    return s;
}
main()
{
    cout << e(1,10);
}