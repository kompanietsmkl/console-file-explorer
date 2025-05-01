#include "utils/FileClock.hpp"
#include <iomanip>
#include <sstream>

std::string Time::time(const std::filesystem::path& path) {
  try {
    auto ftime = std::filesystem::last_write_time(path);
    
    auto system_time = fileTimeToSystemTime(ftime);
    auto time_t = std::chrono::system_clock::to_time_t(system_time);
    
    std::ostringstream oss;
    oss << std::put_time(std::localtime(&time_t), "%d-%b-%y %I:%M %p");
    return oss.str();
  } catch (...) {
    return "N/A";
  }
}

std::chrono::system_clock::time_point Time::fileTimeToSystemTime(std::filesystem::file_time_type ftime) {
    auto system_now = std::chrono::system_clock::now();
    auto file_now = std::filesystem::file_time_type::clock::now();

    auto diff = ftime - file_now;

    return system_now + diff;
}
