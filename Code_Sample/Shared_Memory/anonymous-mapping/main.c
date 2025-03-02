#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    /* code */
    pid_t child_pid;
    
    /**
     * MAP_SHARED : child process will share value after action with parent process
     */
    // char *data = mmap(0, 1, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    /**
     * MAP_PRIVATE : The child process will use a value distinct from the parent process.
     */
    char *data = mmap(0, 1, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);


    if (data == MAP_FAILED)
    {
        printf("%s: mmap failed\n", __FILE__);
    }
    *data = 65;

    child_pid = fork();

    if (child_pid < 0)
    {
        printf("Fork() unsuccessfully\n");
        exit(EXIT_FAILURE);
    }

    if (0 == child_pid) // chuld_process
    {
        printf("Child started, value = %c\n", ++(*data));
        if (munmap(data, sizeof(int)) == -1)
        {
            printf("munmap fail\n");
        }
        exit(EXIT_SUCCESS);
    }
    else // Parent process
    {
        wait(NULL);
        printf("In parent, value = %c\n", *data);
        if (munmap(data, sizeof(int)) == -1)
        {
            printf("munmap fail\n");
        }
        exit(EXIT_SUCCESS);
    }

    return 0;
}
