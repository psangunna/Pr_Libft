#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	char	input;
	int		result;
	char	output;
	
	/*isalpha*/
	printf("ft_isalpha - input: 'a':\n");
	input = 'a';
	result = ft_isalpha(input);
	output = result + '0';
	write(1, &output, 1);
	write(1, "\n", 1);
	/*isdigit*/
    printf("\nft_isdigit - input 'R':\n");
	input = 'R';
	result = ft_isdigit(input);
	output = result + '0';
	write(1, &output, 1);
	write(1, "\n", 1);
	printf("isdigit - input 'R':\n");
	result = isdigit(input);
	output = result + '0';
	write(1, &output, 1);
	/*isalnum*/
	printf("\n\nft_isalnum -  input: '-'\n");
	input = '-';
	result = ft_isalnum(input);
	output = result + '0';
	write(1, &output, 1);
	write(1, "\n", 1);
	printf("isalnum - input: '-'\n%i\n", isalnum(input));
	/*isprint*/
	input = 'A';
	//input = '\t'
	printf("\nft_isprint - input: '%c'\n%i\n", input,ft_isprint(input));
	/*strlen*/
	const char	s[20] = "Have a good one!";
	printf("\nft_strlen -  input:%s\n", s);
	printf("length(s) = %lu\n", ft_strlen(s));
	/*memset*/
	char	buffer1[20];
	ft_memset(buffer1, 'F', sizeof(buffer1));
	printf("\nft_memset - 'F'-  output:%s\n", buffer1);
	char	buffer2[20];
	memset(buffer2, 'D', sizeof(buffer2));
	printf("memset -'D' - output:%s\n", buffer2);
	/*bzero*/
	char	buffer3[20] = "Hola";
	ft_bzero(buffer3, sizeof(buffer3));
	printf("\nft_bzero  - output:%s\n", buffer3);
	char	buffer4[20] = "Que tal";
	bzero(buffer4, sizeof(buffer4));
	printf("bzero  - output:%s\n", buffer4);
	/*memcpy*/
	char	dest[20] = "Hello, world";
	char	src[20] = "Goodbye!";
	ft_memcpy(dest, src, sizeof(src));
	printf("\nft_memcpy - output:%s\n", dest);
	char	dest2[20] = "Hello, world";
	memcpy(dest2, src, sizeof(src));
	printf("memcpy - output:%s\n", dest2);
	/*memmove*/
	printf("\nFT_MEMMOVE: StartS stops; dest+6 - dest+8 - 5");
	char	buff1[] = "StartS stops";
	ft_memmove(buff1+6, buff1+8, 5);
	printf("\nft_memmove - output:%s\n", buff1);
	char	buff2[] = "StartS stops";
	memmove(buff2+6, buff2+8, 5);
	printf("memmove - output:%s\n", buff2);

	printf("Se prueba con memcpy - Error visto al usar python tutor");
	char	buff3[] = "StartS stops";
	ft_memcpy(buff3+6, buff3+8, 5);
	printf("\nft_memcpy - output:%s\n", buff3);
	char	buff4[] = "StartS stops";
	memcpy(buff4+6, buff4+8, 5);
	printf("memcpy - output:%s\n", buff4);
	/*strlcpy*/
	printf("\nFT_STRLCPY\n");
    char    x[8];
    char    z[] = "Buenos tardes";
    unsigned int    len;
    int             size;

    size = (sizeof(x) / sizeof(x[0]));
    printf("size de string destino: %i\n",size);
    len = ft_strlcpy(x, z, size);
    printf("long de string origen (%s) que se intenta copiar: %i\n",z,len);
    printf("valor de destino: %s\n",x);
	/*strlcat*/
	printf("\nFT_STRLCAT\n");
	char    a[6] = "123";
    const char      b[] = "Abcde";
    size_t len_total;
    
	printf("variable origen:%s, variable destino:%s, size origen:%li \n",b, a, sizeof(a));
	len_total = ft_strlcat(a, b, sizeof(a));
	printf("ft_strlcat\n");
    printf("long del string que se ha intentado concatenar:%li\n",len_total);
	printf("variable destino:%s\n",a);
	/*char    a2[6] = "123";
	printf("strlcat\n");
    len_total = strlcat(a2, b, sizeof(a));
    printf("length:%li\n",len_total);
    printf("variable destino:%s\n",a);*/
		/*TOUPPER*/
	printf("\nFT_TOUPPER\n");
	char c1;
    c1 = 'm';
    printf("ft_toupper(%c) -> %c", c1, ft_toupper(c1));
    c1 = 'D';
    printf("\nft_toupper(%c) -> %c", c1, ft_toupper(c1));
    c1 = '9';
    printf("\nft_toupper(%c) -> %c", c1, ft_toupper(c1));
	/*TOUPPER*/
	printf("\nFT_TOLOWER\n");
	char result1;
    c1 = 'M';
    result1 = ft_tolower(c1);
    printf("ft_tolower(%c) = %c\n", c1, result1);
    c1 = 'm';
    result1 = ft_tolower(c1);
    printf("ft_tolower(%c) = %c\n", c1, result1);
    c1 = '+';
    result1 = ft_tolower(c1);
    printf("ft_tolower(%c) = %c\n", c1, result1);
	/*STRCHR*/
	printf("\nFT_STRCHR\n");
	const char stra[] = "This-is-just-a-test-string"; 
	char cha = '-'; 
	char *p, *p2;
	printf("\nstring:%s\n", stra);
	p = ft_strchr(stra, cha); 
	printf("String starting from first occurrence of %c is: %s\n", cha, p);

	p2 = ft_strchr(stra, 'i'); 
	printf("String starting from first occurrence of 'i' is: %s\n", p2);
	/*STRRCHR*/
	printf("\nFT_STRRCHR\n");
	const char strb[] = "This-is-just-a-test-string"; 
	cha = '-'; 

	printf("\nstring:%s\n", strb);
	p = ft_strrchr(strb, cha); 
	printf("String starting from last occurrence of %c is: %s\n", cha, p);

	p2 = ft_strrchr(strb, 'i'); 
	printf("String starting from last occurrence of 'i' is: %s\n", p2);
	/*STRNCMP*/
	printf("\nFT_STRNCMP\n");
	char s1[9] = "artesano";
   	char s2[8] = "artista";
   	int i;
   	printf( "s1=%s\t", s1 );
   	printf( "s2=%s\n", s2 );
	i = ft_strncmp( s1, s2, 3 );
	printf( "Compara las 3 primeras letras resultado: %i\n ", i );
	if( i < 0 )
	{
		printf( "menor s1 a s2" );
	} 
	else if( i > 0 )
	{
		printf( "mayor s1 a s2" );
	}
	else
	{
		printf( "iguales" );
	}
   	printf("\n");	

	/*MEMCHR*/
	printf("\nFT_MEMCHR\n");
	char cadena[] = "Have a very good...";
	char *puntero; 
	printf("Busca 'e' en las 5 primeras letras ");
	puntero = (char *)ft_memchr( cadena, 'e', 5 );
	printf( "%s\n", cadena); 
	printf( "%s\n", puntero );
	/*MEMCMP*/
	printf("\nFT_MEMCMP\n");
	char *straa = "Sunny good day!";
	char *strbb = "Sunny gooD day!";
	unsigned int length;
	
	length = 12;
	printf( "s1=%s\t", straa );
   	printf( "s2=%s\n", strbb);
	i = ft_memcmp(stra, strbb, length);
	printf( "Compara las 12 primeras letras resultado: %i ", i );	
	if (i == 0)
	{
		printf("Strings are equal: %d", i);
	}
	else if (i < 0)
	{
		printf("str1 is less than str2: %d", i);
	}
	else
	{
		printf("str1 is greater than str2; %d", i);
	}

	/*STRNSTR*/
	printf("\n\nFT_STRNSTR\n");
	char	*aa = "El cielo gris";
	char	*bb = "gr";
	char	*r;
	unsigned int	max_length;
	max_length = 13;
	printf("string:%s\n", aa);
	printf("string a buscar: %s en todo el string(13)\n",bb);
	r = ft_strnstr(aa, bb, max_length);
	printf("puntero:%s\n",r);
	//r = strnstr(a, b, max_length);
	/*ATOI*/
	printf("\n\nFT_ATOI\n");
    char    *digit;
    int     res;
    digit = "\n\t-1234y6t";
	printf("string:%s\n", digit);
    res = ft_atoi(digit);
    //resultado = ft_atoi(digit);
    printf("resultado: %i\n", res);
	/*CALLOC*/
	printf("\n\nFT_CALLOC\n");
    int *arr1;
    unsigned int n1;
    n1 = 5;
    // Allocate memory for array of 5 integers
	printf("Number of elements: %i \n", n1);
    arr1 = (int *)ft_calloc(n1, sizeof(int));
    //arr = (int *)calloc(n, sizeof(int));
    if (arr1 == NULL)
    {
        printf("Memory allocation failed\n");
        return (1);
    }
    // Printing the initialized array
    printf("Initialized array:\n");
    i = 0;
    while (i < n1)
    {
		printf("%d ", arr1[i]);
		i++;
    }
    printf("\n");
    free(arr1); // Free allocated memory
	/*STRDUP*/
	printf("\n\nFT_STRDUP\n");
    char *original;
    char *duplicate;

    original = "Hey, have a good one!";
    // Duplicate the string
    //duplicate = strdup(original);
    duplicate = ft_strdup(original);
    if (duplicate != NULL)
	{
        printf("Original: %s\n", original);
        printf("Duplicate: %s\n", duplicate);
        // Remember to free the allocated memory when done
        free(duplicate);
    } else {
        printf("Memory allocation failed.\n");
    }
	return (0);
}
