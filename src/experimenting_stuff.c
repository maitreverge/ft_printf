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

t_flags cleaning_parsing(t_flags f)
{
	// ? clean the placeholder if wrong values
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

t_flags	turbo_parsing(char *format)
{
	t_flags current_flag;

	current_flag = zero_init_struct();
	int i = 0;
	// ! 1/6 parsing # / space / + / -
	while (!isdigit(format[i]))
	{
		if (format[i] == '#')
			current_flag.hashtag++;
		if (format[i] == ' ')
			current_flag.space++;
		if (format[i] == '+')
			current_flag.plus_sign++;
		if (format[i] == '-')
			current_flag.minus_sign++;
		i++;
	}
	// ! 2/6 parsing, zero number
	while (format[i] == '0')
	{
		current_flag.zero++;
		i++;
	}
	// ! 3/6 parsing width
	if (format[i] != '.' && isdigit(format[i]))
	{
		current_flag.width = width_or_precision(&format[i]);
		while (isdigit(format[i]))
			i++;
	}
	// ! 4/6 parsing point
	while (format[i] == '.')
	{
		current_flag.point++;
		i++;
	}
	// ! 5/6 parsing precision
	if (current_flag.point == 1 && isdigit(format[i]))
	{
		current_flag.precision = width_or_precision(&format[i]);
		while (isdigit(format[i]))
			i++;
	}
	current_flag.placeholder = format[i];
	return (current_flag);

	// ! needs a cleaning parsing function


}




int main(void)
{
	t_flags test;

	char *str = "abcd%# -+# +--  #+ -+ #+ #-#  - +000506.4747cABCD";

	test = turbo_parsing(&str[4]);
	print_struct(test);
}

/*


# -+# +--  #+ -+ #+ #-#  - +

6 #
10 spaces
6 minus signs
6 plus signs

*/