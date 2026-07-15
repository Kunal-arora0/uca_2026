#include<stdio.h>
#include<string.h>

void reverse_string(char *str){
	int start = 0;
	int end = strlen(str)-1;

	while(start < end){

		char temp  = str[start];
		str[start] =  str[end];
		str[end] = temp;

		start++;
		end--;

	}
}
int main(){

	char str[100];
	printf( "Enter a String : ");
	scanf("%s" , str);
	reverse_string(str);
	printf("Reversed : %s\n" , str);
}
