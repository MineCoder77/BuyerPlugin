#pragma once

#include <llapi/mc/Player.hpp>
#include <llapi/mc/Item.hpp>
#include <llapi/mc/Inventory.hpp>
#include "../../lib/LLMoney/LLMoney.h"
#include "../../manager/header/ConfigManager.hpp"

#pragma comment(lib, "../../lib/LLMoney/LLMoney.lib")

namespace Buyer {

	bool give_money(Player* player, money_t money_count);

	bool buy_item(Player* player, const Item* item, uint8_t count);
}
