#include <tgbot/tgbot.h>
#pragma once

namespace user {
    TgBot::User::Ptr get(const TgBot::Message::Ptr& message) {
        if (message->replyToMessage) {
             return message->replyToMessage->from;
        } else {
            return message->from;
        }
    }
}