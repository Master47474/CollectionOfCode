#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// function to call on thread
void *myThreadFunc(void *vargp){
  sleep(1);
  printf("SUP THis is a thread LMAO \n");
  return NULL;
}



int main(){
  pthread_t thread_id;
  printf("Before Thread ---- \n");
  pthread_create(&thread_id, NULL, myThreadFunc, NULL);
  pthread_join(thread_id, NULL);
  printf("After Thread\n" );

  return 0;
}
