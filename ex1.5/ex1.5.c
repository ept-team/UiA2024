
#include <stdio.h>
#include <stdlib.h>
#pragma GCC diagnostic ignored "-Wstringop-overflow="
void ignore_me_init_buffering( void ) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}


void win( void ) {
    system("/bin/sh");
}

int main()
{
    char buffer[16];
    int my_number = 0x5117;
    ignore_me_init_buffering();
    printf("The value of 'my_number' is: 0x%x. See if you can set it to 0x%x?\n>> ", my_number, 0xa313742);
    while(my_number != 0xa313742) {
        fflush(stdin);
        fgets(buffer, 50, stdin);
        if (my_number == 0xa313742)
        {
            printf("Value of 'my_number' is now: 0x%x. Well done!\n", my_number);
            system("id");
            system("/bin/sh");  
        }
        else
        {
            printf("Incorrect. The value of 'my_number' is : 0x%x. Set it to 0x%x to pop a shell!\n>>", my_number,0xa313742);
        }
    }
    return 0;
}