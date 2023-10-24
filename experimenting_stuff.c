#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct s_flags {
	char	placeholder;
	int		hashtag;
	int		plus_sign;
	int		space;
	int		minus_sign;
	int		zero;
	int		width;
	int		point;
	size_t	precision;
	int		lenght_print;
}	t_flags;

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
	printf("precision = %li\n---\n", s.precision);
	printf("lenght_print = %i\n---\n", s.lenght_print);
}

t_flags	zero_init_struct(void)
{
	t_flags	f;

	f.placeholder = '\0';
	f.hashtag = 0;
	f.plus_sign = 0;
	f.space = 0;
	f.minus_sign = 0;
	f.zero = 0;
	f.width = 0;
	f.point = 0;
	f.precision = 0;
	f.lenght_print = 0;
	return (f);
}

int	width_or_precision(const char *s)
{
	int	result;
	int i;

	result = 0;
	i = 0;
	while (isdigit(s[i]))
	{
		result = (10 * result) + (s[i] - 48);
		i++;
	}
	return (result);
}

t_flags	cleaning_parsing(t_flags f)
{
	if (f.plus_sign >= 1 && f.space >= 1)
	{
		f.plus_sign = 0;
		f.space = 0;
	}
	if (f.hashtag > 1)
		f.hashtag = 1;
	if (f.plus_sign > 1)
		f.plus_sign = 1;
	if (f.space > 1)
		f.space = 1;
	if (f.minus_sign > 1)
		f.minus_sign = 1;
	if (f.zero > 1)
		f.zero = 1;
	if (f.point > 1)
		f.point = 1;
	return (f);
}

t_flags	first_part_parsing(const char *format, int *i)
{
	t_flags	current_flag;

	current_flag = zero_init_struct();
	while (!isdigit(format[*i]))
	{
		if (format[*i] == '#')
			current_flag.hashtag++;
		else if (format[*i] == ' ')
			current_flag.space++;
		else if (format[*i] == '+')
			current_flag.plus_sign++;
		else if (format[*i] == '-')
			current_flag.minus_sign++;
		(*i)++;
	}
	return (current_flag);
}

int	check_placeholder(char c)
{
	if (c == '%' || c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

t_flags	turbo_parsing(const char *format)
{
	t_flags	current_flag;
	int		i;

	current_flag = zero_init_struct();
	i = 0;
	if (check_placeholder(format[i]) == 1)
	{
		current_flag.placeholder = format[i];
		return (current_flag);
	}
	current_flag = first_part_parsing(&format[i], &i);
	while (format[i] == '0')
	{
		current_flag.zero++;
		i++;
	}
	if (format[i] != '.' && isdigit(format[i]))
	{
		current_flag.width = width_or_precision(&format[i]);
		while (isdigit(format[i]))
			i++;
	}
	while (format[i] == '.')
	{
		current_flag.point++;
		i++;
	}
	if (current_flag.point >= 1 && isdigit(format[i]))
	{
		current_flag.precision = width_or_precision(&format[i]);
		while (isdigit(format[i]))
			i++;
	}
	current_flag.placeholder = format[i];
	current_flag = cleaning_parsing(current_flag);
	return (current_flag);
}



int main(void)
{
	t_flags test;

	// char *str = "abcd%# -+# +--  #+ -+ #+ #-#  - +00000506.47447ajjABCD";
	char *str = "abcd%#-++0506.47447cjjABCD";

	test = turbo_parsing(&str[5]);
	print_struct(test);
}

/*


# -+# +--  #+ -+ #+ #-#  - +

6 #
10 spaces
6 minus signs
6 plus signs

*/