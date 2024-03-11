//Vigenere Decipher

#include <stdio.h>
#include <string.h>

int main()
{
    char key[100], encryptedMessage[100], decryptedMessage[100];
    int i;

    printf("Enter the message: ");
    scanf("%[^\n]s", encryptedMessage);
    getchar();

    printf("Enter the key: ");
    scanf("%[^\n]s", key);
    getchar();

    for(i = 0; encryptedMessage[i] != '\0'; i++)
    {
        if(encryptedMessage[i] == ' ')
        {
            decryptedMessage[i] = ' ';
        }
        else if(encryptedMessage[i] >= 'a' && encryptedMessage[i] <= 'z')
        {
            decryptedMessage[i] = (((encryptedMessage[i] - key[i]) + 26) % 26) + 'a';
        }
        else if(encryptedMessage[i] >= 'A' && encryptedMessage[i] <= 'Z')
        {
            decryptedMessage[i] = (((encryptedMessage[i] - key[i]) + 26) % 26) + 'A';
        }
    }

    decryptedMessage[i] = '\0';

    printf("Decrypted message: %s\n", decryptedMessage);
}