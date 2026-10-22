TrainerTower_Roof_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerTower_Roof_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerTower_Roof_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerTower_OnFrame
	.byte 0

TrainerTower_Roof_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, EventScript_StaticLegendaryTryRemove
	goto TrainerTower_OnResume

TrainerTower_Roof_OnTransition::
	show_static_if_natdex FLAG_HIDE_STATIC_RAYQUAZA, FLAG_FOUGHT_RAYQUAZA
	end

@ Overworld sprite is Ho-Oh. The battle is Rayquaza.
TrainerTower_Roof_EventScript_Rayquaza::
	static_legendary SPECIES_RAYQUAZA, 70, FLAG_FOUGHT_RAYQUAZA

@ Below script is unused, the identical version in the 1F script is used instead

TrainerTower_Roof_EventScript_Owner::
	call TrainerTower_EventScript_SpeakToOwner
	end
