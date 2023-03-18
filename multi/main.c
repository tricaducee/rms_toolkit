#include <stdio.h>
#include "printfd/HEADER/ft_printfd.h"

void	first_line(int n)
{
	ft_printfd(1, "#y%4d #g", 1);
	for (int i = 2; i <= n; i++)
	{
		ft_printfd(1, "%4d ", i);
	}
	if (n > 1)
		ft_printfd(1, "#y   1#0\n");
	else
		ft_printfd(1, "#0\n");
}

void	line(int n, int j)
{
	ft_printfd(1, "#b%4d #0", j);
	for (int i = 2; i <= n; i++)
	{
		if (i == j)
			ft_printfd(1, "#r%4d ", i * j);
		else if (i == j - 1 || i == j + 1)
			ft_printfd(1, "#p%4d ", i * j);
		else if (!((i + j) % 2))
			ft_printfd(1, "#y%4d ", i * j);
		else
			ft_printfd(1, "#0%4d ", i * j);
	}
	ft_printfd(1, "#b%4d#0\n", j);
	// ft_printfd(1, "#b%4d #0", j);
	// for (int i = 2; i <= n; i++)
	// {
	// 	ft_printfd(1, "#p|#0%4d ", i * j);
	// }
	// ft_printfd(1, "#p|#b %d#0\n", j);
}

void	cut_line(int n)
{
	ft_printfd(1, "#y%5c", ' ');
	for (int i = 1; i < n; i++)
	{
		ft_printfd(1, "%4s ", "---");
	}
	ft_printfd(1, "#0\n");
}

void xy_tab(int n)
{
	ft_printfd(1, "\n");
	first_line(n);
	ft_printfd(1, "\n");
	//cut_line(n);
	for (int i = 2; i <= n; i++)
	{
		line(n, i);
		ft_printfd(1, "\n");
		//cut_line(n);
	}
	if (n > 1)
	{
		first_line(n);
		ft_printfd(1, "\n");
	}
}

void range_tab(int n, int min, int max, int columns)
{
	int i;
	int j;
	int min_b = min;
	int check = 1;
	while (check)
	{
		i = 0;
		ft_printfd(1, "\n");
		while (i < 10)
		{
			j = 0;
			while (j++ < columns)
			{
				if (min_b <= max)
					ft_printfd(1, "#b%4d#y x#b %-5d#y= #g%-7d ", min_b, n, min_b * n);
				if (min_b >= max)
				{
					check = 0;
					break;
				}
				min_b += 10;
			}
			ft_printfd(1, "\n");
			if (min >= max)
				break;
			min++;
			min_b = min;
			i++;
		}
		min += (columns - 1) * 10;
		min_b = min;
	ft_printfd(1, "\n#0");
	}
}

void print_usage(void)
{
	ft_printfd(1, "\n#+_yUSAGE#0#y :\n\n#0#g1 argument :#/g [ multi $A ]\n#/b  \"Affiche un tableau de $A * $A avec dans chaques cases le produit de l'axe x et y\"\n\n#0#g2 arguments :#/g [ multi $A $B ]\n#/b  \"Affiche la table de multiplication de $A de 1 * $A a $B * $A\"\n\n#0#g3 arguments :#/g [ multi $A $B $C ]\n#/b  \"Affiche la table de multiplication de $A de $B(valeur min) * $A a $C(valeur max) * $A\"\n\n#0#g4 arguments :#/g [ multi $A $B $C $D ]\n#/b  \"Affiche la table de multiplication de $A de $B(valeur min) * $A a $C(valeur max) * $A sur $D colonnes max (comportement naturel : 3 colonnes)\"\n\n");
}

int	return_error(char *s)
{
	ft_printfd(2, "\n#+rERROR : [#/ !!! %s !!!#0#+r ]#0\n", s);
	print_usage();
	return (1);
}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		print_usage();
		return (0);
	}

	int n = atoi(av[1]);

	if (n < 1)
		return (return_error("Argument invalide, le 1er argument n'est pas un chiffre ou un nombre positif"));

	if (ac < 3)
	{
		if (n > 50)
			return (return_error("Argument invalide, ce nombre est trop grand"));
		xy_tab(n);
	}
	else
	{
		int nb = atoi(av[2]);
		if (nb < 1)
			return (return_error("Argument invalide, le 2eme argument n'est pas un chiffre ou un nombre positif"));
		if (ac > 3)
		{
			int nc = atoi(av[3]);
			if (nc < 1)
				return (return_error("Argument invalide, le 3eme argument n'est pas un chiffre ou un nombre positif"));
			else if (nb > nc)
				return (return_error("Argument invalide, la valeur min ne peux pas etre superieur a la valeur max"));
			if (ac > 4)
			{
				int column_max = atoi(av[4]);
				if (column_max < 1)
					return (return_error("Argument invalide, le 4eme argument n'est pas un chiffre ou un nombre positif"));
				range_tab(n, nb, nc, column_max);
			} else
				range_tab(n, nb, nc, 4);
		} else
			range_tab(n, 1, nb, 4);
	}


	return (0);
}