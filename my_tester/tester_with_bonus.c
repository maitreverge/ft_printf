/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_with_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:22:09 by flverge           #+#    #+#             */
/*   Updated: 2024/12/05 16:27:00 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>
#include <stdio.h>
#include <limits.h>


void	bn(void)
{
	printf("\n");
}

void displayTestSeparator(const char *text, int colorCode)
{
    int separatorLength = 38;  // Total length of the separator line
    int textLength = strlen(text);
    int paddingLength = separatorLength - textLength;
    int leftPadding = paddingLength / 2;
    int rightPadding = paddingLength - leftPadding;

    printf("\033[%dm\n", colorCode);  // Set the desired text color
    printf("  ///////////////////////////////////////////\n");
    printf(" //%*s%s%*s //\n", leftPadding, "", text, rightPadding, "");
    printf("///////////////////////////////////////////\n");
    printf("\033[0m\n");  // Reset text color
}

void	headings(int i)
{
	if (i == 1)
	{
		printf("\033[32;1mREAL PRINTF\033[0m\n");
		return ;
	}
	printf("\033[91;1mMY FT_PRINTF\033[0m\n");
}

void	return_values(int v_1, int v_2)
{
	bn();
    printf("\033[32;1mReturn value of REAL printf\033[0m  = %i\n", v_1);
    printf("\033[31;1mReturn value of MY ft_printf\033[0m = %i\n", v_2);
}

char test_char(char c) // function returns the next char (+1) for testing %c
{
	return (c + 1);
}

char	*test_string(char *str) // capitalize every letter
{
	int i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] >='a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

unsigned int		test_unsigned_int(unsigned int nb)
{
	return ((nb + 1));
}

int	test_int(int nb)
{
		return ((nb + 1));
}

int	main(void)
{
	// return values of both printf and ft_printf
	int	v_printf = 0;
	int	v_ftprintf = 0;
	

	// * TEST 1	
	
	displayTestSeparator("test simple string", 93);
	
	headings(1);
	v_printf = printf("This is a %% casual %% test\n");
	headings(2);
	v_ftprintf = ft_printf("This is a %% casual %% test\n");
	
	return_values(v_printf, v_ftprintf);



	// * TEST 2
	
	displayTestSeparator("test simple char", 96);

	headings(1);
	v_printf = printf("Test char : %c", 'Y');
	bn();
	headings(2);
	v_ftprintf = ft_printf("Test char : %c", 'Y');
	bn();

	return_values(v_printf, v_ftprintf);



	// * TEST 3
	
	displayTestSeparator("test multiple char", 96);

	headings(1);
	v_printf = printf("Test char : %c-%c-%c-%c", 'Y', 'M', 'C', 'A');
	bn();
	headings(2);
	v_ftprintf = ft_printf("Test char : %c-%c-%c-%c", 'Y', 'M', 'C', 'A');
	bn();
	return_values(v_printf, v_ftprintf);



	// * TEST 4
	
	displayTestSeparator("test ft char", 96);

	char value_1 = 'C';

	headings(1);
	v_printf = printf("Test char : %c-%c-%c-%c %%", test_char('X'), 'M', value_1, 'A');
	bn();
	headings(2);
	v_ftprintf = ft_printf("Test char : %c-%c-%c-%c %%", test_char('X'), 'M', value_1, 'A');
	bn();
	return_values(v_printf, v_ftprintf);

	

	// ! BONUS CHAR


	

		// * TEST CHAR BONUSES 1

	displayTestSeparator("BONUS CHAR 1", 96);

	headings(1);
	v_printf = printf("[%2c]", 'A');
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%2c]", 'A');
	bn();
	return_values(v_printf, v_ftprintf);
	
	// * TEST CHAR BONUSES 2

	displayTestSeparator("BONUS CHAR 2", 96);

	headings(1);
	v_printf = printf("[%-2c]", 'A');
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%-2c]", 'A');
	bn();
	return_values(v_printf, v_ftprintf);

	// * TEST CHAR BONUSES 3
	
	displayTestSeparator("BONUS CHAR 3", 96);

	headings(1);
	v_printf = printf("[%-c]", 'B');
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%-c]", 'B');
	bn();
	return_values(v_printf, v_ftprintf);

			// * TEST CHAR BONUSES 4

	displayTestSeparator("BONUS CHAR 4", 96);

	headings(1);
	v_printf = printf("[%1c]", 'A');
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%1c]", 'A');
	bn();
	return_values(v_printf, v_ftprintf);
	
	
	// * TEST CHAR BONUSES 5

	displayTestSeparator("BONUS CHAR 5", 96);

	headings(1);
	v_printf = printf("[%-1c]", 'A');
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%-1c]", 'A');
	bn();
	return_values(v_printf, v_ftprintf);

	

	// ! END BONUS CHAR




	// * TEST 5
	
	displayTestSeparator("test string", 92);

	headings(1);
	v_printf = printf("Test string : %s", "Hello, World !");
	bn();
	headings(2);
	v_ftprintf = ft_printf("Test string : %s", "Hello, World !");
	bn();

	return_values(v_printf, v_ftprintf);



	// * TEST 6
	
	displayTestSeparator("test multiple strings", 92);
	
	char str[] = "thIs senTence ouTput iS SUPosED to Be alL CAps";
	
	headings(1);
	v_printf = printf("Test string : %s\n%s\n%s", "Hello, World !", "Life is potatoes", test_string(str));
	bn();
	headings(2);
	v_ftprintf = ft_printf("Test string : %s\n%s\n%s", "Hello, World !", "Life is potatoes", test_string(str));
	bn();

	return_values(v_printf, v_ftprintf);



	// * TEST 7
	
	displayTestSeparator("combo_previous placeholders", 92);

	headings(1);
	v_printf = printf("String = %s__char : %c.___%%%%%%", "Hello, World !", 'C');
	bn();
	headings(2);
	v_ftprintf = ft_printf("String = %s__char : %c.___%%%%%%", "Hello, World !", 'C');
	bn();

	return_values(v_printf, v_ftprintf);



	// * TEST 8
	
	displayTestSeparator("Test empty string", 92);

	char *empty = NULL;

	headings(1);
	v_printf = printf("String = %s", empty);
	bn();
	headings(2);
	v_ftprintf = ft_printf("String = %s", empty);
	bn();

	return_values(v_printf, v_ftprintf);



	// ! BONUS STRINGS


	

		// * TEST CHAR BONUSES 1_2 (full string)

	displayTestSeparator("BONUS STRING 1", 92);

	headings(1);
	v_printf = printf("[%12s]", "Salut");
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%12s]", "Salut");
	return_values(v_printf, v_ftprintf);
	bn();

	displayTestSeparator("BONUS STRING 2", 92);

	
	headings(1);
	v_printf = printf("[%-12s]", "Salut");
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%-12s]", "Salut");
	return_values(v_printf, v_ftprintf);
	bn();

	

	displayTestSeparator("BONUS STRING 3 ", 92);
	
	headings(1);
	v_printf = printf("[%.5s]", "Salut");
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%.5s]", "Salut");
	return_values(v_printf, v_ftprintf);
	bn();

	

	displayTestSeparator("BONUS STRING 4", 92);
	
	headings(1);
	v_printf = printf("[%.6s]", "Salut");
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%.6s]", "Salut");
	return_values(v_printf, v_ftprintf);
	bn();

	displayTestSeparator("BONUS STRING 5", 92);
	
	headings(1);
	v_printf = printf("[%.4s]", "Salut");
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%.4s]", "Salut");
	return_values(v_printf, v_ftprintf);
	bn();

	displayTestSeparator("BONUS STRING 6", 92);
	
	headings(1);
	v_printf = printf("[%4.4s]", "Salut");
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%4.4s]", "Salut");
	return_values(v_printf, v_ftprintf);
	bn();

	displayTestSeparator("BONUS STRING 7", 92);
	
	headings(1);
	v_printf = printf("[%5.4s]", "Salut");
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%5.4s]", "Salut");
	return_values(v_printf, v_ftprintf);
	bn();

	displayTestSeparator("BONUS STRING 8", 92);
	
	headings(1);
	v_printf = printf("[%6.4s]", "Salut");
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%6.4s]", "Salut");
	return_values(v_printf, v_ftprintf);
	bn();

	displayTestSeparator("BONUS STRING 9", 92);
	
	headings(1);
	v_printf = printf("[%-6.4s]", "Salut");
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%-6.4s]", "Salut");
	return_values(v_printf, v_ftprintf);
	bn();

	


		// * TEST CHAR BONUSES 2_2 (empty string)


		

	displayTestSeparator("BONUS STRING 10", 92);

	headings(1);
	v_printf = printf("[%12s]", empty);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%12s]", empty);
	return_values(v_printf, v_ftprintf);
	bn();

	displayTestSeparator("BONUS STRING 11", 92);

	
	headings(1);
	v_printf = printf("[%-12s]", empty);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%-12s]", empty);
	return_values(v_printf, v_ftprintf);
	bn();

	displayTestSeparator("BONUS STRING 12", 92);
	
	headings(1);
	v_printf = printf("[%.5s]", empty);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%.5s]", empty);
	return_values(v_printf, v_ftprintf);
	bn();

	displayTestSeparator("BONUS STRING 13", 92);
	
	headings(1);
	v_printf = printf("[%.6s]", empty);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%.6s]", empty);
	return_values(v_printf, v_ftprintf);
	bn();

	displayTestSeparator("BONUS STRING 14", 92);
	
	headings(1);
	v_printf = printf("[%.4s]", empty);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%.4s]", empty);
	return_values(v_printf, v_ftprintf);
	bn();

	displayTestSeparator("BONUS STRING 15", 92);
	
	headings(1);
	v_printf = printf("[%4.4s]", empty);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%4.4s]", empty);
	return_values(v_printf, v_ftprintf);
	bn();

	displayTestSeparator("BONUS STRING 16", 92);
	
	headings(1);
	v_printf = printf("[%5.4s]", empty);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%5.4s]", empty);
	return_values(v_printf, v_ftprintf);
	bn();

	displayTestSeparator("BONUS STRING 17", 92);
	
	headings(1);
	v_printf = printf("[%6.4s]", empty);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%6.4s]", empty);
	return_values(v_printf, v_ftprintf);
	bn();

	displayTestSeparator("BONUS STRING 18", 92);
	
	headings(1);
	v_printf = printf("[%-6.4s]", empty);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%-6.4s]", empty);
	return_values(v_printf, v_ftprintf);
	bn();

	displayTestSeparator("BONUS STRING 19", 92);
	
	headings(1);
	v_printf = printf("[%.0sh]", "Coucou");
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%.0sh]", "Coucou");
	return_values(v_printf, v_ftprintf);
	bn();


		// * TEST 9
	
	displayTestSeparator("Test %p adresses", 91);

	char *pointer_test = "test";

	headings(1);
	v_printf = printf("Adress = %p", &pointer_test);
	bn();
	headings(2);
	v_ftprintf = ft_printf("Adress = %p", &pointer_test);
	bn();

	return_values(v_printf, v_ftprintf);

		// * TEST 10
	
	displayTestSeparator("Test empty adress", 91);

	headings(1);
	v_printf = printf("Adress = %p", (void*)-1);
	bn();
	headings(2);
	v_ftprintf = ft_printf("Adress = %p", (void*)-1);
	bn();

	return_values(v_printf, v_ftprintf);

		// * TEST 11
	displayTestSeparator("Test null", 91);

	headings(1);
	v_printf = printf("Adress = %p", 0);
	bn();
	headings(2);
	v_ftprintf = ft_printf("Adress = %p", 0);
	bn();

	return_values(v_printf, v_ftprintf);

	// ! BONUS %P

	

	displayTestSeparator("BONUS %P 1", 91);

	headings(1);
	v_printf = printf("[%1p]", &pointer_test);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%1p]", &pointer_test);
	bn();
	return_values(v_printf, v_ftprintf);

	displayTestSeparator("BONUS %P 2", 91);

	headings(1);
	v_printf = printf("[%12p]", &pointer_test);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%12p]", &pointer_test);
	bn();
	return_values(v_printf, v_ftprintf);

	displayTestSeparator("BONUS %P 3", 91);

	headings(1);
	v_printf = printf("[%-20p]", &pointer_test);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%-20p]", &pointer_test);
	bn();
	return_values(v_printf, v_ftprintf);


	// ! FIN BONUS P

	
	

		// * TEST 12
	displayTestSeparator("Test %u positive int", 95);

	headings(1);
	v_printf = printf("%u", 42);
	bn();
	headings(2);
	v_ftprintf = ft_printf("%u", 42);
	bn();

	return_values(v_printf, v_ftprintf);

	// * TEST 13

	displayTestSeparator("Test %u int_max", 95);

	headings(1);
	v_printf = printf("%u", INT_MAX);
	bn();
	headings(2);
	v_ftprintf = ft_printf("%u", INT_MAX);
	bn();

	return_values(v_printf, v_ftprintf);


	// * TEST 14

	displayTestSeparator("Test %u null int", 95);

	headings(1);
	v_printf = printf("%u", 0);
	bn();
	headings(2);
	v_ftprintf = ft_printf("%u", 0);
	bn();

	return_values(v_printf, v_ftprintf);

	// * TEST 15

	displayTestSeparator("Test %u return ft int", 95);

	headings(1);
	v_printf = printf("%u", test_unsigned_int(42));
	bn();
	headings(2);
	v_ftprintf = ft_printf("%u", test_unsigned_int(42));
	bn();

	return_values(v_printf, v_ftprintf);

	// * TEST 16

	displayTestSeparator("Test %u beyond int max", 95);

	headings(1);
	v_printf = printf("%u", 2148000000);
	bn();
	headings(2);
	v_ftprintf = ft_printf("%u", 2148000000);
	bn();

	return_values(v_printf, v_ftprintf);

	// * TEST 17

	displayTestSeparator("Test %i int positive", 92);

	headings(1);
	v_printf = printf("%i", 42);
	bn();
	headings(2);
	v_ftprintf = ft_printf("%i", 42);
	bn();

	return_values(v_printf, v_ftprintf);

	// * TEST 18

	displayTestSeparator("Test %i int negative", 92);

	headings(1);
	v_printf = printf("%i", -42);
	bn();
	headings(2);
	v_ftprintf = ft_printf("%i", -42);
	bn();

	return_values(v_printf, v_ftprintf);

	// * TEST 19

	displayTestSeparator("Test %i int null", 92);

	headings(1);
	v_printf = printf("%i", 0);
	bn();
	headings(2);
	v_ftprintf = ft_printf("%i", 0);
	bn();

	return_values(v_printf, v_ftprintf);

	
	// * TEST 20

	displayTestSeparator("Test %i int max", 92);

	headings(1);
	v_printf = printf("%i", INT_MAX);
	bn();
	headings(2);
	v_ftprintf = ft_printf("%i", INT_MAX);

	return_values(v_printf, v_ftprintf);

	
	// * TEST 21

	displayTestSeparator("Test %i int min", 92);

	headings(1);
	v_printf = printf("%i", INT_MIN);
	bn();
	headings(2);
	v_ftprintf = ft_printf("%i", INT_MIN);

	return_values(v_printf, v_ftprintf);

	// * TEST 22

	displayTestSeparator("Test %i int multiples", 92);

	headings(1);
	v_printf = printf("%i%i%i%i%i%i%i", 10, 23, -2, 37, 200, -9999, 977779);
	bn();
	headings(2);
	v_ftprintf = ft_printf("%i%i%i%i%i%i%i", 10, 23, -2, 37, 200, -9999, 977779);
	
	return_values(v_printf, v_ftprintf);


	// ! BONUS PART i

	displayTestSeparator("BONUS %i 1", 92);

	headings(1);
	v_printf = printf("[%1i]", 0);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%1i]", 0);

	return_values(v_printf, v_ftprintf);

	
	
	displayTestSeparator("BONUS %i 2", 92);

	headings(1);
	v_printf = printf("[%1i]", -4);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%1i]", -4);

	return_values(v_printf, v_ftprintf);

	displayTestSeparator("BONUS %i 3", 92);

	headings(1);
	v_printf = printf("[%10i]", 42);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%10i]", 42);

	return_values(v_printf, v_ftprintf);

	displayTestSeparator("BONUS %i 4", 92);

	headings(1);
	v_printf = printf("[%20i]", -42000);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%20i]", -42000);

	return_values(v_printf, v_ftprintf);

	displayTestSeparator("BONUS %i 5", 92);

	headings(1);
	v_printf = printf("[%20i]", 42000);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%20i]", 42000);

	return_values(v_printf, v_ftprintf);

	displayTestSeparator("BONUS %i 6", 92);

	headings(1);
	v_printf = printf("[%-20i]", 42000);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%-20i]", 42000);

	return_values(v_printf, v_ftprintf);

	displayTestSeparator("BONUS %i 7", 92);

	headings(1);
	v_printf = printf("[%-20i]", -42000);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%-20i]", -42000);

	return_values(v_printf, v_ftprintf);



	

	displayTestSeparator("BONUS %i 8", 92);

	headings(1);
	v_printf = printf("[%.3i]", -1);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%.3i]", -1);

	return_values(v_printf, v_ftprintf);

	displayTestSeparator("BONUS %i 9", 92);

	headings(1);
	v_printf = printf("[%.5i]", 1234);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%.5i]", 1234);

	return_values(v_printf, v_ftprintf);

	displayTestSeparator("BONUS %i 10", 92);

	headings(1);
	v_printf = printf("[%.13i]", INT_MIN);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%.13i]", INT_MIN);

	return_values(v_printf, v_ftprintf);

	displayTestSeparator("BONUS %i 11", 92);

	headings(1);
	v_printf = printf("[%.1i]", INT_MIN + 1);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%.1i]", INT_MIN + 1);
	return_values(v_printf, v_ftprintf);


	displayTestSeparator("BONUS %i 12", 92);

	headings(1);
	v_printf = printf("[%.1i]", INT_MIN);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%.1i]", INT_MIN);
	return_values(v_printf, v_ftprintf);

	displayTestSeparator("BONUS %i 13", 92);
	
		headings(1);
	v_printf = printf("[%.1i]", INT_MAX);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%.1i]", INT_MAX);

	return_values(v_printf, v_ftprintf);

	displayTestSeparator("BONUS %i 14", 92);

	headings(1);
	v_printf = printf("[%.0i]", 42);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%.0i]", 42);

	return_values(v_printf, v_ftprintf);

	displayTestSeparator("BONUS %i 15", 92);

	headings(1);
	v_printf = printf("[%.0i]", 0);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%.0i]", 0);

	return_values(v_printf, v_ftprintf);

	displayTestSeparator("BONUS %i 16", 92);

	headings(1);
	v_printf = printf("[%.1i]", 0);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%.1i]", 0);

	return_values(v_printf, v_ftprintf);

	displayTestSeparator("BONUS %i 17", 92);

	headings(1);
	v_printf = printf("[%.2i]", 0);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%.2i]", 0);

	return_values(v_printf, v_ftprintf);

	displayTestSeparator("BONUS %i 18", 92);

	headings(1);
	v_printf = printf("[%-1.8i]", 0);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%-1.8i]", 0);

	return_values(v_printf, v_ftprintf);

	displayTestSeparator("BONUS %i 19", 92);

	headings(1);
	v_printf = printf("[%-1.0i]", -10);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%-1.0i]", -10);

	return_values(v_printf, v_ftprintf);

	displayTestSeparator("BONUS %i 20", 92);

	headings(1);
	v_printf = printf("[%-10.0i]", 0);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%-10.0i]", 0);

	return_values(v_printf, v_ftprintf);

	displayTestSeparator("BONUS %i 21", 92);

	headings(1);
	v_printf = printf("[%-20.19i]", 8000);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%-20.19i]", 8000);

	return_values(v_printf, v_ftprintf);

	displayTestSeparator("BONUS %i 22", 92);

	headings(1);
	v_printf = printf("[%20.19i]", 8000);
	bn();
	headings(2);
	v_ftprintf = ft_printf("[%20.19i]", 8000);

	return_values(v_printf, v_ftprintf);

	

	

	

	
	// * TEST 23

	displayTestSeparator("Test %x hexa number", 96);

	headings(1);
	v_printf = printf("%x", 4251);
	bn();
	headings(2);
	v_ftprintf = ft_printf("%x", 4251);
	
	return_values(v_printf, v_ftprintf);

	// * TEST 24

	displayTestSeparator("Test %x other value hexa number", 96);

	headings(1);
	v_printf = printf("%x", 10);
	bn();
	headings(2);
	v_ftprintf = ft_printf("%x", 10);
	
	return_values(v_printf, v_ftprintf);

		// * TEST 25

	displayTestSeparator("Test %x null hexa number", 96);

	headings(1);
	v_printf = printf("%x", 0);
	bn();
	headings(2);
	v_ftprintf = ft_printf("%x", 0);
	
	return_values(v_printf, v_ftprintf);

		// * TEST 26

	displayTestSeparator("Test %x int_max hexa number", 96);

	headings(1);
	v_printf = printf("%x", INT_MAX);
	bn();
	headings(2);
	v_ftprintf = ft_printf("%x", INT_MAX);
	
	return_values(v_printf, v_ftprintf);


		// * TEST 27.1

	displayTestSeparator("Test %x shitty hexa number", 96);

	headings(1);
	v_printf = printf("%x", 3735929054u);
	bn();
	headings(2);
	v_ftprintf = ft_printf("%x", 3735929054u);
	
	return_values(v_printf, v_ftprintf);

		// * TEST 27.2

	displayTestSeparator("Test %x neg hexa number", 96);

	headings(1);
	v_printf = printf("%x", -1);
	bn();
	headings(2);
	v_ftprintf = ft_printf("%x", -1);
	
	return_values(v_printf, v_ftprintf);

	///////////////////////////

	// * TEST 28

	displayTestSeparator("Test %X hexa number", 93);

	headings(1);
	v_printf = printf("%X", 4251);
	bn();
	headings(2);
	v_ftprintf = ft_printf("%X", 4251);
	
	return_values(v_printf, v_ftprintf);

	// * TEST 29

	displayTestSeparator("Test %X other hexa number", 93);

	headings(1);
	v_printf = printf("%X", 10);
	bn();
	headings(2);
	v_ftprintf = ft_printf("%X", 10);
	
	return_values(v_printf, v_ftprintf);

		// * TEST 30

	displayTestSeparator("Test %X null hexa number", 93);

	headings(1);
	v_printf = printf("%X", 0);
	bn();
	headings(2);
	v_ftprintf = ft_printf("%X", 0);
	
	return_values(v_printf, v_ftprintf);

		// * TEST 31

	displayTestSeparator("Test %X int_max hexa number", 93);

	headings(1);
	v_printf = printf("%X", INT_MAX);
	bn();
	headings(2);
	v_ftprintf = ft_printf("%X", INT_MAX);
	
	return_values(v_printf, v_ftprintf);


		// * TEST 32.1

	displayTestSeparator("Test %X shitty hexa number", 93);

	headings(1);
	v_printf = printf("%X", 3735929054u);
	bn();
	headings(2);
	v_ftprintf = ft_printf("%X", 3735929054u);
	
	return_values(v_printf, v_ftprintf);

		// * TEST 32.2

	displayTestSeparator("Test %X shitty hexa number", 93);

	headings(1);
	v_printf = printf("%X", -1);
	bn();
	headings(2);
	v_ftprintf = ft_printf("%X", -1);
	
	return_values(v_printf, v_ftprintf);
}
