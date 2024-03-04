//Afin decrypting

#include <stdio.h>
#include <string.h>

void keyGen(int k1, int k2, int *k3, int *k4)
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

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int i, key, key2;
    int key3, key4;

    char message[100] = "HJLZAH LZAL BU LELTWSB KL BAPSPGHYL H BUBP JPMYB TVUVHSMHILAPJ JB ZBIZAPABAPL JPMYBS SBP JLGHY";
    char ch[100];

    for(i = 0; i < 26; i++)
    {
        if(gcd(i, 26) == 1)
        {
            key = i;

            for(int j = 0; j < 26; j++)
            {
                key2 = j;

                strcpy(ch, message);

                keyGen(key, key2, &key3, &key4);

                for(int k = 0; ch[k] != '\0'; k++)
                {
                    if(ch[k] >= 'A' && ch[k] <= 'Z')
                    {
                        ch[k] = (key3 * ch[k] - 'A' - key4 + 26) % 26 + 'A';
                    }
                    else if(ch[k] >= 'a' && ch[k] <= 'z')
                    {
                        ch[k] = (key3 * ch[k] - 'a' - key4 + 26) % 26 + 'a';
                    }
                }

                //if(ch[0] == 'A')
                    printf("Decrypted message: %s %d %d\n\n", ch, key3, key4);
            }
        }
    }

    return 0;
}