comp15 hw5 Mingzhe Li

/*
Please please read me,
Because I am probably of even more importance than the code
*/

So now my program is still experiencing a segmentation fault (core dumped).
Although I used to make it work well and I believe that should I have more
time I am able to make it work, I am running out of time.  So I would like
to devote the rest of the time before the deadline to write this
confession-sort-of article, which potentially could tell more than my code
can.

First of all I would like to give my thanks to Chris.  Tufts is good at 
recruiting excellent computer science instructors, and you are definitely
more than qualified.  To lead such a big class is no easy job, yet your
dedication makes this class very organized and helpful.  Thanks you!

Second, shout out to Ilan Gray, my lab leader!  You totally opened my eyes.
You led me to a world that much more exciting than what I thought the world
of computer science would be.  I believe your amazing technical proficiency
and personality will take you to wherever you want.

Now let’s talk about the real technical issues.  I just looked back at my
project designed at the very beginning, and it was like garbage — I say so 
because now I finally understand what computer science is, what data 
structure is, and what comp 15 is.  In that document I said I was going to 
use vectors to store the songs, and hash table to search, and blah blah blah 
— those are probably nothing wrong, but also nothing right.  

I have to be able to tell the big picture of the project, instead of obsessively
concerning the low level details.  Yes vectors are a data structure, yes stacks,
queues, tries are all data structures, and knowing how to use them is crucial
for comp 15 — but all that is not comp 15.  Big projects like hw5 require you
not only implement the basic elements, structures, classes, but also ask
you how the problems are being solved via what approaches.  You must 
have a mind map of all the variables, functions, classes.  You must be able
to tell the relationship between them.  Data structures are but dynamic arrays
and linked lists — although they have many different forms of implementation 
— you must know when to use which, and why.  That is comp 15.

Now I will try to re-elaborate my project design.  
First of all, I think the most basic element we need for this project is 
the “song,” basically what the program reads from the file.  I decide to
 create a class called “Song” to hold the “Artist,” “Title,” and ”Lyrics,” 
“Lyrics” is a vector of strings.  I choose vector,because it will be easy 
to trace the context (five words before and after).  

The class “Song” should be able to 1)tell how many times a word appears
in the lyrics, and 2)print the artist, title, and the context of the lyrics 
for each appearance of the word as the given format.  I created public
functions to achieve that.

Then I start thinking of how the program looks like in a larger view.  
It basically does three things:
1)to read data of songs from file;
2)to read a word to search (user’s query);
3)to search and to print a list of songs in the order of the word’s frequency

With that in my mind, I easily build up my main.cpp, and realize the real
challenge that is to set up a connection between a word (user’s query) and
a list of songs (results from search of the database)

I chose to use <unordered_multimap> to implement that. It pairs a string 
and an array of pointers to “Song”s.

After the program reads from the file, a huge vector of pointers to the songs
will make the database.  

After the program reads user’s query -- the target word -- the program 
loops through this huge vector, asks for the word’s frequency for each song, 
and insert the pointers to the songs to an array called “results.”  

This array has a fixed size of 10 and is initialized with value of NULL.  
If “results” is filled up, the rest of the songs have to havea “frequency” 
higher than the minimum in the “results,” and it will replace the one with 
the minimum frequency in the “results.”

After the top ten songs are inserted into the “results,” a function called
“sortResults” will be called to sort the “results.”  I used Insertion Sort
here for its simplicity, stability, and small code size.

Finally, just loop through the “results” to print all the songs. 


Working on this project I applied a "bridge-building" strategy.  When you
build a bridge, you start from the two ends -- and for this project, I
started from both a micro and macro view of the problem.  The hard part
is how to connect the two ends, which is a lot of implementation of 
various data structures.  Unlike the previous sorting assignment, this 
one does not challenge you about those computaion algorithms -- which can
be hard from a mathematical perspective -- but how well you master all 
those kinds of data structures.  That is comp 15.

I did not finish the program before deadline, which is a pity, but I am
taking five classes this semester and I have to make choices.  Nevertheless,
I really enjoyed working on this project.  I enjoyed researching all the
references on cplusplus.com, learning how to use those templates and 
functions.  Through debugging I gained a deeper understanding of the 
compiler(s).  Although this assignment would possibly hurt my grade, I do not
care anymore -- because I have learnt so much from it.

Alright JUST KIDDING I WANT A GOOD GRADE.  If there is anything I can do
on my part to improve my grade, e.g.
a)make you coffee
b)do your laundry
c)swipe you in Dewick
Please do not hesitate to let me know!
