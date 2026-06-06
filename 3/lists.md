# Static List

- We can implement a static list using an array or vector, most of the functionality is similar to an array, we can insert in the midlle, front or back
- insertion in the middle requires O(n) shifting.
- We can also remove from middle, front or back
- removal from the middle also requires O(n) shifting
- Removal from back requires O(1) time, while removal from the front requires O(n) time due to the need for shifting
- Once a staticlist is initialized, it's capacity can no longer chage
- A Static List's items are stored contigiously in memory, meaning the elements are located next to each other,
- Random Access in a Static List is O(1) because memory layout is contiguous, The cpu can perform fast JUMP statements with pointer arithmetic


# Linked List
- A linked list is a Datastructure where it's elements are not necessarily placed contigously in memory, instead, elements are allocated dynamically, where each element holds a pointer to the next element (or a pointer for the previous elem too), forming a chain like datastructure
- Because of this, we have added flexibility to dynamically change the capacity at runtime, however
- Random access is O(n).
- insertion in the middle is also possible, no shifting is required, but we still need O(n) time for traversal
- Removal from the front and back require O(1) time
- Insertion in the middle requires O(n) time
- Insertion from the front or back requires O(1) time


