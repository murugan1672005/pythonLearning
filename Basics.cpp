// You are using GCC
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<limits.h>
using namespace std;
int largest(vector<int>&arr)
{
    int maximum = INT_MIN;
    for(int i=0;i<arr.size();i++)
    {
        if(maximum<arr[i])
        {
            maximum = arr[i];
        }
    }
    return maximum;
}
int secondLargest(vector<int>&arr)
{
    int first = INT_MIN;
    int second = INT_MIN;
    for(int i=0;i<arr.size();i++)
    {
        if(first<arr[i])
        {
            second = first;
            first = arr[i];
        }
        else if(second<arr[i] && first > second)
        {
            second = arr[i];
        }
    }
    return second;
}
void reverse(vector<int>&arr,int left,int right)
{

    while(left<=right)
    {
        swap(arr[left],arr[right]);
        left++;
        right--;
    }
}
void leftRotate(vector<int>&arr,int k)
{
    reverse(arr,0,k-1);
    reverse(arr,k,arr.size()-1);
    reverse(arr,0,arr.size()-1);
}
void rightRotate(vector<int>&arr,int k)
{
    
    reverse(arr,0,arr.size()-1);
    reverse(arr,0,k-1);
    reverse(arr,k,arr.size()-1);
}
bool isSorted(vector<int>&arr)
{
    for(int i=arr.size()-1;i>=1;i--)
    {
        if(arr[i]<arr[i-1])
        {
            return false;
        }
    }
    return true;
}
int removeDuplicates(vector<int>&arr)
{
    int i=0;
    int j = i+1;
    while(j<arr.size())
    {
        if(arr[i]==arr[j])
        {
            j++;
        }
        else{
          swap(arr[i+1],arr[j]);
            i++;
            j++;
        }
    }
    return i+1;
}
void moveZerosToEnd(vector<int>&arr)
{
    int i=0;
    int j = i+1;
    while(i<arr.size()&& j<arr.size())
    {
        if(arr[i]==0)
        {
            while(arr[j]==0&&j<arr.size())
            {
                j++;
            }
            arr[i]=arr[j];
            arr[j]=0;
            i++;
            j++;
        }
        else{
            i++;
        }
    }
}
int linearSearch(vector<int>&arr,int key)
{
    for(int i=0;i<arr.size();i++ )
    {
        if(arr[i]==key)
        {
            return i;
        }
    }
    return -1;
}
void findunion(vector<int>&arr1,vector<int>&arr2)
{
    int i=0;
    int j=0;
    vector<int>Union;
    while(i<arr1.size() && j<arr2.size())
    {
        if(arr1[i]<=arr2[j])
        {
            if(Union.size()==0||Union.back()!=arr1[i])
            {
                Union.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if(Union.size()==0||Union.back()!=arr2[j])
            {
                Union.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(i<arr1.size())
    {
        if(Union.size()==0||Union.back()!=arr1[i])
        {
        Union.push_back(arr1[i]);
        }
        i++;
    }
    while(j<arr2.size())
    {
         if(Union.size()==0||Union.back()!=arr2[j])
        {
        Union.push_back(arr2[j]);
        }
        j++;
    }
    for(int i=0;i<Union.size();i++)
    {
        cout<<Union[i]<<" ";
    }
    cout<<"\n";
    
}
int findMissing(vector<int>&arr)
{
    int missing = 1;
    for(int i=2;i<=arr.size()+1;i++)
    {
        missing^=i;
    }
    for(int i=0;i<arr.size();i++)
    {
        missing^=arr[i];
    }
    return missing;
}
int findLongestSubarray(vector<int>&arr,int k)
{
    int prefixSum = 0;
    int maxLen =0;
    map<int,int>PrefixMap;
    for(int i=0;i<arr.size();i++)
    {
        prefixSum+=arr[i];
        if(prefixSum == k)
        {
            maxLen = max(maxLen,i+1);
        }
        int rem = prefixSum - k;
        if(PrefixMap.find(rem)!=PrefixMap.end())
        {
            int len = i-PrefixMap[rem];
            maxLen = max(len,maxLen);
        }
        if(PrefixMap.find(prefixSum)==PrefixMap.end())
        {
            PrefixMap[prefixSum]=i;
        }
    }
    return maxLen;
    
}
int MaximumConsecutiveOnes(vector<int>&arr)
{
    int i=0;
    int max =0;
    int count =0;
    while(i<arr.size())
    {
        if(arr[i]==1)
        {
            count++;
        }
        else{
            count = 0;
        }
        if(max<count)
        {
            max=count;
        }
        i++;
    }
    return max;
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
    cout<<"Intial array : ";
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
//     cout<<"Largest element in the array : "<<largest(arr)<<"\n";
//     cout<<"Second Largest element in the array : "<<secondLargest(arr)<<"\n";
//     cout<<isSorted(arr)<<"\n";
//     int unique = removeDuplicates(arr);
//     cout<<"Number of unique Elements in this array "<<unique<<"\n";
//     for(int i=0;i<unique;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<"\n";
//     // rightRotate(arr,3);
//     // cout<<"Rotated Array : ";
//     // for(int i=0;i<arr.size();i++)
//     // {
//     //     cout<<arr[i]<<" ";
//     // }
//     // cout<<"\n";
//   moveZerosToEnd(arr);
//     for(int i=0;i<arr.size();i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<"\n";
//     cout<<linearSearch(arr,0)<<"\n";
//     cout<<findMissing(arr)<<"\n";
//     vector<int>arr2;
//     for(int i=0;i<n;i++)
//     {
//         cin>>data;
//         arr2.push_back(data);
//     }
//     findunion(arr,arr2);
//     cout<<"ones"<<"\n";
    //cout<<"Maximum consecutive ones are in array : "<<MaximumConsecutiveOnes(arr)<<"\n";
    cout<<findLongestSubarray(arr,7);
}