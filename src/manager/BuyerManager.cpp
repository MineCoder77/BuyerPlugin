#include "header/BuyerManager.hpp"

namespace Buyer {

	inline const bool give_money(Player* player, money_t money_count) {
		return LLMoneyAdd(player->getXuid(), money_count);
	}

	inline const bool buy_item(Player* player, const Item* item, uint8_t count) {
		return give_money(player, static_cast<money_t>(JsonConfig::get_instance().get_price(item->getRawNameId()) * count));
	}
}