#include "array.h"
#include "readline.h"
#include "libft.h"

void    add_cursor_offset(int offset)
{
	char	str[20];

	if (offset)
	{
		memset(str, 0, 20);
		array_add(CSI, strlen(CSI));
		ft_strnum(str, offset);
		array_add(str, strlen(str));
		array_add("A", 1);
	}
	array_add(CURSOR_MOVE_LINE_START, strlen(CURSOR_MOVE_LINE_START));
}