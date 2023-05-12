#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*first=NULL, *second=NULL, *third=NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        t= new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second=new Node;
    second->data=A[0];
    second->next=NULL;
    last=second;

    for(i=1;i<n;i++)
    {
        t= new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p)
{
    while (p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

void RDisplay(struct Node *p)
{
    if(p!=NULL)
    {
        cout<<p->data<<" ";
        RDisplay(p->next);
    }
}

int count(struct Node *p)
{
    int c=0;
    while(p)
    {
        c++;
        p=p->next;
    }
    return c;
}

int Rcount(struct Node *p)
{
    if(p==0)
        return 0;
    else
        return Rcount(p->next)+1;
}

int add(struct Node *p)
{
    int sum=0;
    while(p)
    {
        sum=sum+p->data;
        p=p->next;
    }
    return sum;
}

int Radd(struct Node *p)
{
    if(p==0)
        return 0;
    else
        return Radd(p->next)+p->data;
}

int max(struct Node *p)
{
    int m=-32768;
    while(p)
    {
        if(p->data>m)
            m=p->data;
        p=p->next;
    }
    return m;
}

int Rmax(struct Node *p)
{
    int x=0;
    if(p==0)
        return INT32_MIN;
    x=max(p->next);
    return x>p->data?x:p->data;
}

struct Node * LSearch(struct Node *p, int key)
{
    while(p!=NULL)
    {
        if(key==p->data)
            return p;
        p=p->next;
    }
    return NULL;
}

struct Node * LSearch2(struct Node *p, int key)
{
    struct Node *q=NULL;
    while(p!=NULL)
    {
        if(key==p->data)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

struct Node * RLSearch(struct Node *p, int key)
{
    if(p==NULL)
        return NULL;
    if(key==p->data)
        return p;
    return RLSearch(p->next, key);
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;

    if(index<0||index>count(p))
        return;
    t=new Node;
    t->data=x;

    if(index==0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(int i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    }
}

void SortedInsert(struct Node *p, int x)
{
    struct Node *t, *q=NULL;
    t=new Node;
    t->next=NULL;

    if(first=NULL)
        first=t;
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }
}

int Delete(struct Node *p, int index)
{
    struct Node *q=NULL;
    int x=-1, i;

    if(index<1||index>count(p))
        return -1;
    if(index==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        delete q;
        return x;
    }
    else
    {
        for(i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
        return x;
    }
}

int isSorted(struct Node *p)
{
    int x=-65536;
    while(p!=NULL)
    {
        if(p->data<x)
            return 0;
        x=p->data;
        p=p->next;
    }
    return 1;
}

void RemoveDuplicate(struct Node *p)
{
    struct Node *q=p->next;
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
}

void Reverse1(struct Node *p)
{
    struct Node *q=NULL, *r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void Reverse2(struct Node *q, struct Node *p)
{
    if(p!=NULL)
    {
        Reverse2(p,p->next);
        p->next=q;
    }
    else
        first=q;
}

void Concat(struct Node *p, struct Node *q)
{
    third=p;
    while(p->next!=NULL)
        p=p->next;
    p->next=q;
}

void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if(p->data < q->data)
    {
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p!=NULL && q!=NULL)
    {
        if(p->data < q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p)
        last->next=p;
    else
        last->next=q;
}

int isLoop(struct Node *f)
{
    struct Node *p, *q;
    p=q=f;

    do
    {
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p && q && p!=q);
    return p==q?1:0;
}

main()
{
    //struct Node *temp;
    struct Node *t1, *t2;

    int A[]={3,5,7,20,25};
    create(A,5);
    //int B[]={1,2,3,4,5};
    //create2(B,5);

    //RDisplay(first);
    //cout<<"Length is "<<Rcount(first);
    //cout<<"Sum is "<<Radd(first)<<endl;
    //cout<<"Max Element is "<<Rmax(first)<<endl;
    /*temp=LSearch2(first,25);
    if(temp)
        cout<<"Key is found: "<<temp->data<<endl;
    else
        cout<<"Key not found."<<endl;*/
    //Insert(first,0,10);
    //SortedInsert(first,10);
    //cout<<"Deleted Element is "<<Delete(first, 4)<<endl;
    //cout<<isSorted(first)<<endl;
    //RemoveDuplicate(first);
    //Reverse2(NULL,first);
    //Concat(first,second);
    //Merge(first,second);
    //cout<<"Merged "<<endl;

    t1=first->next->next;
    t2=first->next->next->next->next;
    t2->next=t1;
    cout<<isLoop(first)<<endl;

    //Display(third);
}