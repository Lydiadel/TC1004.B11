#include <stdio.h>
#include <unistd.h>

int main(){
    int a = 5;
    int pid = fork();
    if (pid == 0){
        printf("Process son : pid = %d \n", pid);
    }
    else {
        printf("Process son: pid = %d \n", pid);
    }
    return 0;
}