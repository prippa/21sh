#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <string.h> 
#include <sys/wait.h>
#include <stdint.h>
#include <string.h>

#define ERR -1
#define READ_END 0
#define WRITE_END 1

static void		p_exit(const char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

static void		p_loop_pipe(int32_t fd[2], char ***cmds, char **paths)
{
	pid_t	father;
	int32_t	fd_in;

	fd_in = STDIN_FILENO;
	while (*cmds)
	{
		if (pipe(fd) == ERR)
			p_exit("pipe");
		if ((father = fork()) == ERR)
			p_exit("fork");
		if (!father)
		{
			if (dup2(fd_in, STDIN_FILENO) == ERR)
				p_exit("dup2");
			if (dup2(fd[WRITE_END], STDOUT_FILENO) == ERR)
				p_exit("dup2");
			close(fd[READ_END]);
			execve(*paths, *cmds, NULL);
			p_exit("execve");
		}
		else
		{
			wait(NULL);
			close(fd[WRITE_END]);
			fd_in = fd[READ_END];
			++cmds;
			++paths;
		}
	}
}

int				main2(void)
{
	char	*cm1[] = {"ls", NULL};
	char	*cm2[] = {"cat", "-e", NULL};
	char	*cm3[] = {"head", "-4", NULL};
	char	*cm4[] = {"wc", "-l", NULL};
	char	**cmds[] = {cm1, cm2, NULL};
	char	*paths[] = {"/bin/ls", "/bin/cat", "/usr/bin/head", "/usr/bin/wc", NULL};
	int32_t	fd[2];
	char	buf[10000];

	bzero(buf, 10000);
	p_loop_pipe(fd, cmds, paths);
	read(fd[READ_END], buf, 10000);
	close(fd[READ_END]);
	printf("%s", buf);
	return (0);
}

int				main(void)
{
	main2();
	system("leaks -q a.out");
	return (0);
}
