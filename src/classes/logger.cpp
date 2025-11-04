#include <bismuth/classes/logger.hpp>

#include <bismuth/utils/log.hpp>

using namespace bismuth;
using namespace dpp;


void logger::operator()(log_t const& log) const noexcept {
	static constexpr std::string_view shardFormatString = "[Shard #{}] {}";

	switch (log.severity) {
		case ll_trace:
			log::trace(shardFormatString, log.shard, log.message);
			return;

		case ll_debug:
			log::debug(shardFormatString, log.shard, log.message);
			return;

		case ll_info:
			log::info(shardFormatString, log.shard, log.message);
			return;

		case ll_warning:
			log::warn(shardFormatString, log.shard, log.message);
			return;

		case ll_error:
			log::error(shardFormatString, log.shard, log.message);
			return;

		case ll_critical:
			log::crit(shardFormatString, log.shard, log.message);
			return;

		default:
			aurora::log::custom(
				{
					.logLevel=aurora::log::LogLevel::Error,
					.logLevelName="-UNK-",
					.headTag="\e[0m",
					.bodyTag="\e[0m"
				},
				shardFormatString,
				log.shard, log.message
			);
			return;
	}
}