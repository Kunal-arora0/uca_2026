#include<stdio.h>


void url_encode(char *str , int true_length){

	char buf[100];
	int index = 0;

	for(int i =0 ; i< true_length ;i++){
		if(str[i] == ' '){
			buf[index++] = '%';
			buf[index++] = '2';
			buf[index++] = '0';
		}
		else{
			buf[index++] = str[i];
		}
	}

	buf[index] = '\0';

	for(int i = 0 ; i <= index; i++){
		str[i] = buf[i];
	}
}

int main(){
	char str[100];
	printf("Enter a string : ");
	fgets(str , 100 , stdin);

	int len = 0;

	while(str[len] != '\n' && str[len]!= '\0'){
		len++;
	}

	str[len] = '\0';
	url_encode(str,len);
	printf("%s" , str);
	return 0;
}
