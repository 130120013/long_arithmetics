#include <cstdint>
#include <cstddef>
#pragma once

bool memadd(std::uint32_t* pResult, std::size_t cbResult, const std::uint32_t* pX, std::size_t cbX, const std::uint32_t* pY, std::size_t cbY) noexcept;