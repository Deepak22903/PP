#include <curl/curl.h>
#include <iostream>

// Callback function to handle response data
size_t WriteCallback(void *contents, size_t size, size_t nmemb,
                     std::string *output) {
  size_t totalSize = size * nmemb;
  output->append((char *)contents, totalSize);
  return totalSize;
}

int main() {
  // Initialize libcurl
  CURL *curl = curl_easy_init();
  if (!curl) {
    std::cerr << "Failed to initialize cURL" << std::endl;
    return 1;
  }

  std::string response;
  curl_easy_setopt(curl, CURLOPT_URL, "https://api.github.com/");
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
  curl_easy_setopt(curl, CURLOPT_USERAGENT,
                   "Mozilla/5.0"); // Some APIs require a user agent

  CURLcode res = curl_easy_perform(curl);
  if (res != CURLE_OK) {
    std::cerr << "cURL request failed: " << curl_easy_strerror(res)
              << std::endl;
  } else {
    std::cout << "Response:\n" << response << std::endl;
  }

  // Cleanup
  curl_easy_cleanup(curl);
  return 0;
}
