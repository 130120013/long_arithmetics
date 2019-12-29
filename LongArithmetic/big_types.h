#include <memory>
#pragma once

bool memadd(std::uint32_t* pResult, std::size_t cbResult, const std::uint32_t* pX, std::size_t cbX, const std::uint32_t* pY, std::size_t cbY) noexcept;


class BigInt {
public: 
	BigInt() = default;
	BigInt(std::uint32_t* number, std::size_t length, std::size_t accuracy) : m_number(number), m_length(length), m_accurancy(accuracy) {}
	BigInt operator+(const BigInt& rhs) 
	{
		auto result_container = std::make_unique<std::uint32_t[]>(this->m_length >= rhs.m_length ? this->m_length : rhs.m_length);
		auto addend = std::make_unique<std::uint32_t[]>(this->m_length >= rhs.m_length ? this->m_length : rhs.m_length);
		std::uint32_t carry = 0;
		if (this->m_length >= rhs.m_length) {
			std::memset(addend.get(), 0, this->m_length - rhs.m_length);
			std::memcpy(addend.get() + (this->m_length - rhs.m_length), rhs.m_number.get(), rhs.m_length);
			for (std::size_t i = m_length; i > 0; --i)
			{
				result_container.get()[i] = addend.get()[i] + this->m_number.get()[i] + carry;
				carry = UINTPTR_MAX - addend.get()[i] - this->m_number.get()[i] < 0 ? 1 : 0;
			}
		}
		else
		{
			std::memset(addend.get(), 0, rhs.m_length - this->m_length);
			std::memcpy(addend.get() + (rhs.m_length - this->m_length), this->m_number.get(), this->m_length);
			for (std::size_t i = rhs.m_length; i > 0; --i)
			{
				result_container.get()[i] = addend.get()[i] + rhs.m_number.get()[i] + carry;
				carry = UINTPTR_MAX - addend.get()[i] - this->m_number.get()[i] < 0 ? 1 : 0;
			}
		}
		BigInt result(result_container.get(), this->m_length >= rhs.m_length ? this->m_length : rhs.m_length, this->m_accurancy >= rhs.m_accurancy ? this->m_accurancy : rhs.m_accurancy);
		return result;
	}
	BigInt& operator-(const BigInt& rhs)
	{
	}
	BigInt& operator*(const BigInt& rhs)
	{
	}
	BigInt& operator/(const BigInt& rhs)
	{
	}
	BigInt& operator=(const BigInt& rhs)
	{
	}
	BigInt& operator=(BigInt&& rhs) noexcept
	{
	}
private:
	std::size_t m_length;
	std::size_t m_accurancy;
	std::unique_ptr<std::uint32_t[]> m_number;
};