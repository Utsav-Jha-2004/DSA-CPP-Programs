#include <bits/stdc++.h>
using namespace std;

int TOH(int n, int A, int B, int C)
{
    if(n>0)
    {
        TOH(n-1,A,C,B);
        cout << "From " << A << " to " << C << endl;
        TOH(n-1,B,A,C);
    }
}

main()
{
    cout << TOH(3,1,2,3) << endl;
}