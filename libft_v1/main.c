#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>
#include <string.h>
#include "libft.h"

// Función de ejemplo para aplicar a cada carácter
static char    add_one(unsigned int index, char c)
{
        return (c + 1); // Incrementa el valor del carácter en 1
}
// Función de ejemplo para imprimir el índice y el carácter
static void    print_index_and_character(unsigned int index, char *c)
{
	printf("Caracter en el indice %u: %c\n", index, *c);
}

/*functions used for main to testing*/
// Function to print the linked list 

static void	print_list(t_list *head)
{ 
	t_list	*current;

	current = head;
	while (current != NULL)
	{
		printf("%s -> ", (char *)current->content); 
		current = current->next; 
	}
    printf("NULL\n"); 

}

// Function to free memory allocated for the linked list 
static void	free_list(t_list *head)
{ 
	t_list	*current;
	t_list	*temp;

	current = head; 
    while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	} 

}

void	del_content(void *content)
{	
	free(content);
} 

// Function to increment the content of a node by one 

static void *add_one_num(void *num)
{
	int *ptr;
	int *result;
	int	i;

	i = (int )num;
    i = i + 1;
	ptr = (int *)i;
    //ptr = (int *)num; >>no funciona 
	result = (int *)malloc(sizeof(int)); 
    if (!result)
	{
		printf("Error");
		return (0); 
    }
	
	result = ptr; 

    return (result); 

}

// Function to print the content of a node 
static void	print_content(void *content) 
{
	printf("%s\n", (char *)content); 

} 

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

	/*FT_SUBSTR*/
	printf("\n\nFunciones aditionales\n");
	printf("\nFT_SUBSTR\n");
	    // Cadena de ejemplo para probar ft_substr
    char st[] = "Ejemplo de cadena para probar la funcion ft_substr";
    // indice de inicio y longitud maxima para la substring
    unsigned int	start_index;
    size_t	max_le;
	char	*substring;
	start_index = 11;
	max_le = 15;
	printf("str: %s, star_index: %i, max_len:%li\n", st, start_index, max_le);
	substring = ft_substr(st, start_index, max_le);
    if (substring == NULL) {
    	printf("Error: No se pudo crear la substring.\n");
        return (1);
    }
	printf("Substring:%s\n", substring);
	free(substring);
	/*FT_STRJOIN*/
	printf("\nFT_STRJOIN\n");
	const char      d1[] = "Hey there, ";
	const char      d2[] = "everybody!";
	char            *resu;
	printf("str1: %s, str2: %s\n", d1, d2);
	resu = ft_strjoin(d1, d2);
	if (!resu)
	{
		printf("Error: Falló la asignación de memoria.\n");
	       	return (1);
	}
	printf("Cadena concatenada: %s\n", resu);
	free(resu);
	/*FT_STRTRIM*/
	printf("\nFT_STRTRIM\n");

    char    s1a[] = "x\t-Hello World?\tx-";
    char    set[] = "x\t-";
    char    *trimmed_str;
	
    printf("string:%s, set:%s('x\\t')\n", s1a, set);
    trimmed_str = ft_strtrim(s1a, set);
    if (!trimmed_str)
    {
        printf("Error: Memory allocation failed.\n");
        return (1);
    }
    printf("Trimmed string: \"%s\"\n", trimmed_str);
    free(trimmed_str);
	/*FT_SPLIT*/
	printf("\nFT_SPLIT\n");
	char *sdr = "Esta-,es-,una-,cadena-,de-,ejemplo";
    char **resuld = ft_split(sdr, ',');
	printf("string: %s, delimiter: '-'\n", sdr);
	if (resuld) 
	{
		size_t y = 0;
		while (resuld[y])
		{
			printf("%s\n", resuld[y]);
			free(resuld[y]); // Liberar memoria asignada a cada subcadena
			y++;
        }
        free(resuld); // Liberar memoria asignada al array de strings
	}
	else
	{
		printf("Error: no se pudo dividir la cadena\n");
	}

	/*FT_ITOA*/
	printf("\nFT_ITOA\n");
	int nubm = -1093;
	char *stre = ft_itoa(nubm);
	if (stre)
	{
		printf("Integer: %d, String: %s\n", nubm, stre);
		free(stre);
	}
	else
	{
		printf("Memory allocation failed.\n");
	}
	/*FT_STRMAPI*/
	printf("\nFT_STRMAPI\n");

    char *input_string = "Buenas tardes!";
	printf ("cadena inicial:%s - cambiamos cada letra: c + 1\n", input_string);
    char *result_string = ft_strmapi(input_string, &add_one);

    if (result_string)
    {
		printf("Cadena resultante: %s\n", result_string);
		// Liberar la memoria asignada a la cadena resultante
		free(result_string);
    } else {
        printf("Error: No se pudo asignar memoria para la cadena resultante.\n");
    }
	/*FT_STRITERI*/
	printf("\nFT_STRITERI\n");
	char stt[] = "Hey, everybody!";
	printf ("cadena inicial:%s\n", stt);
    // Llamar a la función ft_striteri con la función print_index_and_character
    ft_striteri(stt, &print_index_and_character);
	
	/*FT_PUTCHAR_FD*/
	printf("\nFT_PUTCHAR_FD\n");
    int             fd;
    char    character;

    fd = open("output1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        // 1 is the file descriptor for stdout
        write(1, "Error al abrir el archivo\n", 27);
        return (1);
    }
    character = 'A';
    ft_putchar_fd(character, fd);
    close(fd);
    printf("Caracter '%c' escrito en el archivo 'output1.txt'\n", character);
	/*FT_PUTSTR_FD*/
	printf("\nFT_PUTSTR_FD\n");
    char    *sty;

    // Abrir un archivo para escribir
    fd = open("output2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        write(1, "Error al abrir el archivo\n", 27);
        return (1);
    }
	// Cadena a escribir
    sty = "Hey, How's it going?";
	// Llamar a ft_putstr_fd para escribir la cadena en el archivo
    ft_putstr_fd(sty, fd);
	// Cerrar el archivo
    close(fd);
	printf("Cadena '%s' escrita en el archivo 'output2.txt'\n", sty);

	/*FT_PUTENDL_FD*/
	printf("\nFT_PUTENDL_FD\n");
	char    *sth;

    fd = open("output3.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        write(1, "Error al abrir el archivo\n", 27);
        return 1;
    }
    // Cadena a escribir
    sth = "Hey, there!";
    ft_putendl_fd(sth, fd);
	// Cerrar el archivo
    close(fd);
	printf("Cadena '%s' escrita en el archivo 'output3.txt' con un salto de línea\n", sth);

	/*FT_PUTNBR_FD*/
	printf("\nFT_PUTNBR_FD\n");
    int number;

    fd = open("output4.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        write(1, "Error al abrir el archivo\n", 27);
        return (1);
    }
	// Número a escribir
    number = -2147483648;

    // Llamar a ft_putnbr_fd para escribir el número en el archivo
    ft_putnbr_fd(number, fd);

    // Cerrar el archivo
    close(fd);

    printf("Número '%d' escrito en el archivo 'output4.txt'\n", number);
	/*BONUSSSSS FUNCTIONS*/

	/*FT_LSTNEW*/
	printf("\nFT_LSTNEW\n");
	t_list *node;
	// Creamos un nuevo nodo con contenido "Hello, world!"
	node = ft_lstnew("cheers and smile");
	// Verificamos si la creación del nodo fue exitosa 
	if (node)
	{
		// Imprimimos el contenido del nodo
		printf("Contenido del nodo: %s\n", (char *)node->content);
		// Liberamos la memoria del nodo
		free(node);
	}
	else
	{
		printf("Error: No se pudo crear el nodo.\n");
	}
	 
	/*FT_LSTADD_FRONT*/
	printf("\nFT_LSTADD_FRONT\n");
    // Create the first node
	t_list *head1;

	head1 = ft_lstnew("a");
    if (head1 == NULL)
	{
		printf("Error: No se pudo crear el nodo.\n");
	}
    // Print the initial list
	printf("Initial list:\n");
	print_list(head1); 
    // Create a new node
	t_list *new_node;
	
	new_node = ft_lstnew("b"); 
    if (new_node == NULL)
	{
		printf("Error: No se pudo crear el nodo.\n");
	}
    // Add the new node to the front of the list 
    ft_lstadd_front(&head1, new_node); 
	// Print the updated list 
    printf("\nList after adding a new node at the front:\n"); 
	print_list(head1);
    // Free memory 
	free_list(head1); 
	/*FT_LSTSIZE*/
	t_list	*second;
	t_list	*third;
	int		sizes;

	printf("\nFT_LSTSIZE\n");
	// Create some nodes for the linked list 
    head1 = ft_lstnew("First"); 
    second = ft_lstnew("Second"); 
    third = ft_lstnew("Third"); 
    // Connect the nodes to form a linked list 
    head1->next = second; 
    second->next = third; 
    // Call the function ft_lstsize to get the size of the linked list 
	sizes = ft_lstsize(head1);
    // Print the size of the linked list
	printf("list:\n");
	print_list(head1); 
    printf("Size of the linked list: %d\n", sizes);
    // Free memory allocated for the linked list 
    free(head1);
    free(second);
    free(third);


	/*FT_LSTLAST*/
	printf("\nFT_LSTLAST\n");
	t_list *last_node;
    // Create some nodes for the linked list 
    head1 = ft_lstnew("First"); 
    second = ft_lstnew("Second"); 
    third = ft_lstnew("Third"); 

    // Connect the nodes to form a linked list 
	head1->next = second;
	second->next = third;
	third->next = NULL; 
    // Call ft_lstlast to get the last node of the linked list 
    last_node = ft_lstlast(head1); 
	// Print the size of the linked list
	printf("list:\n");
	print_list(head1); 
    if (last_node != NULL)
	{
		printf("Content of the last node: %s\n", (char *)last_node->content); 
    } else {
		printf("The list is empty.\n"); 
    }
    // Free memory allocated for the linked list 
    free(head1); 
    free(second); 
    free(third); 

	/*FT_LSTADD_BACK*/
	printf("\nFT_LSTADD_BACK\n");
   // Create the first node 
	head1 = ft_lstnew("First");
    // Print the initial list 
    printf("Initial list:\n"); 
    print_list(head1); 
    // Create a new node
	new_node = ft_lstnew("Second");
    // Add the new node to the back of the list 
    ft_lstadd_back(&head1, new_node); 
    // Print the updated list 
    printf("\nList after adding a new node at the back:\n"); 
    print_list(head1); 
    // Free memory allocated for the linked list 
    free_list(head1);

	/*FT_LSTDELONE*/
	printf("\nFT_LSTDELONE\n");
    t_list	*head2 = (t_list *)malloc(sizeof(t_list)); 
    if (head2== NULL) 
	{
		printf("Error de memoria");
    } 
    head2->content = strdup("Hello, world!"); 
    head2->next = NULL; 
    // Print the content of the node before deletion
	printf("Content of the node before deletion: %s\n", (char *)head2->content);
    // Call ft_lstdelone to delete the node 
	ft_lstdelone(head2, del_content); 
    // Print a message after deletion 
	printf("Node deleted successfully.\n");


	/*FT_LSTCLEAR*/
	t_list *current;
	printf("\nFT_LSTCLEAR\n");
	// Create a linked list with three nodes
	head1 = (t_list *)malloc(sizeof(t_list)); 
    if (head1 == NULL) 
	{
		printf("Error de memoria");
    } 
	head1->content = strdup("First");
    head1->next = (t_list *)malloc(sizeof(t_list)); 
    head1->next->content = strdup("Second"); 
    head1->next->next = (t_list *)malloc(sizeof(t_list)); 
    head1->next->next->content = strdup("Third"); 
    head1->next->next->next = NULL; 

	// Print the content of each node before deletion 
    printf("Content of nodes before deletion:\n"); 
    current = head1; 
    while (current)
	{
		printf("%s\n", (char *)current->content); 
        current = current->next; 

    }
    // Call ft_lstclear to delete all nodes 
    ft_lstclear(&head1, &del_content); 
    // Print a message after deletion 
    printf("\nNodes deleted successfully.\n");

	/*FT_LSTITER*/
	printf("\nFT_LSTITERT\n");
	head1 = (t_list *)malloc(sizeof(t_list)); 
    if (head1 == NULL) 
	{
		printf("Error de memoria");
    }
	head1->content = strdup("First");
    head1->next = (t_list *)malloc(sizeof(t_list)); 
    head1->next->content = strdup("Second"); 
    head1->next->next = (t_list *)malloc(sizeof(t_list)); 
    head1->next->next->content = strdup("Third"); 
    head1->next->next->next = NULL;
    // Call ft_lstiter to apply print_content to each node's content 
    printf("Contents of the nodes:\n"); 
    ft_lstiter(head1, &print_content); 
	// Liberar la memoria de la lista enlazada
	ft_lstclear(&head1, &del_content);

	/*FT_LSTMAP*/
	printf("\nFT_LSTMAP\n");
	// Create a linked list with three nodes containing integers
	head1 = ft_lstnew((void *)1);
	ft_lstadd_back(&head1, ft_lstnew((void *)2)); 
    ft_lstadd_back(&head1, ft_lstnew((void *)3)); 
    // Print the original list 
	printf("Original list:\n"); 
    current = head1; 
    while (current != NULL)
	{ 

        printf("%d\n", (int)current->content); 

        current = current->next; 

    } 
    // Create a new list by adding one to each element of the original list 
    t_list *new_list = ft_lstmap(head1, &add_one_num, &del_content); 
    // Print the new list 
    printf("\nNew list after mapping:\n"); 
    current = new_list; 
    while (current != NULL) { 
        printf("%d\n", (int)current->content); 
        current = current->next;
    }
    // Free memory allocated for both lists 
    free_list(head1);
    free_list(new_list);

	return (0);
}

