#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<sys/shm.h>
#define SHM_KEY 1234
#define SHM_SIZE 1024
int main()
{
      int shmid = shmget(SHM_KEY , SHM_SIZE , 0666);
      if(shmid == -1)
      {
          perror("shmget");
          exit(1);
      } 
      
      char* shm = shmat(shmid , NULL , 0);
      if(shm == (char *)-1)
      {
             perror("shmat");
             exit(1);
      }
      
      printf("Message from Server %s\n" , shm);
      
      shmdt(shm);
      
      return 0;
}

