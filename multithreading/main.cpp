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

#include <cstdlib>
#include <iostream>
#include <thread>
#include <unistd.h>

void makeSale(int);

using namespace std;
int inventory = 15;
const int min_wait = 500000;
const int max_wait = 2000000;

/*
 * 
 */
int main(int argc, char** argv) {
    cout << "Global Before Items: " << inventory << "\n";

    // Make a sale
    thread t1(makeSale, 2);    
    t1.join();
    
    cout << "Global After Items: " << inventory << "\n";
    
    return 0;
}

void makeSale(int itemsToSell) {
    int available;
    int timeToWait;
    std::thread::id this_id = std::this_thread::get_id();
    do {
        timeToWait = min_wait + (rand() % static_cast<int>(max_wait - min_wait + 1));
        
        cout << "(" << this_id << ") " << "Attempting to sell " << itemsToSell << " items\n";
        available = inventory;
        cout << "(" << this_id << ") " << "Before sale Items: " << available << "\n";
        available -= itemsToSell;
        cout << "(" << this_id << ") " << "Waiting " << timeToWait << " micro seconds\n";
        usleep(timeToWait);
        cout << "(" << this_id << ") " << "Salesman x is making a sale of " << itemsToSell << " items\n";        
        inventory = available;
        cout << "(" << this_id << ") " << "After sale Items: " << available << "\n";
    } while (available >= itemsToSell);
    cout << "(" << this_id << ") " << "Done making sales\n";
}

