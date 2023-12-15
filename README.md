[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/XUCedPox)

# Asteroids Game

### Team Members
Christian Bäckström, Alen Forko, Kristoffer Saxmo, Alexander Wahrenstedt

<img alt="gameplay" src="https://github.com/FG22-GP/214-design-patterns-assignment-aw-ks-af-cb/blob/main/screenshots/gameplay.gif"/>

## Design Patterns
1. **Game Loop**  
   The game loop is handled by our [Core](https://github.com/FG22-GP/214-design-patterns-assignment-aw-ks-af-cb/blob/main/GameEngine/src/BaseClasses/Core.cpp) class, which holds variables like all the Actors, factories, and object pools. All actors inherit from the [Actor](https://github.com/FG22-GP/214-design-patterns-assignment-aw-ks-af-cb/blob/main/GameEngine/src/BaseClasses/Actor.h) base class, which has Update() and RenderPass() functions. The core will then iterate through all the actors and call their respective update and render functions.


2. **Factory**  
   We decided to use the [Factory](https://github.com/FG22-GP/214-design-patterns-assignment-aw-ks-af-cb/blob/main/GameEngine/src/Factories/AsteroidFactory.cpp) pattern for the creation of our asteroids and projectiles, making them easier to create because of the encapsulation it provides. Right now our factory only creates one type of asteroid, but it could easily be expanded to create more types.


3. **Object Pool**  
   To help with performance, we utilize an [ObjectPool](https://github.com/FG22-GP/214-design-patterns-assignment-aw-ks-af-cb/blob/main/GameEngine/src/BaseClasses/AsteroidPool.cpp). This means we don't have to remove objects from the game. Instead, we disable the objects and remake them for future use when they are acquired. When initializing, it creates a chosen amount of objects with the help of our factories. It will create even more of them, should it run out.


4. **Flyweight**  
   We're using the [Flyweight](https://github.com/FG22-GP/214-design-patterns-assignment-aw-ks-af-cb/blob/main/GameEngine/src/BaseClasses/TextureFlyWeight.cpp) pattern for creating and holding all of our textures. It saves us memory by not allowing every object to hold their texture by themselves. This is efficient as there can be quite a few asteroids and projectiles in the game at once, saving us a lot of memory.


5. **Observer**  
   The [InputHandler](https://github.com/FG22-GP/214-design-patterns-assignment-aw-ks-af-cb/blob/main/GameEngine/src/InputHandler/InputHandler.h) is managed using the Observer pattern. With the observer pattern, we only need one object to keep track of keyboard inputs. Everything that needs the keyboard inputs can then just subscribe to the input handler and become notified when needed.


## Learnings
Pointers have been the main point of struggle for us. Initially, we used normal C++ pointers. We soon noticed that smart pointers were a lot easier to handle. Among smart pointers, unique pointers are what we mainly used. Unique pointers allow for ownership to be transferred but not shared, ensuring that the pointer is only owned by one object. This also makes garbage collection easier, as the removal of the pointer is automatic when it gets moved out of scope, preventing memory leaks.
