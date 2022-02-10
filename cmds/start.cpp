#include <mdparser-cpp/WotoMd.h>
#include <tgbot/tgbot.h>

std::string startHandler(const TgBot::Message::Ptr& message) {
    auto md = mdparser::get_bold("Hai ")->AppendUserMention(message->from->firstName, message->from->id)->AppendNormal("!\n\n");
    md = md->AppendNormal("I'm a bot, and I am made solely for testing purposes and fun.")->AppendNormal("\n\n");
    md = md->AppendBold("What's special about me?")->AppendNormal("\n")->AppendItalic("Well nothing much, do note, I'm written pure C++");
    md = md->AppendNormal("\n\n")->AppendBold("This is where my purpose comes in, I exist as Sayan wanted to learn C++")->AppendNormal("\n");
    return md->ToString();
}