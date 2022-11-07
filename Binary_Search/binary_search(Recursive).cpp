#include<bits/stdc++.h>
using namespace std;


int binarySearch(vector<int>& arr, int l, int r, int data){

    if(l>r)
        return -1;

    int mid = l + (r-l)/2;
    if(arr[mid] == data)
        return mid;
    else if(data>arr[mid])
        return binarySearch(arr, mid+1, r, data);
    else
        return binarySearch(arr, l, mid-1, data);
}

int main(){

     vector<int> arr = {4,8,16,22,34};
     int data = 23;
     int res = binarySearch(arr, 0, arr.size()-1, data);
     cout<<res<<endl;
}