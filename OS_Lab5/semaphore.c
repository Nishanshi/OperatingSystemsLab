#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


// for sleep
#include <unistd.h>

#define BUFF_SIZE   5           /* total number of slots */
#define No_Producer          3           /* total number of producers */
#define No_Consumer          3           /* total number of consumers */
#define NITERS      4           /* number of items produced/consumed */

typedef struct
{
    int buf[BUFF_SIZE];   /* shared var */
    int in;               /* buf[in%BUFF_SIZE] is the first empty slot */
    int out;              /* buf[out%BUFF_SIZE] is the first full slot */
    sem_t full;           /* keep track of the number of full spots */
    sem_t empty;          /* keep track of the number of empty spots */

    // use correct type here
    pthread_mutex_t mutex;          /* enforce mutual exclusion to shared data */
} buffer;

buffer shared;


void *Producer(void *arg)
{
    int i, item, index;

    index = (int)arg;


    for (i=0; i < NITERS; i++)
    {

        /* Produce item */
        item = i;

        /* Prepare to write item to buf */

        /* If there are no empty slots, wait */
        sem_wait(&shared.empty);
        /* If another thread uses the buffer, wait */
        
        shared.buf[shared.in] = item;
        shared.in = (shared.in+1)%BUFF_SIZE;
        printf("[P%d] Producing %d ...\n", index, item);    
    }
    return NULL;
}

void *Consumer(void *arg)
{
    int i, item, index;

    index = (int)arg;
    for (i=NITERS; i > 0; i--) {
        sem_wait(&shared.full);
        
        item=i;
        item=shared.buf[shared.out];
        shared.out = (shared.out+1)%BUFF_SIZE;
        printf("[C%d] Consuming  %d ...\n", index, item);
        fflush(stdout);
        /* Release the buffer */
      
    }
    return NULL;
}


