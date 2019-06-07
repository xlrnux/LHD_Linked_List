#include <iostream>
#include "LinkedList.h"
#include<list>
using namespace std;

LinkedList<int> List = LinkedList<int>();
list<int> l;
int main() {
    for(int i = 5; i < 10; i++){
        List.push_front(i);
    }

    for(int i = 5; i >= 1; i--){
        List.push_back(i);
    }

    iter it;
    for(it = List.begin(); it != List.end(); it = List.getNext(it)){
        cout << List.at(it) << "\n";
        if(List.at(it) == 3) break;
    }
    cout << "size: " << List.size() << "\n";
    List.erase(it);
    for(it = List.begin(); it != List.end(); it = List.getNext(it)){
        cout << List.at(it) << "\n";
        if(List.at(it) == 3) break;
    }
    cout << "size: " << List.size() << "\n";
    cout << "List front(): " << List.front() << "\n";
    cout << "List back(): " << List.back() << "\n";


    while(!List.empty()){
        List.pop_front();
    }
    cout << "size: " << List.size() << "\n";
    

    cout << "l front: " <<  *l.begin() << "\n";
    return 0;
}