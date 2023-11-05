#include <stdio.h>

int main(void)
{

	char c = 'A';
	char *str = "Salut";
	char *adress = "qwghtgtrefrg";
	char *empty_adress = NULL;
	int pos_int = 123;
	int neg_int = -123;
	int nul_int = 0;
	int hexa = 0xdeadc0de;
	int neg_hexa = 0xD7;
	int octal = 0337;

	int return_value;


	// printf("[%-c]\n-----\n\n", c);

	// printf("[%-12.3s]\n-----\n\n", str);
	
	// printf("[%p]\n-----\n\n", adress);

	// printf("[%50p]\n-----\n\n", empty_adress);
	
	// return_value = printf("[%.4i]", pos_int);

	// printf("\n---\nReturn value = %i\n\n", return_value - 2);

	// return_value = printf("[%.3i]", neg_int);

	// printf("\n---\nReturn value = %i\n\n", return_value - 2);

	// return_value = printf("[%.i]", nul_int);

	// printf("\n---\nReturn value = %i\n\n", return_value - 2);

	return_value = printf("[%.20x]", hexa);

	printf("\n---\nReturn value = %i\n\n", return_value - 2);

	// return_value = printf("[%+.6i]", 12345);

	// printf("\n---\nReturn value = %i\n\n", return_value - 2);

	// return_value = printf("[%.7i]", -12345);

	// printf("\n---\nReturn value = %i\n\n", return_value - 2);

	// return_value = printf("[%+.7i]", -12345);

	// printf("\n---\nReturn value = %i\n\n", return_value - 2);


	// return_value = printf("[%+.6i]", -12345);

	// printf("\n---\nReturn value = %i\n\n", return_value - 2);

	// return_value = printf("[%.1i]", nul_int);

	// printf("\n---\nReturn value = %i\n\n", return_value - 2);

	// return_value = printf("[%.1i]", 1);

	// printf("\n---\nReturn value = %i\n\n", return_value - 2);

	// 	return_value = printf("[%.2i]", 1);

	// printf("\n---\nReturn value = %i\n\n", return_value - 2);


	// return_value = printf("[%.7i]", nul_int);

	// printf("\n---\nReturn value = %i\n\n", return_value - 2);

	
	// printf("%d\n-----\n\n", neg_int);
	
	// printf("[%.4i]\n-----\n\n", pos_int);
	
	// printf("%-12i\n-----\n\n", neg_int);

	// printf("[%-5i]\n-----\n\n", neg_hexa);

// 	printf("%i\n-----\n\n", hexa);
	
// 	printf("%u\n-----\n\n", pos_int);
	
// 	printf("%x\n-----\n\n", pos_int);
	
	// printf("%x\n-----\n\n", neg_int);
	// printf("%#.10x\n-----\n\n", neg_int);
	
// 	printf("%X\n-----\n\n", hexa);

// 	printf("%X\n-----\n\n", neg_hexa);
	
	// printf("[%%]\n-----\n\n");
// }

}

/*

?											GENERAL STRUCTURE OF PRINTF 

!					% 		[flags]			[width]			[.precision]		placeholder

---------------------------------------------------------------------------------------------------------------
					! FLAGS :


- = Presence de - comme %-5i (avec i = 42) ==> [42   ] %5i => [   42]
--------------------------------------
+ = Forces the printing of a plus sign for positives int numbers
--------------------------------------
' ' (whitespace) = Add a single space before a positive number
--------------------------------------
# = Adds either a 0x (for %x) or a 0X (for %X) 
--------------------------------------
0 (zero) = 
--------------------------------------

* CLASHING FLAGS


! ' ' and + => Basically does not works





----------------------------------------------------------------------------------------------------------------

! WIDTH

The concept of widh basically adds up x spaces before or after the number

? FLAGS OF WIDTH ==>

- = Ident the width AFTER 
Lack of - flag = Ident the width BEFORE

0 = In the first place, ident 0 characters instead of spaces



----------------------------------------------------------------------------------------------------------------
! .PRECISION

.(number)

NUMBER CASES : Cela affiche le nombre de caracteres minimum a afficher,
Si le chiffre est plus grand que la precision, cela ne tronque pas le chiffre

int n = 42;
printf("%.1i", n); ==> Outputs 42
printf("%.2i", n); ==> Outputs 42
printf("%.3i", n); ==> Outputs 042
printf("%.4i", n); ==> Outputs 0042
printf("%.5i", n); ==> Outputs 00042

STRING CASES : Cela affiche le nombre de caractere maximum
Si la string est plus grande que la precision, dans ce cas la precision prends le dessus
et tronque la phrase

char *str = "salut";

printf("%s", str); ==> Outputs "salut"
printf("%.5s", str); ==> Outputs "salut"
printf("%.4s", str); ==> Outputs "salu"
printf("%.3s", str); ==> Outputs "sal"

! COMBO CASES

! [] within the printf is to better visualize width filed

char *str = "salut";
printf("[%-5.4s]\n-----\n\n", str); ==> Outputs [salu ]
printf("[%5.4s]\n-----\n\n", str); ==> Outputs [ salu]



printf("%#.10x\n-----\n\n", neg_int); ==> 0x00ffffffd6 so 10 precision and the # flag does not count into the precision

----------------------------------------------------------------------------------------------------------------
! PLACEHOLDERS




--------------------------------------
%c	= Character
--------------------------------------
%s	= String
--------------------------------------
%p	= Adress
--------------------------------------
%d	= Base 10 number
--------------------------------------
%i	= Convert to base 10 (from hexa and octal)
--------------------------------------
%u	= positive base 10
--------------------------------------
%x	= Unsigned int => Hexa lowercase
--------------------------------------
%X	= Unsigned int => Hexa uppercase
--------------------------------------
%%	= Print %


----------------------------------------------------------------------------------------------------------------








*/