#include "../utils/getuser.hpp"
#include <mdparser-cpp/WotoMd.h>

namespace msg {
    std::string infohandler(const TgBot::Message::Ptr& message){
    auto msg = mdparser::get_bold("User info:")->AppendNormal("\n");
    auto user = user::get(message);
    auto id = boost::format("%1%") % user->id;
    msg = msg->AppendNormal("First Name")->AppendNormal(": ")->AppendNormal(user->firstName)->AppendNormal("\n");
    msg = msg->AppendNormal("Last Name")->AppendNormal(": ")->AppendNormal(user->lastName)->AppendNormal("\n");
    msg = msg->AppendNormal("ID")->AppendNormal(": ")->AppendMono(id.str())->AppendNormal("\n");
    msg = msg->AppendNormal("Link")->AppendNormal(": ")->AppendUserMention("here", user->id);
    return msg->ToString();
}
}