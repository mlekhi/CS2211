// a) Find all the English words that begin with ”qu” and end with ”y”
grep '^qu.*y$' /usr/share/dict/words

// b) Find all the English words that contains all five vowels – a, e, i, o, u – in that order.
grep 'a.*e.*i.*o.*u' /usr/share/dict/words

// c) Find all the English words that do not contain any of the five vowels, – a, e, i, o, u.
grep -v '[aeiou]' /usr/share/dict/words

// d) Find all the Unix commands that begin with ”t”.
compgen -c | grep '^t'

// e) Find all the Unix commands with length 2.
compgen -c | grep '^.\\{2\\}$'

// f) Find all the Unix commands that end with a digit.
compgen -c | grep '[0-9]$'

// g) Find all the lines in a file that contain at least one alphabetic character.
// hint: one can use [[:alpha:]] to replace [a-zA-Z].
grep '[[:alpha:]]' filename

// h) Find all the lines in a file that contain at least one non-alphabetic character.
grep '[^[:alpha:]]' filename

// i) Find all the lines in a file that do not contain even a single alphabetic character.
grep -v '[[:alpha:]]' filename

// j) Find all the lines in a file that do not contain even a single non-alphabetic character.
grep -v '[^[:alpha:]]' filename

// k) Display the number of the empty lines in a file.
grep -c '^$' filename

// l) Find all the lines in a file, display all the lines found, preceded by their line numbers.
// hint: use cat with an option.
cat -n filename

// 
:%s/\(\d\{2\}\)-\(\d\{2\}\)-\(\d\{4\}\) \(\d\{2\}\)-\(\d\{2\}\)-\(\d\{4\}\)/20-\3-\1 21-\4-\2/g