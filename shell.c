#include "shell.h"

/**
 * main - Shell
 * Return: 0 on success
 */

int main(void)
{
        ssize_t len = 0;
        char *buff = NULL, *value, *pathname, **arr;
        size_t size = 0;
        list_path *ogP = '\0';
        void (*f)(char **);

        signal(SIGINT, sig_handler);
        while (len != EOF)
        {
                _isatty();
                len = getline(&buff, &size, stdin);
                _EOF(len, buff);
                arr = splitstring(buff, " \n");
                if (!arr || !arr[0])
                        execute(arr);
                else
                {
                        value = _getenv("PATH");
                        ogP = linkpath(value);
                        pathname = _which(arr[0], ogP);
                        f = chkbuild(arr);
                        if (f)
                        {
                                free(buff);
                                f(arr);
                        }
                        else if (!pathname)
                                execute(arr);
                        else if (pathname)
                        {
                                free(arr[0]);
                                arr[0] = pathname;
                                execute(arr);
                        }
                }
        }
        free_list(ogP);
        freearr(arr);
        free(buff);
        return (0);
}
