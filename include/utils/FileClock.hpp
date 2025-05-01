#pragma once
#include <string>
#include <filesystem>

struct Time {
  static std::string time(const std::filesystem::path& path);
private:
  static std::chrono::system_clock::time_point fileTimeToSystemTime(std::filesystem::file_time_type ftime);
};