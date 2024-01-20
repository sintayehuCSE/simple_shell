#include "shell.h"
void set_info(info_t *info, char **argv)
{
    info->fname = argv[0];
}