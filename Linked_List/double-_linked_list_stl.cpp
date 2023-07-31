#include<bits/stdc++.h>
using namespace std;


void printList(list<int>& l){
    list<int>::iterator it;
    for(it=l.begin();it!=l.end();it++)
        cout<<*it<<" ";
    cout<<endl;
}


int main(){

    //CREATION:
    //--------------------------------------------------------------------------

    list<int> list1;   //list of 0 length

    //INSERTION:
    // -------------------------------------------------------------------------
    list1.push_back(5);
    list1.push_back(7);
    list1.push_back(1);
    list1.push_back(9);
    list1.push_back(12);



    //ITERATORS:
    //-------------------------------------------------------------------------

    list<int> ::iterator it;    //points to elements of list
    it = list1.begin();        //it points to first element of list.


    /*
    cout<<*it;                 //prints element in the list to which it points to
    */

    cout<<"LIST 1: "<<endl;
    printList(list1);          //OUTPUT: 5 7 1 9 12



    //INSERTING AT A PARTICULAR POSITION:
    //-----------------------------------

    list<int> list2(7);   //empty list of size 7
    list<int> ::iterator it2;
    it = list2.begin();
    *it = 2;
    it++;
    *it=6;
    it++;
    *it=8;
    cout<<endl<<"LIST 2: "<<endl;
    printList(list2);      //output: 2 6 8 0 0 0 0


    //DELETING ELEMENTS FROM THE BACK:
    //---------------------------------

    /*Note: Deleting elements from the stack means removing the element along with deleting its memory as well.
     */
    list2.pop_back();
    cout<<endl<<"List 2 after deleting last element using pop_back: "<<endl;
    printList(list2);      //output: 2 6 8 0 0 0


    //DELETING ELEMENTS FROM FRONT:

    list2.pop_front();
    cout<<endl<<"List 2 after deleting first element using pop_front: "<<endl;
    printList(list2);     //output: 6 8 0 0 0

    //ADDING ELEMENT AT THE BEGINNING OF THE LIST:
    list2.push_front(6);
    list2.push_front(6);
    cout<<endl<<"List 2 after two times insertion of 6 to the front: "<<endl;
    printList(list2);      //output: 6 6 6 8 0 0 0

    //REMOVE ALL OCCURANCE OF A NUMBER FROM LIST:
    list2.remove(6);
    cout<<endl<<"List 2 after removal of all 6: "<<endl;
    printList(list2);     //Output: 8 0 0 0

    //SORTING THE LIST:
    list1.sort();
    cout<<endl<<"Sorted List 1:"<<endl;
    printList(list1);      //Output: 1 5 7 9 12

    //MERGING LISTS TOGETHER:
    cout<<endl<<"Merging List2 with List1"<<endl;
    list1.merge(list2);
    //merge function inserts the the list 2 at a position in list 1 where
    //the first element of list 2 is greater than the last element of list 1.
    printList(list1);



    //REVERSE A LIST:
    list1.reverse();
    cout<<endl<<"Reversed order of LIST 1"<<endl;
    printList(list1);

    return 0;
}