#include <bits/stdc++.h>
using namespace std;

int fun(int n)
{
    if(n>100)
        return n-10;
    else
        return fun(fun(n+11));
}
main()
{
    cout << fun(95);
}