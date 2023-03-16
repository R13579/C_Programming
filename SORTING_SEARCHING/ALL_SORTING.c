#include<stdio.h>



/** insertion we just take first elemtn in unsorted part and place it in sorted array 
 * selection we just take min element (index) and just swap it with end of sorted part
 * **/
void isort(int a[],int n)
{
    
//* here we just take the element in usorted array and place it in crct position of sorted array
int pivot,temp,j;
for(int i=1;i<n;i++)
{
    pivot=a[i];
    j=i-1;
    while(j>0 && a[j]>pivot)
    {
        a[j+1]=a[j];//carefull with j-- , dont do here as it effect j in lside )
        j--;
    }
    a[j+1]=pivot;
}


}


void ssort(int a[],int n)
{
    /**Selection sort invloves sorted and unsorted array where we moe across unsorted array
     * finding any min index and replacing it with largest element in sorted array/
     * 
     * Even the best case time complexity is o(n2) as we search for any min element index in Unsorted part in every iteration 
     * 
     * **/
for(int i=0;i<n;i++)
{
    int min_idx=i,temp;
    int j=i+1;
    while(j<n)
    {
        if(a[min_idx]>a[j])
        {
            min_idx=j;
        }
        j++;
    }
    if(min_idx!=i)
    {
        temp=a[i];
        a[i]=a[min_idx];
        a[min_idx]=temp;
    }
}
    
}


void merge(int a[],int l,int m,int r)
{
    /**we just create 2 arrays and copy all the values
     * 
     **/
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++)
    {
        L[i]=a[l+i];
    }
    for(int j=0;j<n2;j++)
    {
        R[j]=a[m+j+1];
    }
    i=j=0,k=l;
    while(i<n1 && j <n2)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i++];
        }
        else
        {
            a[k]=R[j++];
        }
        k++;
    }
    while (i<n1)
    {
         a[k++]=L[i++];
    }
    while (j<n2)
    {
         a[k++]=R[j++];
    }
    
}

void msort(int a[],int l,int r)
{
    /**In merge sort we just divide the array till we reach atomic variables
     * then we merge the arrays back*/
    if(l<r)
    {
        int m=l+(r-l)/2;
        msort(a,l,m);
        msort(a,m+1,r);
        merge(a,l,m,r);
    }
}


int partition_findex(int a[],int l,int r)
{
    /**#1
     * #2
     **/
    int pivot=a[l];
    int sorted_count=r+1;
    int j=sorted_count,temp=0;
    for(int i=r;i>l;i--)
    {/*sort all the elements less than pivot to one end and hold the sorted_count*/
        
        if(a[i]>pivot)//Toggle here for ascending> descending <//
        {
            j--;
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
    /*swap the pivot after the end of sorted array and return that position as the partition index*/
    temp=a[j-1];
    a[j-1]=a[l];
    a[l]=temp;
    return j-1;
}
int partition_lindex(int a[],int l,int r)
{
    /**#1
     * #2
     **/
    int pivot=a[r];
    int sorted_count=l-1;
    int j=sorted_count,temp=0;
    for(int i=l;i<r;i++)
    {/*sort all the elements less than pivot to one end and hold the sorted_count*/
        
        if(a[i]<pivot)
        {
            j++;
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
    /*swap the pivot after the end of sorted array and return that position as the partition index*/
    temp=a[j+1];
    a[j+1]=a[r];
    a[r]=temp;
    return j+1;
}

void qksort(int a[],int l,int r)
{
    /** In Quick Sort we take the pivot either(0 or n-1 index) and we place the pivot in crct position
     * and all smaller and bigger elements around it.
     * further we just take the position of pivot returned above and auick by splitting array around pivot
     * 
     **/
    if(l<r)
    {
        int qp=partition_findex(a,l,r);
        qksort(a,l,qp-1);
        qksort(a,qp+1,r);
    }
}



void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

int bnsearch(int a[],int n,int key)
{
   // int n=sizeof(a)/sizeof(a[0]);
    printf("%d is size",n);
    msort(a,0,n-1);
    int l=0,mid,r=n-1;
    
    while(l<=r)
    {   mid=l+(r-l)/2;
        printf("{ -- %d %d %d %d \n --}",key,a[mid],l,r);
        if(key==a[mid])
        {
            return mid;
        }
        else if (key > a[mid])
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return -1;
}

void main()
{
    int a[]={1,5,2,7,3,8,4,9,10,11};

    int n=sizeof(a)/sizeof(a[0]);
    //ssort(a,n);
    //isort(a,n);
    //msort(a,0,n-1);
    int key=10;
    // printf("key is at : %d",bnsearch(a,n,key));
    //qksort(a,0,n-1);
    print(a,n);
}
