#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
	FILE * fhandle = fopen(argv[1],"r");
	char c;

	int num_count[10] = {0};
	int char_count[26] = {0};

	while((c = fgetc(fhandle)) != EOF)
	{
		if (isdigit(c))
		{
			int num_array_index = c - '0';
			num_count[num_array_index]++;
		}
		else if(isupper(c))
		{
			int UpperChar_array_index = c - 'A';
			char_count[UpperChar_array_index]++;
		}
		else if(islower(c))
		{
			int LowerChar_array_index = c - 'a';
			char_count[LowerChar_array_index]++;
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		if (num_count[i] != 0)
		{
			printf("%c: ", '0' + i);
			for (int j = 0; j < num_count[i]; ++j)
			{
				printf("%c", '#');
			}
			printf("(%d)\n", num_count[i]);
		}
	}
	for (int i = 0; i < 26; ++i)
	{
		if (char_count[i] != 0)
		{
			printf("%c: ", 'a' + i);
			for (int j = 0; j < char_count[i]; ++j)
			{
				printf("%c", '#');
			}
			printf("(%d)\n", char_count[i]);
		}
	}
	return 0;
}
