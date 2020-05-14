#include <pthread.h>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include <semaphore.h>
#include <string>
#include <ctime>

int bankAccount;// переменная представляющая счет в банке

pthread_t threadConsumer1;// 1 поток потребитель
pthread_t threadConsumer2;// 2 поток потребитель
pthread_t threadСontributor1;// 1 поток вкладичк
pthread_t threadСontributor2;// 2 поток вкладчик

sem_t semaphore;// семафор для блокирования потоков

void* removeMoney(void* args);// снятие денежных средств
void* addMoney(void* args);// пополнение денежных средств
void createThreads(); // создание потоков

void main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bankAccount = 1000;
    printf("Значение счета перед началом операций - %d\n", bankAccount);

    sem_init(&semaphore, 0, 1);
    srand(GetTickCount());
    createThreads();

    sem_destroy(&semaphore);
    printf("Значение счета после завершения операций - %d\n", bankAccount);
    _getch();
}

void createThreads()
{
    pthread_create(&threadConsumer1, NULL, removeMoney, (void*)("Поток-потребитель 1"));
    pthread_create(&threadConsumer2, NULL, removeMoney, (void*)("Поток-потребитель 2"));
    pthread_create(&threadСontributor1, NULL, addMoney, (void*)("Поток-вкладчик 1"));
    pthread_create(&threadСontributor2, NULL, addMoney, (void*)("Поток-вкладчик 2"));

    pthread_join(threadConsumer1, NULL);
    pthread_join(threadConsumer2, NULL);
    pthread_join(threadСontributor1, NULL);
    pthread_join(threadСontributor2, NULL);
}


void* removeMoney(void* args)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        sem_wait(&semaphore);
        const auto rand_value = rand() % 135 + 1;
        printf("\n------\n%s:Текущее значение счета - %d руб \n Снятие со счета - %d руб \n Итоговое значение счета после операции = %d \n------\n",
            static_cast<char*>(args), bankAccount, rand_value, bankAccount - rand_value);
        bankAccount -= rand_value;
        Sleep(60);
        sem_post(&semaphore);
    }
    return nullptr;
}

void* addMoney(void* args) {
    int i;
    for (i = 0; i < 10; i++) {
        sem_wait(&semaphore);
        const auto rand_value = rand() % 159 + 1;
        printf("\n------\n%s:Текущее значение счета - %d руб \n Пополнение со счета - %d руб \n Итоговое значение счета после операции = %d \n------\n",
            static_cast<char*>(args), bankAccount, rand_value, bankAccount + rand_value);
        bankAccount += rand_value;
        Sleep(60);
        sem_post(&semaphore);
    }
    return nullptr;
}