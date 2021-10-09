# Linux-Cut-Command

Simplistic implementation of the Linux Cut command

-Unfinished


-it only cuts FIELDS (not characters, bytes, etc).


-it requires between 1 and 100 fields (inclusive)


-it requires fields to be unique, and specified in increasing order


-it does not implement any functionality of cut other than cutting fields with given input delimiter and output delimiter 


-the format of its command line arguments are simpler than cut's

Program expects command line arguments (CLAs) specifying the following, in this order:


	-input  delimiter (a single character)
 
	-output delimiter (a single character)
  
  	-field(s) (at least one, and at most 100, unique positive integers, given in increasing order of size)

Examples:


	> a.out , . 2 4 5 6 9 <input
    
	> a.out , , 3 <input
    
	> a.out x y 1 4 32 33 37 42 57 77 86 204 337 <input
