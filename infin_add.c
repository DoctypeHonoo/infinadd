/*
** EPITECH PROJECT, 2021
** C Pool
** File description:
** infinadd
*/

#include "./include/my.h"
#include <stdlib.h>
#include <unistd.h>

char *add_char(char const *s1, char const *s2);

char *sign(char const *s1, char const *s2)
{
    char *final = malloc((sizeof(char) * (my_strlen(s1)) + 2));

    final[0] = '\0';
    final[my_strlen(s1) + 1] = '\0';
    if (s1[0] != '-' && s2[0] != '-')
        return (add_char(s1, s2));
    if (s1[0] == '-' && s2[0] == '-') {
        my_putchar('-');
        return add_char(&s1[1], &s2[1]);
    }
}

int compch(char const *s1, char const *s2)
{
    int i = 0;
    if (s1[0] == '-')
        return compch(&s1[1], s2);
    if (s2[0] == '-')
        return compch(s1, &s2[1]);
    while (s1[i] != '\0') {
        if (s1[i] > s2[i])
            return 1;
        if (s1[i] < s2[i])
            return 2;
        i++;
    }
    return 1;
}

char *str_display(char *final_res)
{
    int i = 0;
    int j;
    while (final_res[i] < '1') {
        if (final_res[i] == '0')
            final_res[i] = '\0';
            i++;
    }

    for (j = 0; final_res[j] == '\0'; j++)
    if (final_res[j] == 'Q') {
        final_res[j] = '0';
    }
    return (&final_res[j]);
}

char *add_char(char const *s1, char const *s2)
{
    char *final = malloc((sizeof(char) * (my_strlen(s1)) + 2));
    int a;
    int b;
    int result = 0;
    int hold = 0;

    final[my_strlen(s1) + 1] = '\0';
    final[0] = '\0';

    for (int i = (my_strlen(s1) - 1); i >= 0; i--) {
        a = (s1[i] - '0');
        if ((i - (my_strlen(s1) - my_strlen(s2))) < 0)
            b = 0;
        else
            b = s2[i - (my_strlen(s1) - my_strlen(s2))] - '0';
        result = (a + b + hold);
        final[i + 1] = ((result % 10) + '0');
        hold = result / 10;
    }
    if (hold == 1)
        final[0] = '1';
    return str_display(final);
}

void infinadd(char const *s1, char const *s2)
{
    int s1length = my_strlen(s1);
    int s2length = my_strlen(s2);
    int big_str = (s1length > s2length) ? 1 : 2;

    if (s1[0] == '-')
        s1length--;
    if (s2[0] == '-')
        s2length--;
    if (s1length == s2length)
        big_str = compch(s1, s2);
    if (big_str == 1) {
        my_putstr(sign(s1, s2));
        my_putchar('\n');
    }
    if (big_str == 2) {
        my_putstr(sign(s2, s1));
        my_putchar('\n');
    }
}

int main(int argc, char **argv)
{
    if (argc < 3 || my_str_isnum(argv[1]) != 1 || my_str_isnum(argv[2]) != 1) {
        write(2, "Invalid Input", 14);
        return 84;
    }
    infinadd(argv[1], argv[2]);
    return 0;
}
