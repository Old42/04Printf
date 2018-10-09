#include "../../Includes/Print_Unicode/create_and_print_t_bin_list.h"
#include "../../Includes/Handlers/handlers.h"


unsigned int				compute_minimum_number_of_bits(unsigned int n)
{
	unsigned int		pow2;
	unsigned int		k;

	pow2 = 1;
	k = 0;
	while (n >  pow2)
	{
		pow2 = 2 * pow2;
		k++;
	}
	return (k);
}

int				compute_minimum_number_of_bytes_in_utf8(int decimal)
{
	int		numb_of_bits;

	numb_of_bits = compute_minimum_number_of_bits(decimal);
	if (numb_of_bits <= 7)
		return (1);
	else if (numb_of_bits <= 11)
		return (2);
	else if (numb_of_bits <= 16)
		return (3);
	else if (numb_of_bits <= 21)
		return (4);
	else if (numb_of_bits <= 26)
		return (5);
	else// (numb_of_bits <= 31)
		return (6);
}

int				compute_power(int base, unsigned int exposant)
{
	int		result;

	if (exposant == 0)
		return (1);
	result = 1;
	while (exposant > 0)
	{
		result = result * base;
		exposant--;
	}
	return (result);
}

void			convert_bin_to_dec(t_bin_list *begin_list)
{
	t_bin_list	*temp;
	int			i;
	int			n;

	temp = begin_list;
	while (temp)
	{
		i = 7;
		n = 0;
		while (i >= 0)
		{
			n =  n +(temp->binary[i] - '0') * compute_power(2, 7 - i);
			i--;
		}
		temp->binary[0] = (unsigned char)n;
		temp->binary[1] = 0;
		temp = temp->next;
	}
}

void	annex_to_convert_dectobin(int i, int n_bytes, t_bin_list *b_list, int dec)
{
	int		j;
	
	while (i <= n_bytes)
	{
		j = 7;
		if (i++ == n_bytes)
		{
			while (j > n_bytes)
			{
				b_list->binary[j--] = (unsigned char) (char)(dec % 2 + 48);
				dec = dec / 2;
			}
			while (--j >= 0)
				b_list->binary[j] = '1';
			break;
		}
		else
		{
			(b_list->binary)[0] = '1';
			while (j >= 2)
			{
				b_list->binary[j--] = (unsigned char)(dec % 2 + 48);
				dec = dec / 2;
			}
		}
		b_list = b_list->next;
	}
}

void			convert_dec_to_bin_utf8(int	number_of_bytes, t_bin_list *begin_bin_list, int dec)
{
	t_bin_list	*temp;
	int			i;
	int			j;

	temp = begin_bin_list;
	i = 1;
	if (number_of_bytes != 1)
		annex_to_convert_dectobin(i, number_of_bytes, begin_bin_list, dec);
	else
	{
		j = 7;
		while (j >= 0)
		{
			temp->binary[j--] = (unsigned char)(dec % 2 + 48);
			dec = dec / 2;
		}
	}
}

/*
 * Remplit les octets en convertissant le nombre decimal en binaire, au format UTF8
 */
