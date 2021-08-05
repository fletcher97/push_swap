#include "ft_stdlib.h"
#include "ft_norm.h"

#include "push_swap.h"
#include "common.h"

static void pusha(t_ps *ps)
{
    int         size;
    int         count;
    int         med;
    t_content   pushed;

    size = ft_stackpop(ps->bs).i;
    count = -1;
    pushed.i = 0;
    med = get_median(ps->b, size);
    while (++count != ft_abs(size))
    {
        if (size < 0)
            print_rrb(ps);
        if (ft_stackpeek(ps->b).i > med)
            pushed.i++;
        if (ft_stackpeek(ps->b).i > med)
            print_pa(ps);
        else if (size > 0)
            print_rb(ps);
    }
    ft_stackpush(ps->as, pushed);
    pushed.i = count - pushed.i;
    if (size > 0 && pushed.i < (int)ps->b->size)
        pushed.i = pushed.i * -1;
    ft_stackpush(ps->bs, pushed);
}

static void pushb(t_ps *ps, int size)
{
    int         count;
    int         med;
    t_content   pushed;

    count = -1;
    pushed.i = 0;
    med = get_median(ps->a, size);
    while (++count != ft_abs(size))
    {
        if (size < 0)
            print_rra(ps);
        if (ft_stackpeek(ps->a).i <= med)
            pushed.i++;
        if (ft_stackpeek(ps->a).i <= med)
            print_pb(ps);
        else if (size > 0)
            print_ra(ps);
    }
    ft_stackpush(ps->bs, pushed);
    pushed.i = count - pushed.i;
    if (size > 0 && pushed.i < (int)ps->a->size)
        pushed.i = pushed.i * -1;
    ft_stackpush(ps->as, pushed);
}

static void    sort(t_ps *ps)
{
    int sizea;
    int sizeb;

    if (ft_stacksize(ps->as) > 0 && ft_abs(ft_stackpeek(ps->as).i) <= 2)
        sizea = ft_stackpop(ps->as).i;
    else
        sizea = 10;
    if (ft_stacksize(ps->bs) > 0 && ft_abs(ft_stackpeek(ps->bs).i) <= 2)
        sizeb = ft_stackpop(ps->bs).i;
    else
        sizeb = 10;
    bring_up(ps, sizea, sizeb);
    sswap(ps, sizea, sizeb);
    // can be optimized by checking >= 1 first
    if (ft_abs(sizeb) == 2)
        print_pa(ps);
    if (ft_abs(sizeb) == 2)
        print_pa(ps);
    if (ft_abs(sizeb) == 1)
        print_pa(ps);
}

// void sp(t_stack *s)
// {
//  t_stack_elem    *ele;

//  if (!s || !s->top)
//      return ;
//  ele = s->top;
//  ft_putnbr_fd(ele->cont.i, 1);
//  while (ele->prev)
//  {
//      ele = ele->prev;
//      ft_putstr_fd("->", 1);
//      ft_putnbr_fd(ele->cont.i, 1);
//  }
//  ft_putstr_fd("\n", 1);
// }

void    execute_big(t_ps *ps)
{
    static int  flag = 0;
    int         size;

    if (ps->bs->size == 0 && issorted(ps->a))
        return ;
    if ((ps->as->size && ft_abs(ft_stackpeek(ps->as).i) <= 2)
        || (ps->bs->size && ft_abs(ft_stackpeek(ps->bs).i) <= 2))
        sort(ps);
    else if (ft_stacksize(ps->as) > 0)
    {
        size = ft_stackpop(ps->as).i;
        pushb(ps, ft_ternary32(!flag, ft_abs(size), size));
    }
    else if (ft_stacksize(ps->bs) > 0)
    {
        flag = 1;
        pusha(ps);
    }
    // sp(ps->a);
    // sp(ps->as);
    // sp(ps->b);
    // sp(ps->bs);
    execute_big(ps);
}
