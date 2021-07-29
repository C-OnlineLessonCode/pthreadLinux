#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;
// Declaration of thread condition variable
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

// declaring mutex
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
void* tfunc(void* param) {
pthread_cond_wait(&cond, &lock);
std::cout << "I'm thread " <<std::endl;
pthread_mutex_unlock(&lock);
return nullptr;
}

int main() {
pthread_t tid[2] = {};
pthread_attr_t attr = {};
pthread_attr_init(&attr);
int param2 = 2;
pthread_mutex_lock(&lock);
pthread_create(&tid[0], &attr, tfunc, &param2);
pthread_create(&tid[1], &attr, tfunc, &param2);
sleep(5);
pthread_cond_broadcast(&cond);
void* data;
pthread_join(tid[0], &data);
pthread_join(tid[1], &data);
return 0;
}
