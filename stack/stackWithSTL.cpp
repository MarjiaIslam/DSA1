#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<int> stck;
    /// push
    stck.push_back(10);
    stck.push_back(5);
    stck.push_back(7);
    stck.push_back(13);
    cout<<stck.back()<<endl;
    stck.pop_back();
    cout<<stck.back()<<endl;
    cout<<stck.empty()<<endl;
    return 0;
}
