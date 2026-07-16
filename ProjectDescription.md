# Project Plan

## Theme

Stardew Valley.

## Classes

Player, Villager, Location, Beach, Farm, Joja, Mines, Town, Crop, Item, Quest.

## Limited Resources

Energy and inventory space.

## Time Handling

Most actions will increase the time, but depending on the action there might be a different increase.

## Extra Credit

A weather system with gameplay effects implemented using the "weather" class. Each day will have an instance of that class which will then effects gameplay. Raining days increase fishing luck and water all the crops. Stormy days will water all crops and increase mining luck.

A smarter bundle planner gives the player more information when examining the bundle. The bundle  will have a function providing information, that information will come from accessing the different instances of the quest class. The bundle  will take key information from the quests needed to complete the bundle.

Mining and fishing luck based on a random number generator. Using the "random" library from c++ a random number generator will be impelemented determining the reward of the player mining amd fishing. The generator can then be skewed to a certain result based on the luck of the day.

## Tradeoff System

Items of the bundle will require help from the villagers or Joja to get. 

Sometimes the help will be the item given directly to the player after a quest done for a villager. For example, Lewis will give truffle oil to the player once they help him get some parsnips. The Joja route would be to just buy the truffle oil from Joja for cheap.

The item might also only be acquired by getting a certain item to then get the bundle item. For example, Willy will provide the player deluxe bait to help catch an octopus in exchange for bringing him the tuna needed to make the bait. The player can also just buy an octopus from Joja.

Picking the Joja option will increase their influence. 1-2 influence there's no major effect on the town. At 3 influence the town's at a tipping point. Larger than 4 influence Joja has become majorily ingrained in the town.

## Mapping Style

A connected location map where the town is the middle and connects to other locations. Also, displays where the player currently is.

## Win/Loss

Winning requires finishing the bundle in the span of 10 days. Winning endings will change based on Joja influence.

Losing requires the player to fail to finish the bundle in the 10 day timespan.
