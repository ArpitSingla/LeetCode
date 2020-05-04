#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int min=*max_element(arr,arr+n);
    int total=accumulate(arr,arr+n,0);
    while(min<=total){
        int mid=min+(total-min)/2;
        int curr_time=0;
        int person=1;
        for(int i=0;i<n;i++){
            if(curr_time+arr[i]>mid){
                person++;
                curr_time=0;
            }
            curr_time+=arr[i];
        }
        if(person>k){
            min=mid+1;
        }
        else{
            total=mid-1;
        }
    }
    cout<<min<<endl;
}