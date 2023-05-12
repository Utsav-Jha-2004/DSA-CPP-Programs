#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    cout << "Elements are: ";
    for(i=0;i<arr.length;i++)
        cout << arr.A[i] << " ";
}

void Append(struct Array *arr, int x)
{
    if(arr->length<arr->size)
        arr->A[arr->length++] = x;
}

void Insert(struct Array *arr, int index, int x)
{
    if(index>=0 && index<=arr->length)
    {
        for(int i=arr->length;i>index;i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index)
{
    int x=0;
    if(index>=0 && index<arr->length)
    {
        x=arr->A[index];
        for(int i=index; i<arr->length-1; i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
        return x;
    }
}

void swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int LinearSearch(struct Array *arr, int key)
{
    for(int i=0; i<arr->length; i++)
    {
        if(key==arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int key)
{
    int l=0,mid,h=arr.length-1;

    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr.A[mid])
            return mid;
        else if(key<arr.A[mid])
            h=mid-1;
        else
            l=mid+1;
    }
    return -1;
}

int RBinSearch(int a[], int l, int h, int key)
{
    int mid;
    if(l<=h)
    {
        mid=(l+h)/2;
        if(key==a[mid])
            return mid;
        else if(key<a[mid])
            return RBinSearch(a,l,mid-1,key);
        else
            return RBinSearch(a, mid+1, h, key);
    }
    return -1;
}

int Get(struct Array arr, int index)
{
        if(index>=0 && index<arr.length)
            return arr.A[index];
    return -1;
}

void Set(struct Array *arr, int index, int x)
{
    if(index>=0 && index<arr->length)
        arr->A[index]=x;
}

int Max(struct Array arr)
{
    int max=arr.A[0];
    for(int i=1; i<arr.length; i++)
    {
        if(arr.A[i]>max)
            max=arr.A[i];
    }
    return max;
}

int Min(struct Array arr)
{
    int min=arr.A[0];
    for(int i=1; i<arr.length; i++)
    {
        if(arr.A[i]<min)
            min=arr.A[i];
    }
    return min;
}

int Sum(struct Array arr)
{
    int s=0;
    for(int i=0; i<arr.length; i++)
        s=s+arr.A[i];
    return s;
}

float Avg(struct Array arr)
{
    return (float)Sum(arr)/arr.length;
}

void Reverse(struct Array *arr)
{
    int *B,i,j;

    B = new int[arr->length*sizeof(int)];
    for(i=arr->length-1, j=0; i>=0; i--, j++)
        B[j] = arr->A[i];
    for(i=0; i<arr->length; i++)
        arr->A[i]=B[i];
}

void Reverse2(struct Array *arr)
{
    for(int i=0, j=arr->length-1; i<j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}

void InsertSort(struct Array *arr, int x)
{
    int i=arr->length-1;
    if(arr->length==arr->size)
        return;
    while (i>=0 && arr->A[i]>x)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}

int isSorted(struct Array arr)
{
    for(int i=0; i<arr.length-1; i++)
    {
        if(arr.A[i]>arr.A[i+1])
            return 0;
    }
    return 1;
}

struct Array* Merge(struct Array *arr, struct Array *arr1)
{
    int i=0,j=0,k=0;
    struct Array *arr2= (struct Array *)new int[sizeof(struct Array)];

    while (i<arr->length && j<arr1->length)
    {
        if(arr->A[i]<arr1->A[j])
            arr2->A[k++]=arr->A[i++];
        else
            arr2->A[k++]=arr1->A[j++];
    }
    for(; i<arr->length; i++)
        arr2->A[k++]=arr->A[i];
    for(; j<arr1->length; j++)
        arr2->A[k++]=arr1->A[j];
    arr2->length = arr->length + arr1->length;
    arr2->size=10;
}

struct Array* Union(struct Array *arr, struct Array *arr1)
{
    int i=0,j=0,k=0;
    struct Array *arr2= (struct Array *)new int[sizeof(struct Array)];

    while (i<arr->length && j<arr1->length)
    {
        if(arr->A[i]<arr1->A[j])
            arr2->A[k++]=arr->A[i++];
        else if(arr1->A[j]<arr->A[i])
            arr2->A[k++]=arr1->A[j++];
        else
        {
            arr2->A[k++]=arr->A[i++];
            j++;
        }
    }
    for(; i<arr->length; i++)
        arr2->A[k++]=arr->A[i];
    for(; j<arr1->length; j++)
        arr2->A[k++]=arr1->A[j];
    arr2->length = k;
    arr2->size=10;
}

struct Array* Intersection(struct Array *arr, struct Array *arr1)
{
    int i=0,j=0,k=0;
    struct Array *arr2= (struct Array *)new int[sizeof(struct Array)];

    while (i<arr->length && j<arr1->length)
    {
        if(arr->A[i]<arr1->A[j])
            i++;
        else if(arr1->A[j]<arr->A[i])
            j++;
        else if(arr->A[i]==arr1->A[j])
        {
            arr2->A[k++]=arr->A[i++];
            j++;
        }
    }
    
    arr2->length = k;
    arr2->size=10;
}

struct Array* Difference(struct Array *arr, struct Array *arr1)
{
    int i=0,j=0,k=0;
    struct Array *arr2= (struct Array *)new int[sizeof(struct Array)];

    while (i<arr->length && j<arr1->length)
    {
        if(arr->A[i]<arr1->A[j])
            arr2->A[k++]=arr->A[i++];
        else if(arr1->A[j]<arr->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for(; i<arr->length; i++)
        arr2->A[k++]=arr->A[i];

    arr2->length = k;
    arr2->size=10;
    
}

main()
{
    struct Array arr = {{2,6,10,15,25},10,5};
    struct Array arr1 = {{3,6,7,15,20},10,5};
    struct Array *arr2;

    //arr2 = Merge(&arr, &arr1);
    //arr2 = Union(&arr, &arr1);
    //arr2 = Intersection(&arr, &arr1);
    arr2 = Difference(&arr, &arr1);

    //Append(&arr, 10);
    //Insert(&arr, 5, 10);
    //cout << Delete(&arr, 0) << endl;
    //cout << LinearSearch(&arr,4) << endl;
    //cout << BinarySearch(arr, 5) << endl;
    //cout << RBinSearch(arr.A, 0, arr.length, 5) << endl;
    //cout << Get(arr,2) << endl;
    //Set(&arr,0,15);
    //cout << Max(arr) << endl;
    //cout << Min(arr) << endl;
    //cout << Sum(arr) << endl;
    //cout << Avg(arr) << endl;
    //Reverse2(&arr);
    //InsertSort(&arr, 20);
    //cout << isSorted(arr);
    
    Display(*arr2);
}