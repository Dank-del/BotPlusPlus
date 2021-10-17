#include <tgbot/tgbot.h>
#include <spdlog/spdlog.h>
#include <mdparser-cpp/WotoMd.h>
#include <mdparser-cpp/WotoMd.cpp>
#include "cmds/info.cpp"
#include <toml.hpp>

int main(int argc, char *argv[]) {
    spdlog::set_level(spdlog::level::debug); // Set global log level to debug
    spdlog::set_pattern("[%H:%M:%S %z] [Bot++] [%^---%L---%$] [thread %t] %v");
    if (argc == 1) {
        spdlog::error(".toml configuration file wasn't provided, quitting....");
        exit(1);
    }
    std::string config_file = std::string(argv[1]);
    spdlog::info("Using config file {}", config_file);
    auto data = toml::parse(config_file);
    std::string bot_token = toml::find<std::string>(data, "bot_token");
    TgBot::Bot bot(bot_token);
    auto self = bot.getApi().getMe();
    bot.getEvents().onCommand("start", [&bot](const TgBot::Message::Ptr& message) {
        auto msg = get_bold("Hi ")->AppendUserMention(message->from->firstName, message->from->id)->AppendBold(", I'm a bot.");
        bot.getApi().sendMessage(message->chat->id, msg->ToString(), false, 0, nullptr, "markdownv2");
    });
    bot.getEvents().onCommand("info", [&bot](const TgBot::Message::Ptr& message) {
        bot.getApi().sendMessage(message->chat->id, msg::infohandler(message), false, 0, nullptr, "markdownv2");
    });
    /* bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
        printf("User wrote %s\n", message->text.c_str());
        if (StringTools::startsWith(message->text, "/start")) {
            return;
        }
        bot.getApi().sendMessage(message->chat->id, "Your message is: `" + message->text + "`", false, 0, nullptr, "markdownv2");
    }); */
    try {
        spdlog::info("Bot username: {}\n", bot.getApi().getMe()->username.c_str());
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            spdlog::debug("Long poll started\n");
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        spdlog::error("error: {}\n", e.what());
    }
    return 0;
}
