#include <iostream>
#include <thread>
#include <chrono>

// this function will be executed in the thread
void compute(int& xValue, int& yValue, int* result) {
    // wait 3 secs just to simulate complex things
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // simple computation
    *result = xValue * yValue;
}

int main() {
    // wait for user input
    int x, y, result;
    std::cout << "Enter value of x: ";
    std::cin >> x;
    std::cout << "Enter value of y: ";
    std::cin >> y;

    // Create a new thread to execute `compute` function
    /**
     * By using std::ref(), we can send argument variables to threads as references.
     * So threads can access and modify these argument variables without having to copy data.
    */
    std::thread t(compute, std::ref(x), std::ref(y), &result);

    /**
     * The code below can be executed even if the thread has not completed its task (compute function).
     * 
     * This is the asynchronous concept.
     * It means, threads run independently. So they don't block execution of the main program.
    */
    std::cout << "Computing..." << std::endl;

    // wait for the thread to complete its task (compute function).
    t.join();

    // print the result of a compute function on a thread
    std::cout << "Result of " << x << " * " << y << " is " << result << std::endl;

    return EXIT_SUCCESS;
}