#pragma once

#include <llapi/EventAPI.h>
#include <llapi/mc/ColorFormat.hpp>
#include <llapi/mc/Player.hpp>
#include <llapi/mc/ItemStack.hpp>
#include <llapi/mc/Item.hpp>
#include "../../manager/BuyerManager.cpp"

class EventHandler {
private:
	void on_entity_attack();
public:
	void init();
};
