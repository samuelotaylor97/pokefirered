MtEmber_RubyPath_B5F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtEmber_RubyPath_B5F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, MtEmber_RubyPath_B5F_OnResume
	.byte 0

MtEmber_RubyPath_B5F_OnTransition::
	show_static_if_natdex FLAG_HIDE_STATIC_GROUDON, FLAG_FOUGHT_GROUDON
	end

MtEmber_RubyPath_B5F_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, EventScript_StaticLegendaryTryRemove
	end

@ Overworld sprite is Entei. The battle is Groudon. Ruby Path is reachable before the National Dex.
MtEmber_RubyPath_B5F_EventScript_Groudon::
	static_legendary SPECIES_GROUDON, 45, FLAG_FOUGHT_GROUDON

MtEmber_RubyPath_B5F_EventScript_BrailleMessage::
	lockall
	setvar VAR_0x8005, 130
	braillemessage_wait Braille_Text_Everything
	braillemessage_wait Braille_Text_HasMeaning1
	braillemessage_wait Braille_Text_Existence
	braillemessage_wait Braille_Text_HasMeaning2
	braillemessage_wait Braille_Text_BeingAlive
	braillemessage_wait Braille_Text_HasMeaning3
	braillemessage_wait Braille_Text_HaveDreams
	braillemessage Braille_Text_UsePower
	waitbuttonpress
	releaseall
	end
