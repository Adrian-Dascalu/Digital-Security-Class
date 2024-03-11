// Vigenere Cipher

#include <stdio.h>
#include <string.h>

int main()
{
    //char message[100] = "AZI ESTE MIERCURI";
    //char key[100] = "LUNI";

    char message[100], key[100];

    printf("Enter the message: ");
    scanf("%[^\n]s", message);
    getchar();

    printf("Enter the key: ");
    scanf("%[^\n]s", key);
    getchar();

    int i, j;

    char newKey[100], encryptedMessage[100];

    j = 0;

    for(i = 0; message[i] != '\0'; i++)
    {

        if(key[j] == '\0')
        {
            j = 0;
        }

        if(message[i] == ' ')
        {
            newKey[i] = ' ';
            j--;
        }
        else
            newKey[i] = key[j];

        j++;
    }

    newKey[i] = '\0';

    //printf("%s\n", message);
    //printf("%s\n", newKey);

    for(i = 0; message[i] != '\0'; i++)
    {
        if(message[i] == ' ')
        {
            encryptedMessage[i] = ' ';
            continue;
        }
        else if(message[i] >= 'a' && message[i] <= 'z')
        {
            encryptedMessage[i] = ((message[i] + newKey[i]) % 26) + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z')
        {
            encryptedMessage[i] = ((message[i] + newKey[i]) % 26) + 'A';
        }
    }

    encryptedMessage[i] = '\0';

    printf("Encrypted message: %s\n", encryptedMessage);
    printf("New key: %s\n", newKey);

    return 0;
}