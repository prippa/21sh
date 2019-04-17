#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

# define REWRITE_FLAGS	(O_CREAT | O_WRONLY | O_TRUNC)
# define APPEND_FLAGS	(O_CREAT | O_WRONLY | O_APPEND)
# define RW_RIGHTS		(S_IWUSR | S_IRUSR)
# define FILE_NAME		"test.txt"
# define SOME_TEXT		"LOOLOLOLOL\n123\n"

int main(int argc, char **argv)
{
	int file_desc;
	int saved_stdout;

	saved_stdout = dup(1);
	// file_desc = open(FILE_NAME, APPEND_FLAGS, RW_RIGHTS);
	// dup2(file_desc, 1);
	close(1);
	write(1, SOME_TEXT, strlen(SOME_TEXT));
	dup2(saved_stdout, 1);
	close(saved_stdout);
	close(file_desc);
	write(1, "alive\n", 6);
	// if (argc > 1)
	// 	file_desc = open(FILE_NAME, REWRITE_FLAGS, RW_RIGHTS);
	// else
	// 	file_desc = open(FILE_NAME, APPEND_FLAGS, RW_RIGHTS);
	// close(1);
	// dup2(file_desc, 1);
	// dup2(1, file_desc);
	// system("ls");
	return (0);
}