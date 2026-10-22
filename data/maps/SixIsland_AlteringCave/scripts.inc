SixIsland_AlteringCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_AlteringCave_OnTransition
	.byte 0

SixIsland_AlteringCave_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SIX_ISLAND_ALTERING_CAVE
	@ Advance one set per visit. 9 matches NUM_ALTERING_CAVE_TABLES. Set 0 returns after a full cycle.
	addvar VAR_ALTERING_CAVE_WILD_SET, 1
	compare VAR_ALTERING_CAVE_WILD_SET, 9
	goto_if_lt SixIsland_AlteringCave_EventScript_End
	setvar VAR_ALTERING_CAVE_WILD_SET, 0
SixIsland_AlteringCave_EventScript_End::
	end
