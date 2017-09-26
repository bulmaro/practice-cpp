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

void makeSale(int);

using namespace std;
int inventory = 15;
/*
 * 
 */
int main(int argc, char** argv) {
    cout << "Global Before Items: " << inventory << "\n";

    // Make a sale
    makeSale(2);
    
    cout << "Global After Items: " << inventory << "\n";
    
    return 0;
}

void makeSale(int itemsToSell) {
    int available;
    do {
        cout << "Attempting to sell " << itemsToSell << " items\n";
        available = inventory;
        cout << "Before sale Items: " << available << "\n";
        available -= itemsToSell;
        cout << "Salesman x is making a sale of " << itemsToSell << " items\n";        
        inventory = available;
        cout << "After sale Items: " << available << "\n";
    } while (available >= itemsToSell);
    cout << "Done making sales\n";
}

