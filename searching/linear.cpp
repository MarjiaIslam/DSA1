#include<bits/stdc++.h>
using namespace std;

int linearSearch(int a[],int n,int item){
    for(int i=0;i<n;i++){
        if(a[i]==item)
            return i;
    }

    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    int item;
    cin>>item;
    int res = linearSearch(arr,n,item);
    if(res==-1){
        cout<<item<<" isn't found"<<endl;
    }
    else{
        cout<<item<<" is found at index "<<res<<endl;
    }
    return 0;
}
