# Basic-BlackJack
 blackjack in c++

# Basic Blackjack in C++

This project is a complete, command-line blackjack game written in modern C++. It provides a classic single-player experience against an automated dealer, built from the ground up with a strong emphasis on object-oriented design and clean, separated logic. It serves as a practical demonstration of core C++ principles.

## 🃏 Features

* **Classic Blackjack Rules**: The game faithfully implements standard rules. The goal is to achieve a hand value closer to 21 than the dealer's without exceeding it. Aces are handled as 11 by default.
* **Player Actions**: Supports the essential player actions: **hit** (take another card) to improve your hand, and **stand** (end your turn) to face the dealer.
* **Automated Dealer**: The dealer plays according to a fixed, common casino strategy: they will continue to hit until their hand value reaches 17 or more, at which point they must stand.
* **Interactive Betting System**: Before each round, you can place a bet from your virtual bankroll. Winnings are paid out at 1:1.
* **Clear Command-Line Interface**: The game is played entirely in the terminal. The interface provides clear prompts and status updates to guide you through each step of the game.

## 🛠️ C++ Concepts Showcase

This project was built to apply and demonstrate several key C++ concepts:

* **Object-Oriented Programming (OOP)**: The entire application is designed around objects. `Player`, `Deck`, and `Card` are all classes/structs with their own distinct responsibilities, data, and methods. The main `Session` class coordinates these objects to run the game, demonstrating encapsulation and separation of concerns.
* **Header Guards**: To prevent issues with multiple inclusions, all header files (`.h`) use `#ifndef`/`#define`/`#endif` header guards, which is a fundamental practice for managing larger C++ projects.
* **STL Containers**: The project makes use of standard library containers. `std::vector` is used in the `Player` class to dynamically store the cards in a player's hand, and `std::array` is used in the `Deck` for a fixed-size collection of 52 cards.
* **Namespaces**: The user input functions are organized within a `user` namespace (`UserInput.h`/`.cpp`) to avoid potential naming conflicts and logically group related functions.
* **Static Members**: The `Deck` class uses a `static` member variable (`current_card_`) to keep track of the next card to be dealt, ensuring that all players draw from the same point in the shuffled deck.
* **`constexpr`**: The `Card` struct uses `constexpr` for arrays that define card ranks, suits, and their corresponding values. This allows the compiler to evaluate these values at compile-time for improved performance.

## ⚙️ How to Compile and Run

You will need a C++ compiler (like g++) to build and run the project.

1.  **Navigate to the Project Directory**
    Open your terminal or command prompt and change to the root directory where you've saved these files.

2.  **Compile the Source Code**
    Use the following command to compile all the `.cpp` source files from the `src` directory into a single executable file named `blackjack`.

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

1.  **Place Your Bet**: At the start of a new round, you'll be asked to enter how much you want to bet.
2.  **Make Your Move**: After the initial cards are dealt, you can either type `h` to **hit** or `s` to **stand**.
3.  **Dealer's Turn**: Once you stand, the dealer will reveal their face-down card and play out their turn automatically.
4.  **Outcome**: The winner is determined, and the bet is settled.
5.  **Play Again?**: You'll be asked if you want to play another round (`y`) or exit the game (`n`).

## 📄 License

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for full details.