#pragma once

#include <cpr/cpr.h>
#include <boost/format.hpp>
#include "url.hpp"
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include "../schemas/kitsu.hpp"

using json = nlohmann::json;

namespace anime {
    quicktype::KitsuAnime get(const std::string &query) {
        auto url = boost::format("https://kitsu.io/api/edge/anime?filter[text]=%1%") % url::encode(query);
        cpr::Response r = cpr::Get(cpr::Url{url.str()}, cpr::Parameters{{"Accept",       "application/vnd.api+json"},
                                                                        {"Content-Type", "application/vnd.api+json"}});
        try {
            json root = nlohmann::json::parse(r.text);
            return root;
        } catch (const std::exception &e) {
            spdlog::error(e.what());
            return {};
        } catch (const std::runtime_error &e) {
            spdlog::error(e.what());
            return {};
        }
    }
}