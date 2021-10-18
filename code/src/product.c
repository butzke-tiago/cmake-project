/**
 * @file product.c
 * @author Tiago Santos
 * @brief 
 * @version 0.1
 * @date 2021-10-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/* System includes */
#include <stdarg.h>

int product (const int n, ...)
{
    va_list list;
    va_start(list, n);

    int result = 1;
    for (int i = 0; i < n; i++)
    {
        result *= va_arg(list, int);
    }

    va_end(list);

    return result;
}