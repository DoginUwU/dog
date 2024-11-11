#include <core/logger.hpp>
#include <cstdarg>
#include <ctime>
#include <string>

void Logger::info(const char *format, ...) {
    char *string;
    va_list args;
    va_start(args, format);

    vasprintf(&string, format, args);
    print(string);

    free(string);

    va_end(args);
}

void Logger::print(const char *text) {
    const std::time_t now = std::time(nullptr);
    char timeStr[20];
    std::strftime(timeStr, sizeof(timeStr), "%H:%M:%S ", std::localtime(&now));

    std::string final_text;

    final_text.append(timeStr);
    final_text.append(text);
    final_text.append("\n");

    printf(final_text.c_str());
}
