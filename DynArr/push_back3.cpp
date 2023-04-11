#include <iostream>
#include "DynArr.cpp"
using namespace std;
#include <chrono>
#include <fstream>


int main()
{
    ofstream out("push_back3.txt");
    for (int ADD_NUMBER = 100; ADD_NUMBER <= 1000000; ADD_NUMBER += 100){
        out << ADD_NUMBER << '\t';
        
        DynArr darr3(1);
        auto begin = chrono::steady_clock::now();
        for(int i = 0 ; i<ADD_NUMBER;++i){
            darr3.push_back3(1);
        }
        auto end = chrono::steady_clock::now();
        auto time_span = chrono::duration_cast<chrono::microseconds>(end - begin);
        out << time_span.count() << '\n';
    }
}