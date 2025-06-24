
#include "../../include/minishell.h"

void	signals2(void)
{
	signal(SIGQUIT, SIG_DFL);
}
