#include <stdio.h>
#include "ft_printf/includes/ft_printf.h"

int main(void)
{
    int count = 0;
	int i = 8;
	char n = 'D';
	int temp = 0;
	char array[9];
	char base[] = "01";
	
	while (n != 0)
	{
		temp = n % 2;
		array[i--] = base[temp];
		n /= 2;
	}
	while (i <= 8)
	{
		count += ft_printchar(array[i]);
		i++;
	}
	return (count);
}
