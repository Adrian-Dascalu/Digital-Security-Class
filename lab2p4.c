// ADFGVX decryption

#include <stdio.h>
#include <string.h>

int main()
{
    char key[100] = {0}, encryptedMessage[100] = "GVGVGVGVGVGVGVGVGVGV XAXAXAXAXAXAXAXAXAXA GXGXGXGXGXGXGXGXGXGX VFVFVFVFVFVFVFVFVFVF", decryptedMessage[100] = {0};

    printf("Enter the key: ");
    scanf("%[^\n]s", key);

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

    char minc = 'Z' + 1;
    int mini[keyLength];

    char copy[keyLength];
    strcpy(copy, key);

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

    int counter = 0;
    int substitution[100][100] = {0};

    for(int i = 0; i < keyLength; i++)
    {
        for(int j = 0; encryptedMessage[counter] != ' ' && encryptedMessage[counter] != '\0'; j++)
        {
            substitution[j][mini[i]] = encryptedMessage[counter++];
        }
        counter++;
    }

    for(int i = 0; i < counter / keyLength - 1; i++)
    {
        for(int j = 0; j < keyLength; j++)
        {
            if(substitution[i][j] == '\0')
            {
                printf(" ");
            }

            printf("%c", substitution[i][j]);
        }
        
        printf("\n");
    }

    char temp[100] = {0};
    int tempCounter = 0;

    for(int i = 0; i < counter / keyLength - 1; i++)
    {
        for(int j = 0; j < keyLength; j++)
        {
            temp[tempCounter++] = substitution[i][j];
        }
    }

    char temp2[100] = {0};
    temp2[65] = 0;
    temp2[68] = 1;
    temp2[70] = 2;
    temp2[71] = 3;
    temp2[86] = 4;
    temp2[88] = 5;

    for(int i = 0, j = 0; i < tempCounter; i += 2, j++)
    {
        decryptedMessage[j] = table[temp2[temp[i]]][temp2[temp[i + 1]]];
    }

    printf("Decrypted message: %s\n", decryptedMessage);

    return 0;
}