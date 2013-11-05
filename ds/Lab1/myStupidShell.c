#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int makeargv(const char *s, const char *delimiters, char ***argvp);

int main (int argc, char *argv[]) {
  char delimiters[] = " \t";
  int i;
  char **myargv;
  int numtokens;
  pid_t pid;

  if(argc != 2) {
    fprintf(stderr, "Usage: %s string\n", argv[0]);
    return 1;
  }

  if((numtokens = makeargv(argv[1], delimiters, &myargv)) == -1) {
    fprintf(stderr, "Couldn't construct arg array for %s\n", argv[1]);
    return 1;
  }

  printf("\n----List of arguments---- \n");
  for(i=0; i<numtokens; i++)
    if (i == 0)
      printf("%d arg (command): %s\n", i, myargv[i]);
    else
      printf("%d arg: %s\n", i, myargv[i]);
  
  printf("\n----Now let's look at some pids----\n");
  pid = fork();
  
  if(pid == 0) {
    printf("You're in the child, pid: %u\n", getpid());
    printf("\n----Finally, let's execute that command----\n");
    printf("Exec the %s process image from the 0th arg\n", myargv[0]);
    execve(myargv[0], myargv, NULL);
    exit(EXIT_FAILURE);
  }else {
    printf("You're in the parent, pid: %u and the child pid is %u\n", getpid(), pid);
    exit(EXIT_FAILURE);
  }
  return 0;
}
