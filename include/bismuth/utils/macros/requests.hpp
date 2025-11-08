#pragma once

#include <dpp/queues.h>


namespace bismuth::utils::impl {

/**
 * @attention Implement this function to handle @ref REQUEST_VERIFICATION macros failing
 * 
 */
void requestFailed(dpp::http_request_completion_t const& request, std::size_t tag);

}

#define REQUEST_VERIFICATION(request, tag)                         \
	do {                                                           \
		if ((request).status != 200) {                             \
			bismuth::utils::impl::requestFailed((request), (tag)); \
			return;                                                \
		}                                                          \
	} while (false)

#define REQUEST_VERIFICATION_CORO(request, tag)                    \
	do {                                                           \
		if ((request).status != 200) {                             \
			bismuth::utils::impl::requestFailed((request), (tag)); \
			co_return;                                             \
		}                                                          \
	} while (false)

#define REQUESTS_VERIFICATION(tagOffset, ...)         \
	do {                                              \
		std::size_t tag = tagOffset;                  \
		for (auto const& request : { __VA_ARGS__ }) { \
			REQUEST_VERIFICATION(request, tag);       \
			++tag;                                    \
		}                                             \
	} while (false)

#define REQUESTS_VERIFICATION_CORO(tagOffset, ...)    \
	do {                                              \
		std::size_t tag = tagOffset;                  \
		for (auto const& request : { __VA_ARGS__ }) { \
			REQUEST_VERIFICATION_CORO(request, tag);  \
			++tag;                                    \
		}                                             \
	} while (false)