# How will the beginning of this work???
List of ways this may start:

* *"You suddenly awaken, in a forest with a headache. You take a look around and find some sticks. what will you do?"*
* *"The world is putting its pieces together. It hurts to watch but suddenly youre in the wilderness and dont know where you are. You look around and find some things that might help on your journey. [Items listed in new line]"*

Options for these could be:

* take sticks
* explore,walk around
* sleep [amt of time here]


# How are the mechanics of the game going to work??
Inventory shouldn't be too big because then it wouldn't properly display. It also shouldn't be too small because then *how are you going to hold something???* I think it should be between 10 to 20 slots of items.

Movement is also something thats a bit off. Theres no way to postition yourself and go in a specific direction. One idea I have to solve that is having the play make a compass to stop *explore*ing and start *move*ing :/. The way this could work is using a move command with a syntax like this:

```
move [direction (north,south,east,west)] [amt of steps/distance????]
```

Another item to address would be world generation. It would be a little boring to be playing in the same place constantly. Using some way of randomizing a mass amount of numbers in a certain amount of time, it may be possible. I dont know a way to do it yet though. Srand allows for a seed, maybe we generate a 10 digit number to use for the seed?

One more thing is the items that go inside of your inventory. I think it would be best for items to have an id.

```
--------------
List of Items
--------------

1 - Stick
2 - Stone
3 - Tree
4 - Dirt
5 - Plant
6 - Cactus
7 - Sand
8 - Mud
```

Those are just 5* items I came up with that could be used in the game. I brought items up though because during world generation some event or something (like an item) will be placed in the certain area the player is in. So, at the start of the game it will tell you what is easily accesible (whatever the player sees after suddenly existing) but not what isn't easily accesible. This would be done with using some extra data and common sense from the developer to define attributes of an object.

You may (or most likely may not) have noticed I made items array strings. Why? To hold all of their attributes. All their sizes are six because I haven't thought of attributes. They're strings because checking if an item can do something/has the attribute is just **"true"** or **"false"** and that you can have numbers or any other type of data.

There's also where you are going to spawn. Having it generate a number which picks which *biome* you spawn in may be the best option for now. Heres a list of possible places to spawn.

```
id|  area
__|________
1 - Forest
2 - Desert
3 - Some snowy place with trees
4 - Swamp (Get out of my swamp!)
5 - Mountains (Maybe also extreme mountains?)
```

Maybe having the game tell time would improve how enemies summon/interact with the player. Some enemies may have chances to spawn in the daylight and most will spawn in the night. It will only tell time relatively when you don't have a watch/clock/any way to tell time. 

Including what the object is made of/its primary material type would be nice. Heres a material list

```
id mat
__|____
1 |Wood
2 |Stone
3 |Metal
4 |Plant
5 |Sand
6 |Dirt
```

# Cool! How is this all going to be saved?

I don't know *how* it would be easily divided or even able to be read by the program yet but I'm almost there. Using i/ofstream the program will be able to take input and output respectively. When reading a file it allows for an offset (I dont know if its by characters or lines) which could be used to start reading and writing to and from the proper spot.
