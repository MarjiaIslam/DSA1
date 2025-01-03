#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int a[],int n){
    int totalIt = 0,isSorted;
    for(int i=0;i<n;i++){
        ///isSorted=1;
        for(int j=0;j<n-i-1;j++){
                totalIt++;
            if(a[j]>a[j+1]){
                ///isSorted=0;
                swap(a[j],a[j+1]);
            }
        }
        ///if(isSorted==1){break;}
    }
    cout<<totalIt<<endl;
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
    bubbleSort(arr,n);
    cout<<"-----------After Sorting--------"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
