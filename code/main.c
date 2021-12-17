/**
 * @file main.c
 * @author Tiago Santos
 * @brief
 * @version 0.1
 * @date 2021-10-13
 *
 * @copyright Copyright (c) 2021
 *
 */

/* System includes */
#include <stdio.h>

#include "cmake-project.h"

#ifdef USE_LIBS
/* Libs includes */
#include "mymath.h"
#else
/* Modules includes */
#include "summation.h"
#include "product.h"
#endif

int main(int argc, char * argv[])
{
    printf("CMake Project v%s\n", PROJECT_VERSION_STR);

    printf("A summation of 1 and 2: %d\n", summation(2, 1, 2));
    printf("A summation of 1, 2, 3, 4: %d\n", summation(4, 1, 2, 3, 4));

    printf("A product of 1 and 2: %d\n", product(2, 1, 2));
    printf("A product of 1, 2, 3, 4: %d\n", product(4, 1, 2, 3, 4));
}