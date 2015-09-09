This assignment includes selection sort as required, and I chose quick sort 
	and merge sort as the rest two.

The algorithm of selection sort goes something like this:
	It initially looks for the smallest(largest) element in the list,
	then swaps it with the leftmost element and thus creates a
	sorted sublist. It repeats in the unsorted list, and eventually
	makes the whole list sorted.

	Selection sort has O(n2) time complexity, because it has to loop
	through the whole list to search for the minimum time and time 
	again.  It is not the best algorithm to use when dealing with
	a large quantity of inputs, but it is very simple and possibly
	uses less memory.

The algorithm of quick sort goes something like this:
	First we need to choose a pivot. Computer scientist Sedgewick
	recommends choosing the median of the first, middle, and last
	last element for the best overall performance. Then for each
	element in the list, those smaller than the pivot go to a sublist
	and those greater go to another sublist, and thus a partition
	is finished. It does this recursively, so that each sublist is
	sorted and so is the list as a whole.

	The quick sort on average has an O(n log n) time complexity, and 
	O(n2) in the worst case.  It is not a stable sort.  It is faster
	than other O(n log n) sorting algorithms in most cases.

The algorithm of merge sort goes something like this:
	It recursively splits the unsorted list into many sublists, each
	containing just one element.  Then repeatedly merge these 
	sublists and keep them in order, producing sorted sublists.  It
	does this until all the sublists merge into one list, which is
	then sorted.

	Invented by John von Neumann, merge sort is a stable, 
	comparison-based sorting algorithm.  It has an O(n log n) time
	complexity.


Major reference source: Wikipedia
