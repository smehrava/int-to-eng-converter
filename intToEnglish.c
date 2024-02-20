/*this program translates integers into the equivalent English word.
student name = sara mehravar
student id = 251185394
*/

#include <stdio.h>
#include <stdlib.h>

#include <string.h>
 
void getAlphabetNumbers(char* number)
{
int i = strlen(number);
// putting all the numbers required for writting a number from 1-999 in arrays

char* oneDigits[]= { "zero", "one", "two",   "three", "four","five", "six", "seven", "eight", "nine" };

char* twoDigits[]= { "","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen" };
 
char* ys[] = { "","","twenty","thirty", "forty", "fifty","sixty","seventy", "eighty","ninety" };
 
char* ThreeandFourDigits[] = {"hundred and"};
printf("\nYou entered the number ");
// checks if the entered input is a single digit
if (i == 1) 
{
printf("%s\n", oneDigits[*number - '0']);
return;
}
// 
while (*number != '\0') {
// checks if the entered digit has three digits(100-999)
if (i == 3) {
if (*number - '0' != 0) {
printf("%s ", oneDigits[*number - '0']);
printf("%s ",
ThreeandFourDigits[i - 3]); 
}
i--;
}

else
{
if (*number == '1') 
{
int sum = *number - '0' + *(number + 1) - '0';
printf("%s\n", twoDigits[sum]);
return;
}
else if (*number == '2' && *(number + 1) == '0')
{
printf("twenty\n");
return;
}
 
else
{
int i = *number - '0';
printf("%s ", i ? ys[i] : "");
number++;
if (*number != '0')
printf("%s ",
oneDigits[*number - '0']);
}
}
number++;
}
printf("\n");
}
 
int main(void)
{
int number;
char str[3];
while(1){
printf("\nEnter a number (1-999,0 to quit): ");
scanf("%s",str);
//the program terminates if the user enters 0
if(str[0]=='0') break;
else{
//calling functing getAlphabetNumbers from above            
getAlphabetNumbers(str);
}
}
 
return 0;
}
