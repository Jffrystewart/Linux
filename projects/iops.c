#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<time.h>

void write_func(char *wfilename, int wopen_file, char *wcontent);
void read_func(char *wfilename, int  wopen_file, char *wcontent);
int main(){
	// allocates requested memory and returns pointer. calloc sets allocated memory to zero
	char *content = (char *) calloc(100, sizeof(char));
	int  file_descriptor;
	int open_file;
	char  open_filename[255];
	char filename[255];

	printf("Enter file name: ");
	scanf("%[^\n]%*c",  open_filename);
	printf("Creating %s\n" , open_filename);
	open_file = open(open_filename, O_RDWR | O_CREAT, 0777);

	if(open_file != -1){
		printf("%s opened \n", open_filename);
	}
	else{
		printf("Could not open %s\n" , open_filename);

	}
	// %[^\n]%*c read a line of characters until first end of line, and *c is used to tell scanf to discard the new
	// line.
	printf("Enter content to write to file: ");
	scanf("%[^\n]%*c" , content);

	write_func(open_filename, open_file, content);
	read_func(open_filename, open_file, content);
	free(content);

	return 0;
}


void write_func(char *wfilename, int wopen_file, char *wcontent){

	printf("File name passed to function is %s\n", wfilename);	


	printf("Writing to %s\n" , wfilename);

	int size = write(wopen_file, wcontent, strlen(wcontent));
	
	printf("%d\n", size);
	close(wopen_file);



}

void read_func(char *wfilename, int  wopen_file, char *wcontent ){
	printf("Reading file..");

	// reading wcontent of size 100, and setting 99 to the null byte, which tells us to stop at the 99th index
	int size = read(wopen_file, wcontent, 100);
	wcontent[99] = '\0';
	printf("File content is: %s\n" , wcontent);
	close(wopen_file);

}


