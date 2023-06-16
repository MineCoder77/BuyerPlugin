#pragma once

#include <nlohmann/json.hpp>
#include <llapi/LoggerAPI.h>

extern Logger logger;

class JsonConfig {
private:
	nlohmann::json json_config;
	static JsonConfig instance;
	bool create_file();
	bool isset_config_path();
	bool isset_config();
	bool is_config_correct();
	void set_config();
	nlohmann::json get_config();
	JsonConfig() {}
	JsonConfig(const JsonConfig&) = delete;
	JsonConfig& operator=(JsonConfig&) = delete;
public:
	void init();
	static JsonConfig& get_instance();
	long get_price(std::string item_id);
	bool isset_value(std::string item_id);
};
