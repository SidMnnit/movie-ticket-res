# movie-ticket-res
C++ program for a system of movie ticket reservations
* Input number of test cases for one of the following types of reservation commands:
* * add-screen: Adds a screen to the cinema system, with the specified number of rows and columns, along with the seat numbers which are the aisle seats in that theatre/screen. prints success if a new screen has been created, and failure if it already exists.
* * reserve-seat: Reserves seats in a particular screen, with given row number and seat numbers. prints failure if not possible and success otherwise.
* * get-unreserved-seats: Prints all the unreserved seat numbers for a particular row at a specified screen.
* * suggest-contiguous seats: Suggests specified number of contiguous unreserved seats in a particular row, taking into account aisle seats, and one preferred seat number which should be necessarily included. prints 'none' if this is not possible in that row
* These commands should be executed in the following fashion:
* * add-screen name-of-screen number-of-rows number-of-columns space-separated-aisle-seats
* * reserve-seat name-of-screen row-number space-separated-seats-to-be-reserved
* * get-unreserved-seats name-of-screen row-number
* * suggest-contiguous-seats name-of-screen number-of-seats row-number choice-of-seat
* An example input has been specified below:
```
7
add-screen Screen1 12 10 4 5 8 9
add-screen Screen2 20 25 3 4 12 13 17 18
reserve-seat Screen1 4 5 6 7
reserve-seat Screen2 13 6 7 8 9 10
reserve-seat Screen2 13 4 5 6
get-unreserved-seats Screen2 13
suggest-contiguous-seats Screen2 4 13 4
```
