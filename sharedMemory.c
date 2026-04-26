#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    key_t key;
    int shmid;
    char *str;

    key = ftok("shmfile", 65);

    shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    str = (char*) shmat(shmid, NULL, 0);

    // Writing
    strcpy(str, "Hello Shared Memory");

    printf("Written to memory: %s\n", str);

    // Reading (same process demo)
    printf("Read from memory: %s\n", str);

    shmdt(str);

    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
