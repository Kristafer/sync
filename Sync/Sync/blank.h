#include <cstdio>
#include <semaphore.h>
#include <string>
#include <ctime>
sem_t semaphore;
int bankAccount;
int countIteration;
int countSemaphoreBlockers;
void initBank()
{
    bankAccount = 1000;
    countIteration = 10;
    countSemaphoreBlockers = 1;
    sem_init(&semaphore, 0, countSemaphoreBlockers);
    std::srand(time(NULL));
}


void* removeMoney(void* args)
{
    int i;
    for (i = 0; i < countIteration; i++)
    {
        sem_wait(&semaphore);
        auto randValue = std::rand() % 100 + 1;
        printf("\n------\n%s:Текущее значение счета - %d руб \n Снятие со счета - %d руб \n Итоговое значение счета после операции = %d \n------\n", static_cast<char*>(args), bankAccount, randValue, bankAccount - randValue);
        bankAccount -= randValue;
        sem_post(&semaphore);
    }
    return nullptr;
}

void* addMoney(void* args) {
    int i;
    for (i = 0; i < countIteration; i++) {
        sem_wait(&semaphore);
        auto randValue = std::rand() % 100 + 1;
        printf("\n------\n%s:Текущее значение счета - %d руб \n Пополнение со счета - %d руб \n Итоговое значение счета после операции = %d \n------\n", static_cast<char*>(args), bankAccount, randValue, bankAccount - randValue);
        bankAccount += randValue;
        sem_post(&semaphore);
    }
    return nullptr;
}
