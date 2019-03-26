#include "stddef.h"
#include "ft_is.h"

size_t	ft_get_right_word(const char *line, size_t pos, size_t end)
{
	size_t n;

	n = 0;
	while (pos < end)
	{
		if (ft_isalnum(line[pos]))
		{
			++n;
			while (++pos < end && ft_isalnum(line[pos]))
				++n;
			return (n);
		}
		++pos;
		++n;
	}
	return (n);
}
