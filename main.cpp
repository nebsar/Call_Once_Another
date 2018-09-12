/* 
 * File:   main.cpp
 * Author: Eagleye
 *
 * Created on September 11, 2018, 11:38 PM
 */

/*
 Sometimes you want a function to be called only once no matter the number of threads that are used.
 * Imagine a function that has two parts.
 * The first part has to be called only once and the second has to be executed every time the function gets called.
 * We can use the std::call_once function to fix this problem very easily.
 * Here is an example using this mechanism:
 * 
 * Each std::call_once is matched to a std::once_flag variable. 
 * Here I put a closure to be executed only once, 
 * but a function pointer or a std::function will make the trick.
 * 
 * 
 */

#include <iostream>
#include <mutex>
#include <thread>

std::once_flag flag;

void do_something() {
    std::call_once(flag, []() {
        std::cout << "Called once" << std::endl;
    });

    std::cout << "Called each time" << std::endl;
}

int main() {
    std::thread t1(do_something);
    std::thread t2(do_something);
    std::thread t3(do_something);
    std::thread t4(do_something);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}




