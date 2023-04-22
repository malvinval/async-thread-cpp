## C++ Thread

Thread refers to an execution flow that is independent of the main execution flow or main program. By using threads, programs can execute multiple tasks simultaneously. Each thread runs in parallel and can perform different tasks at the same time.


Threads can be created using a standard C++11 library and above, such as ```std::thread```. Threads can be used to execute functions, class methods, and blocks of code asynchronously, so they don't affect the main program execution flow.

> Simple multithreading example: [simple_multithreading.cpp](https://github.com/malvinval/async-thread-cpp/blob/master/simple_multithreading.cpp)

## ```std::future<result_type>```
- ```std::future``` is a class template in the C++ Standard Library.
- It represents a "future" result of an asynchronous operation.
- It is used to retrieve the result of a function that has been executed asynchronously.

## ```std::async()```
- ```std::async()``` is a C++ Standard Library function that allows you to launch a function asynchronously in a separate thread.
- ```std::launch::async``` is a policy that can be used optionally as the first argument of ```std::async()``` to specify the function passed to it should be executed asynchronously.

> Asynchronous multithreading example: [async_future.cpp](https://github.com/malvinval/async-thread-cpp/blob/master/async_future.cpp)