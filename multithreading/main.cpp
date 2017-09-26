/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: esteban
 *
 * Created on September 25, 2017, 8:03 PM
 */

// TODO: Give unique seeds to each thread.
// TODO: Write tests!
// TODO: Scale?
// TODO: WHAT ELSE TO DO???

#include <cstdlib>
#include <iostream>
#include <thread>
#include <unistd.h>

void makeSale(int);

using namespace std;
int inventory = 15;
const int min_wait = 50000;
const int max_wait = 200000;
mutex m;

/*
 * 
 */
int main(int argc, char** argv) {
    cout << "Global Before Items: " << inventory << "\n";

    // Make a sale
    thread t1(makeSale, 1);
    thread t2(makeSale, 1);
    thread t3(makeSale, 1);
    t1.join();
    t2.join();
    t3.join();
    
    cout << "Global After Items: " << inventory << "\n";
    
    return 0;
}

void makeSale(int itemsToSell) {
    int available;
    int timeToWait;
    int soldItemsHere=0;
    std::thread::id this_id = std::this_thread::get_id();
    do {
        timeToWait = min_wait + (rand() % static_cast<int>(max_wait - min_wait + 1));

        m.lock();        
        
        cout << "(" << this_id << ") " << "Attempting to sell " << itemsToSell << " items\n";
        available = inventory;
        if (available >= itemsToSell) {
            cout << "(" << this_id << ") " << "Before sale Items: " << available << "\n";
            available -= itemsToSell;
            soldItemsHere += itemsToSell;
            cout << "(" << this_id << ") " << "Waiting " << timeToWait << " micro seconds\n";
            usleep(timeToWait);
            cout << "(" << this_id << ") " << "Making a sale of " << itemsToSell << " items\n";        
            inventory = available;        
            cout << "(" << this_id << ") " << "After sale Items: " << available << "\n\n";
        }
        else {
            m.unlock();
            break;
        }
        m.unlock();        
    } while (1);
    cout << "(" << this_id << ") " << "**** Done selling " << soldItemsHere << " items\n";
}
