#pragma once

#include <cstddef>
#include <string>
#include <variant>

namespace lv {
constexpr size_t bool_index = 0;
constexpr size_t double_index = 1;
constexpr size_t string_index = 2;
constexpr size_t nullptr_index = 3;
}  // namespace lv

using LiteralValue = std::variant<bool, double, std::string, std::nullptr_t>;