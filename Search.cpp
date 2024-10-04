// Searching Algorithms
#include<iostream>
#include<vector>
using namespace std;
// Linear Search
int isFound(vector<int>&arr,int ele)
{
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==ele)
        {
            return i;
        }
    }
    return -1;

}
// BinarySearch
int binarySearch(vector<int>&arr,int data)
{
    int left = 0;
    int right = arr.size()-1;
    while(left<=right)
    {
        int mid = (left+right)/2;
        if(arr[mid]==data)
        {
            return mid;
        }
        else if(arr[mid]>data)
        {
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr;
    int data;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        arr.push_back(data);
    }
    int found =binarySearch(arr,5);
    if(found)
    {
        cout<<"Element is found";
    }
    else{
        cout<<"Element not found";
    }
}
