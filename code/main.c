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

#include "jansson.h"

int main(int argc, char * argv[])
{
    printf("CMake Project v%s\n", PROJECT_VERSION_STR);

    printf("A summation of 1 and 2: %d\n", summation(2, 1, 2));
    printf("A summation of 1, 2, 3, 4: %d\n", summation(4, 1, 2, 3, 4));

    printf("A product of 1 and 2: %d\n", product(2, 1, 2));
    printf("A product of 1, 2, 3, 4: %d\n", product(4, 1, 2, 3, 4));
    
    printf("Jansson version is %s.\n", jansson_version_str());

    json_t *json = json_pack("{s:s,s:i,s:f}", "string", "value", "int", 1, "float", 1.);
    printf("A simple json: %s\n",json_dumps(json, JSON_COMPACT));
    json_decref(json); 
}