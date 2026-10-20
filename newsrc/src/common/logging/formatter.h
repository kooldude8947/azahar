// Copyright 2022-2024 Citra Emulator Project / Azahar Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <type_traits>
#include <fmt/format.h>

// adapted from https://stackoverflow.com/a/77751342
// a generic formatter for enum classes
#if FMT_VERSION >= 80100
template <typename EnumType>
requires std::is_enum_v<EnumType>
struct fmt::formatter<EnumType> : fmt::formatter<std::underlying_type_t<EnumType>> {
    // Forwards the formatting by casting the enum to it's underlying type
    auto format(const EnumType& enumValue, format_context& ctx) const {
        return fmt::formatter<std::underlying_type_t<EnumType>>::format(
            static_cast<std::underlying_type_t<EnumType>>(enumValue), ctx);
    }
};
#endif
