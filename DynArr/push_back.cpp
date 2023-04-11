#include <iostream>
#include "DynArr.cpp"
using namespace std;
#include <chrono>
#include <fstream>


int main()
{
    ofstream out("data.txt");
    for (int ADD_NUMBER = 100; ADD_NUMBER <= 20000; ADD_NUMBER += 100){
        out << ADD_NUMBER << '\t';
        DynArr darr1(1);
        auto begin = chrono::steady_clock::now();
        for(int i = 0 ; i<ADD_NUMBER;++i){
            darr1.push_back1(1);
        }
        auto end = chrono::steady_clock::now();
        auto time_span = chrono::duration_cast<chrono::milliseconds>(end - begin);
        out << time_span.count() << '\t';

        DynArr darr2(1);
        begin = chrono::steady_clock::now();
        for(int i = 0 ; i<ADD_NUMBER;++i){
            darr2.push_back2(1);
        }
        end = chrono::steady_clock::now();
        time_span = chrono::duration_cast<chrono::milliseconds>(end - begin);
        out << time_span.count() << '\t';

        DynArr darr3(1);
        begin = chrono::steady_clock::now();
        for(int i = 0 ; i<ADD_NUMBER;++i){
            darr3.push_back3(1);
        }
        end = chrono::steady_clock::now();
        time_span = chrono::duration_cast<chrono::milliseconds>(end - begin);
        out << time_span.count() << '\n';
    }
}