#include <cstddef>
#include <pthread.h>

#include "blank.h"

    pthread_t threadСonsumer1;
    pthread_t thread2;
    pthread_t thread3;
    pthread_t thread4;
    void CreateTreads()
    {
        pthread_create(&threadСonsumer1, NULL, removeMoney, (void*)("Поток-потребитель 1"));
        pthread_create(&thread3, NULL, removeMoney, (void*)("Поток-потребитель 2"));
        pthread_create(&thread2, NULL, addMoney, (void*)("Поток-вкладчик 1"));
        pthread_create(&thread4, NULL, addMoney, (void*)("Поток-вкладчик 2"));

        pthread_join(threadСonsumer1, NULL);
        pthread_join(thread2, NULL);
        pthread_join(thread3, NULL);
        pthread_join(thread4, NULL);
    }
#pragma once
