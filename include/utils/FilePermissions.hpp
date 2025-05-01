#pragma once
#include <string>
#include <filesystem>

namespace FileUtils{
  std::string print_permissions(const std::filesystem::path& path);
}
