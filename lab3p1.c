// DES encryption

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fp1(char message[], int (*p1)[8])
{
    char temp[8] = {0};

    for(int i = 0; i < 8; i++)
    {
        temp[i] = message[(*p1)[i] - 1];
    }

    for(int i = 0; i < 8; i++)
    {
        message[i] = temp[i];
    }
}

void fre(char message[], int (*e)[], char re[])
{
    char temp[8] = {0};

    for(int i = 0; i < 8; i++)
    {
        temp[i] = message[(*e)[i] - 1];
    }

    for(int i = 0; i < 8; i++)
    {
        re[i] = temp[i];
    }
}

void ff(char k1[], char mr[], int **f)
{
    int count = 0;

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            f[i][j] = k1[count] ^ mr[count];
            count++;
        }
    }
}

void fp10(char key[], int (**p10)[])
{
    char temp[10] = {0};

    for(int i = 0; i < 10; i++)
    {
        temp[i] = key[(**p10)[i] - 1];
    }

    for(int i = 0; i < 10; i++)
    {
        key[i] = temp[i];
    }
}

void fp8(char key[], int (**p8)[])
{
    char temp[8] = {0};

    for(int i = 0; i < 8; i++)
    {
        temp[i] = key[(**p8)[i] - 1];
    }

    for(int i = 0; i < 8; i++)
    {
        key[i] = temp[i];
    }
}

void generateKeys(char key[], int (*p10)[], int (*p8)[], char k1[], char k2[])
{
    char temp[10] = {0};

    int (**pp10)[10];

    pp10 = &p10;

    fp10(key, pp10);

    printf("Key after p10: ");

    for(int i = 0; i < 10; i++)
    {
        printf("%c", key[i]);
    }
    printf("\n");

    char kl[5] = {0}, kr[5] = {0};

    for(int i = 0; i < 5; i++)
    {
        kl[i] = key[i];
        kr[i] = key[i + 5];
    }

    printf("kl: ");
    for(int i = 0; i < 5; i++)
    {
        printf("%c", kl[i]);
    }
    printf("\n");

    printf("kr: ");
    for(int i = 0; i < 5; i++)
    {
        printf("%c", kr[i]);
    }
    printf("\n");

    char temp1, temp2;

    temp1 = kl[4];
    temp2 = kr[4];

    kl[4] = kl[0];
    kr[4] = kr[0];

    for(int i = 3; i >= 0; i--)
    {
        temp[0] = kl[i];
        kl[i] = temp1;
        temp1 = temp[0];

        temp[0] = kr[i];
        kr[i] = temp2;
        temp2 = temp[0];
    }

    printf("kl: ");
    for(int i = 0; i < 5; i++)
    {
        printf("%c", kl[i]);
    }
    printf("\n");

    printf("kr: ");
    for(int i = 0; i < 5; i++)
    {
        printf("%c", kr[i]);
    }
    printf("\n");

    char ktmp[10] = {0};

    strcpy(ktmp, kl);

    strcpy(ktmp + 5, kr);

    printf("ktmp: ");
    for(int i = 0; i < 10; i++)
    {
        printf("%c", ktmp[i]);
    }
    printf("\n");

    for(int i = 0; i < 5; i++)
    {
        kl[i] = ktmp[i];
        kr[i] = ktmp[i + 5];
    }

    int (**pp8)[8];

    pp8 = &p8;

    fp8(ktmp, pp8);

    printf("ktmp after p8: ");
    for(int i = 0; i < 8; i++)
    {
        printf("%c", ktmp[i]);
    }
    printf("\n");

    for(int i = 0; i < 8; i++)
    {
        k1[i] = ktmp[i];
    }

    for(int j = 0; j < 2; j++)
    {
        temp1 = kl[4];
        temp2 = kr[4];

        kl[4] = kl[0];
        kr[4] = kr[0];

        for(int i = 3; i >= 0; i--)
        {
            temp[0] = kl[i];
            kl[i] = temp1;
            temp1 = temp[0];

            temp[0] = kr[i];
            kr[i] = temp2;
            temp2 = temp[0];
        }
    }

    printf("kl: ");
    for(int i = 0; i < 5; i++)
    {
        printf("%c", kl[i]);
    }
    printf("\n");

    printf("kr: ");
    for(int i = 0; i < 5; i++)
    {
        printf("%c", kr[i]);
    }
    printf("\n");
    
    strcpy(ktmp, kl);

    strcpy(ktmp + 5, kr);

    printf("ktmp: ");
    for(int i = 0; i < 10; i++)
    {
        printf("%c", ktmp[i]);
    }
    printf("\n");

    fp8(ktmp, pp8);

    k2 = memset(k2, 0, 8);

    for(int i = 0; i < 8; i++)
    {
        k2[i] = ktmp[i];
    }

    printf("k1: ");
    for(int i = 0; i < 8; i++)
    {
        printf("%c", k1[i]);
    }
    printf("\n");

    printf("k2: ");
    for(int i = 0; i < 8; i++)
    {
        printf("%c", k2[i]);
    }
    printf("\n");
}

void sk(int *sk, int **f)
{
    int s0[4][4] = {{1, 0, 3, 2}, {3, 2, 1, 0}, {0, 2, 1, 3}, {3, 1, 3, 2}};
    int s1[4][4] = {{0, 1, 2, 3}, {2, 0, 1, 3}, {3, 0, 1, 0}, {2, 1, 0, 3}};

    int row, col;

    switch(f[0][0])
    {
        case 0:
            if(f[0][3] == 0)
            {
                row = 0;
            }
            else
            {
                row = 1;
            }
            break;
        case 1:
            if(f[0][3] == 0)
            {
                row = 2;
            }
            else
            {
                row = 3;
            }
            break;
    }

    switch(f[0][1])
    {
        case 0:
            if(f[0][2] == 0)
            {
                col = 0;
            }
            else
            {
                col = 1;
            }
            break;
        case 1:
            if(f[0][2] == 0)
            {
                col = 2;
            }
            else
            {
                col = 3;
            }
            break;
    }

    sk[0] = s0[row][col];

    switch(f[1][0])
    {
        case 0:
            if(f[1][3] == 0)
            {
                row = 0;
            }
            else
            {
                row = 1;
            }
            break;
        case 1:
            if(f[1][3] == 0)
            {
                row = 2;
            }
            else
            {
                row = 3;
            }
            break;
    }

    switch(f[1][1])
    {
        case 0:
            if(f[1][2] == 0)
            {
                col = 0;
            }
            else
            {
                col = 1;
            }
            break;
        case 1:
            if(f[1][2] == 0)
            {
                col = 2;
            }
            else
            {
                col = 3;
            }
            break;
    }

    sk[1] = s1[row][col];

    printf("sk: ");
    for(int i = 0; i < 2; i++)
    {
        printf("%d", sk[i]);
    }
    printf("\n");

    int temp[4] = {0};

    for(int i = 0; i < 2; i++)
    {
        switch(sk[i])
        {
            case 0:
                temp[i * 2] = 0;
                temp[i * 2 + 1] = 0;
                break;
            case 1:
                temp[i * 2] = 0;
                temp[i * 2 + 1] = 1;
                break;
            case 2:
                temp[i * 2] = 1;
                temp[i * 2 + 1] = 0;
                break;
            case 3:
                temp[i * 2] = 1;
                temp[i * 2 + 1] = 1;
                break;
        }
    }

    for(int i = 0; i < 4; i++)
    {
        sk[i] = temp[i];
    }

    printf("sk: ");
    for(int i = 0; i < 4; i++)
    {
        printf("%d", sk[i]);
    }
    printf("\n");
}

void fp4(int *sk1)
{
    int p4[4] = {2, 4, 3, 1};

    int temp[4] = {0};

    for(int i = 0; i < 4; i++)
    {
        temp[i] = sk1[p4[i] - 1];
    }

    for(int i = 0; i < 4; i++)
    {
        sk1[i] = temp[i];
    }
}

void flspk(char ml[], int *spk1)
{
    char temp[4] = {0};

    for(int i = 0; i < 4; i++)
    {
        temp[i] = ml[i] ^ spk1[i];
    }

    for(int i = 0; i < 4; i++)
    {
        ml[i] = temp[i];
    }
}

void interchange(char ml[], char mr[])
{
    char temp[4] = {0};

    for(int i = 0; i < 4; i++)
    {
        temp[i] = ml[i];
        ml[i] = mr[i];
        mr[i] = temp[i];
    }
}

int main()
{
    char key[10] = {0}, k1[8] = {0}, k2[8] = {0}, block[100] = {0};

    char message[8] = {0}, encryptedMessage[100] = {0};

    printf("Enter the key: ");
    scanf("%[^\n]s", key);
    getchar();

    //int keyLength = strlen(key);

    printf("Enter the message: ");
    scanf("%[^\n]s", message);
    getchar();

    int p10[] = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
    int p8[] = {6, 3, 7, 4, 8, 5, 10, 9};

    int p1[] = {2, 6, 3, 1, 4, 8, 5, 7};

    int (*pp10)[10];

    pp10 = &p10;

    int (*pp8)[8];

    pp8 = &p8;

    generateKeys(key, pp10, pp8, k1, k2);

    printf("K1: ");
    for(int i = 0; i < 8; i++)
    {
        printf("%c", k1[i]);
    }
    printf("\n");

    printf("K2: ");
    for(int i = 0; i < 8; i++)
    {
        printf("%c", k2[i]);
    }
    printf("\n");

    int (*pp1)[8];

    pp1 = &p1;

    fp1(message, pp1);

    printf("Message after p1: ");
    for(int i = 0; i < 8; i++)
    {
        printf("%c", message[i]);
    }
    printf("\n");

    char ml[8] = {0}, mr[8] = {0};

    for(int i = 0; i < 4; i++)
    {
        ml[i] = message[i];
        mr[i] = message[i + 4];
    }

    printf("ml: ");
    for(int i = 0; i < 4; i++)
    {
        printf("%c", ml[i]);
    }
    printf("\n");

    printf("mr: ");
    for(int i = 0; i < 4; i++)
    {
        printf("%c", mr[i]);
    }
    printf("\n");

    char re[8] = {0};
    int e[8] = {4, 1, 2, 3, 2, 3, 4, 1};

    int (*pe)[8];

    pe = &e;

    fre(mr, pe, re);

    printf("re: ");
    for(int i = 0; i < 8; i++)
    {
        printf("%c", re[i]);
    }
    printf("\n");

    int **fp = (int **)malloc(2 * sizeof(int *));

    for(int i = 0; i < 2; i++)
    {
        fp[i] = (int *)malloc(4 * sizeof(int));
    }

    ff(k1, re, fp);

    printf("f:\n");
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%d", fp[i][j]);
        }

        printf("\n");
    }
    printf("\n");

    int *sk1 = (int *)malloc(4 * sizeof(int));

    sk(sk1, fp);

    int *p4 = (int *)malloc(4 * sizeof(int));

    fp4(sk1);

    printf("skp1: ");
    for(int i = 0; i < 4; i++)
    {
        printf("%d", sk1[i]);
    }
    printf("\n");

    flspk(ml, sk1);

    printf("ml: ");
    for(int i = 0; i < 4; i++)
    {
        printf("%c", ml[i]);
    }
    printf("\n");

    printf("mr: ");
    for(int i = 0; i < 4; i++)
    {
        printf("%c", mr[i]);
    }
    printf("\n");

    interchange(ml, mr);

    printf("ml: ");
    for(int i = 0; i < 4; i++)
    {
        printf("%c", ml[i]);
    }
    printf("\n");

    printf("mr: ");
    for(int i = 0; i < 4; i++)
    {
        printf("%c", mr[i]);
    }
    printf("\n");

    fre(mr, pe, re);

    printf("re: ");
    for(int i = 0; i < 8; i++)
    {
        printf("%c", re[i]);
    }
    printf("\n");

    ff(k2, re, fp);

    printf("f:\n");
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%d", fp[i][j]);
        }

        printf("\n");
    }
    printf("\n");

    sk(sk1, fp);

    fp4(sk1);

    printf("skp2: ");
    for(int i = 0; i < 4; i++)
    {
        printf("%d", sk1[i]);
    }
    printf("\n");

    flspk(ml, sk1);

    printf("ml: ");
    for(int i = 0; i < 4; i++)
    {
        printf("%c", ml[i]);
    }
    printf("\n");

    printf("mr: ");
    for(int i = 0; i < 4; i++)
    {
        printf("%c", mr[i]);
    }
    printf("\n");

    for(int i = 0; i < 4; i++)
    {
        message[i] = ml[i];
        message[i + 4] = mr[i];
    }

    printf("Message: ");
    for(int i = 0; i < 8; i++)
    {
        printf("%c", message[i]);
    }
    printf("\n");

    int pi[8] = {4, 1, 3, 5, 7, 2, 8, 6};

    pp1 = &pi;

    fp1(message, pp1);

    printf("Encrypted message: ");
    for(int i = 0; i < 8; i++)
    {
        printf("%c", message[i]);
    }
    printf("\n");

    return 0;
}