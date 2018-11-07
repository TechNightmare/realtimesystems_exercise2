#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void usage(void){
    printf("Usage:\n./zombie [Number of Zombies]\n");
    printf("./zombie -1 <- Raises the Undead-Army!\n");
}

int main(int argc, char *argv[]){

    if(argc != 2) usage();
    else{
        int zombies = atoi(argv[1]);
        //Erzeugung der Zombie Kinder
        if(zombies >= 0){
            int pid;
            for(int i = 0; i < zombies; i++){
                pid = fork();
                if(pid == 0){
                    exit(0);
                }
            }
            pause();
        //Endlose Zombie Horden!
        }else{
            int pid;
            while(1){
                pid = fork();
                if(pid == 0){
                    exit(0);
                }else if(pid == -1) break;
            }
            printf("Alle PIDs sind voll!\n");
            pause();
        }
    }
    return 0;
}