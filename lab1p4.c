//Afin decrypting

#include <stdio.h>

void condition(int k1, int k2, int *k3, int *k4)
{
    int flag;

    for(int i = 0; i < 26; i++)
    {
        flag = (k1 * i) % 26;
        
        if(flag == 1)
        {
            k1 = i;
            break;
        }
    }

    *k3 = k1;
    *k4 = k1 * k2 % 26;
}

int main()
{
    char message[100];
    int i, key, key2;
    int key3, key4;

    printf("Enter a message to decrypt: ");
    scanf("%s", message);
    
    printf("Enter key: ");
    scanf("%d", &key);
    printf("Enter key2: ");
    scanf("%d", &key2);

    condition(key, key2, &key3, &key4);

    printf("k3: %d\n", key3);
    printf("k4: %d\n", key4);

    for(i = 0; message[i] != '\0'; i++)
    {
        if(message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = (key3 * message[i] - 'A' - key4 + 26) % 26 + 'A';
        }
        else if(message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = (key3 * message[i] - 'a' - key4 + 26) % 26 + 'a';
        }
    }

    printf("Decrypted message: %s", message);

    return 0;
}