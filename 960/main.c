#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void put_bishop(const char **position, const char *bishop, int first_place)
{
	int r_num = rand() % 4;
	int r_position = first_place;
	for (int i = 0; i < r_num; i++)
		r_position += 2;
	position[r_position] = bishop;
}

void put_knight_and_queen(const char **position, const char *piece)
{
	int r;
	while (1)
	{
		r = rand() % 8;
		if (!position[r])
		{
			position[r] = piece;
			break;
		}
	}
}

void put_rook_and_king(const char **position, const char *rook, const char *king)
{
	int i = 0;
	while (position[i])
		if (++i > 5)
			return;
	position[i++] = rook;
	while (position[i])
		if (++i > 6)
			return;
	position[i++] = king;
	while (position[i])
		if (++i > 7)
			return;
	position[i] = rook;
}

void print_position(const char **position)
{
	printf("| %s | %s | %s | %s | %s | %s | %s | %s |\n", position[0], position[1], position[2], position[3], position[4], position[5], position[6], position[7]);
}

void print_pawn(const char *pawn)
{
	printf("| %s | %s | %s | %s | %s | %s | %s | %s |\n", pawn, pawn, pawn, pawn, pawn, pawn, pawn, pawn);
}

void print_line(void)
{
	printf(" --- --- --- --- --- --- --- --- \n");
}

int return_error(const char *message, const char *arg)
{
	if (!arg)
		printf("\033[31;1mERROR : !!! %s !!!\033[0m", message);
	else
		printf("\033[31;1mERROR : !!! %s : %s !!!\033[0m", message, arg);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac > 2)
		return (return_error("Too many arguments", NULL));
	srand(time(NULL));
	const char *position[8] = {NULL};
	const char king[] = "\033[31;1mK\033[0m";
	const char queen[] = "\033[35;1mQ\033[0m";
	const char rook[] = "\033[33;1mR\033[0m";
	const char bishop[] = "\033[34;1mB\033[0m";
	const char knight[] = "\033[32;1mN\033[0m";
	const char pawn[] = "\033[36;1mp\033[0m";

	const char uni_king[] = "\033[31;1m♔\033[0m";
	const char uni_queen[] = "\033[35;1m♕\033[0m";
	const char uni_rook[] = "\033[33;1m♖\033[0m";
	const char uni_bishop[] = "\033[34;1m♗\033[0m";
	const char uni_knight[] = "\033[32;1m♘\033[0m";
	const char uni_pawn[] = "\033[36;1m♙\033[0m";

	const char *actual_pawn;

	if (ac == 2)
	{
		if (!strcmp(av[1], "uni") && !strcmp(av[1], "--uni") && !strcmp(av[1], "-u"))
			return (return_error("Invalid argument", av[1]));
		else
		{
			put_bishop(position, uni_bishop, 0);
			put_bishop(position, uni_bishop, 1);
			put_knight_and_queen(position, uni_knight);
			put_knight_and_queen(position, uni_knight);
			put_knight_and_queen(position, uni_queen);
			put_rook_and_king(position, uni_rook, uni_king);
			actual_pawn = uni_pawn;
		}
	}
	else
	{
		put_bishop(position, bishop, 0);
		put_bishop(position, bishop, 1);
		put_knight_and_queen(position, knight);
		put_knight_and_queen(position, knight);
		put_knight_and_queen(position, queen);
		put_rook_and_king(position, rook, king);
		actual_pawn = pawn;
	}

	printf("\n ------   ------ \n| %s = %s | %s = %s |\n ------   ------ \n| %s = %s | %s = %s |\n ------   ------ \n| %s = %s | %s = %s |\n ------   ------ \n\n\n", king, uni_king, queen, uni_queen, rook, uni_rook, bishop, uni_bishop, knight, uni_knight, pawn, uni_pawn);
	print_line();
	print_position(position);
	print_line();
	print_pawn(actual_pawn);
	print_line();
	printf("|   | * |   | * |   | * |   | * |\n");
	print_line();
	printf("| * |   | * |   | * |   | * |   |\n");
	print_line();
	printf("|   | * |   | * |   | * |   | * |\n");
	print_line();
	printf("| * |   | * |   | * |   | * |   |\n");
	print_line();
	print_pawn(actual_pawn);
	print_line();
	print_position(position);
	printf(" --- --- --- --- --- --- --- --- \n\n");

	return (0);
}