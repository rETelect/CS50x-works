Speller
Here’s my take on building a spell checker that reads in a dictionary file and looks for spelling mistakes within a set of text. This assignment was for Week 5 of Harvard’s CS50x.

How I built it

The purpose of this program is to make it as fast as possible. In order to achieve this, I used a Hash Table. What this means is instead of searching a list from beginning to end, my program 'hashes' a word to a location, making lookup times extremely quick.

Key Features
The

Efficiency: Employed a hash function to group words into buckets.

Memory Management: Managed memory manually using `malloc` and `free` in C. Ensured that there are no memory leaks when the program exits. Speed: It can handle a very large dictionary (containing over 140,000 words) and search a large text in a matter of a fraction of a second. Why this project? I learned the reality of how data is stored inside a computer during this project. Handling pointers and linked lists was tough, but watching the program execute so quickly at the end made it all worthwhile. Special mention once again to Neso Academy for their videos on Hash Tables and Linked Lists, which helped me understand the flow of data inside memory, an important factor that enabled me to complete the functions related to unloading and loading.
