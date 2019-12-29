#ifndef BIG_TYPES_H
#define BIG_TYPES_H
#include "big_types.h"
bool memadd(std::uint32_t* pResult, std::size_t cbResult, const std::uint32_t* pX, std::size_t cbX, const std::uint32_t* pY, std::size_t cbY) noexcept {
	std::uint32_t carry = 0;
	if (cbX >= cbY) {
		cbResult = cbX;
		for (std::size_t i = cbY - 1; i > 0; --i)
		{
			pResult[i] = pY[i] + pX[i] + carry;
			carry = UINTPTR_MAX - pY[i] - pX[i] - carry < 0 ? 1 : 0;
		}
		for (std::size_t i = cbX - cbY - 1; i > 0; --i)
		{
			pResult[i] = pX[i] + carry;
			carry = UINTPTR_MAX - pX[i] - carry < 0 ? 1 : 0;
		}
	}
	else
	{
		cbResult = cbY;

		for (std::size_t i = cbX - 1; i > 0; --i)
		{
			pResult[i] = pY[i] + pX[i] + carry;
			carry = UINTPTR_MAX - pY[i] - pX[i] - carry < 0 ? 1 : 0;
		}
		for (std::size_t i = cbY - cbX - 1; i > 0; --i)
		{
			pResult[i] = pY[i] + carry;
			carry = UINTPTR_MAX - pY[i] - carry < 0 ? 1 : 0;
		}
	}
	return carry;
}
#endif // !BIG_TYPES_H
