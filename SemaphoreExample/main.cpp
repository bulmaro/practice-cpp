/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: esteban
 *
 * Created on September 26, 2017, 7:49 PM
 */

#include <cstdlib>
#include <iostream>
#include <queue>
#include <thread>
#include <unistd.h>

void producer();
void consumer();

#define RAND(min,max) ((min) + (rand() % static_cast<int>((max) - (min) + 1)))
#define QSIZE 20

using namespace std;

queue<int> product;

/*
 * 
 */
int main(int argc, char** argv) {        
    // Start producer
    thread p(producer);

    // Start consumer
    thread c(consumer);
    
    // Wait for key, then terminate program
    cout << "Press enter key to terminate\n";
    getchar();

    return 0;
}

void producer() {
    // Produce eternally 
    while(1) {
        // Take time
        int waste = RAND(100000,500000);
        usleep(waste);
        
        // Produce and push to queue
        int item = RAND(1,10);
        // TODO: Insert the semaphore
        cout << "producing " << item << "\n";
        product.push(item);
        
        // Take time
        int work = RAND(100000,500000);
        usleep(work);        
    }
}

void consumer() {
    // Consume eternally 
    while(1) {
        // Take time
        int waste = RAND(100000,500000);
        usleep(waste);
        
        // Pop from queue and print it
        // TODO: Insert semaphore
        cout << "consuming " << product.front() << "\n";
        product.pop();
        
        // Take time
        int work = RAND(100000,500000);
        usleep(work);        
    }
}
