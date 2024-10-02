Bài tập code môn Cấu trúc dữ liệu và giải thuật
Homework Exercise 1
------6.1 Question 1: Music player------
You are tasked with designing a simple music player using a linked list. The player should be able
to perform the following operations:
1. Add a Song: Add a song to the end of the playlist.
2. Play Next: Move to the next song in the playlist. If at the end, loop back to the first song.
3. Play Previous: Move to the previous song in the playlist. If at the beginning, loop to the
last song.
4. Remove a Song: Remove a song by its name from the playlist.
5. Display Playlist: Output the current playlist in order.

------6.2 Question 2: Web Browser back and next------
In a web browser that operates with a single tab, the user starts on the homepage and can navigate
to various URLs, retrace their steps in the browsing history, or advance through it.
To implement this functionality, the ‘BrowserHistory‘ class will be designed with the following
specifications:
• Initialization: The constructor ‘BrowserHistory(string homepage)‘ initializes the instance
with the designated homepage URL.
• Visiting URLs: The method ‘void visit(string url)‘ allows the user to navigate to a new URL
from the current page, while simultaneously clearing any forward history.
• Navigating Back: The method ‘string back(int steps)‘ enables the user to move backward
through the history by a specified number of steps. If the number of steps exceeds the available
history, the user will return only as far back as possible. This method returns the current URL
after the backward movement.
• Navigating Forward: The method ‘string forward(int steps)‘ allows the user to advance
through the history by a specified number of steps. Similar to the back method, if the number
of steps exceeds the available forward history, the user will only move forward as far as possible.
The current URL is returned after this operation.

------6.3 Question 3: AuthenticationManager Class------
The AuthenticationManager class should be implemented with the following functionalities:
• Constructor: The constructor AuthenticationManager(int timeToLive) initializes the authentication manager with the defined timeToLive duration.
• Token Generation: The method generate(string tokenId, int currentTime) creates a
new token associated with the specified tokenId at the given currentTime in seconds.
• Token Renewal: The method renew(string tokenId, int currentTime) allows for the
renewal of an unexpired token identified by tokenId at the specified currentTime. If no
unexpired token exists for the provided tokenId, the request is disregarded, resulting in no
action taken.
• Counting Unexpired Tokens: The method countUnexpiredTokens(int currentTime)
returns the total number of tokens that remain unexpired at the specified currentTime. It is
crucial to note that if a token’s expiration occurs at time t, any subsequent actions, such as
renewal or counting unexpired tokens, will consider the expiration to have taken place prior
to those actions
