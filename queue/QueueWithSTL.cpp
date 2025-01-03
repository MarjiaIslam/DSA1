#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<char> Q;
    Q.push('a');/// enqueue
    Q.push('b');
    Q.push('d');
    cout<<Q.front()<<endl;
    Q.pop();///dequeue
    cout<<Q.front()<<endl;
    Q.push('k');

    while(!Q.empty()){
        cout<<Q.front()<<" ";
        Q.pop();
    }
    return 0;
}
