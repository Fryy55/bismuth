#pragma once

#include <random>


namespace bismuth::utils {

inline std::mt19937_64& getMT() noexcept {
	thread_local std::mt19937_64 mt{std::random_device{}()};

	return mt;
}

/**
 * @brief Returns a random number from @p min to @p max
 * 
 * @tparam T Type of a number (has to satisfy @ref std::is_arithmetic_v)
 * @param min Minimum value
 * @param max Maximum value
 * @return Random number in a [min; max] range
 */
template <typename T>
	requires std::is_arithmetic_v<T>
T random(T min, std::type_identity_t<T> max) noexcept {
	auto& mt = getMT();

	if constexpr (std::is_integral_v<T>)
		return std::uniform_int_distribution<T>(min, max)(mt);
	else
		return std::uniform_real_distribution<T>(min, max)(mt);
}

} // namespace bismuth::utils