//RSA encryption

#include <stdio.h>
#include <math.h>

void fN(int p, int q, int *n)
{
    *n = p * q;
}

void fT(int p, int q, int *t)
{
    *t = (p - 1) * (q - 1);
}

void eRelativelyPrimeWithT(int t, int *e)
{
    for(int i = 2; i < t; i++)
    {
        if(t % i != 0)
        {
            *e = i;
            break;
        }
    }
}

void determineD(int e, int t, int *d)
{
    for(int i = 1; i < t; i++)
    {
        if((i * e) % t == 1)
        {
            *d = i;
            break;
        }
    }
}

void encrypt(int n, int e, char *c, char *m)
{
    int a = pow(*m, e);

    printf("a = %d\n", a);

    *c = a % n;
}

void decrypt(int n, int d, char *c, char *m)
{
    int a = pow(*c, d);

    *m = a % n;
}

int main()
{
    int p, q, n, t, e, d;

    char message[100] = {0};
    char c[100] = {0};
    char decryptedMessage[100] = {0};

    int i = 0;
    printf("Message: ");
    while((message[i] = getchar()) != '\n' && i < 100)
    {
        i++;
    }

    printf("Enter p: ");
    scanf("%d", &p);

    printf("Enter q: ");
    scanf("%d", &q);

    fN(p, q, &n);

    fT(p, q, &t);

    eRelativelyPrimeWithT(t, &e);

    determineD(e, t, &d);

    printf("n = %d\n", n);
    printf("t = %d\n", t);
    printf("e = %d\n", e);
    printf("d = %d\n", d);

    printf("Public key: (%d, %d)\n", n, e);
    printf("Private key: (%d, %d)\n", n, d);

    i = 0;
    while(message[i] != '\n')
    {
        encrypt(n, e, &c[i], &message[i]);
        i++;
    }

    printf("Encrypted message: ");
    i = 0;
    while(c[i] != '\0')
    {
        printf("%d", c[i]);
        i++;
    }

    i = 0;
    while(c[i] != '\0')
    {
        decrypt(n, d, &c[i], &decryptedMessage[i]);
        i++;
    }

    printf("\nDecrypted message: ");
    i = 0;
    while(decryptedMessage[i] != '\0')
    {
        printf("%c", decryptedMessage[i]);
        i++;
    }

    return 0;
}