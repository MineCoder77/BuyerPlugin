#pragma once

#include <nlohmann/json.hpp>
#include <llapi/LoggerAPI.h>

extern Logger logger;

class JsonConfig {
private:
	nlohmann::json json_config;
	static JsonConfig instance;
	const bool create_file();
	const bool isset_config_path();
	const bool isset_config();
	const bool check_config_correct();
	void set_config();
	nlohmann::json get_config();
	JsonConfig() {}
	JsonConfig(const JsonConfig&) = delete;
	JsonConfig& operator=(JsonConfig&) = delete;
public:
	const void init();
	static JsonConfig& get_instance();
	const long get_price(std::string item_id);
	const bool isset_value(std::string item_id);
};
