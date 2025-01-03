#include<bits/stdc++.h>
using namespace std;
void conquer(int a[],int l,int m,int h){
    int nL = m-l+1;
    int nR = h-m;
    int Left[nL],Right[nR];
    int i,j,k;
    for(i=0;i<=nL;i++){
        Left[i] = a[i+l];
    }
    for(i=0;i<=nR;i++){
        Right[i] = a[m+1+i];
    }
    i=j=0;
    k=l;
    while(i<nL && j<nR){
        if(Left[i]<Right[j]){
            a[k] = Left[i];
            i++;
        }
        else{
            a[k] = Right[j];
            j++;
        }
        k++;
    }
    while(i<nL){
        a[k] = Left[i];
        i++;
        k++;
    }
    while(j<nR){
        a[k] = Right[j];
        j++;
        k++;
    }

}
void divide(int a[],int l,int h){
    if(l<h){
        int m = (l+h)/2;
        divide(a,l,m);
        divide(a,m+1,h);
        conquer(a,l,m,h);
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
    divide(arr,0,n-1);
    cout<<"-----------After Sorting--------"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
