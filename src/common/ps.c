#include "ft_stdlib.h"
#include "ft_stack.h"
#include "actions.h"

t_ps	*dup_ps(t_ps *ps)
{
	t_ps	*ret;

	ret = ft_malloc(sizeof(t_ps));
	if (!ret)
		return (NULL);
	ret->a = ft_stackdup(ps->a, NULL);
	ret->b = ft_stackdup(ps->b, NULL);
	ret->as = ft_stackdup(ps->as, NULL);
	ret->bs = ft_stackdup(ps->bs, NULL);
	return (ret);
}

void	destroy_ps(t_ps *ps)
{
	if(ps->a)
		ft_stackdestroy(ps->a, NULL);
	if(ps->b)
		ft_stackdestroy(ps->b, NULL);
	if(ps->as)
		ft_stackdestroy(ps->as, NULL);
	if(ps->bs)
		ft_stackdestroy(ps->bs, NULL);
	ft_free(ps);
}
