#pragma once


namespace bismuth::utils::impl {

/**
 * @attention Implement this function to handle @ref OPTIONS_PRELUDE macros not having any options passed
 * 
 */
void noOptions();

}

#define OPTIONS_PRELUDE(eventPointer)                                                \
	auto const& options = (eventPointer)->command.get_command_interaction().options; \
	do {                                                                             \
		if (options.empty()) {                                                       \
			bismuth::utils::impl::noOptions();                                       \
			return;                                                                  \
		}                                                                            \
	} while (false)

#define OPTIONS_PRELUDE_CORO(eventPointer)                                           \
	auto const& options = (eventPointer)->command.get_command_interaction().options; \
	do {                                                                             \
		if (options.empty()) {                                                       \
			bismuth::utils::impl::noOptions();                                       \
			co_return;                                                               \
		}                                                                            \
	} while (false)

#define OPTIONS_EXCLUSIVE_SUBCOMMAND_PRELUDE(eventPointer) \
	OPTIONS_PRELUDE(eventPointer);                         \
	auto const& subcommandName = options[0].name

#define OPTIONS_EXCLUSIVE_SUBCOMMAND_PRELUDE_CORO(eventPointer) \
	OPTIONS_PRELUDE_CORO(eventPointer);                         \
	auto const& subcommandName = options[0].name