#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
}*poly=NULL;

void Create()
{
    struct Node *t, *last=NULL;
    int num, i;

    cout<<"Enter no. of terms: "<<endl;
    cin>>num;
    cout<<"Enter each term with coeff & exp: \n";

    for(i=0;i<num;i++)
    {
        t=new Node;
        cin>>t->coeff>>t->exp;
        t->next=NULL;
        if(poly==NULL)
            poly=last=t;
        else
        {
            last->next=t;
            last=t;
        }
    }
}

void Display(struct Node *p)
{
    while(p)
    {
        cout<<p->coeff<<"x"<<p->exp<<" + ";
        p=p->next;
    }
    cout<<endl;
}

long Eval(struct Node *p, int x)
{
    long val;
    
    while(p)
    {
        val+=p->coeff*pow(x,p->exp);
        p=p->next;
    }
    return val;
}

main()
{
    Create();
    Display(poly);

    cout<<Eval(poly,1);
}