#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include <iostream>


using namespace std;

int main() {

    cout << "Hello World!!" << endl;
    cout << "Dank things to come!!!" << endl;
    cout << "HOW BOUT DEM APPLES " << curl_version();
    cout << "Setting my Global init for libcurl" << endl;
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        
        curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");
        
        // Perform the request
        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }
    cout << "About to clean up libcurl" << endl;
    curl_global_cleanup();
    cout << "Clean up done for libcurl" << endl;
    return 0;
}
