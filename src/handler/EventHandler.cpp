#include "headers/EventHandler.hpp"

inline void EventHandler::on_player_attack() {
    Event::PlayerAttackEvent::subscribe([](const Event::PlayerAttackEvent& event) {
        if (event.mTarget->getTypeName() == "byr:byr_person") {
            Player* player = event.mPlayer;
            const ItemStack* item_stack = player->getHandSlot();
            if (item_stack->getId() != 0) {
                if (player->isCreative() && player->getPlayerPermissionLevel() != PlayerPermissionLevel::Operator) {
                    player->sendText(ColorFormat::RED + "Невозможно торговаться со скупщиком в режиме Креатив.");
                    return true;
                }
                if (player->getPlayerPermissionLevel() == PlayerPermissionLevel::Operator && item_stack->getId() == 389)
                    event.mTarget->kill();
                else if ((player->getPlayerPermissionLevel() == PlayerPermissionLevel::Operator && item_stack->getId() != 389) || (player->getPlayerPermissionLevel() != PlayerPermissionLevel::Operator)) {
                    if (!JsonConfig::get_instance().isset_value(std::to_string(item_stack->getId()))) {
                        player->sendText(ColorFormat::RED + "Предмет, что вы пытаетесь продать - не покупается скупщиком!");
                        return true;
                    }
                    if (Buyer::buy_item(player, item_stack->getItem(), item_stack->getCount())) {
                        player->sendTitlePacket("Продано!", TitleType::SetTitle, 20, 20, 20);
                        player->sendTitlePacket(ColorFormat::YELLOW + "+ " + ColorFormat::GREEN + std::to_string(JsonConfig::get_instance().get_price(std::to_string(item_stack->getId())) * item_stack->getCount()) + '$', TitleType::SetSubtitle, 20, 20, 20);
                        player->sendText(ColorFormat::GREEN + "Вы успешно продали предмет " + item_stack->getName() + " в количестве: " + ColorFormat::GRAY + std::to_string(item_stack->getCount()) + " шт.!\n" + ColorFormat::RESET + "Вы получили за продажу : " + ColorFormat::GREEN + std::to_string(JsonConfig::get_instance().get_price(std::to_string(item_stack->getId())) * item_stack->getCount()) + '$');
                        player->clearItem(item_stack->getItem()->getFullItemName(), item_stack->getCount());
                    }
                    else
                        player->sendText(ColorFormat::RED + "Произошла ошибка при продаже предмета! Обратитесь к администратору!\n");
                }
            }
            else
                player->sendText(ColorFormat::RED + "Чтобы что-то продать, необходимо держать это в руках!\n");
        }
        return true;
    });
}

inline void EventHandler::init() {
    on_player_attack();
 }