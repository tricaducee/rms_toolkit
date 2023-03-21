#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define KING 0
#define QUEEN 1
#define ROOK 2
#define BISHOP 3
#define KNIGHT 4
#define PAWN 5
#define UNI_KING 6
#define UNI_QUEEN 7
#define UNI_ROOK 8
#define UNI_BISHOP 9
#define UNI_KNIGHT 10
#define UNI_PAWN 11
#define N_PIECES 12
#define NAME_MAX_SIZE 25

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

void generate_random_positions(const char **position, const char pieces[N_PIECES][NAME_MAX_SIZE])
{
	put_bishop(position, pieces[BISHOP], 0);
	put_bishop(position, pieces[BISHOP], 1);
	put_knight_and_queen(position, pieces[KNIGHT]);
	put_knight_and_queen(position, pieces[KNIGHT]);
	put_knight_and_queen(position, pieces[QUEEN]);
	put_rook_and_king(position, pieces[ROOK], pieces[KING]);
}

void generate_random_positions_uni(const char **position, const char pieces[N_PIECES][NAME_MAX_SIZE])
{
	put_bishop(position, pieces[UNI_BISHOP], 0);
	put_bishop(position, pieces[UNI_BISHOP], 1);
	put_knight_and_queen(position, pieces[UNI_KNIGHT]);
	put_knight_and_queen(position, pieces[UNI_KNIGHT]);
	put_knight_and_queen(position, pieces[UNI_QUEEN]);
	put_rook_and_king(position, pieces[UNI_ROOK], pieces[UNI_KING]);
}

void print_position(const char **position, int line)
{
	printf(" %d | %s | %s | %s | %s | %s | %s | %s | %s | %d\n", line, position[0], position[1], position[2], position[3], position[4], position[5], position[6], position[7], line);
}

void print_pawn(const char *pawn, int line)
{
	printf(" %d | %s | %s | %s | %s | %s | %s | %s | %s | %d\n", line, pawn, pawn, pawn, pawn, pawn, pawn, pawn, pawn, line);
}

void print_line(void)
{
	printf("    --- --- --- --- --- --- --- --- \n");
}

void print_legende(const char pieces[N_PIECES][NAME_MAX_SIZE])
{
	printf("\n    ------   ------ \n   | %s = %s | %s = %s |\n    ------   ------ \n   | %s = %s | %s = %s |\n    ------   ------ \n   | %s = %s | %s = %s |\n    ------   ------ \n\n", pieces[KING], pieces[UNI_KING], pieces[QUEEN], pieces[UNI_QUEEN], pieces[ROOK], pieces[UNI_ROOK], pieces[BISHOP], pieces[UNI_BISHOP], pieces[KNIGHT], pieces[UNI_KNIGHT], pieces[PAWN], pieces[UNI_PAWN]);
}

void print_chess(const char **position, const char pieces[N_PIECES][NAME_MAX_SIZE], const char *actual_pawn)
{
	print_legende(pieces);
	printf("     a   b   c   d   e   f   g   h\n");
	print_line();
	print_position(position, 8);
	print_line();
	print_pawn(actual_pawn, 7);
	print_line();
	printf(" 6 |   | * |   | * |   | * |   | * | 6\n");
	print_line();
	printf(" 5 | * |   | * |   | * |   | * |   | 5\n");
	print_line();
	printf(" 4 |   | * |   | * |   | * |   | * | 4\n");
	print_line();
	printf(" 3 | * |   | * |   | * |   | * |   | 3\n");
	print_line();
	print_pawn(actual_pawn, 2);
	print_line();
	print_position(position, 1);
	print_line();
	printf("     a   b   c   d   e   f   g   h\n\n");
}

int return_error(const char *message, const char *arg)
{
	if (!arg)
		printf("\033[31;1mERROR : !!! %s !!!\033[0m\n", message);
	else
		printf("\033[31;1mERROR : !!! %s : %s !!!\033[0m\n", message, arg);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac > 2)
		return (return_error("Too many arguments", NULL));
	srand(time(NULL));
	const char *position[8] = {NULL};
	const char pieces[N_PIECES][NAME_MAX_SIZE] = {
		"\033[31;1mK\033[0m",
		"\033[35;1mQ\033[0m",
		"\033[33;1mR\033[0m",
		"\033[34;1mB\033[0m",
		"\033[32;1mN\033[0m",
		"\033[36;1mp\033[0m",
		"\033[31;1m♔\033[0m",
		"\033[35;1m♕\033[0m",
		"\033[33;1m♖\033[0m",
		"\033[34;1m♗\033[0m",
		"\033[32;1m♘\033[0m",
		"\033[36;1m♙\033[0m"
	};

	const char *actual_pawn;

	if (ac == 2)
	{
		if (!strcmp(av[1], "uni") || !strcmp(av[1], "--uni") || !strcmp(av[1], "-u"))
		{
			generate_random_positions_uni(position, pieces);
			actual_pawn = pieces[UNI_PAWN];
		}
		else
			return (return_error("Invalid argument", av[1]));
	}
	else
	{
		generate_random_positions(position, pieces);
		actual_pawn = pieces[PAWN];
	}

	print_chess(position, pieces, actual_pawn);

	return (0);
}