// ADFGVX cipher

#include <stdio.h>
#include <string.h>

int main()
{
    char message[100] = {0}, key[100] = {0}, encryptedMessage[100] = {0};

    printf("Enter the message: ");
    scanf("%[^\n]s", message);
    getchar();

    printf("Enter the key: ");
    scanf("%[^\n]s", key);
    getchar();

    int keyLength = strlen(key);

    char table[6][6] = {
        {'K', 'Z', 'W', 'R', '1', 'F'},
        {'9', 'B', '6', 'C', 'L', '5'},
        {'Q', '7', 'J', 'P', 'G', 'X'},
        {'E', 'V', 'Y', '3', 'A', 'N'},
        {'8', 'O', 'D', 'H', '0', '2'},
        {'U', '4', 'I', 'S', 'T', 'M'}
    };

    char adfgvx[6] = {'A', 'D', 'F', 'G', 'V', 'X'};

    char substitution[100][100] = {0};

    int counter = 0;

    for(int i = 0; message[i] != '\0'; i++)
    {
        for(int j = 0; j < 6 || substitution[counter / keyLength][counter % keyLength] != '\0' ; j++)
        {
            for(int k = 0; k < 6; k++)
            {
                if(message[i] == table[j][k])
                {
                    substitution[counter / keyLength][counter++ % keyLength] = adfgvx[j];
                    substitution[counter / keyLength][counter++ % keyLength] = adfgvx[k];
                    
                    break;
                }        
            }
        }
    }

    substitution[counter / keyLength][counter % keyLength] = '\0';

    int j = 0;

    for(int i = 0; i < counter / keyLength + 1; i++)
    {
        for(j = 0; j < keyLength; j++)
        {
            if(substitution[i][j] == '\0')
            {
                break;
            }

            printf("%c", substitution[i][j]);
        }
        
        printf("\n");
    }

    char copy[keyLength];

    strcpy(copy, key);

    char minc = 'Z' + 1;
    int mini[keyLength];

    for(int i = 0; i < keyLength; i++)
    {
        for(int k = 0; k < keyLength; k++)
        {
            if(copy[k] < minc)
            {
                minc = copy[k];
                mini[i] = k;
            }
        }

        minc = 'Z' + 1;
        copy[mini[i]] = 'Z' + 1;
    }

    for(int i = 0; i < keyLength; i++)
    {
        for(int j = 0; substitution[j][mini[i]] != '\0'; j++)
        {
            printf("%c", substitution[j][mini[i]]);  
        }

        printf(" ");

        copy[i] = 'Z' + 1;
        minc = 'Z';
    }
}