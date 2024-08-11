//#include <iostream>
//#include <thread>
//#include <semaphore>
//
//std::counting_semaphore<10> semaphore(3);
//
//void task(int id) {
//    semaphore.acquire();
//    std::cout << "Task " << id << " is running\n";
//    std::this_thread::sleep_for(std::chrono::seconds(1));  // Simulate work
//    std::cout << "Task " << id << " is done\n";
//    semaphore.release();
//}
//
//int main() {
//    std::thread threads[5];
//
//    for (int i = 0; i < 5; ++i) {
//        threads[i] = std::thread(task, i);
//    }
//
//    for (auto& th : threads) {
//        th.join();
//    }
//
//    return 0;
//}


#include <iostream>
#include <thread>
#include <semaphore>
#include <chrono>

std::binary_semaphore semaphore(1); // Initial count of 1

void task(int id) {
    std::cout << "Thread " << id << " trying to acquire semaphore\n";
    semaphore.acquire();  // Blocks if semaphore count is 0
    std::cout << "Thread " << id << " acquired semaphore\n";

    // Simulate some work
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "Thread " << id << " releasing semaphore\n";
    semaphore.release();  // Releases the semaphore
}

int main() {
    std::thread t1(task, 1);
    std::thread t2(task, 2);

    t1.join();
    t2.join();

    return 0;
}

