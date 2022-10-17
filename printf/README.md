Steps to build printf function.
1 -> Create jump table that points to all relevant functions used in the printf function (%d, %c, etc...)
2 -> Create all functions per character (which are pointed to by the jump table). 
3 -> Create final printf function which loops through all chars in FORMAT string and if meets %, goes in [Format + 1] and applies relevant function depending on character. Else, ft_putstr on all chars up to %. 
