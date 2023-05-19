#include "headers/ConfigManager.hpp"

JsonConfig* JsonConfig::p_instance = 0;

JsonConfigDestroyer JsonConfig::destroyer;
  
JsonConfigDestroyer::~JsonConfigDestroyer() {
    delete p_instance;
}

void JsonConfigDestroyer::initialize(JsonConfig* p) {
    p_instance = p; 
}

JsonConfig& JsonConfig::get_instance() {
    if(!p_instance) {
        p_instance = new JsonConfig();
        destroyer.initialize(p_instance);     
    }
    return *p_instance;
}

void JsonConfig::init() {
	if (!isset_config_path()) {
		logger.info("Папка Buyer не существует. Создаю...");
		std::filesystem::create_directories("plugins/Buyer");
		logger.info("Папка успешно создана.");
		logger.info("Создаю конфиг prices.json.");
		if (!create_file()) {
			logger.error("Проблемы с созданием конфига. Проверьте права на запись файла.");
			return;
		}
		else
			logger.info("Файл prices.json успешно создан!");
	}
	else if (!isset_config()) {
		logger.info("Не найден конфиг prices.json. Создаю новый...");
		if (!create_file()) {
			logger.error("Проблемы с созданием конфига. Проверьте права на запись файла.");
			return;
		}
		else
			logger.info("Файл prices.json успешно создан!");
	}
	JsonConfig::set_config();
}

nlohmann::json JsonConfig::get_config() {
	return JsonConfig::json_config;
}

void JsonConfig::set_config() {
	std::ifstream file("plugins/Buyer/prices.json");
	JsonConfig::json_config = nlohmann::json::parse(file);
	file.close();
}

bool JsonConfig::create_file() {
	nlohmann::json j;
	j["prices"]["57"]["price"] = 1000;
	std::ofstream file("plugins/Buyer/prices.json");
	if (!file) {
		file.close();
		return false;
	}
	file << std::setw(4) << j << std::endl;
	file.close();
	return true;
}

bool JsonConfig::isset_config_path() {
	return std::filesystem::exists("plugins/Buyer");
}

bool JsonConfig::isset_config() {
	return std::filesystem::exists("plugins/Buyer/prices.json");
}

long JsonConfig::get_price(std::string item_id) {
	return get_config()["prices"][item_id]["price"];
}

bool JsonConfig::isset_value(std::string item_id) {
	return get_config()["prices"].contains(item_id);
}