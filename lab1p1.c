//Cezar crypting

#include <stdio.h>

int main()
{
    char message[100];
    int i, key;

    printf("Enter a message to encrypt: ");
    scanf("%s", message);
    
    printf("Enter key: ");
    scanf("%d", &key);

    for(i = 0; message[i] != '\0'; i++)
    {
        if(message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = (message[i] - 'A' + key) % 26 + 'A';
        }
        else if(message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = (message[i] - 'a' + key) % 26 + 'a';
        }
    }

    printf("Encrypted message: %s", message);

    return 0;
}
