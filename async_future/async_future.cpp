#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <unordered_map>

std::unordered_map<std::thread::id, int> multiply(int& x, int& y) {
    // 3 secs sleep to simulate complex task
    std::this_thread::sleep_for(std::chrono::seconds(3));
    
    // an unordered map holds thread id (as key) and result (as value) of computation
    std::unordered_map<std::thread::id, int> result {{ // notice: braced assignment.
        {std::this_thread::get_id(), x * y}
    }};

    return result;
}

int main() {
    int x {150}, y {3};

    /**
     * std::future is a class template in the C++ Standard Library.
     * It represents a "future" result of an asynchronous operation.
     * It is used to retrieve the result of a function that has been executed asynchronously,
    */

    /**
     * std::launch::async is a policy that can be used with std::async function to specify how the function passed to it should be executed.
     * 
     * When launch::async is used, the function will be executed asynchronously in a new thread,
     * meaning it will run concurrently with the calling thread.
     * 
     * In this case, multiply function will be executed in separated thread asynchronously.
    */
    std::future<std::unordered_map<std::thread::id, int>> result { // notice: braced assignment to result variable.
        std::async(std::launch::async, multiply, std::ref(x), std::ref(y))
    };

    /**
     * Do some other work while thread is running.
     * Here you can see the asynchronous effect.
    */
    std::cout << "Working on it..." << std::endl;

    // Iterate over the keys and value in the unordered map using std::pair<type, type>
    for (std::pair<std::thread::id, int> map : result.get()) {
        std::cout << "Thread " << map.first << " finished! Result: " << x << " * " << y << " = " << map.second << std::endl;
    }

    return EXIT_SUCCESS;
}