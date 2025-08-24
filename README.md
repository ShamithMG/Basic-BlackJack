# Basic Blackjack in C++

![Language](https://img.shields.io/badge/language-C%2B%2B-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

A complete, command-line blackjack game written in modern C++. This project provides a classic single-player experience against an automated dealer, built from the ground up with a strong emphasis on object-oriented design and clean, separated logic. It serves as a practical demonstration of core C++ principles.

## 📚 Table of Contents

- [Features](#-features)
- [C++ Concepts Showcase](#-c-concepts-showcase)
- [Getting Started](#-getting-started)
  - [Prerequisites](#prerequisites)
  - [Compilation & Execution](#compilation--execution)
- [How to Play](#-how-to-play)
- [Project Structure](#-project-structure)
- [Contributing](#-contributing)
- [License](#-license)

## 🃏 Features

* **Classic Blackjack Rules**: Faithfully implements standard rules. The goal is to get closer to 21 than the dealer without busting. Aces are handled as 11 by default.
* **Player Actions**: Supports essential player actions: **hit** (take another card) and **stand** (end your turn).
* **Automated Dealer**: The dealer plays according to a fixed, common casino strategy, hitting until their hand value reaches 17 or more.
* **Interactive Betting System**: Before each round, you can place a bet from your virtual bankroll. Winnings are paid out at 1:1.
* **Clear Command-Line Interface**: The game is played entirely in the terminal, with clear prompts and status updates to guide you.

## 🛠️ C++ Concepts Showcase

This project was built to apply and demonstrate several key C++ concepts, making it a strong portfolio piece for a C++ learner.

* **Object-Oriented Programming (OOP)**: The entire application is designed around objects. `Player`, `Deck`, and `Card` are all classes/structs with their own distinct responsibilities (data and methods), demonstrating encapsulation and separation of concerns.
* **Header Guards**: All header files (`.h`) use `#ifndef`/`#define`/`#endif` guards to prevent multiple inclusion errors, a fundamental practice for managing C++ projects.
* **STL Containers**: Makes effective use of the Standard Template Library. `std::vector` is used in the `Player` class for a dynamic hand of cards, and `std::array` is used in the `Deck` for a fixed-size collection of 52 cards.
* **Namespaces**: User input functions are organized within a `user` namespace to avoid potential naming conflicts and logically group related functionality.
* **Static Members**: The `Deck` class uses a `static` member variable (`current_card_`) to track the next card to be dealt, ensuring all players draw from a single, shared deck state.
* **`constexpr`**: The `Card` struct uses `constexpr` for arrays that define card properties, allowing the compiler to evaluate these values at compile-time for improved performance.

## 🚀 Getting Started

Follow these instructions to get a copy of the project up and running on your local machine.

### Prerequisites

You will need a C++ compiler installed on your system. The `g++` compiler is a common choice.

* **g++** (Part of the GNU Compiler Collection)

### Compilation & Execution

1.  **Clone the repository (or download the files)**
    ```bash
    git clone https://your-repository-url/basic-blackjack.git
    cd basic-blackjack
    ```

2.  **Compile the Source Code**
    Navigate to the project's root directory in your terminal and run the following command. This will compile all `.cpp` files from the `src` directory and create a single executable named `blackjack`.
    ```bash
    g++ src/*.cpp -o blackjack
    ```

3.  **Run the Game**
    Once compilation is successful, start the game by running the executable:
    ```bash
    ./blackjack
    ```

## 🎮 How to Play

The game will guide you with on-screen prompts:

1.  **Place Your Bet**: At the start of a new round, enter how much you want to bet.
2.  **Make Your Move**: After the initial cards are dealt, type `h` to **hit** or `s` to **stand**.
3.  **Dealer's Turn**: Once you stand, the dealer will reveal their face-down card and play their turn.
4.  **Outcome**: The winner is determined, and the bet is settled.
5.  **Play Again?**: You'll be asked if you want to play another round (`y`) or exit (`n`).

## 📂 Project Structure

The project's source code is logically separated into different files:

```
/
├── src/
│   ├── main.cpp          # Application entry point
│   ├── Game.h / .cpp     # Manages the main game session and flow
│   ├── Player.h / .cpp   # Defines the Player and Dealer classes
│   ├── Deck.h / .cpp     # Manages the 52-card deck, shuffling, and dealing
│   ├── Card.h            # Defines the Card struct
│   ├── UserInput.h / .cpp# Handles all user keyboard input
│   └── Random.h          # Utility for random number generation
│
├── .gitignore            # Specifies files for Git to ignore
├── LICENSE               # Project's MIT License
└── README.md             # This file
```

## 🙌 Contributing

Contributions are welcome! If you have suggestions for improvements, please feel free to fork the repo and create a pull request, or open an issue with the tag "enhancement".

1.  Fork the Project
2.  Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3.  Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4.  Push to the Branch (`git push origin feature/AmazingFeature`)
5.  Open a Pull Request

## 📄 License

This project is distributed under the MIT License. See the `LICENSE` file for more information.
