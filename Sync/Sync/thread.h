#include <cstddef>
#include <pthread.h>

#include "blank.h"

    pthread_t thread�onsumer1;
    pthread_t thread2;
    pthread_t thread3;
    pthread_t thread4;
    void CreateTreads()
    {
        pthread_create(&thread�onsumer1, NULL, removeMoney, (void*)("�����-����������� 1"));
        pthread_create(&thread3, NULL, removeMoney, (void*)("�����-����������� 2"));
        pthread_create(&thread2, NULL, addMoney, (void*)("�����-�������� 1"));
        pthread_create(&thread4, NULL, addMoney, (void*)("�����-�������� 2"));

        pthread_join(thread�onsumer1, NULL);
        pthread_join(thread2, NULL);
        pthread_join(thread3, NULL);
        pthread_join(thread4, NULL);
    }
#pragma once
