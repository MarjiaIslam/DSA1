#include<bits/stdc++.h>
using namespace std;

int binarySearch(int a[],int n,int item){
   int LB = 0, UB = n-1, MID;
   while(LB<=UB){
        MID = (LB+UB)/2;
        if(a[MID]==item)
        {
            return MID;
        }
        else if(a[MID]<item){ /// RIGHT
            LB = MID + 1;
        }
        else{///LEFT
            UB = MID - 1;
        }
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
    int item;
    cin>>item;
    int res = binarySearch(arr,n,item);
    if(res==-1){
        cout<<item<<" isn't found"<<endl;
    }
    else{
        cout<<item<<" is found at index "<<res<<endl;
    }
    return 0;
}
