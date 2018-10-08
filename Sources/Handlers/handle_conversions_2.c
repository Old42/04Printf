#include "../../Includes/Auxiliary_Functions/bonus.h"
#include "../../Includes/Auxiliary_Functions/numbers_functions.h"
#include "../../Includes/Auxiliary_Functions/numbers_functions_hexa.h"
#include "../../Includes/Auxiliary_Functions/strings_functions.h"

int		handle_conversions_7(char conv, va_list *ap, t_flag flag, int lenght_conv)
{
	int		total_len;

	if (conv == 'b')
	{
		if (lenght_conv == H)
			total_len = convert_dec_to_binary((unsigned short) (va_arg(*ap, int)), flag);
		else if (lenght_conv == HH)
			total_len = convert_dec_to_binary((unsigned char) (va_arg(*ap, int)), flag);
		else if (lenght_conv == L)
			total_len = convert_dec_to_binary(va_arg(*ap, unsigned long), flag);
		else if (lenght_conv == LL)
			total_len = convert_dec_to_binary(va_arg(*ap, unsigned long long), flag);
		else if (lenght_conv == J)
			total_len = convert_dec_to_binary(va_arg(*ap, uintmax_t), flag);
		else if (lenght_conv == Z)
			total_len = convert_dec_to_binary(va_arg(*ap, unsigned long), flag);
		else
		total_len = convert_dec_to_binary(va_arg(*ap, unsigned int), flag);
	}
	else if (conv == 'f' || conv == 'F')
		total_len = my_putnbr_double(va_arg(*ap, double), flag);
	return (total_len);
}

int		handle_conversions_6(char conv, va_list *ap, t_flag flag,int lenght_conv)
{
	int		total_len;

	if (conv == 'X')
	{
		if (lenght_conv == H)
			total_len = my_putnbr_HEXA((unsigned short) (va_arg(*ap, int)), flag);
		else if (lenght_conv == HH)
			total_len = my_putnbr_HEXA((unsigned char) (va_arg(*ap, int)), flag);
		else if (lenght_conv == L)
			total_len = my_putnbr_HEXA(va_arg(*ap, unsigned long), flag);
		else if (lenght_conv == LL)
			total_len = my_putnbr_HEXA(va_arg(*ap, unsigned long long), flag);
		else if (lenght_conv == J)
			total_len = my_putnbr_HEXA(va_arg(*ap, uintmax_t), flag);
		else if (lenght_conv == Z)
			total_len = my_putnbr_HEXA(va_arg(*ap, unsigned long), flag);
		else
		total_len = my_putnbr_HEXA(va_arg(*ap, unsigned int), flag);
	}
	else if (conv == 'c')
		total_len = my_putchar_printf((char) (va_arg(*ap, int)), flag);
	else if (conv == 's')
		total_len = my_putstr_printf(va_arg(*ap, char *), flag);
	else
	handle_conversions_7(conv, ap, flag, lenght_conv);
	return (total_len);
}