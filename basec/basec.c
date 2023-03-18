#include <unistd.h>

typedef struct S_base
{
    unsigned long long  prog;
    unsigned long long  base;
}                       t_base;

unsigned long long  strulllen(char *s)
{
    unsigned long long  i = 0;
    while (s[i])
        i++;
    return (i);
}

void    ft_putnbr_base(unsigned long long n, char *s, unsigned long long base)
{
    if (n >= base)
        ft_putnbr_base(n / base, s, base);
    write(1, s + (n % base), 1);
}

unsigned long long    ft_strchr(char c, char *s)
{
    unsigned long long    i;
    i = 0;
    while (s[i])
    {
        if (s[i] == c)
            return (i);
        i++;
    }
    return (0);
}

char    s_strchr(char *s, char c)
{
    while (*s)
        if (*s++ == c)
            return (c);
    return (0);
}

int comp_check(char *s1, char *s2)
{
    while (*s1)
    {
        if (!s_strchr(s2, *(s1++)))
        {
            write(2, "Base doesn't contain all char\nUse : [ basec value_arg base_arg ]\nOr  : [ basec (0 for decimal to base and 1 for base to decimal) value_arg base_arg ]\n", 153);
            return (1);
        }
    }
    return (0);
}

unsigned long long    ft_atobase(char *s, char *sb, unsigned long long base)
{
    unsigned long long    i;
    unsigned long long    n;
    n = 0;
    while (*s)
    {
        n *= base;
        n += ft_strchr(*(s++), sb);
    }
    return (n);
}

int check_n(char *s)
{
    int i = 0;
    while (s[i] >= '0' && s[i] <= '9')
        i++;
    if (s[i])
    {
       write(2, "Not a number\nUse : [ basec value_arg base_arg ]\nOr  : [ basec (0 for decimal to base and 1 for base to decimal) value_arg base_arg ]\n", 136);
       return (1);
    }
    return (0);
}

int double_check(char *s)
{
    int i = 0;
    int j = 0;
    while (s[i])
    {
        j = i + 1;
        while (s[j])
        {
            if (s[i] == s[j++])
            {
               write(2, "Base contains at least one duplicate\nUse : [ basec value_arg base_arg ]\nOr  : [ basec (0 for decimal to base and 1 for base to decimal) value_arg base_arg ]\n", 160);
               return (1);
            }
        }
        i++;
    }
    return (0);
}

int main(int ac, char **av)
{
    t_base  data;
    if (ac < 3)
    {
        write(2, "Not enough arguments\nUse : [ basec value_arg base_arg ]\nOr  : [ basec (0 for decimal to base and 1 for base to decimal) value_arg base_arg ]\n", 141);
        return (0);
    } else if (ac == 3) {
        data.prog = 0;
        if (check_n(av[1]))
            return (1);
        data.base = strulllen(av[2]);
        if (data.base < 2)
        {
            write(2, "Base min 2 char\nUse : [ basec value_arg base_arg ]\nOr  : [ basec (0 for decimal to base and 1 for base to decimal) value_arg base_arg ]\n", 139);
            return (1);
        }
        if (double_check(av[2]))
            return (1);
        ft_putnbr_base(ft_atobase(av[1], "0123456789", 10), av[2], data.base);
        write(1, "\n", 1);
    } else if (ac == 4) {
        if (check_n(av[1]))
            return (1);
        data.prog = ft_atobase(av[1], "0123456789", 10);
        data.base = strulllen(av[3]);
        if (data.base < 2)
        {
            write(2, "Base min 2 char\nUse : [ basec value_arg base_arg ]\nOr  : [ basec (0 for decimal to base and 1 for base to decimal) value_arg base_arg ]\n", 139);
            return (1);
        }
        if (double_check(av[3]))
            return (1);
        if (!data.prog)
        {
            if (check_n(av[2]))
                return (1);
            ft_putnbr_base(ft_atobase(av[2], "0123456789", 10), av[3], data.base);
            write(1, "\n", 1);
        }
        else if (data.prog == 1) {
            if (comp_check(av[2], av[3]))
                return (1);
            ft_putnbr_base(ft_atobase(av[2], av[3], data.base), "0123456789", 10);
            write(1, "\n", 1);  
        }
        else {
            write(2, "Not valid first arg\nUse : [ basec value_arg base_arg ]\nOr  : [ basec (0 for decimal to base and 1 for base to decimal) value_arg base_arg ]\n", 143);
            return (1);
        }
    }  
    return (0);
}
