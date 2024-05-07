# C Blackjack Game

This repository contains a C-based implementation of the classic card game Blackjack, which you can play in the terminal. This game supports features like betting, splitting hands, and seed-based deck initialization for reproducible results. Players start with a default balance and attempt to maximize their earnings against a computer-controlled dealer.

## Features

- **Command Line Interface:** Utilize a user-friendly command line interface for game interactions.
- **Betting System:** Start with a preset balance and make bets each round.
- **Hand Splitting:** Option to split hands when the first two cards are of the same value.
- **Seed Initialization:** Optionally start the game with a specific seed for predictable card sequences.
- **Replayability:** After each round, choose whether to play again or end the game.

## Prerequisites

Before you can run the game, make sure you have the following requirements met:
- A C compiler like `gcc`.

## Installation

To install and run the Blackjack game, follow these steps:

```bash
# Clone the repository
git clone https://github.com/WacoderForever/BlackJack.git
cd BlackJack

# Compile the game (example using gcc)
gcc -o blackjack main.c 

# Run the game
./blackjack

```
## Usage

Start the game by running the compiled executable. You can optionally specify the initial balance and seed for deck shuffling:

```bash

    ./blackjack -b 5000 -s 12345

```

## Game Commands

- Bet Amount: At the start of each round, you'll be prompted to enter your bet.
- Splitting: If your first two cards are a pair, you'll have the option to split.
- Hit or Stand: Choose whether to receive another card or stand with your current hand.
- End Game: After each round, decide if you want to continue or end the game.

## Contributing

Contributions are welcome! If you have suggestions or improvements, please fork the repository and submit a pull request.

## Contact

If you have any questions, please email [sethomondi088@gmail.com].

