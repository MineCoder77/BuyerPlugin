#include "headers/BuyerManager.hpp"

namespace Buyer {

	inline bool give_money(Player* player, money_t money_count) {
		return LLMoneyAdd(player->getXuid(), money_count);
	}

	inline bool buy_item(Player* player, const Item* item, uint8_t count) {
		return give_money(player, static_cast<money_t>(JsonConfig::get_instance().get_price(std::to_string(item->getId())) * count));
	}
}