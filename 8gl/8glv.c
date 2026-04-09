#include <stdio.h>
#include "encrypt.h"
#include "checksum.h"

int main()
{
    char s[] = "Секретные данные банка";
    encrypt(s);
    printf("Зашифровано: %s\n", s);
    printf("Контрольная сумма: %i\n", checksum(s));
    encrypt(s);
    printf("Расшифровано: %s\n", s);
    printf("Контрольная сумма: %i\n", checksum(s));
    return 0;
}