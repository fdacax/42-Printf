/* #include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include "ft_printf.h"

#define TEST(...) do {                          \
    int ret1;                                  \
    int ret2;                                  \
    printf("\n----------------------------\n"); \
    printf("TEST: %s\n", #__VA_ARGS__);        \
    printf("ORIGINAL: [");                     \
    fflush(stdout);                            \
    ret1 = printf(__VA_ARGS__);                 \
    printf("]\n");                             \
    printf("FT_PRINTF: [");                    \
    fflush(stdout);                            \
    ret2 = ft_printf(__VA_ARGS__);              \
    printf("]\n");                             \
    printf("RETURN: printf=%d | ft_printf=%d", \
           ret1, ret2);                        \
    if (ret1 == ret2)                          \
        printf(" [OK]\n");                     \
    else                                       \
        printf(" [KO]\n");                     \
} while (0)

int main(void)
{
    char c = 'A';
    char *str = "Hello 42!";
    int n = 42;

    printf("\n========== CHAR %%c ==========\n");

    TEST("%c", 'A');
    TEST("%c", 'z');
    TEST("%c", '0');
    TEST("%c", ' ');
    TEST("%c", '\n');
    TEST("%c", '\t');
    TEST("%c", '\0');
    TEST("%c", 0);
    TEST("%c", 127);
    TEST("%c", 255);
    TEST("%c", 256);
    TEST("%c", -1);
    TEST("ABC%cDEF", 'X');
    TEST("%c%c%c", 'A', 'B', 'C');

    printf("\n========== STRING %%s ==========\n");

    TEST("%s", "Hello World");
    TEST("%s", "");
    TEST("%s", " ");
    TEST("%s", "42");
    TEST("%s", "Hello\nWorld");
    TEST("%s", "Hello\tWorld");
    TEST("%s", "Special !@#$^&*()");
    TEST("%s", str);
    TEST("%s", (char *)NULL);
    TEST("ABC%sDEF", "42");
    TEST("%s%s%s", "A", "B", "C");
    TEST("%s", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");

    printf("\n========== POINTER %%p ==========\n");

    TEST("%p", &n);
    TEST("%p", &c);
    TEST("%p", str);
    TEST("%p", (void *)NULL);
    TEST("%p", (void *)(uintptr_t)1);
    TEST("%p", (void *)(uintptr_t)16);
    TEST("%p", (void *)(uintptr_t)255);
    TEST("%p", (void *)(uintptr_t)4095);
    TEST("%p", (void *)(uintptr_t)UINTPTR_MAX);
    TEST("ABC%pDEF", (void *)&n);
    TEST("%p %p", (void *)&n, (void *)&c);

    printf("\n========== DECIMAL %%d ==========\n");

    TEST("%d", 0);
    TEST("%d", 1);
    TEST("%d", -1);
    TEST("%d", 42);
    TEST("%d", -42);
    TEST("%d", 100);
    TEST("%d", -100);
    TEST("%d", 999);
    TEST("%d", -999);
    TEST("%d", INT_MAX);
    TEST("%d", INT_MIN);
    TEST("%d", 2147483647);
    TEST("%d", (-2147483647 - 1));
    TEST("ABC%dDEF", 42);
    TEST("%d %d %d", 1, -1, 0);

    printf("\n========== INTEGER %%i ==========\n");

    TEST("%i", 0);
    TEST("%i", 1);
    TEST("%i", -1);
    TEST("%i", 42);
    TEST("%i", -42);
    TEST("%i", 999);
    TEST("%i", -999);
    TEST("%i", INT_MAX);
    TEST("%i", INT_MIN);
    TEST("%i %i %i", INT_MIN, 0, INT_MAX);

    printf("\n========== UNSIGNED %%u ==========\n");

    TEST("%u", 0u);
    TEST("%u", 1u);
    TEST("%u", 42u);
    TEST("%u", 100u);
    TEST("%u", 999u);
    TEST("%u", UINT_MAX);
    TEST("%u", 4294967295u);
    TEST("%u", (unsigned int)-1);
    TEST("%u", (unsigned int)-42);
    TEST("%u %u %u", 0u, 42u, UINT_MAX);

    printf("\n========== HEX LOWER %%x ==========\n");

    TEST("%x", 0u);
    TEST("%x", 1u);
    TEST("%x", 10u);
    TEST("%x", 15u);
    TEST("%x", 16u);
    TEST("%x", 42u);
    TEST("%x", 255u);
    TEST("%x", 256u);
    TEST("%x", 4095u);
    TEST("%x", 4096u);
    TEST("%x", 65535u);
    TEST("%x", UINT_MAX);
    TEST("%x", (unsigned int)-1);
    TEST("%x", (unsigned int)-42);
    TEST("%x %x %x", 0u, 255u, UINT_MAX);

    printf("\n========== HEX UPPER %%X ==========\n");

    TEST("%X", 0u);
    TEST("%X", 1u);
    TEST("%X", 10u);
    TEST("%X", 15u);
    TEST("%X", 16u);
    TEST("%X", 42u);
    TEST("%X", 255u);
    TEST("%X", 256u);
    TEST("%X", 4095u);
    TEST("%X", 4096u);
    TEST("%X", 65535u);
    TEST("%X", UINT_MAX);
    TEST("%X", (unsigned int)-1);
    TEST("%X", (unsigned int)-42);
    TEST("%X %X %X", 0u, 255u, UINT_MAX);

    printf("\n========== PERCENT %%%% ==========\n");

    TEST("%%");
    TEST("%%%%");
    TEST("%%%%%%%%");
    TEST("ABC%%DEF");
    TEST("%% %d %%", 42);
    TEST("%% %s %%", "Hello");

    printf("\n========== MIXED TESTS ==========\n");

    TEST("Hello %s!", "World");
    TEST("Char: %c | String: %s", 'A', "42");
    TEST("Decimal: %d | Integer: %i", -42, 42);
    TEST("Unsigned: %u | Hex: %x | HEX: %X",
         UINT_MAX, UINT_MAX, UINT_MAX);
    TEST("Pointer: %p | Number: %d", &n, 42);

    TEST("%c%s%p%d%i%u%x%X%%",
         'A', "42", (void *)&n, -42, 42, 42u, 255u, 255u);

    TEST("%d%d%d%d%d", 1, 2, 3, 4, 5);
    TEST("%s%s%s%s%s", "1", "2", "3", "4", "5");
    TEST("%%%%%d%%%%", 42);

    printf("\n========== EMPTY / RETURN TESTS ==========\n");

    TEST("");
    TEST("A");
    TEST("Hello World");
    TEST("\n");
    TEST("\t");
    TEST("1234567890");
    TEST("%s", "");
    TEST("%c", '\0');
    TEST("%d", 0);
    TEST("%x", 0u);

    printf("\n========== STRESS TESTS ==========\n");

    TEST("%d %d %d %d %d %d %d %d %d %d",
         1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

    TEST("%x %X %u %d %i",
         UINT_MAX, UINT_MAX, UINT_MAX, INT_MIN, INT_MAX);

    TEST("%s %s %s %s %s",
         "Hello", "42", "", "World", "!");

    TEST("%c%c%c%c%c%c%c%c%c%c",
         '0', '1', '2', '3', '4',
         '5', '6', '7', '8', '9');

    printf("\n========== END OF TESTS ==========\n");

    return (0); */