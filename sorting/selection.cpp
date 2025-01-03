#include<bits/stdc++.h>
using namespace std;

void selectionSort(int a[],int n){
    int minIdx;
    for(int i=0;i<n;i++){
        minIdx = i;
        for(int j=i+1;j<n;j++){
            if(a[j]>a[minIdx]){
                minIdx = j;
            }
        }
        swap(a[i],a[minIdx]);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"-----------Before Sorting--------"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    selectionSort(arr,n);
    cout<<"-----------After Sorting--------"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
