#include "ft_printf.h"

// 메인 printf함수
int ft_printf(const char *s, ...)
{
    va_list ap;
    va_start(ap, s);
    t_flags flags;
    char *percent;
    char *s_copy;
    int arg;
    int len = 0;

    s_copy = (char *)s;
    // percent변수에 문자열에서 %부분 주소값 받아오기
    while ((percent = ft_strchr(s_copy, '%')))
    {
        write(1, s_copy, percent - s_copy);
        ft_memset(&flags, 0, sizeof(t_flags));
        percent++;
        check_string(&percent, &flags);
        if (*percent == 'd')
        {	
            len = get_arg(&arg, ap, &flags);
            get_width(&flags, len);
            if (!flags.minus)
                output_plus(&flags, arg);
            else
                output_minus(&flags, arg);
        }
        percent++;
        s_copy = percent;
    }
    ft_putstr_fd(s_copy, 1);
    return (0);
}

int main()
{
    ft_printf("ft_printf: hello [%10d] world\n", 7);
    printf("   printf: hello [%10d] world\n", 7);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%4d] world\n", 77777);
    printf("   printf: hello [%4d] world\n", 77777);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%-10d] world\n", 7);
    printf("   printf: hello [%-10d] world\n", 7);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%-4d] world\n", 77777);
    printf("   printf: hello [%-4d] world\n", 77777);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%.10d] world\n", 7);
    printf("   printf: hello [%.10d] world\n", 7);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%.4d] world\n", 77777);
    printf("   printf: hello [%.4d] world\n", 77777);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%10.6d] world\n", 7);
    printf("   printf: hello [%10.6d] world\n", 7);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%-10.6d] world\n", 7);
    printf("   printf: hello [%-10.6d] world\n", 7);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%*d] world\n", 10, 7);
    printf("   printf: hello [%*d] world\n", 10, 7);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%*d] world\n", -10, 7);
    printf("   printf: hello [%*d] world\n", -10, 7);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%.*d] world\n", 10, 7);
    printf("   printf: hello [%.*d] world\n", 10, 7);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%0*d] world\n", 10, 7);
    printf("   printf: hello [%0*d] world\n", 10, 7);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%*.*d] world\n", 10, 2, 777);
    printf("   printf: hello [%*.*d] world\n", 10, 2, 777);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%*.*d] world\n", -10, 2, 777);
    printf("   printf: hello [%*.*d] world\n", -10, 2, 777);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%-4.7d] world\n",12345);
    printf("   printf: hello [%-4.7d] world\n",12345);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%-7.3d] world\n",12345);
    printf("   printf: hello [%-7.3d] world\n",12345);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%010.7d] world\n",12345);
    printf("   printf: hello [%010.7d] world\n",12345);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%010.3d] world\n",12345);
    printf("   printf: hello [%010.3d] world\n",12345);
    write(1, "\n", 1);
}