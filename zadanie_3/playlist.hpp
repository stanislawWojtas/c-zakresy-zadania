#pragma once

#include <array>
#include <cstddef>
#include <string>

struct Song {
    std::string title;
    std::string artist;
    int seconds;
};

// Playlista o stałej pojemności. Ważne są tylko pierwsze count_ utwory.
class Playlist {
public:
    static constexpr std::size_t capacity = 16;

    bool add(const Song& song) {
        if (count_ == capacity) {
            return false;
        }
        songs_[count_++] = song;
        return true;
    }

    std::size_t size() const {
        return count_;
    }

    // TODO: begin() i end() (zwykłe i const), obejmujące tylko dodane utwory.

private:
    std::array<Song, capacity> songs_ {};
    std::size_t count_ = 0;
};
