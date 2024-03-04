// Vigenere Cipher

#include <stdio.h>
#include <string.h>

int main()
{
    char message[100] = "AZI ESTE MIERCURI";
    char key[100] = "LUNI";

    int i, j, keyLength, messageLength;

    char newKey[100], encryptedMessage[100], decryptedMessage[100];

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

    keyLength = strlen(newKey);
    messageLength = strlen(message);

    for(i = 0; i < messageLength; i++)
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
        else
        {
            encryptedMessage[i] = ((message[i] + newKey[i]) % 26) + 'A';
        }
    }
    encryptedMessage[i] = '\0';

    printf("Encrypted message: %s\n", encryptedMessage);

    for(i = 0; i < messageLength; i++)
    {
        if(encryptedMessage[i] == ' ')
        {
            decryptedMessage[i] = ' ';
            continue;
        }
        else if(encryptedMessage[i] >= 'a' && encryptedMessage[i] <= 'z')
        {
            decryptedMessage[i] = (((encryptedMessage[i] - newKey[i]) + 26) % 26) + 'a';
        }
        else if(encryptedMessage[i] >= 'A' && encryptedMessage[i] <= 'Z')
        {
            decryptedMessage[i] = (((encryptedMessage[i] - newKey[i]) + 26) % 26) + 'A';
        }
    }
    decryptedMessage[i] = '\0';

    printf("Decrypted message: %s\n", decryptedMessage);

    return 0;
}