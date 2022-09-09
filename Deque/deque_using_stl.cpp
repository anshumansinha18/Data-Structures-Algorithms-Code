#include <bits/stdc++.h>
using namespace std;


int main() {

    deque<int> d;
    d.push_front(12);
    d.push_front(13);
    d.push_back(14);

    cout<<d.front()<<endl;
    cout<<d.back()<<endl;

    d.pop_front();
    d.pop_front();
    d.pop_back();

    if(d.empty())
        cout<<"Dequeu is empty";
    else
        cout<<"deque is not empty";

}
