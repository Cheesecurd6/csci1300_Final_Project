# Project Plan

## Theme

Stardew Valley.

## Classes

Player, Villager, Location, Item, Quest, Inventory, Bundle, Weather.

## Limited Resources

Relationship, Energy, Inventory space.

## Time Handling

Most actions will increase the time, but depending on the action there might be a different increase.

## Extra Credit

A weather system with gameplay effects implemented using the "weather" class. Each day will have an instance of that class which will then effects gameplay. Raining days increase fishing luck. Sunny days increase crop growth and double the chance for crops harvested to produce two of the same crop. Snowing days will decrease foraging luck, but increase fishing luck.

A smarter bundle planner gives the player more information when examining the bundle. The bundle class will have a function providing information, that information will come from accessing the different instances of the quest class. The bundle class will take key information from the quests needed to complete the bundle.

Mining and fishing luck based on a random number generator. Using the "random" library from c++ a random number generator will be impelemented determining the reward of the player mining, fishing, and foraging. The generator can then be skewed to a certain result based on the luck of the day.

## Tradeoff System

Items of the bundle will require help from the villagers or Joja to get. 

Sometimes the help will be the item given directly to the player after a favor and enough relationship with a villager. For example, Lewis will give truffle oil to the player once they help him with his affair with Marnie and negotiating with Joja. The Joja route would be to help them sabatoge Lewis in exchange for truffle oil. The sabatoge would be easy and take very little effort.

The item might also only be acquired by getting a certain item to then get the bundle item. For example, Willy will provide the player ultra deluxe bait to help catch octopus in exchange for helping him fix his shack and bait supply. The player can also just buy Joja brand Super Bait.

Picking the Joja option will increase their influence up to a number of 10.

## Mapping Style

A connected location map that changes when areas are unlocked. Also, displays where the player currently is.

## Win/Loss

Winning requires finishing the bundle in the span of two weeks. Winning endings will change based on Joja influence and relationship with villagers.

Losing requires the player to fail to finish the bundle in the two week timespan. Ending will change based on relationship with villagers.
