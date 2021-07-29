#include <iostream>
#include <pthread.h>

#include <QCoreApplication>
#include <QTextStream>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* ShowThread(void* param) {
    int* i = static_cast<int*>(param);
    pthread_mutex_lock(&lock);

    std::cout<<"I am thread  " << *i<< std::endl;

    pthread_mutex_unlock(&lock);
    return nullptr;
}


int main()
{

    pthread_t tid[2] = {};
    pthread_attr_t attr = {};

    for(int i = 0; i < 2; ++i) {
        pthread_create(&tid[i], &attr, ShowThread, &i);

    }
    void* data;
    pthread_join(tid[0], &data);
    pthread_join(tid[1], &data);
}
