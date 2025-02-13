/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <giuliafanelli111@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:11:38 by gifanell          #+#    #+#             */
/*   Updated: 2025/01/20 17:38:12 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_formats(va_list ap, const char specifier)
{
	int	res;

	res = 0;
	if (specifier == 'c')
		res += ft_putchar(va_arg(ap, int));
	else if (specifier == 's')
		res += ft_putstr(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		res += ft_putnbr(va_arg(ap, int));
	else if (specifier == 'x' || specifier == 'X')
		res += ft_puthex(va_arg(ap, unsigned int), specifier == 'x');
	else if (specifier == 'u')
		res += ft_uputnbr(va_arg(ap, unsigned int));
	else if (specifier == 'p')
		res += ft_putptr(va_arg(ap, unsigned long));
	else if (specifier == '%')
		res += ft_putchar('%');
	return (res);
}

int	ft_printf(const char *format_str, ...)
{
	va_list	ap;
	size_t	i;
	int		res;

	va_start(ap, format_str);
	i = 0;
	res = 0;
	if (!format_str)
		return (-1);
	while (format_str && format_str[i])
	{
		if (format_str[i] == '%')
		{
			res += ft_print_formats(ap, format_str[i + 1]);
			i++;
		}
		else
			res += ft_putchar(format_str[i]);
		i++;
	}
	va_end(ap);
	return (res);
}

/* DESCRIPTION
	/ENG/
	DESCRIZIONE/SPIEGAZIONE FUNZIONE
	/ITA/
	Il nuovo concetto di questo progetto sono le funzioni variadiche:
	Le funzioni che hai utilizzato e creato finora nel tuo corso avevano
	argomenti fissi. Potrebbero essercene diversi, ma sapevi sempre
	in anticipo di quali argomenti avresti avuto bisogno.
	Una funzione variadica percio' è una funzione che accetta un
	numero variabile di argomenti.
	È caratterizzato dal "..." (ellissi) in una funzione.
	La funzione variadica deve avere almeno un argomento obbligatorio,
	const char *format è l'argomento obbligatorio di printf.
	Non esiste un numero minimo di argomenti variabili.
	Va_list è un tipo di oggetto adatto a contenere le informazioni
	necessarie alle macro va_start (inizializza), va_copy, va_arg e va_end
	In altre parole, è una lista che conterrà tutti gli argomenti
	dinamici.
	va_start deve essere chiamato prima di qualsiasi utilizzo di
	va_arg, altrimenti la variabile/tabella va_list sarà vuota.
	Una volta terminato "il programma" non dimenticare di ripulire
	l'oggetto che hai inizializzato chiamando va_start.
	Per farlo si usa va_end che liberera' la memoria allocata.
   CHANGE_LOG
   	CAMBIAMENTO APPORTATO E PERCHE'
   RETURN VALUE
	La funzione ritorna un int principalmente per verificare la presenza
	di errori, se viene restituito un valore positivo (indicante il
	numero di caratteri scritti) significa che l'operazione è andata a
	buon fine se viene restituito un numero negativo (0)
	si è verificato un errore.
----------------------------------------------------------------------------
*/

/*  int main()
{
	ft_printf("%s\n","");
	printf("%s\n","");
} */

/* int	main(void)
{
	char	prova_1 = 'a';
 	char	prova2[] = "mamma funzionaaaa";
 	int		prova_3 = -2147483648;
 	long	prova_4 = 2147483649;
	char	*str = NULL;
	
	ft_printf("%%c __________________________\n");
	ft_printf("ft prima prova di char: %c\n", prova_1);
	printf("prima prova di char: %c\n", prova_1);
	printf("n char %d\n", ft_printf("prima prova di char: %c\n", prova_1));
	printf("n char %d\n", printf("prima prova di char: %c\n", prova_1));

	ft_printf("%%s __________________________\n");
	ft_printf("seconda prova stringa mia : %s\n", prova2);
	printf("seconda prova stringa real : %s\n", prova2);
	printf("n char %d\n", ft_printf("prima prova di char: %s\n", prova2));
	printf("n char %d\n", printf("prima prova di char: %s\n", prova2));

	ft_printf("%%%% __________________________\n");
	ft_printf("proviamo la doppia percentuale mia : %%\n");
	printf("doppia percentuale real : %%\n");
	printf("n char %d\n", ft_printf("%%\n"));
	printf("n char %d\n", printf("%%\n"));
	
	ft_printf("%%d %%i __________________________\n");
	ft_printf("prova numero mia: %d %i\n", prova_3, prova_3);
	printf("n char mio %d\n", ft_printf("%d %i\n", prova_3, prova_3));
	printf("n char real %d\n", ft_printf("%d %i\n", prova_3, prova_3));
	printf("n char real %d\n", printf("%d %i\n", prova_3, prova_3));

	ft_printf("%%u __________________________\n");
	ft_printf("prova unsigned mio: %u\n", prova_4);
	printf("prova unsigned mio: %ld\n", prova_4);
	printf("n char real %d\n", ft_printf("prova unsigned mio: %u\n",
						prova_4));
	printf("n char real %d\n", printf("prova unsigned mio: %ld\n",
						prova_4));

 	ft_printf("%%x __________________________\n");
 	printf("esad reale: %x\n", 'c');
 	ft_printf("esad mio: %x\n", 'c');
 	printf("esad reale: %x\n", -2147483647);
 	ft_printf("esad mio: %x\n", -2147483647);
 	printf("esad reale: %x\n", 2147483647);
 	ft_printf("esad mio:%x\n", 2147483647);

 	ft_printf("%%X _________________________\n");
 	printf("esad vero: %X\n", 2147483647);
 	ft_printf("esad mio: %X\n", 2147483647);
 	printf("esad vero: %X\n", -2147483647);
 	ft_printf("esad mio: %X\n", -2147483647);

	ft_printf("%%p _________________________\n");
	printf("Real: %p\n", &prova_1);
	ft_printf("Mine: %p\n", &prova_1);
	printf("Real: %p\n", &prova_4);
	ft_printf("Mine: %p\n", &prova_4);
	printf("Real: %p\n", str);
	ft_printf("Mine: %p\n", str);
} */
/*
int	main(void)
{
 	int		a = 255;
	
 	printf("esad reale: %x\n", a);
 	ft_printf("esad mio: %x\n", a);
 	printf("esad reale: %X\n", a);
 	ft_printf("esad mio:%X\n", a);
}
*/
