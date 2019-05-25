//Program for readers writers problem.
//by Surya Prakash Reddy.
//Last Updated: 25-05-2019


#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>


sem_t readerAccess;
sem_t variableAccess;
int readerCount=0;
int sharedVariable=0;


void *Reader(void *args);
void *Writer(void *args);


int main()
{
int i=0,NumberofReaderThreads=0,NumberofWriterThreads;
sem_init(&readerAccess,0,1);
sem_init(&variableAccess,0,1);


pthread_t Readers_threads[100],Writers_threads[100];
printf("\nEnter the number of Readers threads (MAX 10):");
scanf("%d",&NumberofReaderThreads);
printf("\nEnter number of Writers thread(MAX 10):");
scanf("%d",&NumberofWriterThreads);


for(i=0;i<NumberofReaderThreads;i++)
{
pthread_create(&Readers_threads[i],NULL,Reader,(void *)i);
}


for(i=0;i<NumberofWriterThreads;i++)
{
pthread_create(&Writers_threads[i],NULL,Writer,(void *)i);
}


for(i=0;i<NumberofWriterThreads;i++)
{
pthread_join(Writers_threads[i],NULL);
}


for(i=0;i<NumberofReaderThreads;i++)
{
pthread_join(Readers_threads[i],NULL);
}


sem_destroy(&variableAccess);
sem_destroy(&readerAccess);


return 0;
}


void * Writer(void *arg)
{
Sleep(2);
int temp=(int)arg;
printf("\nWriter %d is trying to enter into database for modifying the data\n",temp);
sem_wait(&variableAccess);
printf("\nWriter %d is writting into the database\n Number of readers are %d\n",temp,readerCount);

int c = sharedVariable;
c = c+1;
sharedVariable = c;

printf("\nWriter %d is leaving the database\nValue written is %d\n",temp,sharedVariable);
sem_post(&variableAccess);
}


void *Reader(void *arg)
{
Sleep(2);
int temp=(int)arg;
printf("\nReader %d is trying to enter into the Database for reading the data\n",temp);
sem_wait(&readerAccess);
readerCount++;
if(readerCount==1)
{
sem_wait(&variableAccess);
}
sem_post(&readerAccess);

printf("\nReader %d is reading the Database. Value read is %d.\nNumber of readers are %d\n",temp,sharedVariable,readerCount);
Sleep(2);
sem_wait(&readerAccess);
readerCount--;
if(readerCount==0)
{
sem_post(&variableAccess);
}
printf("\nReader %d is leaving the database\n",temp);
sem_post(&readerAccess);
}
