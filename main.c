#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <stdlib.h>

size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata) {
    size_t total = size * nmemb;
    fwrite(ptr, size, nmemb, stdout);
    return total;
}

char* addNginxToken() {
    char *authToken = malloc(128 * sizeof(char));
    printf("Please enter your nginx auth token: ");
    scanf("%s", authToken);
    return authToken;
}

void TokenChecker() {
    char *token = addNginxToken();
    printf("%s", token);
}

void FuncOfCurl() {

    CURL * curl;

    CURLcode res;
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.youtube.com/");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "my-c-client/1.0");
        res = curl_easy_perform(curl);

        if(res != CURLM_OK) {
            fprintf(stderr, "error: %s\n", curl_easy_strerror);
        }

        curl_easy_cleanup(curl);
    }
}

int main(void) {
    TokenChecker();
    return 0;
}