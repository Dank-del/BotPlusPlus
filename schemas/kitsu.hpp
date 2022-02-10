//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     KitsuAnime data = nlohmann::json::parse(jsonString);

#pragma once

#include <nlohmann/json.hpp>

#include <optional>
#include <stdexcept>
#include <regex>

#ifndef NLOHMANN_OPT_HELPER
#define NLOHMANN_OPT_HELPER
namespace nlohmann {
    template <typename T>
    struct adl_serializer<std::shared_ptr<T>> {
        static void to_json(json & j, const std::shared_ptr<T> & opt) {
            if (!opt) j = nullptr; else j = *opt;
        }

        static std::shared_ptr<T> from_json(const json & j) {
            if (j.is_null()) return std::unique_ptr<T>(); else return std::unique_ptr<T>(new T(j.get<T>()));
        }
    };
}
#endif

namespace quicktype {
    using nlohmann::json;

    inline json get_untyped(const json & j, const char * property) {
        if (j.find(property) != j.end()) {
            return j.at(property).get<json>();
        }
        return json();
    }

    inline json get_untyped(const json & j, std::string property) {
        return get_untyped(j, property.data());
    }

    template <typename T>
    inline std::shared_ptr<T> get_optional(const json & j, const char * property) {
        if (j.find(property) != j.end()) {
            return j.at(property).get<std::shared_ptr<T>>();
        }
        return std::shared_ptr<T>();
    }

    template <typename T>
    inline std::shared_ptr<T> get_optional(const json & j, std::string property) {
        return get_optional<T>(j, property.data());
    }

    enum class AgeRating : int { PG };

    enum class AgeRatingGuide : int { TEENS_13_OR_OLDER };

    class Large {
        public:
        Large() = default;
        virtual ~Large() = default;

        private:
        std::shared_ptr<int64_t> width;
        std::shared_ptr<int64_t> height;

        public:
        std::shared_ptr<int64_t> get_width() const { return width; }
        void set_width(std::shared_ptr<int64_t> value) { this->width = value; }

        std::shared_ptr<int64_t> get_height() const { return height; }
        void set_height(std::shared_ptr<int64_t> value) { this->height = value; }
    };

    class PurpleDimensions {
        public:
        PurpleDimensions() = default;
        virtual ~PurpleDimensions() = default;

        private:
        std::shared_ptr<Large> tiny;
        std::shared_ptr<Large> large;
        std::shared_ptr<Large> small;

        public:
        std::shared_ptr<Large> get_tiny() const { return tiny; }
        void set_tiny(std::shared_ptr<Large> value) { this->tiny = value; }

        std::shared_ptr<Large> get_large() const { return large; }
        void set_large(std::shared_ptr<Large> value) { this->large = value; }

        std::shared_ptr<Large> get_small() const { return small; }
        void set_small(std::shared_ptr<Large> value) { this->small = value; }
    };

    class CoverImageMeta {
        public:
        CoverImageMeta() = default;
        virtual ~CoverImageMeta() = default;

        private:
        std::shared_ptr<PurpleDimensions> dimensions;

        public:
        std::shared_ptr<PurpleDimensions> get_dimensions() const { return dimensions; }
        void set_dimensions(std::shared_ptr<PurpleDimensions> value) { this->dimensions = value; }
    };

    class CoverImage {
        public:
        CoverImage() = default;
        virtual ~CoverImage() = default;

        private:
        std::shared_ptr<std::string> tiny;
        std::shared_ptr<std::string> large;
        std::shared_ptr<std::string> small;
        std::shared_ptr<std::string> original;
        std::shared_ptr<CoverImageMeta> meta;

        public:
        std::shared_ptr<std::string> get_tiny() const { return tiny; }
        void set_tiny(std::shared_ptr<std::string> value) { this->tiny = value; }

        std::shared_ptr<std::string> get_large() const { return large; }
        void set_large(std::shared_ptr<std::string> value) { this->large = value; }

        std::shared_ptr<std::string> get_small() const { return small; }
        void set_small(std::shared_ptr<std::string> value) { this->small = value; }

        std::shared_ptr<std::string> get_original() const { return original; }
        void set_original(std::shared_ptr<std::string> value) { this->original = value; }

        std::shared_ptr<CoverImageMeta> get_meta() const { return meta; }
        void set_meta(std::shared_ptr<CoverImageMeta> value) { this->meta = value; }
    };

    class FluffyDimensions {
        public:
        FluffyDimensions() = default;
        virtual ~FluffyDimensions() = default;

        private:
        std::shared_ptr<Large> tiny;
        std::shared_ptr<Large> large;
        std::shared_ptr<Large> small;
        std::shared_ptr<Large> medium;

        public:
        std::shared_ptr<Large> get_tiny() const { return tiny; }
        void set_tiny(std::shared_ptr<Large> value) { this->tiny = value; }

        std::shared_ptr<Large> get_large() const { return large; }
        void set_large(std::shared_ptr<Large> value) { this->large = value; }

        std::shared_ptr<Large> get_small() const { return small; }
        void set_small(std::shared_ptr<Large> value) { this->small = value; }

        std::shared_ptr<Large> get_medium() const { return medium; }
        void set_medium(std::shared_ptr<Large> value) { this->medium = value; }
    };

    class PosterImageMeta {
        public:
        PosterImageMeta() = default;
        virtual ~PosterImageMeta() = default;

        private:
        std::shared_ptr<FluffyDimensions> dimensions;

        public:
        std::shared_ptr<FluffyDimensions> get_dimensions() const { return dimensions; }
        void set_dimensions(std::shared_ptr<FluffyDimensions> value) { this->dimensions = value; }
    };

    class PosterImage {
        public:
        PosterImage() = default;
        virtual ~PosterImage() = default;

        private:
        std::shared_ptr<std::string> tiny;
        std::shared_ptr<std::string> large;
        std::shared_ptr<std::string> small;
        std::shared_ptr<std::string> medium;
        std::shared_ptr<std::string> original;
        std::shared_ptr<PosterImageMeta> meta;

        public:
        std::shared_ptr<std::string> get_tiny() const { return tiny; }
        void set_tiny(std::shared_ptr<std::string> value) { this->tiny = value; }

        std::shared_ptr<std::string> get_large() const { return large; }
        void set_large(std::shared_ptr<std::string> value) { this->large = value; }

        std::shared_ptr<std::string> get_small() const { return small; }
        void set_small(std::shared_ptr<std::string> value) { this->small = value; }

        std::shared_ptr<std::string> get_medium() const { return medium; }
        void set_medium(std::shared_ptr<std::string> value) { this->medium = value; }

        std::shared_ptr<std::string> get_original() const { return original; }
        void set_original(std::shared_ptr<std::string> value) { this->original = value; }

        std::shared_ptr<PosterImageMeta> get_meta() const { return meta; }
        void set_meta(std::shared_ptr<PosterImageMeta> value) { this->meta = value; }
    };

    enum class Status : int { CURRENT, FINISHED };

    class Titles {
        public:
        Titles() = default;
        virtual ~Titles() = default;

        private:
        std::shared_ptr<std::string> en;
        std::shared_ptr<std::string> en_jp;
        std::shared_ptr<std::string> ja_jp;
        std::shared_ptr<std::string> en_us;

        public:
        std::shared_ptr<std::string> get_en() const { return en; }
        void set_en(std::shared_ptr<std::string> value) { this->en = value; }

        std::shared_ptr<std::string> get_en_jp() const { return en_jp; }
        void set_en_jp(std::shared_ptr<std::string> value) { this->en_jp = value; }

        std::shared_ptr<std::string> get_ja_jp() const { return ja_jp; }
        void set_ja_jp(std::shared_ptr<std::string> value) { this->ja_jp = value; }

        std::shared_ptr<std::string> get_en_us() const { return en_us; }
        void set_en_us(std::shared_ptr<std::string> value) { this->en_us = value; }
    };

    class Attributes {
        public:
        Attributes() = default;
        virtual ~Attributes() = default;

        private:
        std::shared_ptr<std::string> created_at;
        std::shared_ptr<std::string> updated_at;
        std::shared_ptr<std::string> slug;
        std::shared_ptr<std::string> synopsis;
        std::shared_ptr<std::string> description;
        std::shared_ptr<int64_t> cover_image_top_offset;
        std::shared_ptr<Titles> titles;
        std::shared_ptr<std::string> canonical_title;
        std::shared_ptr<std::vector<std::string>> abbreviated_titles;
        std::shared_ptr<std::string> average_rating;
        std::shared_ptr<std::map<std::string, std::string>> rating_frequencies;
        std::shared_ptr<int64_t> user_count;
        std::shared_ptr<int64_t> favorites_count;
        std::shared_ptr<std::string> start_date;
        std::shared_ptr<std::string> end_date;
        std::shared_ptr<std::string> next_release;
        std::shared_ptr<int64_t> popularity_rank;
        std::shared_ptr<int64_t> rating_rank;
        std::shared_ptr<AgeRating> age_rating;
        std::shared_ptr<AgeRatingGuide> age_rating_guide;
        std::shared_ptr<std::string> subtype;
        std::shared_ptr<Status> status;
        std::shared_ptr<std::string> tba;
        std::shared_ptr<PosterImage> poster_image;
        std::shared_ptr<CoverImage> cover_image;
        std::shared_ptr<int64_t> episode_count;
        std::shared_ptr<int64_t> episode_length;
        std::shared_ptr<int64_t> total_length;
        std::shared_ptr<std::string> youtube_video_id;
        std::shared_ptr<std::string> show_type;
        std::shared_ptr<bool> nsfw;

        public:
        std::shared_ptr<std::string> get_created_at() const { return created_at; }
        void set_created_at(std::shared_ptr<std::string> value) { this->created_at = value; }

        std::shared_ptr<std::string> get_updated_at() const { return updated_at; }
        void set_updated_at(std::shared_ptr<std::string> value) { this->updated_at = value; }

        std::shared_ptr<std::string> get_slug() const { return slug; }
        void set_slug(std::shared_ptr<std::string> value) { this->slug = value; }

        std::shared_ptr<std::string> get_synopsis() const { return synopsis; }
        void set_synopsis(std::shared_ptr<std::string> value) { this->synopsis = value; }

        std::shared_ptr<std::string> get_description() const { return description; }
        void set_description(std::shared_ptr<std::string> value) { this->description = value; }

        std::shared_ptr<int64_t> get_cover_image_top_offset() const { return cover_image_top_offset; }
        void set_cover_image_top_offset(std::shared_ptr<int64_t> value) { this->cover_image_top_offset = value; }

        std::shared_ptr<Titles> get_titles() const { return titles; }
        void set_titles(std::shared_ptr<Titles> value) { this->titles = value; }

        std::shared_ptr<std::string> get_canonical_title() const { return canonical_title; }
        void set_canonical_title(std::shared_ptr<std::string> value) { this->canonical_title = value; }

        std::shared_ptr<std::vector<std::string>> get_abbreviated_titles() const { return abbreviated_titles; }
        void set_abbreviated_titles(std::shared_ptr<std::vector<std::string>> value) { this->abbreviated_titles = value; }

        std::shared_ptr<std::string> get_average_rating() const { return average_rating; }
        void set_average_rating(std::shared_ptr<std::string> value) { this->average_rating = value; }

        std::shared_ptr<std::map<std::string, std::string>> get_rating_frequencies() const { return rating_frequencies; }
        void set_rating_frequencies(std::shared_ptr<std::map<std::string, std::string>> value) { this->rating_frequencies = value; }

        std::shared_ptr<int64_t> get_user_count() const { return user_count; }
        void set_user_count(std::shared_ptr<int64_t> value) { this->user_count = value; }

        std::shared_ptr<int64_t> get_favorites_count() const { return favorites_count; }
        void set_favorites_count(std::shared_ptr<int64_t> value) { this->favorites_count = value; }

        std::shared_ptr<std::string> get_start_date() const { return start_date; }
        void set_start_date(std::shared_ptr<std::string> value) { this->start_date = value; }

        std::shared_ptr<std::string> get_end_date() const { return end_date; }
        void set_end_date(std::shared_ptr<std::string> value) { this->end_date = value; }

        std::shared_ptr<std::string> get_next_release() const { return next_release; }
        void set_next_release(std::shared_ptr<std::string> value) { this->next_release = value; }

        std::shared_ptr<int64_t> get_popularity_rank() const { return popularity_rank; }
        void set_popularity_rank(std::shared_ptr<int64_t> value) { this->popularity_rank = value; }

        std::shared_ptr<int64_t> get_rating_rank() const { return rating_rank; }
        void set_rating_rank(std::shared_ptr<int64_t> value) { this->rating_rank = value; }

        std::shared_ptr<AgeRating> get_age_rating() const { return age_rating; }
        void set_age_rating(std::shared_ptr<AgeRating> value) { this->age_rating = value; }

        std::shared_ptr<AgeRatingGuide> get_age_rating_guide() const { return age_rating_guide; }
        void set_age_rating_guide(std::shared_ptr<AgeRatingGuide> value) { this->age_rating_guide = value; }

        std::shared_ptr<std::string> get_subtype() const { return subtype; }
        void set_subtype(std::shared_ptr<std::string> value) { this->subtype = value; }

        std::shared_ptr<Status> get_status() const { return status; }
        void set_status(std::shared_ptr<Status> value) { this->status = value; }

        std::shared_ptr<std::string> get_tba() const { return tba; }
        void set_tba(std::shared_ptr<std::string> value) { this->tba = value; }

        std::shared_ptr<PosterImage> get_poster_image() const { return poster_image; }
        void set_poster_image(std::shared_ptr<PosterImage> value) { this->poster_image = value; }

        std::shared_ptr<CoverImage> get_cover_image() const { return cover_image; }
        void set_cover_image(std::shared_ptr<CoverImage> value) { this->cover_image = value; }

        std::shared_ptr<int64_t> get_episode_count() const { return episode_count; }
        void set_episode_count(std::shared_ptr<int64_t> value) { this->episode_count = value; }

        std::shared_ptr<int64_t> get_episode_length() const { return episode_length; }
        void set_episode_length(std::shared_ptr<int64_t> value) { this->episode_length = value; }

        std::shared_ptr<int64_t> get_total_length() const { return total_length; }
        void set_total_length(std::shared_ptr<int64_t> value) { this->total_length = value; }

        std::shared_ptr<std::string> get_youtube_video_id() const { return youtube_video_id; }
        void set_youtube_video_id(std::shared_ptr<std::string> value) { this->youtube_video_id = value; }

        std::shared_ptr<std::string> get_show_type() const { return show_type; }
        void set_show_type(std::shared_ptr<std::string> value) { this->show_type = value; }

        std::shared_ptr<bool> get_nsfw() const { return nsfw; }
        void set_nsfw(std::shared_ptr<bool> value) { this->nsfw = value; }
    };

    class DatumLinks {
        public:
        DatumLinks() = default;
        virtual ~DatumLinks() = default;

        private:
        std::shared_ptr<std::string> self;

        public:
        std::shared_ptr<std::string> get_self() const { return self; }
        void set_self(std::shared_ptr<std::string> value) { this->self = value; }
    };

    class RelationshipLinks {
        public:
        RelationshipLinks() = default;
        virtual ~RelationshipLinks() = default;

        private:
        std::shared_ptr<std::string> self;
        std::shared_ptr<std::string> related;

        public:
        std::shared_ptr<std::string> get_self() const { return self; }
        void set_self(std::shared_ptr<std::string> value) { this->self = value; }

        std::shared_ptr<std::string> get_related() const { return related; }
        void set_related(std::shared_ptr<std::string> value) { this->related = value; }
    };

    class Relationship {
        public:
        Relationship() = default;
        virtual ~Relationship() = default;

        private:
        std::shared_ptr<RelationshipLinks> links;

        public:
        std::shared_ptr<RelationshipLinks> get_links() const { return links; }
        void set_links(std::shared_ptr<RelationshipLinks> value) { this->links = value; }
    };

    enum class Type : int { ANIME };

    class Datum {
        public:
        Datum() = default;
        virtual ~Datum() = default;

        private:
        std::shared_ptr<std::string> id;
        std::shared_ptr<Type> type;
        std::shared_ptr<DatumLinks> links;
        std::shared_ptr<Attributes> attributes;
        std::shared_ptr<std::map<std::string, Relationship>> relationships;

        public:
        std::shared_ptr<std::string> get_id() const { return id; }
        void set_id(std::shared_ptr<std::string> value) { this->id = value; }

        std::shared_ptr<Type> get_type() const { return type; }
        void set_type(std::shared_ptr<Type> value) { this->type = value; }

        std::shared_ptr<DatumLinks> get_links() const { return links; }
        void set_links(std::shared_ptr<DatumLinks> value) { this->links = value; }

        std::shared_ptr<Attributes> get_attributes() const { return attributes; }
        void set_attributes(std::shared_ptr<Attributes> value) { this->attributes = value; }

        std::shared_ptr<std::map<std::string, Relationship>> get_relationships() const { return relationships; }
        void set_relationships(std::shared_ptr<std::map<std::string, Relationship>> value) { this->relationships = value; }
    };

    class KitsuAnimeLinks {
        public:
        KitsuAnimeLinks() = default;
        virtual ~KitsuAnimeLinks() = default;

        private:
        std::shared_ptr<std::string> first;
        std::shared_ptr<std::string> next;
        std::shared_ptr<std::string> last;

        public:
        std::shared_ptr<std::string> get_first() const { return first; }
        void set_first(std::shared_ptr<std::string> value) { this->first = value; }

        std::shared_ptr<std::string> get_next() const { return next; }
        void set_next(std::shared_ptr<std::string> value) { this->next = value; }

        std::shared_ptr<std::string> get_last() const { return last; }
        void set_last(std::shared_ptr<std::string> value) { this->last = value; }
    };

    class KitsuAnimeMeta {
        public:
        KitsuAnimeMeta() = default;
        virtual ~KitsuAnimeMeta() = default;

        private:
        std::shared_ptr<int64_t> count;

        public:
        std::shared_ptr<int64_t> get_count() const { return count; }
        void set_count(std::shared_ptr<int64_t> value) { this->count = value; }
    };

    class KitsuAnime {
        public:
        KitsuAnime() = default;
        virtual ~KitsuAnime() = default;

        private:
        std::shared_ptr<std::vector<Datum>> data;
        std::shared_ptr<KitsuAnimeMeta> meta;
        std::shared_ptr<KitsuAnimeLinks> links;

        public:
        std::shared_ptr<std::vector<Datum>> get_data() const { return data; }
        void set_data(std::shared_ptr<std::vector<Datum>> value) { this->data = value; }

        std::shared_ptr<KitsuAnimeMeta> get_meta() const { return meta; }
        void set_meta(std::shared_ptr<KitsuAnimeMeta> value) { this->meta = value; }

        std::shared_ptr<KitsuAnimeLinks> get_links() const { return links; }
        void set_links(std::shared_ptr<KitsuAnimeLinks> value) { this->links = value; }
    };
}

namespace nlohmann {
    void from_json(const json & j, quicktype::Large & x);
    void to_json(json & j, const quicktype::Large & x);

    void from_json(const json & j, quicktype::PurpleDimensions & x);
    void to_json(json & j, const quicktype::PurpleDimensions & x);

    void from_json(const json & j, quicktype::CoverImageMeta & x);
    void to_json(json & j, const quicktype::CoverImageMeta & x);

    void from_json(const json & j, quicktype::CoverImage & x);
    void to_json(json & j, const quicktype::CoverImage & x);

    void from_json(const json & j, quicktype::FluffyDimensions & x);
    void to_json(json & j, const quicktype::FluffyDimensions & x);

    void from_json(const json & j, quicktype::PosterImageMeta & x);
    void to_json(json & j, const quicktype::PosterImageMeta & x);

    void from_json(const json & j, quicktype::PosterImage & x);
    void to_json(json & j, const quicktype::PosterImage & x);

    void from_json(const json & j, quicktype::Titles & x);
    void to_json(json & j, const quicktype::Titles & x);

    void from_json(const json & j, quicktype::Attributes & x);
    void to_json(json & j, const quicktype::Attributes & x);

    void from_json(const json & j, quicktype::DatumLinks & x);
    void to_json(json & j, const quicktype::DatumLinks & x);

    void from_json(const json & j, quicktype::RelationshipLinks & x);
    void to_json(json & j, const quicktype::RelationshipLinks & x);

    void from_json(const json & j, quicktype::Relationship & x);
    void to_json(json & j, const quicktype::Relationship & x);

    void from_json(const json & j, quicktype::Datum & x);
    void to_json(json & j, const quicktype::Datum & x);

    void from_json(const json & j, quicktype::KitsuAnimeLinks & x);
    void to_json(json & j, const quicktype::KitsuAnimeLinks & x);

    void from_json(const json & j, quicktype::KitsuAnimeMeta & x);
    void to_json(json & j, const quicktype::KitsuAnimeMeta & x);

    void from_json(const json & j, quicktype::KitsuAnime & x);
    void to_json(json & j, const quicktype::KitsuAnime & x);

    void from_json(const json & j, quicktype::AgeRating & x);
    void to_json(json & j, const quicktype::AgeRating & x);

    void from_json(const json & j, quicktype::AgeRatingGuide & x);
    void to_json(json & j, const quicktype::AgeRatingGuide & x);

    void from_json(const json & j, quicktype::Status & x);
    void to_json(json & j, const quicktype::Status & x);

    void from_json(const json & j, quicktype::Type & x);
    void to_json(json & j, const quicktype::Type & x);

    inline void from_json(const json & j, quicktype::Large& x) {
        x.set_width(quicktype::get_optional<int64_t>(j, "width"));
        x.set_height(quicktype::get_optional<int64_t>(j, "height"));
    }

    inline void to_json(json & j, const quicktype::Large & x) {
        j = json::object();
        if (x.get_width()) {
            j["width"] = x.get_width();
        }
        if (x.get_height()) {
            j["height"] = x.get_height();
        }
    }

    inline void from_json(const json & j, quicktype::PurpleDimensions& x) {
        x.set_tiny(quicktype::get_optional<quicktype::Large>(j, "tiny"));
        x.set_large(quicktype::get_optional<quicktype::Large>(j, "large"));
        x.set_small(quicktype::get_optional<quicktype::Large>(j, "small"));
    }

    inline void to_json(json & j, const quicktype::PurpleDimensions & x) {
        j = json::object();
        if (x.get_tiny()) {
            j["tiny"] = x.get_tiny();
        }
        if (x.get_large()) {
            j["large"] = x.get_large();
        }
        if (x.get_small()) {
            j["small"] = x.get_small();
        }
    }

    inline void from_json(const json & j, quicktype::CoverImageMeta& x) {
        x.set_dimensions(quicktype::get_optional<quicktype::PurpleDimensions>(j, "dimensions"));
    }

    inline void to_json(json & j, const quicktype::CoverImageMeta & x) {
        j = json::object();
        if (x.get_dimensions()) {
            j["dimensions"] = x.get_dimensions();
        }
    }

    inline void from_json(const json & j, quicktype::CoverImage& x) {
        x.set_tiny(quicktype::get_optional<std::string>(j, "tiny"));
        x.set_large(quicktype::get_optional<std::string>(j, "large"));
        x.set_small(quicktype::get_optional<std::string>(j, "small"));
        x.set_original(quicktype::get_optional<std::string>(j, "original"));
        x.set_meta(quicktype::get_optional<quicktype::CoverImageMeta>(j, "meta"));
    }

    inline void to_json(json & j, const quicktype::CoverImage & x) {
        j = json::object();
        if (x.get_tiny()) {
            j["tiny"] = x.get_tiny();
        }
        if (x.get_large()) {
            j["large"] = x.get_large();
        }
        if (x.get_small()) {
            j["small"] = x.get_small();
        }
        if (x.get_original()) {
            j["original"] = x.get_original();
        }
        if (x.get_meta()) {
            j["meta"] = x.get_meta();
        }
    }

    inline void from_json(const json & j, quicktype::FluffyDimensions& x) {
        x.set_tiny(quicktype::get_optional<quicktype::Large>(j, "tiny"));
        x.set_large(quicktype::get_optional<quicktype::Large>(j, "large"));
        x.set_small(quicktype::get_optional<quicktype::Large>(j, "small"));
        x.set_medium(quicktype::get_optional<quicktype::Large>(j, "medium"));
    }

    inline void to_json(json & j, const quicktype::FluffyDimensions & x) {
        j = json::object();
        if (x.get_tiny()) {
            j["tiny"] = x.get_tiny();
        }
        if (x.get_large()) {
            j["large"] = x.get_large();
        }
        if (x.get_small()) {
            j["small"] = x.get_small();
        }
        if (x.get_medium()) {
            j["medium"] = x.get_medium();
        }
    }

    inline void from_json(const json & j, quicktype::PosterImageMeta& x) {
        x.set_dimensions(quicktype::get_optional<quicktype::FluffyDimensions>(j, "dimensions"));
    }

    inline void to_json(json & j, const quicktype::PosterImageMeta & x) {
        j = json::object();
        if (x.get_dimensions()) {
            j["dimensions"] = x.get_dimensions();
        }
    }

    inline void from_json(const json & j, quicktype::PosterImage& x) {
        x.set_tiny(quicktype::get_optional<std::string>(j, "tiny"));
        x.set_large(quicktype::get_optional<std::string>(j, "large"));
        x.set_small(quicktype::get_optional<std::string>(j, "small"));
        x.set_medium(quicktype::get_optional<std::string>(j, "medium"));
        x.set_original(quicktype::get_optional<std::string>(j, "original"));
        x.set_meta(quicktype::get_optional<quicktype::PosterImageMeta>(j, "meta"));
    }

    inline void to_json(json & j, const quicktype::PosterImage & x) {
        j = json::object();
        if (x.get_tiny()) {
            j["tiny"] = x.get_tiny();
        }
        if (x.get_large()) {
            j["large"] = x.get_large();
        }
        if (x.get_small()) {
            j["small"] = x.get_small();
        }
        if (x.get_medium()) {
            j["medium"] = x.get_medium();
        }
        if (x.get_original()) {
            j["original"] = x.get_original();
        }
        if (x.get_meta()) {
            j["meta"] = x.get_meta();
        }
    }

    inline void from_json(const json & j, quicktype::Titles& x) {
        x.set_en(quicktype::get_optional<std::string>(j, "en"));
        x.set_en_jp(quicktype::get_optional<std::string>(j, "en_jp"));
        x.set_ja_jp(quicktype::get_optional<std::string>(j, "ja_jp"));
        x.set_en_us(quicktype::get_optional<std::string>(j, "en_us"));
    }

    inline void to_json(json & j, const quicktype::Titles & x) {
        j = json::object();
        if (x.get_en()) {
            j["en"] = x.get_en();
        }
        if (x.get_en_jp()) {
            j["en_jp"] = x.get_en_jp();
        }
        if (x.get_ja_jp()) {
            j["ja_jp"] = x.get_ja_jp();
        }
        if (x.get_en_us()) {
            j["en_us"] = x.get_en_us();
        }
    }

    inline void from_json(const json & j, quicktype::Attributes& x) {
        x.set_created_at(quicktype::get_optional<std::string>(j, "createdAt"));
        x.set_updated_at(quicktype::get_optional<std::string>(j, "updatedAt"));
        x.set_slug(quicktype::get_optional<std::string>(j, "slug"));
        x.set_synopsis(quicktype::get_optional<std::string>(j, "synopsis"));
        x.set_description(quicktype::get_optional<std::string>(j, "description"));
        x.set_cover_image_top_offset(quicktype::get_optional<int64_t>(j, "coverImageTopOffset"));
        x.set_titles(quicktype::get_optional<quicktype::Titles>(j, "titles"));
        x.set_canonical_title(quicktype::get_optional<std::string>(j, "canonicalTitle"));
        x.set_abbreviated_titles(quicktype::get_optional<std::vector<std::string>>(j, "abbreviatedTitles"));
        x.set_average_rating(quicktype::get_optional<std::string>(j, "averageRating"));
        x.set_rating_frequencies(quicktype::get_optional<std::map<std::string, std::string>>(j, "ratingFrequencies"));
        x.set_user_count(quicktype::get_optional<int64_t>(j, "userCount"));
        x.set_favorites_count(quicktype::get_optional<int64_t>(j, "favoritesCount"));
        x.set_start_date(quicktype::get_optional<std::string>(j, "startDate"));
        x.set_end_date(quicktype::get_optional<std::string>(j, "endDate"));
        x.set_next_release(quicktype::get_optional<std::string>(j, "nextRelease"));
        x.set_popularity_rank(quicktype::get_optional<int64_t>(j, "popularityRank"));
        x.set_rating_rank(quicktype::get_optional<int64_t>(j, "ratingRank"));
        x.set_age_rating(quicktype::get_optional<quicktype::AgeRating>(j, "ageRating"));
        x.set_age_rating_guide(quicktype::get_optional<quicktype::AgeRatingGuide>(j, "ageRatingGuide"));
        x.set_subtype(quicktype::get_optional<std::string>(j, "subtype"));
        x.set_status(quicktype::get_optional<quicktype::Status>(j, "status"));
        x.set_tba(quicktype::get_optional<std::string>(j, "tba"));
        x.set_poster_image(quicktype::get_optional<quicktype::PosterImage>(j, "posterImage"));
        x.set_cover_image(quicktype::get_optional<quicktype::CoverImage>(j, "coverImage"));
        x.set_episode_count(quicktype::get_optional<int64_t>(j, "episodeCount"));
        x.set_episode_length(quicktype::get_optional<int64_t>(j, "episodeLength"));
        x.set_total_length(quicktype::get_optional<int64_t>(j, "totalLength"));
        x.set_youtube_video_id(quicktype::get_optional<std::string>(j, "youtubeVideoId"));
        x.set_show_type(quicktype::get_optional<std::string>(j, "showType"));
        x.set_nsfw(quicktype::get_optional<bool>(j, "nsfw"));
    }

    inline void to_json(json & j, const quicktype::Attributes & x) {
        j = json::object();
        if (x.get_created_at()) {
            j["createdAt"] = x.get_created_at();
        }
        if (x.get_updated_at()) {
            j["updatedAt"] = x.get_updated_at();
        }
        if (x.get_slug()) {
            j["slug"] = x.get_slug();
        }
        if (x.get_synopsis()) {
            j["synopsis"] = x.get_synopsis();
        }
        if (x.get_description()) {
            j["description"] = x.get_description();
        }
        if (x.get_cover_image_top_offset()) {
            j["coverImageTopOffset"] = x.get_cover_image_top_offset();
        }
        if (x.get_titles()) {
            j["titles"] = x.get_titles();
        }
        if (x.get_canonical_title()) {
            j["canonicalTitle"] = x.get_canonical_title();
        }
        if (x.get_abbreviated_titles()) {
            j["abbreviatedTitles"] = x.get_abbreviated_titles();
        }
        if (x.get_average_rating()) {
            j["averageRating"] = x.get_average_rating();
        }
        if (x.get_rating_frequencies()) {
            j["ratingFrequencies"] = x.get_rating_frequencies();
        }
        if (x.get_user_count()) {
            j["userCount"] = x.get_user_count();
        }
        if (x.get_favorites_count()) {
            j["favoritesCount"] = x.get_favorites_count();
        }
        if (x.get_start_date()) {
            j["startDate"] = x.get_start_date();
        }
        if (x.get_end_date()) {
            j["endDate"] = x.get_end_date();
        }
        if (x.get_next_release()) {
            j["nextRelease"] = x.get_next_release();
        }
        if (x.get_popularity_rank()) {
            j["popularityRank"] = x.get_popularity_rank();
        }
        if (x.get_rating_rank()) {
            j["ratingRank"] = x.get_rating_rank();
        }
        if (x.get_age_rating()) {
            j["ageRating"] = x.get_age_rating();
        }
        if (x.get_age_rating_guide()) {
            j["ageRatingGuide"] = x.get_age_rating_guide();
        }
        if (x.get_subtype()) {
            j["subtype"] = x.get_subtype();
        }
        if (x.get_status()) {
            j["status"] = x.get_status();
        }
        if (x.get_tba()) {
            j["tba"] = x.get_tba();
        }
        if (x.get_poster_image()) {
            j["posterImage"] = x.get_poster_image();
        }
        if (x.get_cover_image()) {
            j["coverImage"] = x.get_cover_image();
        }
        if (x.get_episode_count()) {
            j["episodeCount"] = x.get_episode_count();
        }
        if (x.get_episode_length()) {
            j["episodeLength"] = x.get_episode_length();
        }
        if (x.get_total_length()) {
            j["totalLength"] = x.get_total_length();
        }
        if (x.get_youtube_video_id()) {
            j["youtubeVideoId"] = x.get_youtube_video_id();
        }
        if (x.get_show_type()) {
            j["showType"] = x.get_show_type();
        }
        if (x.get_nsfw()) {
            j["nsfw"] = x.get_nsfw();
        }
    }

    inline void from_json(const json & j, quicktype::DatumLinks& x) {
        x.set_self(quicktype::get_optional<std::string>(j, "self"));
    }

    inline void to_json(json & j, const quicktype::DatumLinks & x) {
        j = json::object();
        if (x.get_self()) {
            j["self"] = x.get_self();
        }
    }

    inline void from_json(const json & j, quicktype::RelationshipLinks& x) {
        x.set_self(quicktype::get_optional<std::string>(j, "self"));
        x.set_related(quicktype::get_optional<std::string>(j, "related"));
    }

    inline void to_json(json & j, const quicktype::RelationshipLinks & x) {
        j = json::object();
        if (x.get_self()) {
            j["self"] = x.get_self();
        }
        if (x.get_related()) {
            j["related"] = x.get_related();
        }
    }

    inline void from_json(const json & j, quicktype::Relationship& x) {
        x.set_links(quicktype::get_optional<quicktype::RelationshipLinks>(j, "links"));
    }

    inline void to_json(json & j, const quicktype::Relationship & x) {
        j = json::object();
        if (x.get_links()) {
            j["links"] = x.get_links();
        }
    }

    inline void from_json(const json & j, quicktype::Datum& x) {
        x.set_id(quicktype::get_optional<std::string>(j, "id"));
        x.set_type(quicktype::get_optional<quicktype::Type>(j, "type"));
        x.set_links(quicktype::get_optional<quicktype::DatumLinks>(j, "links"));
        x.set_attributes(quicktype::get_optional<quicktype::Attributes>(j, "attributes"));
        x.set_relationships(quicktype::get_optional<std::map<std::string, quicktype::Relationship>>(j, "relationships"));
    }

    inline void to_json(json & j, const quicktype::Datum & x) {
        j = json::object();
        if (x.get_id()) {
            j["id"] = x.get_id();
        }
        if (x.get_type()) {
            j["type"] = x.get_type();
        }
        if (x.get_links()) {
            j["links"] = x.get_links();
        }
        if (x.get_attributes()) {
            j["attributes"] = x.get_attributes();
        }
        if (x.get_relationships()) {
            j["relationships"] = x.get_relationships();
        }
    }

    inline void from_json(const json & j, quicktype::KitsuAnimeLinks& x) {
        x.set_first(quicktype::get_optional<std::string>(j, "first"));
        x.set_next(quicktype::get_optional<std::string>(j, "next"));
        x.set_last(quicktype::get_optional<std::string>(j, "last"));
    }

    inline void to_json(json & j, const quicktype::KitsuAnimeLinks & x) {
        j = json::object();
        if (x.get_first()) {
            j["first"] = x.get_first();
        }
        if (x.get_next()) {
            j["next"] = x.get_next();
        }
        if (x.get_last()) {
            j["last"] = x.get_last();
        }
    }

    inline void from_json(const json & j, quicktype::KitsuAnimeMeta& x) {
        x.set_count(quicktype::get_optional<int64_t>(j, "count"));
    }

    inline void to_json(json & j, const quicktype::KitsuAnimeMeta & x) {
        j = json::object();
        if (x.get_count()) {
            j["count"] = x.get_count();
        }
    }

    inline void from_json(const json & j, quicktype::KitsuAnime& x) {
        x.set_data(quicktype::get_optional<std::vector<quicktype::Datum>>(j, "data"));
        x.set_meta(quicktype::get_optional<quicktype::KitsuAnimeMeta>(j, "meta"));
        x.set_links(quicktype::get_optional<quicktype::KitsuAnimeLinks>(j, "links"));
    }

    inline void to_json(json & j, const quicktype::KitsuAnime & x) {
        j = json::object();
        if (x.get_data()) {
            j["data"] = x.get_data();
        }
        if (x.get_meta()) {
            j["meta"] = x.get_meta();
        }
        if (x.get_links()) {
            j["links"] = x.get_links();
        }
    }

    inline void from_json(const json & j, quicktype::AgeRating & x) {
        if (j == "PG") x = quicktype::AgeRating::PG;
        else throw "Input JSON does not conform to schema";
    }

    inline void to_json(json & j, const quicktype::AgeRating & x) {
        switch (x) {
            case quicktype::AgeRating::PG: j = "PG"; break;
            default: throw "This should not happen";
        }
    }

    inline void from_json(const json & j, quicktype::AgeRatingGuide & x) {
        if (j == "Teens 13 or older") x = quicktype::AgeRatingGuide::TEENS_13_OR_OLDER;
        else throw "Input JSON does not conform to schema";
    }

    inline void to_json(json & j, const quicktype::AgeRatingGuide & x) {
        switch (x) {
            case quicktype::AgeRatingGuide::TEENS_13_OR_OLDER: j = "Teens 13 or older"; break;
            default: throw "This should not happen";
        }
    }

    inline void from_json(const json & j, quicktype::Status & x) {
        if (j == "current") x = quicktype::Status::CURRENT;
        else if (j == "finished") x = quicktype::Status::FINISHED;
        else throw "Input JSON does not conform to schema";
    }

    inline void to_json(json & j, const quicktype::Status & x) {
        switch (x) {
            case quicktype::Status::CURRENT: j = "current"; break;
            case quicktype::Status::FINISHED: j = "finished"; break;
            default: throw "This should not happen";
        }
    }

    inline void from_json(const json & j, quicktype::Type & x) {
        if (j == "anime") x = quicktype::Type::ANIME;
        else throw "Input JSON does not conform to schema";
    }

    inline void to_json(json & j, const quicktype::Type & x) {
        switch (x) {
            case quicktype::Type::ANIME: j = "anime"; break;
            default: throw "This should not happen";
        }
    }
}
