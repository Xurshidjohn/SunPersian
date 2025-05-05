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

int addLocalHostPort() {
    int port = 0;
    printf("Please enter your file runned port: ");
    scanf("%d", &port);
    return port;
}

void PortChecker() {
    int port = addLocalHostPort();
    char *command = malloc(128 * sizeof(char));
    sprintf(command, "ngrok http %d", port);
    system(command); 
}

void TokenChecker() {
    char *token = addNginxToken();
    char *command = malloc(250 * sizeof(char));
    sprintf(command, "ngrok config add-authtoken %s", token);
    system(command);
}

int main(void) {
    TokenChecker();
    PortChecker();
    return 0;
}