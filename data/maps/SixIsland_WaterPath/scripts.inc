SixIsland_WaterPath_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_WaterPath_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SixIsland_WaterPath_OnResume
	.byte 0

SixIsland_WaterPath_OnTransition::
	show_static_if_natdex FLAG_HIDE_SUDOWOODO, FLAG_FOUGHT_SUDOWOODO
	end

SixIsland_WaterPath_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, EventScript_StaticLegendaryTryRemove
	end

@ Odd tree uses the Cut-tree artwork under its own graphics id, so Cut leaves it alone.
SixIsland_WaterPath_EventScript_Sudowoodo::
	static_legendary SPECIES_SUDOWOODO, 30, FLAG_FOUGHT_SUDOWOODO

SixIsland_WaterPath_EventScript_HornWantedSign::
	msgbox SixIsland_WaterPath_Text_WantedUltimateHorn, MSGBOX_SIGN
	end

SixIsland_WaterPath_EventScript_RouteSign::
	msgbox SixIsland_WaterPath_Text_RouteSign, MSGBOX_SIGN
	end
