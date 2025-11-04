#pragma once

#include <aurora/log.hpp>


namespace bismuth::log {

template <typename ...Args>
void trace(std::format_string<Args...> const& formatString, Args&&... args) noexcept {
	aurora::log::custom(
		{
			.logLevel=aurora::log::LogLevel::Debug,
			.logLevelName="TRACE",
			.headTag="\e[90m",
			.bodyTag="\e[30m"
		},
		formatString, std::forward<Args>(args)...
	);

	return;
}

template <typename ...Args>
void debug(std::format_string<Args...> const& formatString, Args&&... args) noexcept {
	aurora::log::debug(formatString, std::forward<Args>(args)...);

	return;
}

template <typename ...Args>
void info(std::format_string<Args...> const& formatString, Args&&... args) noexcept {
	aurora::log::info(formatString, std::forward<Args>(args)...);

	return;
}

template <typename ...Args>
void warn(std::format_string<Args...> const& formatString, Args&&... args) noexcept {
	aurora::log::warn(formatString, std::forward<Args>(args)...);

	return;
}

template <typename ...Args>
void error(std::format_string<Args...> const& formatString, Args&&... args) noexcept {
	aurora::log::error(formatString, std::forward<Args>(args)...);

	return;
}

template <typename ...Args>
void crit(std::format_string<Args...> const& formatString, Args&&... args) noexcept {
	aurora::log::custom(
		{
			.logLevel=aurora::log::LogLevel::Error,
			.logLevelName="CRIT ",
			.headTag="\e[4;91m",
			.bodyTag="\e[4;91m"
		},
		formatString, std::forward<Args>(args)...
	);

	return;
}

} // namespace bismuth::log