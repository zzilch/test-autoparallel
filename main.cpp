#include <iostream>
#include <vector>
#include <chrono>

void main()
{
    int m;
    std::cin>>m;

    std::vector<int> A(m);
    std::chrono::steady_clock clock;

    auto start = clock.now();
#pragma loop(no_parallel)
    for (int i=0,n=m; i<n; ++i) {
        A[i] = A[i] + 1;
    }
    auto end = clock.now();
    std::cout<< "vec(default): "<< std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << "ms" << std::endl;

    start = clock.now();
#pragma loop(no_vector)
#pragma loop(no_parallel)
    for (int i=0,n=m; i<n; ++i) {
        A[i] = A[i] + 1;
    }
    end = clock.now();
    std::cout<< "serial: "<< std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << "ms" << std::endl;

    start = clock.now();
#pragma loop(hint_parallel(0))
    for (int i=0,n=m; i<n; ++i) {
        A[i] = A[i] + 1;
    }
    end = clock.now();
    std::cout<<"parallel&vec: "<< std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << "ms" << std::endl;
}