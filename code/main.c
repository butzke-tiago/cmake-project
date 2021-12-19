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
#include "curl/curl.h"

static void test_mymath(void);
static void test_jansson(void);
static void test_curl(void);

int main(int argc, char * argv[])
{
    printf("CMake Project v%s\n", PROJECT_VERSION_STR);

    test_mymath();
    test_jansson();
    test_curl();
}

void test_mymath(void)
{
    printf("\n\n=== %s ===\n\n", __func__);

    printf("A summation of 1 and 2: %d\n", summation(2, 1, 2));
    printf("A summation of 1, 2, 3, 4: %d\n", summation(4, 1, 2, 3, 4));

    printf("A product of 1 and 2: %d\n", product(2, 1, 2));
    printf("A product of 1, 2, 3, 4: %d\n", product(4, 1, 2, 3, 4));    

}

void test_jansson(void)
{
    printf("\n\n=== %s ===\n\n", __func__);

    printf("Jansson version is %s.\n", jansson_version_str());

    json_t *json = json_pack("{s:s,s:i,s:f}", "string", "value", "int", 1, "float", 1.);
    printf("A simple json: %s\n",json_dumps(json, JSON_COMPACT));
    json_decref(json); 
}

void test_curl(void)
{
    printf("\n\n=== %s ===\n\n", __func__);

    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        printf("Getting https://example.com\n");
        curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");
        /* example.com is redirected, so we tell libcurl to follow redirection */
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if(res != CURLE_OK)
            printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    else
    {
        printf("curl_easy_init() failed.");
    }
}