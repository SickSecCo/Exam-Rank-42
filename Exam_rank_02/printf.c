#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int print_int(int num)
{
	static int count = 0;
	if(num > 9)
		print_int(num / 10);
	if (num < 0)
	{
		count += ft_putchar('-');
		print_int(-num);
	}
	else
		count += ft_putchar((num % 10) + '0');
	return (count);
}

int print_hex(unsigned int num)
{
	static int count = 0;
	char base[16] = "0123456789abcdef";
	if (num > 16)
		print_hex(num / 16);
	count += ft_putchar(base[num % 16]);
	return (count);
}

int print_string(char *s)
{
	int i = 0 , count = 0;
	if (!s)
		return(print_string("(null)"));
	while (s[i])
	{
		count += ft_putchar(s[i]);
		i++;
	}
	return (count);
}

int ft_printf(char *s, ...)
{
	va_list arg;
	int i = 0;
	int count = 0;
	va_start(arg, s);
	while (s[i]){
		if(s[i] == '%'){
			i++;
			if(s[i] == 'd'){
				count += print_int(va_arg(arg, int));
			}
			if(s[i] == 'x'){
				count += print_hex(va_arg(arg, unsigned int));
			}
			if(s[i] == 's'){
				count += print_string(va_arg(arg, char *));
			}
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	return(count);
}

int main(){
	int i;
	i = ft_printf("%d%s%x", 123456, "123456", 0);
	printf("\n%d\n", i);
}

