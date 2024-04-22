//DES decryption

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pff(char message[], int (*pf)[8])
{
    char temp[8] = {0};

    for(int i = 0; i < 8; i++)
    {
        temp[i] = message[(*pf)[i] - 1];
    }

    for(int i = 0; i < 8; i++)
    {
        message[i] = temp[i];
    }
}

int main()
{
    int pf[8] = {4, 1, 3, 5, 7, 2, 8, 6};
    int (*pfp)[8] = &pf;

    char message[8] = {0};

    printf("Message: ");
    for(int i = 0; i < 8; i++)
    {
        message[i] = getchar();
    }

    pff(message, pfp);

    printf("Message after permutation: ");
    for(int i = 0; i < 8; i++)
    {
        printf("%c", message[i]);
    }
    printf("\n");

    

    return 0;
}
