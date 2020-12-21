//
// Created by dream on 2020/12/20.
//

#include <iostream>
#include <map>
using namespace std;

int main(){

    map<int, string> myMap;
    myMap.insert({2, "this is 2"});
    myMap.insert({3, "this is 3"});
    myMap.insert({1, "this is 1"});
    myMap.insert({6, "this is 6"});
    myMap.insert({9, "this is 9"});
    myMap.insert({7, "this is 7"});
    myMap.insert({8, "this is 8"});

    cout << myMap[6] << endl;

    myMap[6] = "this is 66";

    cout << myMap[6] << endl;

    myMap.erase(6);

    cout << myMap[6] << endl;

    cout << "first key: " << myMap.
    return 0;

}