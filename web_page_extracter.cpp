#include<iostream>
#include<fstream>
#include<string>
#include<curl/curl.h>

using namespace std;

static size_t writeCallBack(void *contents, size_t size, size_t nmemb, void *userp){
    ((string *)userp)->append((char *)contents, size * nmemb);
    return size * nmemb;
}

int main()
{
    CURL *curl;
    CURLcode res;
    string readBuffer;
    ofstream out("largefile.txt",ios::app);

    curl = curl_easy_init();
    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, "https://en.wikipedia.org/wiki/C%2B%2B11");//wikipedia page of c++11
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallBack);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        
        //cout<<readBuffer<<endl;
        //write to a file

        out<<readBuffer<<flush;
    }
    return 0;
}
