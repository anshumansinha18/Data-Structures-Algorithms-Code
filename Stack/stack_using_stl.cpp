#include <bits/stdc++.h>
using namespace std;


int main() {

    stack<int> s;
    s.push(2);
    s.push(3);
    s.pop();

    if(s.empty())
        cout<<"Stack Empty";
    else
        cout<<s.top();
    
}
