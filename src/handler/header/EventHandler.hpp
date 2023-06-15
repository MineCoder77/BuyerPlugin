#pragma once

#include <llapi/EventAPI.h>
#include <llapi/mc/ColorFormat.hpp>
#include <llapi/mc/Player.hpp>
#include <llapi/mc/ItemStack.hpp>
#include <llapi/mc/Item.hpp>
#include "../../manager/header/BuyerManager.hpp"

class EventHandler {
private:
	EventHandler() {}
	static EventHandler instance;
	void on_entity_attack();
	EventHandler(const EventHandler&) = delete;
	EventHandler& operator=(EventHandler&) = delete;
public:
	const void init();
	static EventHandler& get_instance();
};
