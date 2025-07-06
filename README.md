ESCAPING THE HUNTED HOUSE: A ZORK STYLE ADVENTURE

A text-based adventure game created in C++ that pays homage to the classic *Zork*-style gameplay. You will explore a mysterious house, interact with rooms, find items, and try to escape — but beware, not everything is as it seems...

---

##  Game Info

- **Title:** ESCAPING THE HUNTED HOUSE
- **Genre:** Text-based Adventure
- **Platform:** Windows (Console)
- **Language:** English
- **Author:** Jose Angulo
- **Institution:**  Universitat Politècnica de Catalunya
- **GitHub Repository:** [[https://github.com/your-username/Zork](https://github.com/your-username/Zork)](https://github.com/hellosound/Zork/tree/1.0)
- **Release:**: https://github.com/hellosound/Zork/releases/tag/1.0
- **License:** MIT License

---

##  How to Play

1. Run the executable (`Zork.exe`).
2. The game starts with a short dialogue.
3. Enter your name and choose whether to begin the test.
4. Use the following **commands** to navigate:
   - `NORTH`
   - `EAST`
   - `SOUTH`
   - `WEST`
   - `QUIT` – exit the game.

5. At certain points, you may be asked:
   - If you want to **pick up items**, type `Y` or `N`.

---

##  Goal of the Game

You must escape the *House of Horrors*. To do this:

- **Explore** the rooms.
- **Collect** key items (like the **Magic Ring**) to **unlock doors**.
- **Interact** with the environment and make decisions.
- Reach the **Final Room** to win the game.

---

##  Tips

- Look around carefully and pick up items when prompted.
- Some rooms may not reveal their secrets until you have the right item.

---
##  About the process
The approach for building this game was "make the tools first, then build the game using those tools." I began by listing the core requirements — such as a navigation system, item pickup and inventory mechanics, and some light player personalization — and developed supporting systems accordingly.

After designing and implementing the Room and Exit classes, I created a graph of the world map to visualize room connectivity and ensure all exits were logically placed.

<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/f8f74ee7-55ed-49db-947a-d6fba44d8dcf" />

Working with lists and loops was a key part of the development, and this project significantly deepened my understanding of these concepts and their syntax in C++.

The game is structured using inheritance and polymorphism. A base class called Entity represents all interactive objects in the world. Specialized classes like Player and Exit inherit from Entity, allowing each to behave differently while sharing a common interface — a core principle of polymorphism in object-oriented programming.

One interesting challenge was implementing the locked north door in the Living Room. Initially, I wanted the player to unlock the door using the magic ring, but managing the locked state became complicated. The final and simpler solution was to not create the north door at all until the player had collected the ring. Once the ring is in the inventory, the door is dynamically added, and the player experiences this as the door being unlocked. This approach, combined with descriptive narrative, maintains immersion while simplifying logic.


---

##  License

This project is licensed under the **MIT License**. You are free to modify, distribute, and use it for educational purposes.

---

##  Credits

Created by Jose Angulo as the admission test for the Master's in Advanced Programming for AAA Games of the Universitat Politécnica de Catalunya.
