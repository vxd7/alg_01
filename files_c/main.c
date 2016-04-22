#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define FILE_IN "input.txt"
#define FILE_OUT "output.txt"
#define LSIZE 256

void mod(FILE *fp_out, char *line);
void printfile(const char *fname_out);

int main(){
	FILE *fp;
	FILE *fp_out;
	char line[LSIZE];
	int i = 1;

	if((fp = fopen(FILE_IN, "rw+")) == NULL) printf("ERROR. CANNOT OPEN FILE");
	if((fp_out = fopen(FILE_OUT, "rw+")) == NULL) printf("E");

	while(fgets(line, LSIZE, fp))
	{
		printf("%s", line);
		if(i%2 != 0)
			mod(fp_out, line);
		i++;
	}	
	fclose(fp);
	fclose(fp_out);

	printfile(FILE_OUT);
	return 0;
}
void mod(FILE *fp_out, char *line)
{
	int i, j, k = 0;;
	int num = 0;
	char res[LSIZE];
	for(i = 0; i< strlen(line); i++)
	{
		if(isdigit(line[i]))
		{
			res[k] = '(';
			k++;

			while(isdigit(line[i]))
			{
				res[k] = line[i];
				k++;
				i++;
			}

			res[k] = ')';
			res[k+1] = line[i]; //operate on next character after out number
			k+=2;

		}
		else
		{
			res[k] = line[i];
			k++;
		}
	}
	fprintf(fp_out, "%s", res);
}

void printfile(const char *fname_out)
{
	FILE *fp_out;
	int i;
	char line[LSIZE];

	printf("--------------------\n");

	if((fp_out = fopen(fname_out, "rt")) == NULL) printf("ERROR. CANNOT OPEN FILE");
	while(fgets(line, LSIZE, fp_out))
	{
		printf("%s", line);
	}
	fclose(fp_out);
}
