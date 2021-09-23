#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*res;
	char			*tmp;
	unsigned int	i;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	tmp = (char *)s1;
	i = 0;
	res = malloc(sizeof(int) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (*s1)
		res[i++] = (char)*s1++;
	while (*s2)
		res[i++] = (char)*s2++;
	res[i] = '\0';
	//free(tmp);
	return (res);
}