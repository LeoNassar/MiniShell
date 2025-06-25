#include "../../include/minishell.h"

static int append_char_res(char **res, char c)
{
    char tmp[2];
    char *new;

    tmp[0] = c;
    tmp[1] = '\0';
    new = ft_strjoin(*res, tmp);
    free(*res);
    if (!new)
        return (0);
    *res = new;
    return (1);
}

static char escape_char(char c)
{
    if (c == 'n')
        return ('\n');
    if (c == 't')
        return ('\t');
    if (c == 'r')
        return ('\r');
    if (c == 'v')
        return ('\v');
    if (c == 'b')
        return ('\b');
    if (c == 'a')
        return ('\a');
    if (c == 'f')
        return ('\f');
    if (c == '\\' || c == '\'')
        return (c);
    return (c);
}

int replace_ansi_quotes(char **line)
{
    char    *src;
    char    *res;
    int             i;

    src = *line;
    res = ft_strdup("");
    if (!res)
        return (0);
    i = 0;
    while (src[i])
    {
        if (src[i] == '$' && src[i + 1] == '\'')
        {
            i += 2;
            if (!append_char_res(&res, '"'))
                return (free(res), 0);
            while (src[i] && src[i] != '\'')
            {
                if (src[i] == '\\' && src[i + 1])
                {
                    if (!append_char_res(&res, escape_char(src[i + 1])))
                        return (free(res), 0);
                    i += 2;
                }
                else
                {
                    if (!append_char_res(&res, src[i++]))
                        return (free(res), 0);
                }
            }
            if (src[i] == '\'')
                i++;
            if (!append_char_res(&res, '"'))
                return (free(res), 0);
        }
        else
        {
            if (!append_char_res(&res, src[i++]))
                return (free(res), 0);
        }
    }
    free(*line);
    *line = res;
    return (1);
}
