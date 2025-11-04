#pragma once

#include <dpp/dispatcher.h>


namespace bismuth {

struct logger final {
	void operator()(dpp::log_t const&) const noexcept;
};

}