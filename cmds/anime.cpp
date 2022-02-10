#include "../utils/anime.hpp"
#include <nlohmann/json.hpp>
#include <tgbot/tgbot.h>
#include <mdparser-cpp/WotoMd.h>


using json = nlohmann::json;

std::string animehandler(const TgBot::Message::Ptr& message) {
    std::string txt = message->text;
    try {
        std::string q = txt.substr(txt.find_first_not_of(" \t\r\n", txt.find_first_of(" \t\r\n", txt.find_first_not_of(" \t\r\n"))));
        auto ok = anime::get(q);
        // std::cout << (boost::format("%1%") % ok).str() << std::endl;
        // return md->ToString();
        ok.get_data();
    } catch (std::exception &e) {
        return e.what();
    } catch (std::runtime_error &e){
        return e.what();
    } catch (...) {
        return "An unknown error occurred.";
    }
    return {};
}