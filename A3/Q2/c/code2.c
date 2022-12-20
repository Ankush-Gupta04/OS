# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/shm.h>


#define SHMSZ     27

int main()
{
    int shmid;
    key_t key;
    char *shm, *s;

    key = 1234;
    shmid = shmget(key, SHMSZ, 0666)
    if (shmid) == -1) {
        perror("shmget");
        exit(1);
    }

    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    for (s = shm; *s != NULL; s++)
        putchar(*s);
    putchar('\n');

    *shm = '*';

    return 0;
}
