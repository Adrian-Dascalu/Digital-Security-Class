#include <stdio.h>
#include <string.h>

int main()
{
    char message[100] = "HJLZAH LZAL BU LELTWSB KL BAPSPGHYL H BUBP JPMYB TVUVHSMHILAPJ JB ZBIZAPABAPL JPMYBS SBP JLGHY";
    int i, key;

    char ch[100];

    for(int j = 0; j < 26; j++)
    {
        key = j;

        strcpy(ch, message);

        for(i = 0; message[i] != '\0'; i++)
        {
            if(ch[i] >= 'A' && ch[i] <= 'Z')
            {
                ch[i] = (ch[i] - 'A' - key + 26) % 26 + 'A';
            }
            else if(ch[i] >= 'a' && ch[i] <= 'z')
            {
                ch[i] = (ch[i] - 'a' - key + 26) % 26 + 'a';
            }
        }

        printf("Decrypted message: %s %d\n\n", ch, key);
    }


    return 0;
}