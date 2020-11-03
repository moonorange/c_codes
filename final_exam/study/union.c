#include <unistd.h>

int     ft_strlen(char *str)
{
    int     len;

    len = 0;
    while (str[len] != '\0')
        len++;
    return (len);
}

int     is_exsited(char ch, int *ch_array)
{
    return (ch_array[(unsigned char)ch]);
}

void    record_ch(char ch, int *ch_array)
{
    ch_array[(unsigned char)ch] = 1;
}

void    inter(char *str, char *charset)
{
    int     ch_array[255];
    int     s_id;
    int     c_id;

    s_id = 0;
    while (s_id < ft_strlen(str))
    {
        c_id = 0;
        while (c_id < ft_strlen(charset))
        {
            if (str[s_id] == charset[c_id])
            {
                if(!is_exsited(str[s_id], ch_array))
                    write(1, &str[s_id], 1);
                record_ch(str[s_id], ch_array);
            }
            c_id++;
        }
        s_id++;
    }
}

int     main(int argc, char **argv)
{
    if (argc == 3)
        inter(argv[1], argv[2]);
    write(1, "\n" , 1);
}
