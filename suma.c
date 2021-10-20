#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 10000
int saldo;

pthread_mutex_t saldoLock = PTHREAD_MUTEX_INITIALIZER; //Locks are used to make sure each thread runs one at a time.

void * suma100(void *arg){
    pthread_mutex_lock(&saldoLock);
    int lsaldo = saldo;
    lsaldo += 100;
    saldo = lsaldo;
    pthread_mutex_unlock(&saldoLock);

    pthread_exit(NULL); //Here each thread notifies that it has ended
}

int main(){
    saldo = 0;

    pthread_t threads[NUM_THREADS];
    for(int i = 0; i < NUM_THREADS; i++){
        pthread_create(&threads[i], NULL, suma100, NULL);
    }
    for(int i =0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }
    
    printf("Saldo final es de %d\n", saldo);
    pthread_exit(NULL); //Here, main() waits for each thread to be ended before returning 0.
}