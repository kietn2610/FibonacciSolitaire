# FibonacciSolitaire
A simple interactive game coded in C++
Rules:
1) Take the top card from the deck and place it face up on the table.
2) The Sum is now the value of that card (Ace = 1, 2 = 2, … 10 = 10, Jack = 10, Queen = 10, King = 10)
3) If the Sum is a Fibonacci number, discard that pile (hand), and start over at instruction #1
4) If the Sum is not Fibonacci, take the next card from the top of the deck and place it on top of the card
stack (pile or hand) on the table.
5) The Sum is now the sum of all cards in the stack on the table.
6) Go to instruction #3.
