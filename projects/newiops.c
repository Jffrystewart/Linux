#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdio.h>


int main(){

	char filename[255]; 	
	char content[1024];
	printf("Enter name of file: ");
	scanf("%[^\n]%*c" , filename);

	int file_descriptor = open(filename, O_WRONLY | O_CREAT, 0777);
	if (file_descriptor !=  -1){
		printf("File opened\n");

	}
	else{
		printf("Could not open %s\n", filename);

	}
	printf("Enter content to write to file: ");
	scanf("%[^\n]%*c" , content);

	int size = write(file_descriptor, content, strlen(content) );
	printf("%d" , size);
	close(file_descriptor);


	return 0;
}


