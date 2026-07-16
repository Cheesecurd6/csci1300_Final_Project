# CSCI 1300 Final Project

## Theme

My game's theme is based off of the game Stardew Valley. It's not a one to one replica obviously, but a few of Stardew's characters and locations are included. Also, the general gameplay of farming and doing quests like in Stardew is also done here. The main gameplay loop is similar.

## Goal

Complete the final bundle consisting of 10 blueberries, truffle oil, a diamond, an octopus, and a crystal fruit.

## How to compile and run

Compile:
g++ -Wall -Werror -Wpedantic -Wextra Crop.cpp Farm.cpp Item.cpp location.cpp player.cpp villager.cpp Quest.cpp Town.cpp main.cpp Mines.cpp Beach.cpp Validation.cpp Joja.cpp -o main

Run:
./main

## How to play

Entering numbers 0-9 to do actions presented by the terminal.

## Classes

Player, Villager, Location, Beach, Farm, Joja, Mines, Town, Crop, Item, Quest.

Exact uses of the classses: 
The player class tracks the players name, energy, gold, time and other stats. 
The villager class tracks villagers name, description, and quest.
The location class has the general stats for locations.
Beach class for the beach location, has the fishing function.
Farm class for the farm location, has functions all related to farming.
Joja class for the Joja mart location.
Mines class for the mines, has the mining function.
Town class for the town location.
Crop class for tracking crops planted on the farm.
Item class for storing information about items name, description, value.
Quest class for tracking quest names, descriptions, rewards, and requirements.

## Extra credit

Weather system with gameplay effects, smarter bundle planner, random number generator for the weather, fishing, and mining results.