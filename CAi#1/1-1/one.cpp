#include <iostream>
#include <vector>
#include <algorithm> // Added for std::remove_if

template<typename T>
class Song {
private:
    T title;
    T singer;

public:
    Song(const T& title, const T& singer) : title(title), singer(singer) {}

    void displayTitle() const {
        std::cout << "Title: " << title << std::endl;
    }

    void displaySinger() const {
        std::cout << "Singer: " << singer << std::endl;
    }

    const T& getTitle() const {
        return title;
    }
};

template<typename T>
class Playlist {
private:
    std::vector<Song<T>> songs;

public:
    void addSong(const T& title, const T& singer) {
        songs.emplace_back(title, singer);
    }

    void displaySongs() const {
        for (const auto& song : songs) {
            song.displayTitle();
            song.displaySinger();
            std::cout << std::endl;
        }
    }

    void updateSong(const T& oldTitle, const T& newTitle, const T& newSinger) {
        for (auto& song : songs) {
            if (song.getTitle() == oldTitle) {
                song = Song<T>(newTitle, newSinger);
                break;
            }
        }
    }

    void deleteSong(const T& title) {
        songs.erase(
            std::remove_if(
                songs.begin(),
                songs.end(),
                [title](const Song<T>& song) { return song.getTitle() == title; }
            ),
            songs.end()
        );
    }
};

int main() {
    system("cls");

    Playlist<std::string> myPlaylist;

    myPlaylist.addSong("Song 1", "Singer 1");
    myPlaylist.addSong("Song 2", "Singer 2");
    myPlaylist.addSong("Song 3", "Singer 3");

    myPlaylist.displaySongs();
    std::cout << std::endl;

    myPlaylist.updateSong("Song 2", "Updated Song", "Updated Singer");

    myPlaylist.displaySongs();
    std::cout << std::endl;

    myPlaylist.deleteSong("Song 1");

    myPlaylist.displaySongs();

    return 0;
}
