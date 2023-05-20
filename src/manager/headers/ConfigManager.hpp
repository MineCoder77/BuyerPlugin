#pragma once

#include <nlohmann/json.hpp>
#include <llapi/LoggerAPI.h>

extern Logger logger;

class JsonConfig;

class JsonConfigDestroyer {
private:
	JsonConfig* p_instance;
public:
	~JsonConfigDestroyer();
	void initialize(JsonConfig* p);
};

class JsonConfig {
private:
	static JsonConfig* p_instance;
	static JsonConfigDestroyer destroyer;
	nlohmann::json json_config;
	bool create_file();
	bool isset_config_path();
	bool isset_config();
	void set_config();
	nlohmann::json get_config();
protected:
	JsonConfig() {}
	JsonConfig(const JsonConfig&) = delete;
	JsonConfig& operator=(JsonConfig&) = delete;
	~JsonConfig() {}
	friend class JsonConfigDestroyer;
public:
	void init();
	static JsonConfig& get_instance();
	long get_price(std::string item_id);
	bool isset_value(std::string item_id);
};
