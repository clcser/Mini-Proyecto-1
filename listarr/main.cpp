#include <iostream>
#include <chrono>
#include <math.h>
#include <time.h>
#include "ListArr.h"

long long b = 1024;
long long n = pow(2,14);

using namespace std;

int main() {
    srand(time(NULL));
    double avgTime;
    double duration;

    cout << "20 repeticiones de " << n << " casos, con b = " << b << endl << endl;
    
    //crear ListArr
    ListArr* la = new ListArr(b);
    
    avgTime = 0;
    duration = 0;
    //medir tiempo insert left
    for(int j = 0; j<20; j++) {
        //delete la;
        la = new ListArr(b);

        for(int i = 0; i < n; i++) {
            auto start = chrono::high_resolution_clock::now();

            la->insert_left(i);
        
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> diff = end - start;
            duration = diff.count();
            avgTime += duration;
        }
        //cout << "Tiempo " << j+1 << ": " << avgTime/(n) << endl;
    }
    cout << "Tiempo promedio insert-left: " << avgTime/(n*20) << endl;
    

    //medir tiempo insert right
    avgTime = 0;
    duration = 0;

    for(int j = 0; j<20; j++) {
        la = new ListArr(b);

        for(int i = 0; i*i < n; i++) {
            auto start = chrono::high_resolution_clock::now();

            la->insert_right(i);  

            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> diff = end - start;
            duration = diff.count();
            avgTime += duration;
        }
        //cout << "Tiempo " << j+1 << ": " << avgTime/(n) << endl;
    }
    cout << "Tiempo promedio insert-right: " << avgTime/(n*20) << endl;

    avgTime = 0;
    duration = 0;
    //medir tiempo find
    for(int j = 0; j<20; j++) {
        for(int i = 0; i < n; i++) {
            auto start = chrono::high_resolution_clock::now();
            
            la->find(i);

            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> diff = end - start;
            duration = diff.count();
            avgTime += duration;
        }
        //cout << "Tiempo " << j+1 << ": " << avgTime/(n) << endl;
    }
    cout << "Tiempo promedio find: " << avgTime/(n*20) << endl;

    //la->print();
    cout << endl;
    cout << "Size: " << la->size() << endl;

    return 0;
}