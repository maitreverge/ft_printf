#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct s_flags {
	char placeholder;
	int hashtag;
	int plus_sign;
	int space;
	int minus_sign;
	int zero;
	int point;
	int width;
	int precision;
} t_flags;

t_flags	zero_init_struct()
{
	t_flags f;
	
	f.placeholder = 0;
	f.hashtag = 0;
	f.plus_sign = 0;
	f.space = 0;
	f.minus_sign = 0;
	f.zero = 0;
	f.width = 0;
	f.point = 0;
	f.precision = 0;
	return (f);
}

int width_or_precision(char *s)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (isdigit(s[i]))
	{
		result = (10 * result) + s[i] - 48;
		i++;
	}
	return (result);
}

t_flags	turbo_parsing(char *format)
{
	t_flags current_flag;

	current_flag = zero_init_struct();
	int i = 0;
	while (!isdigit(format[i]))
	{
		if (format[i] == '#')
			current_flag.hashtag = 1;
		if (format[i] == ' ')
			current_flag.space = 1;
		if (format[i] == '+')
			current_flag.plus_sign = 1;
		if (format[i] == '-')
			current_flag.minus_sign = 1;
		if (format[i] == '0')
			current_flag.zero = 1;
		i++;
	}
	// pousser le parsing des combinaisons de flags qui s'annullent
	if (current_flag.space == 1 && current_flag.plus_sign == 1)
	{
		current_flag.space = 0;
		current_flag.plus_sign = 0;
	}
	current_flag.width = width_or_precision(&format[i]);
	while (isdigit(format[i]))
		i++;
	if (format[i] == '.')
	{
		current_flag.point = 1;
		i++;
	}
	if (current_flag.point = 1)
		current_flag.precision = width_or_precision(&format[i]);
	while (isdigit(format[i]))
		i++;
	current_flag.placeholder = format[i];
	return (current_flag);
}



void	print_struct(t_flags s)
{
	printf("placeholder = %c\n---\n", s.placeholder);
	printf("hashtag = %i\n---\n", s.hashtag);
	printf("plus_sign = %i\n---\n", s.plus_sign);
	printf("space = %i\n---\n", s.space);
	printf("minus_sign = %i\n---\n", s.minus_sign);
	printf("zero = %i\n---\n", s.zero);
	printf("point = %i\n---\n", s.point);
	printf("width = %i\n---\n", s.width);
	printf("precision = %i\n---\n", s.precision);

}

int main(void)
{
	t_flags test;

	char *str = "abcd%# +-056.56cABCD";

	test = turbo_parsing(str);
	print_struct(test);
}