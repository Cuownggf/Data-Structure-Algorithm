#include <iostream>
#include <string>
using namespace std;

class SongNode {
public:
    string name;
    SongNode* prev;
    SongNode* next;

    SongNode(string song_name) {
        name = song_name;
        prev = NULL;
        next = NULL;
    }
};

class MusicPlayer {
private:
    SongNode* head;
    SongNode* tail;
    SongNode* current;

public:
    MusicPlayer() {
        head = NULL;
        tail = NULL;
        current = NULL;
    }

    void add_song(const string& song_name) {
        SongNode* new_song = new SongNode(song_name);

        if (!head) {
            // First song in the playlist
            head = tail = current = new_song;
            new_song->next = new_song->prev = new_song;
        } else {
            // Append to the end of the playlist
            new_song->prev = tail;
            new_song->next = head;
            tail->next = new_song;
            head->prev = new_song;
            tail = new_song;
        }
    }

    void play_next() {
        if (current) {
            current = current->next;
        }
    }

    void play_previous() {
        if (current) {
            current = current->prev;
        }
    }

    void remove_song(const string& song_name) {
        if (!head) {
            return;  // Playlist is empty
        }

        SongNode* temp = head;
        SongNode* song_to_remove = NULL;

        // Traverse the list to find the song
        do {
            if (temp->name == song_name) {
                song_to_remove = temp;
                break;
            }
            temp = temp->next;
        } while (temp != head);

        if (!song_to_remove) {
            return;  // Song not found
        }

        if (song_to_remove == head && song_to_remove == tail) {
            // Only one song in the playlist
            head = tail = current = NULL;
        } else {
            song_to_remove->prev->next = song_to_remove->next;
            song_to_remove->next->prev = song_to_remove->prev;
            if (song_to_remove == head) {
                head = song_to_remove->next;
            }
            if (song_to_remove == tail) {
                tail = song_to_remove->prev;
            }
            if (song_to_remove == current) {
                current = song_to_remove->next;
            }
        }

        delete song_to_remove;
    }

    void display_playlist() {
        if (!head) {
            cout << endl;
            return;
        }

        SongNode* temp = head;
        do {
            cout << temp->name << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    MusicPlayer player;

    for (int i = 0; i < n; ++i) {
        string operation;
        cin >> operation;

        if (operation == "ADD") {
            string song_name;
            cin >> song_name;
            player.add_song(song_name);
        } else if (operation == "NEXT") {
            player.play_next();
        } else if (operation == "PREV") {
            player.play_previous();
        } else if (operation == "REMOVE") {
            string song_name;
            cin >> song_name;
            player.remove_song(song_name);
        } else if (operation == "DISPLAY") {
            player.display_playlist();
        }
    }

    return 0;
}

