#include<bits/stdc++.h>
using namespace std;

int main(){
    string brackets;
    vector<char> stck;
    cin>>brackets;
    for(char ch:brackets){
        if(ch=='('||ch=='{'||ch=='['){
            stck.push_back(ch);
        }
        else{
            char top = stck.back();
            if(top=='(' && ch==')'){
                stck.pop_back();
            }
            else if(top=='{' && ch=='}'){
                stck.pop_back();
            }
            else if(top=='[' && ch==']'){
                stck.pop_back();
            }
            else{
                cout<<"INVALID"<<endl;
                break;
            }
        }
    }
    if(stck.empty()){
        cout<<"VALID"<<endl;
    }

    return 0;
}
