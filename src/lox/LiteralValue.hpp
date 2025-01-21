#include <cstddef>
#include <variant>
#include <string>

namespace lv {
constexpr size_t INT_INDEX = 0;
constexpr size_t DOUBLE_INDEX = 1;
constexpr size_t STRING_INDEX = 2;
constexpr size_t NULLPTR_INDEX = 3;

}  // namespace lv

using LiteralValue = std::variant<bool, double, std::string, std::nullptr_t>;