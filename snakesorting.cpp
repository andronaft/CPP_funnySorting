#include <stdio.h>//Sorry idk what happaned with format
#include <Windows.h>
#define MAX_ROW 100
#define MAX_COLLOM 100
void SetColor(int text, int background)
{
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
int main(){
int a1,a2,m,n;
int max,min,buf,vubir,i,element,j,minp,g;
int a[MAX_ROW][MAX_COLLOM];
printf("input row(<%d): \b",MAX_ROW);
scanf("%d",&m);
while (m<2 || m>MAX_ROW){
//проверка кол-ва строчек
SetColor( 15, 4);
if(m<2){
printf("ROW MUST BE >1 !!!\n");
}
else{
printf("ROW MUST BE

<%d\n",MAX_ROW);
}
SetColor(7,0);
printf("input row(<%d): \b",MAX_ROW);
scanf("%d",&m);

}
printf("input coloumn(<%d): \b",MAX_COLLOM);
scanf("%d",&n);
while (n<2 || n>MAX_COLLOM){
//проверка кол-ва столбцов
SetColor( 15, 4);
if(n<2){
printf("COLOUM MUST BE >1 !!!\n");
}
else {
printf("COLOUM MUST

BE<%d\n",MAX_COLLOM);
}
SetColor(7,0);
printf("input coloumn(<%d): \b",MAX_COLLOM);
scanf("%d",&n);
}
printf("does computer fills the array?yes /no(1,0): \b");
scanf("%f",&vubir);
if (vubir==0){
//самостоятелбный ввод матрици
for (a1=0;a1<m;a1++){
for(a2=0;a2<n;a2++){

printf("a[%d][%d]= ",a1,a2);
scanf("%d",&element);
a[a1][a2]=element;
}
}
system("cls");
printf("\n");
printf("matrica1\n\n");
}
else{
//рандомный ввод матрици
printf("Enter the maximum number you see

in array: \b");

scanf("%d",&max);
printf("Enter the minimum number you see

in array: \b");

scanf("%d",&min);
while(max<min){

// проверка , чтобы мин елемент не был больше

макс

SetColor(15,4);
printf("MAX MUST BE >

THEN MIN !!!\n");

SetColor(7,0);
printf("Enter the

maximum number you see in array: \b");

scanf("%d",&max);
printf("Enter the minimum

number you see in array: \b");

scanf("%d",&min);
}
system("cls");

printf("\n");
printf("matrica1\n\n");

for (a1=0;a1<m;a1++){
for(a2=0;a2<n;a2++){
a[a1][a2]= min +

rand() %(max-min+1);

}
}

}
for (a1=0;a1<m;a1++){
//вывод необработаной матрици
for(a2=0;a2<n;a2++){
printf("%d ",a[a1][a2]);
}
printf("\n");
}
for (g=0;g<(m*n);g++){
for(a1=0;a1<m;a1++){
if (!((a1+1)%2)){

for (i = 0; i < n; i++){
minp=i;
for (a2=(i+1);a2<n;a2++){

// перестановка елементом методом выбора если номер строки
парный

if (a[a1][minp] < a[a1][a2]){
minp = a2;
buf = a[a1][minp];
a[a1][minp] = a[a1][i];
a[a1][i] =buf;
}

}
}
}
else {
for (i = 0; i < n; i++){

// перестановка методом выбора елемента если номер строки не
парный

minp=i;
for (a2=(i+1);a2<n;a2++){
if (a[a1][minp] > a[a1][a2]){
minp = a2;
buf = a[a1][minp];
a[a1][minp] = a[a1][i];
a[a1][i] =buf;
}
}
}
}
}
for (a1=1;a1<m;a1++){
//цикл ,сравнивающий елементы разных строк
if (!((a1+1)%2)){

if (a[a1][n-1]<a[a1-1][n-1]){
buf=a[a1][n-1];
a[a1][n-1]=a[a1-1][n-1];
a[a1-1][n-1]=buf;
}

}
else {
if (a[a1][0]<a[a1-1][0]){
buf=a[a1][0];
a[a1][0]=a[a1-1][0];
a[a1-1][0]=buf;
}
}

}
}
SetColor(4,0);
printf("\nmatrica2\n\n");
SetColor(2,15);
for (a1=0;a1<m;a1++){
//вывод обработаной матрици
for(a2=0;a2<n;a2++){
printf("%d ",a[a1][a2]);
}
printf("\n");
}
SetColor(7,0);
}
