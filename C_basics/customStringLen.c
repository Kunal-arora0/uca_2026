#include<stdio.h>

int my_strlen(const char *str){
	int length = 0;

	while(*str != '\0'){
		length++;
		str++;	
	}


	return length;
}

int main(){

	char str[] = "Hello World";
	printf( "%d\n" , my_strlen(str));
}
