#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 255
struct student
{
char Surname[MAX];
struct date
{
unsigned int Day;
unsigned int Month;
unsigned int Year;
} DateOfBirth;
int Course;
float Test[4];
};
int BinOutput(struct student* S, int n, char *fname)
{
int result = 1;
FILE *file;
if ((file = fopen(fname, "wb")) == NULL)
{
printf("Can't open file '%s'\n", fname);
result = 0;
}
else
{
if (fwrite(S, n * sizeof(struct student), 1, file) < 1)
{
printf("Error while writing to file '%s'\n",

fname);

fclose(file);
result = 0;
}
else
{
fclose(file);
result = 1;
}
}
return result;
}
int BinInput(struct student** S, int *n, char *fname)
{
int result = 1;
FILE *file;
if ((file = fopen(fname, "rb")) == NULL)
{
printf("Can't open file '%s'\n", fname);
result = 0;
}
else
{
fseek(file, 0, SEEK_END);
*n = ftell(file) / sizeof(struct student);

*S = (struct student*)malloc((*n) * sizeof(struct

student));

fseek(file, 0, SEEK_SET);
if (fread(*S, sizeof(struct student), (*n), file) < *n)
{
printf("Error while reading from file '%s'\n",

fname);

fclose(file);
result = 0;
}
else
{
fclose(file);
result = 1;
}
}
return result;
}
struct student* input_arr(int n)
{
int i, j;
struct student* S = (struct student*)malloc(n * sizeof(struct
student));
if (S != NULL)
{
printf("Input Array Elements:\n");
for (i = 0; i < n; i++)
{
printf("Now You input data of %d student\n", i

+ 1);

for(j=0;j<255;j++)

S[i].Surname[j]=32;
while (1)
{
printf("Input surname \n");
if (scanf("%s", S[i].Surname) != 1)
{
fflush(stdin);
continue;
}
break;
}
printf("Input date of birth :\n");
while (1)
{
printf("Input month\n");
if (scanf("%d",

&S[i].DateOfBirth.Month) != 1 || !(0 < S[i].DateOfBirth.Month && 13 >
S[i].DateOfBirth.Month))
{
fflush(stdin);
continue;
}
break;
}
while (1)
{
printf("Input day\n");
if (scanf("%d",

&S[i].DateOfBirth.Day) != 1 || !(0 < S[i].DateOfBirth.Day && 32 >
S[i].DateOfBirth.Day))

{
fflush(stdin);
continue;
}

break;
}
while (1)
{
printf("Input year\n");
if (scanf("%d",

&S[i].DateOfBirth.Year) != 1) {

fflush(stdin);
continue;
}
break;
}
printf("Input grades :\n");
for (j = 0; j < 4; j++)
{
while (1)
{
printf("Input %d grade\n", j +

1);

if (scanf("%f", &S[i].Test[j])

!= 1) {

fflush(stdin);
continue;
}
break;
}
}
while (1)
{
printf("Input course\n");
if (scanf("%d", &S[i].Course) != 1) {
fflush(stdin);
continue;
}
break;
}
}
}
return S;
}
void output_arr(struct student* S, int len)
{
int i, j;
for (i = 0; i<len; i++)
{
printf("Surname t %s\n", S[i].Surname);
printf("Date of birth %d.%d.%d\n",

S[i].DateOfBirth.Month, S[i].DateOfBirth.Day, S[i].DateOfBirth.Year);

printf("Grades :\n");
for (j = 0; j<4; j++)
{
printf(" %d grade: %f\n", j + 1,

S[i].Test[j]);
}
printf("Course: %d\n", S[i].Course);
printf("\n");
}
}
int output_file_arr(struct student* S, int len, char *fname)
{
int result = 1;
FILE *file;
if ((file = fopen(fname, "wt")) == NULL)
{

printf("Can't open file '%s'\n", fname);
result = 0;
}
else
{
int i, j;
for (i = 0; i<len; i++)
{
if(fprintf(file,"Surname %s\nDate of birth
%d.%d.%d\nGrades :\n", S[i].Surname, S[i].DateOfBirth.Month,
S[i].DateOfBirth.Day, S[i].DateOfBirth.Year)<4)
{
printf("Error while writing to file '%s'\n", fname);
fclose(file);
result = 0;
}
else
{
for (j = 0; j<4; j++)
{
if(fprintf(file," %d grade: %f\n", j + 1,
S[i].Test[j])<2)
{
printf("Error while writing to file '%s'\n", fname);
fclose(file);
result = 0;
break;
}
}
if(result != 0)
{
if(fprintf(file,"Course: %d\n\n",
S[i].Course)<1)
{
printf("Error while writing to file '%s'\n", fname);
fclose(file);
result = 0;
break;
}
}
}
}
fclose(file);
}
return result;
}
int compare(const void * a, const void * b)
{
int result = 0, i;
const char* surname1 = ((struct student*)a)->Surname;
const char* surname2 = ((struct student*)b)->Surname;
int len1 = strlen(surname1);
int len2 = strlen(surname2);
int minLen = len1 > len2 ? len2 : len1;
for (i = 0; i < minLen; i++)
{
result = surname1[i] - surname2[i];
if (result != 0)
{
break;
}
}

if (result == 0)
{
result = len1 - len2;
}
return result;
}
int input (struct student** s, const int file_or_console) /*console = 0
file=other */
{
int n = 0;
switch (file_or_console)
{
case 0:
{
while (1)
{
printf("Input size of array:\n");
if (scanf("%d", &n) != 1)
{
fflush(stdin);
continue;
}
break;
}
*s = input_arr(n);
break;
}
case 1:
default:
{
if(!BinInput(s, &n, "input.struct"))
n=0;
break;
}
}
return n;
}
int main()
{
struct student** e = (struct student**)malloc(sizeof(struct
student*));
int k;
while (1)
{
printf("From where i must input data?\nType some digit.\n0 for
console\nOther for file\n");
if (scanf("%d", &k) != 1)
{
fflush(stdin);
continue;
}
break;
}
int n = input(e,k);
if (n)
{
printf("Your Array\n");
output_arr(*e, n);
qsort(*e, n, sizeof(struct student), compare);
printf("New Array\n");
output_arr(*e, n);
BinOutput(*e, n, "output.struct");
output_file_arr(*e, n, "output.txt");

} return 0;}