#include "readline.h"
#include "get_next_line.h"
#include "libft.h"
#include <pwd.h>
#include <unistd.h>
#include <fcntl.h>

static void read_history_from_file(int fd)
{
	int			ret;
	char		*str;
	int 		len;
	t_cursor	pos;

	pos.row = 0;
	pos.col = 0;
	while ((ret = get_next_line(fd, &str)))
	{
		len = ft_strlen(str);
		if (g_history->size == g_history->len)
			history_resize(g_history);
		g_history->len++;
		g_history->matrix[g_history->len - 1] = matrix_init();
		matrix_create_line(g_history->matrix[g_history->len - 1], 0);
		matrix_string_insert(g_history->matrix[g_history->len - 1], pos, str, len);
		string_fill(g_history->matrix[g_history->len - 1]->str, str, len);
		free(str);
	}
}

static void	read_history_from_disk(void)
{
	int				fd;
	char			*file_name;
	struct passwd	*pw;

	pw = getpwuid(getuid());
	file_name = ft_strjoin(pw->pw_dir, "/", 0);
	file_name = ft_strjoin(file_name, HISTORY_FILE, 1);
	fd = open(file_name, O_CREAT | O_RDONLY | O_APPEND, 0777);
	read_history_from_file(fd);
	close(fd);
	free(file_name);
}

static void	init_history(void)
{
	g_history = (t_history *)xmalloc(sizeof(t_history));
	g_history->matrix = (t_matrix **)xmalloc(HISTORY_DEFAULT_SIZE * sizeof(t_matrix *));
	g_history->size = HISTORY_DEFAULT_SIZE;
	g_history->len = 0;
	g_history->cur = 0;
	g_history->last_offset = 0;
	g_history->str = string_init();
	read_history_from_disk();
	g_mode = VI;
}

void		history_fill(void)
{
	if (g_history == NULL)
		init_history();
	if (g_history->size == g_history->len)
		history_resize(g_history);
	g_history->len++;
	g_history->cur = g_history->len - 1;
	g_history->last_offset = 0;
	g_history->cur_matrix = matrix_init();
	matrix_create_line(g_history->cur_matrix, 0);
	g_history->matrix[g_history->cur] = matrix_dup(g_history->cur_matrix);
}