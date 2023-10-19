#include <stdio.h>

int main(void)
{

	// 3735929054 == deadc0de
	int i = 1735929054;
	char str[] = "salut";

	// printf("%#x\n", i);
	printf("% s\n", str);
	// printf("%+ d\n", i);
}


/*

GENERAL STRUCTURE OF PRINTF 

% [flags]		[width]			[.precision]  placeholder


! FLAGS :

- =
--------------------------------------
+ = 
--------------------------------------
' ' (whitespace) = 
--------------------------------------
# = Adds either a 0x (for %x) or a 0X (for %X) 
--------------------------------------
0 (zero) = 
--------------------------------------

! WIDTH

! .PRECISION


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
--------------------------------------









*/