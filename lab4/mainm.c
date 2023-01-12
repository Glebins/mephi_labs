#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

#include "funcs.h"

/* char lower(char c);
char *get_str();
char **split(char **arr, char *s, int *l);
void print_arr(char **arr, int l);
char is_anagrams(unsigned char *a, unsigned char *b);
char *delete_substr(char *str, int beg, int end);
int find(int *mas, int len, int element);

char *work(char **words, int len, char *s);

int my_strlen(char *str);
int my_strstr(char *text, char *str, int start);
char *my_strcat(char *s1, char *s2);
char *my_strcpy(char* s1, char *s2); */

int main()
{
	while (1)
	{
		char *s = get_str();
		if (!s) break;

		clock_t start = clock();
		
		    char **words = (char **) malloc(0);
		    int len = 0;
		
		    words = split(words, s, &len);

		    // print_arr(words, len);
		
		    s = work(words, len, s);
		
		    printf("\n%s\n", s);
		
		    free(s);
		    for (int i = 0; i < len; i++)
		    	free(words[i]);
		    free(words);

		 clock_t end = clock();

		 printf("Time = %.10f\n", (double) (end - start) / CLOCKS_PER_SEC);
	}

    return 0;
}



/* char *work(char **words, int len, char *s)
{
	    int counter = 0;
    int curr_position = 0;

    int *positions = (int *) malloc(0);
    int positions_len = 0;
    
    while (counter != len)
    {
    	if (find(positions, positions_len, curr_position) != -1)
    	{
    		curr_position++;
    		counter++;
    		continue;
    	}
    	
    	char *word = words[curr_position];

    	char flag = 0;
    	
    	for (int i = curr_position + 1; i < len; i++)
    	{
    		if (find(positions, positions_len, i) != -1)
    		{
    			continue;
    		}
    	
    		char *word_curr = words[i];
    		
    		if (is_anagrams((unsigned char *) word, (unsigned char *) word_curr) == 1)
    		{
    			flag = 1;

    			int ptr = my_strstr(s, word_curr, 0);

    			if (ptr == -1) continue;

    			while (lower(s[ptr + my_strlen(word_curr)]) != -1)
    			{
    				ptr = my_strstr(s, word_curr, ptr + 1);
    			}
    			
    			s = delete_substr(s, ptr, ptr + strlen(word_curr) - 1);
    			counter++;

    			positions_len++;
    			positions = (int *) realloc(positions, positions_len * sizeof(int));
    			positions[positions_len - 1] = i;
    		}
    	}

    	if (flag)
    	{
    		if (my_strstr(s, word, 0) == -1)
    		{
    			curr_position++;
    			counter++;
    			continue;
    		}
    		
    		int ptr = my_strstr(s, word, 0);

    		while (lower(s[ptr + my_strlen(word)]) != -1)
    		{
    			ptr = my_strstr(s, word, ptr + 1);
    		}
    		
    		s = delete_substr(s, ptr, ptr + my_strlen(word) - 1);

    		positions_len++;
    		positions = (int *) realloc(positions, positions_len * sizeof(int));
    		positions[positions_len - 1] = curr_position;
    	}

    	curr_position++;
    	counter++;
    }

    free(positions);

    return s;
}


int find(int *mas, int len, int element)
{
	int pos = -1;

	for (int i = 0; i < len; i++)
	{
		if (mas[i] == element) pos = i;
	}

	return pos;
}

char *my_strcpy(char *s1, char *s2)
{
	if (s1 == NULL) return NULL;

	char *ptr = s1;

	while (*s2 != '\0')
	{
		*s1 = *s2;
		s1++;
		s2++;
	}

	*s1 = '\0';

	return ptr;
}

char *my_strcat(char *s1, char *s2)
{
	char *ptr = s1 + strlen(s1);

	while (*s2 != '\0')
	{
		*ptr = *s2;
		ptr++;
		s2++;
	}

	*ptr = '\0';

	return s1;
}

int my_strstr(char *text, char *str, int start)
{
	int pos = -1;
	
	for (size_t i = start; i < strlen(text); i++)
	{
		if (text[i] == str[0])
		{
			if (i + strlen(str) > strlen(text)) break;

			char flag = 0;
			
			for (size_t j = 0; j < strlen(str); j++)
			{
				if (text[i + j] != str[j])
				{
					flag = 1;
					break;
				}
			}

			if (flag == 0)
			{
				pos = i;
				break;
			}
		}
	}

	return pos;
}

int my_strlen(char *str)
{
	int cntr = 0;
	while (*(str + cntr) != '\0')
		cntr++;

	return cntr;
}


char *delete_substr(char *str, int beg, int end)
{
	// printf("%lu\n", len * sizeof(char));
	char *news = (char *) malloc(sizeof(char) * (strlen(str)));

	int counter = 0;
	
	for (int i = 0; i < (int) strlen(str); i++)
	{
		if (!(beg <= i && i <= end))
		{
			// printf("%d", counter);
			news[counter] = str[i];
			counter++;
		}
	}

	news[counter] = '\0';

	free(str);
	
	return news;
}

char **split(char **arr, char *s, int *l)
{
    int number = 0;
    int len = 0;
    char *current_str = malloc(0);

    for (size_t i = 0; i <= strlen(s); i++)
    {
        if (lower(s[i]) == -1)
        {
        	// printf("%c - %lu\n", s[i], i);
        	
            if (len != 0)
            {
            	number++;
                arr = (char **) realloc(arr, number * sizeof(char *));
                current_str = realloc(current_str, (len + 1) * sizeof(s[i]));
                current_str[len] = '\0';
                
                arr[number - 1] = malloc(sizeof(current_str));

                my_strcpy(arr[number - 1], current_str);
                
                current_str = realloc(current_str, 0);
                len = 0;
            }

            else continue;
        }

        else
        {
            len++;
            current_str = realloc(current_str, (len) * sizeof(s[i]));
            current_str[len - 1] = s[i];
        }
    }

    *l = number;

    free(current_str);

    return arr;
}

char is_anagrams(unsigned char *a, unsigned char *b)
{
	if (strlen((char *) a) != strlen((char*) b)) return 0;
	
	int letters[256];
	int i = 0;

    for (int i = 0; i < 256; i++)
		letters[i] = 0;

	i = 0;
	while (a[i] != '\0')
		letters[a[i++]]++;

	i = 0;
	while (b[i] != '\0')
		letters[b[i++]]--;

	char flag = 0;
	
	for (i = 0; i < 256; i++)
	{
		if (letters[i] != 0)
		{
			flag = 1;
			break;
		}
	}

	if (flag == 0) return 1;
	else return 0;
}

char *get_str()
{
    char *ptr = (char *) malloc(1);
    const int BUFF_SIZE = 81;
    char buf[BUFF_SIZE];

    int n, len = 0;
    *ptr = '\0';

    do
    {
        n = scanf("%80[^\n]", buf);
        if (n == EOF)
        {
        	free(ptr);
        	return NULL;
        }

        if (n < 0)
        {
            free(ptr);
            ptr = NULL;
            continue;
        }

        else if (n == 0) scanf("%*c");

        else
        {
            len += (int) my_strlen(buf);
            ptr = (char *) realloc(ptr, len + 1);
            my_strcat(ptr, buf);
        }
    } while (n > 0);

    return ptr;
}

char lower(char c)
{
    if (c >= 65 && c <= 90)
        c += 32;

    else if (c >= 97 && c <= 122);

    else
        c = -1;

    return c;
}

void print_arr(char **arr, int l)
{
	for (int i = 0; i < l; i++)
	{
		printf("%s\n", arr[i]);
	}
}
 */
