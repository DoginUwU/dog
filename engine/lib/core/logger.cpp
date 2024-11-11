#include <core/logger.hpp>
#include <cstdarg>
#include <ctime>
#include <string>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE    "\x1b[37m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void Logger::info(const char *format, ...) {
    char *string;
    va_list args;
    va_start(args, format);

    vasprintf(&string, format, args);
    print(string, ANSI_COLOR_WHITE);

    free(string);

    va_end(args);
}

void Logger::error(const char *format, ...) {
    char *string;
    va_list args;
    va_start(args, format);

    vasprintf(&string, format, args);
    print(string, ANSI_COLOR_RED);

    free(string);

    va_end(args);
}

void Logger::print(const char *text, const char *color) {
    const std::time_t now = std::time(nullptr);
    char timeStr[20];
    std::strftime(timeStr, sizeof(timeStr), "%H:%M:%S ", std::localtime(&now));

    std::string final_text;

    final_text.append(color);
    final_text.append(timeStr);
    final_text.append(text);
    final_text.append("\n");
    final_text.append(ANSI_COLOR_RESET);

    printf(final_text.c_str());
}
