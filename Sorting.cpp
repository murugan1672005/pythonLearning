#include<iostream>
using namespace std;
void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
// Bubble Sort
void BubbleSort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j+1]<arr[j]){
                  swap(arr[j+1],arr[j]);
            }
        }
    }
}
// Recursive Bubble Sort
void RecursiveBubbleSort(int arr[],int n)
{
    if(n==1)
    {
        return;
    }
    bool swaps = false;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i+1]<arr[i])
        {
            swap(arr[i+1],arr[i]);
            swaps = true;
        }
    }
    if(!swaps)
    {
        return;
    }
     RecursiveBubbleSort(arr,n-1);
}
// Insertion Sort
void InsertionSort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int temp = arr[i];
        int j=i-1;
        while(j>=0 && temp < arr[j])
        {
            arr[j+1]=arr[j];
            j--;
        }
        if(arr[j+1]!=temp)
        {
            arr[j+1]=temp;
        }
    }
}
// Recursive Insertion Sort
void RecursiveInsertionSort(int arr[],int i,int n)
{
    if(i==n)
    {
        return;
    }
    int j=i;
    while(j>0 && arr[j-1]>arr[j])
    {
       swap(arr[j-1],arr[j]);
        j--;
    }
    RecursiveInsertionSort(arr,i+1,n);

}
// Selection Sort
void SelectionSort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int min_index = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[min_index]>arr[j])
            {
                min_index = j;
            }
        }
        swap(arr[min_index],arr[i]);
    }
}
// Merge Sort
void merge(int arr[],int left,int mid,int right){
    int leftArray[mid-left+1];
    int rightArray[right-mid];
    for(int i=0;i<mid-left+1;i++)
    {
        leftArray[i]=arr[left+i];
    }
    for(int j=0;j<right-mid;j++)
    {
        rightArray[j]=arr[mid+j+1];
    }
    int i=0;
    int j=0;
    int k=left;
    while(i<mid-left+1 && j<right-mid)
    {
        if(leftArray[i]<=rightArray[j]){
            arr[k++]=leftArray[i++];
        }
        else{
            arr[k++]=rightArray[j++];
        }
    }
    while(i<mid-left+1)
    {
         arr[k++]=leftArray[i++];
    }
    while(j<right-mid)
    {
     arr[k++]=rightArray[j++];
    }
}
void MergeSort(int arr[],int left,int right)
{
    if(left<right)
    {
        int mid = left + (right - left) / 2;
        MergeSort(arr,left,mid);
        MergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
// Quick sort
int partition(int arr[],int low,int high)
{
    int pivot = arr[low];
    int i=low;
    int j=high;
    while(i<j)
    {
        while(arr[i]<=pivot && i<=high-1)
        {
            i++;
        }
        while(arr[j]> pivot && j>=0)
        {
            j--;
        }
        if(i<j)
        {
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}
void QuickSort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi = partition(arr,low,high);
        QuickSort(arr,low,pi-1);
        QuickSort(arr,pi+1,high);
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    print(arr,n);
   QuickSort(arr,0,n-1);
    print(arr,n);
}
