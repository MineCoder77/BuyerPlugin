#include "handler/EventHandler.cpp"

void PluginInit() {

	EventHandler handler;
	handler.init();

	JsonConfig& config = JsonConfig::get_instance();
	config.init();

}
