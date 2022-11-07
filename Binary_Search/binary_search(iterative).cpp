#include<bits/stdc++.h>
using namespace std;


int binarySearch(vector<int>& arr, int l, int r, int data){

    int ans = -1;
    while(l<=r)
    {
        int mid = l + (r-l)/2;   
        if(data == arr[mid]){
            ans = mid;
            break;
        }
        else if(data>arr[mid])
            l = mid+1;
        else
            r = mid-1;
    }

    return ans;
}

int main(){

     vector<int> arr = {4,8,16,22,34};
     int data = 98;
     int res = binarySearch(arr, 0, arr.size()-1, data);
     cout<<res<<endl;
}