#include <stdlib.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <fcntl.h>

# define REWRITE_FLAGS	(O_CREAT | O_WRONLY | O_TRUNC)
# define APPEND_flags	(O_CREAT | O_WRONLY | O_APPEND)
# define RW_RIGHTS		(S_IWUSR | S_IRUSR)
# define FILE_NAME		"test.txt"

int main(int argc, char **argv)
{
	int file_desc;

	if (argc > 1)
    	file_desc = open(FILE_NAME, REWRITE_FLAGS, RW_RIGHTS);
	else
		file_desc = open(FILE_NAME, APPEND_flags, RW_RIGHTS);
    dup2(file_desc, 1);
	system("ls");
	return (0);
}