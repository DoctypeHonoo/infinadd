/*
** EPITECH PROJECT, 2021
** my_isneg
** File description:
** check if negative or positive
*/

void my_putchar(char ch);

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    return 0;
}
