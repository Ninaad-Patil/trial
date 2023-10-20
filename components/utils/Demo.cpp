#include <iostream>
#include <locale>
#include <string>
#include <cstring>
int main() {
    setlocale(LC_ALL, ""); // set the program's locale based on environment variables
    const char* utf8String = "こんにちは";
    size_t len = strlen(utf8String);

    // Use the deprecated conversion facet to convert from UTF-8 to wide characters    typedef std::codecvt<wchar_t, char, std::mbstate_t> codecvt_t;
    const codecvt_t& converter = std::use_facet<codecvt_t>(std::locale());

    std::mbstate_t state = std::mbstate_t(); // initial state    const char* from_next;
    wchar_t wideBuffer[10];
    wchar_t* to_next;

    converter.in(state, utf8String, utf8String + len, from_next, wideBuffer, wideBuffer + 10, to_next);

    std::wcout << L"Converted string: " << wideBuffer << std::endl;

    return 0;
}