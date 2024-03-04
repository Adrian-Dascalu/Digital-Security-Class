//Afin crypting

#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    char message[100], ch;
    int i, key, key2;

    printf("Enter a message to encrypt: ");
    scanf("%s", message);
    
    printf("Enter key: ");
    scanf("%d", &key);
    printf("Enter key2: ");
    scanf("%d", &key2);

    if(gcd(key, 26) != 1)
    {
        printf("Key is not valid");
        return 0;
    }
    else
    {
        for(i = 0; message[i] != '\0'; i++)
        {
            if(message[i] >= 'A' && message[i] <= 'Z')
            {
                message[i] = (key * message[i] - 'A' + key2) % 26 + 'A';
            }
            else if(message[i] >= 'a' && message[i] <= 'z')
            {
                message[i] = (key * message[i] - 'a' + key2) % 26 + 'a';
            }
        }
    }

    printf("Encrypted message: %s", message);

    return 0;
}