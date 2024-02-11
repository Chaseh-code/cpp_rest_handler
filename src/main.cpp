#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include <iostream>


using namespace std;

int main() {
    CURL *curl;
    CURLcode res;
    const int STATIC_URL_SIZE = 256;
    string input;
    //string url; // no bueno
    //string url = "https://example.com"; // no bueno
    //char url[] = "https://example.com"; // Was bueno
    char * url = new char[256]; // Was bueno. How to handle mem allocation?
    const string HTTPS = "https://";

    cout << "Hello World!!" << endl;
    cout << "Dank things to come!!!" << endl;
    cout << "HOW BOUT DEM APPLES " << curl_version() << endl;

    cout << "Setting my Global init for libcurl" << endl;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    cout << "Please enter the name of a website" << endl;
    cin >> input;

    while(cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Sorry, some kind of typo happened... Crazy how that happens.\n What url were you looking for?" << endl;
        cin >> input;
    }

    if(input.substr(0, 8) == HTTPS) {
        strcpy(url, input.c_str());
    } else {
        strcpy(url, (HTTPS + input).c_str());
    }
    //url.insert(0, input);
    //url.insert(0, HTTPS);
    cout << "What does my url look like: " << url << endl;
    
    if(curl) {
        
        curl_easy_setopt(curl, CURLOPT_URL, url); //"https://example.com" example I was testing with
        //curl_easy_reset() // This resets any setopt options. So that the same curl pointer can be used for different tasks.

        // Perform the request
        res = curl_easy_perform(curl);

        if(CURLE_OK == res) {
            char *ct;
            /* ask for the content-type*/
            res = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &ct);

            if((CURLE_OK == res) && ct) {
                cout << "We received Content-Type: \n" << ct << endl;
            }
        }
        if(res != CURLE_OK) {
            //fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            cout << "curl_easy_perform() failed!!!!: " << curl_easy_strerror(res) << endl;
        }

        curl_easy_cleanup(curl);
    }
    cout << "About to clean up libcurl" << endl;
    curl_global_cleanup();
    cout << "Clean up done for libcurl" << endl;
    delete url;
    return 0;
}
