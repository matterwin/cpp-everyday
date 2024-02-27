# overview

- the standard template library (STL) is a set of template classes and functions that supply the programmer with 

1. containers for storing information
2. iterators for accessing the information stored
3. algorithms for manipulating the content of the containers


# STL containers 

- Containers are STL classes that are used to store data
- STL supplies 2 types of container classes:

1. sequential containers
2. associative containers 

- in addition to these STL provides classes called container adapters that are 
variants of the same with reduced functionality to support a specific purpose


# Sequential containers 

- hence the name, these containers are used to hold data in a sequential fashion,
such as arrays and lists

- sequential containers are characterized by a fast insertion time, but
are relatively slow in find operations

1. std::vector 
-- operates like a dynamic array and grows at the end 

2. std::deque
-- similar to std::vector except that it allows for new elements to be 
inserted or removed at the beginning too

3. std::list 
-- operates like a doubly linked list.
Think of this like a chain where an object is a link in the chain.
You can add or remove links -- that is, objects, at any position

4. std::forward_list
-- similar to std::list except that it is a singly linked list of elements
that allows you to iterate only in 1 direction
