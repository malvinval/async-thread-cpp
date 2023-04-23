## ```std::future<result_type>```
- ```std::future``` is a class template in the C++ Standard Library.
- It represents a "future" result of an asynchronous operation.
- It is used to retrieve the result of a function that has been executed asynchronously.

## ```std::async()```
- ```std::async()``` is a C++ Standard Library function that allows you to launch a function asynchronously in a separate thread.
- ```std::launch::async``` is a policy that can be used optionally as the first argument of ```std::async()``` to specify the function passed to it should be executed asynchronously.

## Important note

```std::async()``` always returns a ```std::future ``` object that represents the result of the asynchronous task. Therefore, you cannot use ```std::async()``` without a future.