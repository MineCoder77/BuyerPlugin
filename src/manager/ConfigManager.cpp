#include "header/ConfigManager.hpp"

inline JsonConfig JsonConfig::instance = JsonConfig();

inline JsonConfig& JsonConfig::get_instance() {
	return instance;
}

inline nlohmann::json JsonConfig::get_config() {
	return JsonConfig::json_config;
}

inline void JsonConfig::set_config() {
	std::ifstream file("plugins/Buyer/prices.json");
	JsonConfig::json_config = nlohmann::json::parse(file);
	file.close();
}

inline bool JsonConfig::create_file() {
	nlohmann::json j;
	j["item_1"]["id"] = "minecraft:diamond_block";
	j["item_1"]["price"] = 1000;
	std::ofstream file("plugins/Buyer/prices.json");
	if (!file) {
		file.close();
		return false;
	}
	file << std::setw(4) << j << std::endl;
	file.close();
	return true;
}

inline bool JsonConfig::isset_config_path() {
	return std::filesystem::exists("plugins/Buyer");
}

inline bool JsonConfig::isset_config() {
	return std::filesystem::exists("plugins/Buyer/prices.json");
}

inline long JsonConfig::get_price(std::string item_id) {
	for (const auto& x : get_config()) {
		if (x["id"] == "minecraft:" + item_id)
			return x["price"];
	}
	return NULL;
}

inline bool JsonConfig::isset_value(std::string item_id) {
	for (const auto& x : get_config()) {
		if (x["id"] == "minecraft:" + item_id)
			return true;
	}
	return false;
}

inline bool JsonConfig::is_config_correct() {
	for (const auto& x : get_config()) {
		if (x.empty()) {
			logger.error("Информация о предмете не может быть пустой!");
			return false;
		}
		if (!x["id"].is_string()) {
			logger.error("Айди должно быть строкой!");
			return false;
		}
		if (!x["price"].is_number() || !x["price"].is_number_integer()) {
			logger.error("Цена должна быть целочисленным числом!");
			return false;
		}
	}
	return true;
}

inline void JsonConfig::init() {
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
	set_config();
	is_config_correct() ? logger.info("Конфиг-файл настроен правильно. Плагин работает!") :
		logger.error("В конфиг-файле были найдены ошибки. Пока Вы их не исправите, код не будет работать!");
}
