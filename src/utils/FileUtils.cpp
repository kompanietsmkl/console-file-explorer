#include "utils/FileUtils.hpp"

namespace FileUtils {
  std::string print_permissions(const std::filesystem::path& path) {
    std::string permission = "---------";
    try {
      std::filesystem::perms p = std::filesystem::status(path).permissions();
      auto show = [&permission, &p](int pos, char op, std::filesystem::perms perm) {
        if ((perm & p) != std::filesystem::perms::none) permission[pos] = op;
      };

      show(0, 'r', std::filesystem::perms::owner_read);
      show(1, 'w', std::filesystem::perms::owner_write);
      show(2, 'x', std::filesystem::perms::owner_exec);
      show(3, 'r', std::filesystem::perms::group_read);
      show(4, 'w', std::filesystem::perms::group_write);
      show(5, 'x', std::filesystem::perms::group_exec);
      show(6, 'r', std::filesystem::perms::others_read);
      show(7, 'w', std::filesystem::perms::others_write);
      show(8, 'x', std::filesystem::perms::others_exec);
    } catch (const std::filesystem::filesystem_error& e) {
      return "?????????";
    }

    return permission;
  }
}
