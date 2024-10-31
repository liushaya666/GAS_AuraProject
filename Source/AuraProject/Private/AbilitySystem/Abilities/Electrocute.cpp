// Copyright LiuSha


#include "AbilitySystem/Abilities/Electrocute.h"

FString UElectrocute::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	if (Level == 1)
	{
		return FString::Printf(TEXT(
			//Title
			"<Title>ELECTROCUTE</>\n"
			//Level
			"<Small>Level: </><Level>%d</>\n"
			//ManaCost
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			//Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n>"
			//Description
			"<Default>Emits a beam of lighting, "
			"connecting with the target, repeatedly causing: </>"
			//Damage
			"<Damage>%d</><Default> lightning damage with a chance to stun</>"),
			Level,
			ManaCost,
			Cooldown,
			ScaledDamage);
	}
	return FString::Printf(TEXT(
	//Title
	"<Title>ELECTROCUTE</>\n"
	//Level
	"<Small>Level: </><Level>%d</>\n"
	//ManaCost
	"<Small>ManaCost: </><ManaCost>%.1f</>\n"
	//Cooldown
	"<Small>Cooldown: </><Cooldown>%.1f</>\n>"
	//Number of Shock Targets
	"<Default>Emits a beam of lighting, "
	"propagating to %d additional targets nearby, causing: </>"
	//Damage
	"<Damage>%d</><Default> lightning damage with a chance to stun</>"),
	Level,
	ManaCost,
	Cooldown,
	FMath::Min(Level, MaxNumShockTargets - 1),
	ScaledDamage);
	
}

FString UElectrocute::GetNextLevelDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	return FString::Printf(TEXT(
	//Title
	"<Title>NEXT LEVEL</>\n"
	//Level
	"<Small>Level: </><Level>%d</>\n"
	//ManaCost
	"<Small>ManaCost: </><ManaCost>%.1f</>\n"
	//Cooldown
	"<Small>Cooldown: </><Cooldown>%.1f</>\n"
	//Description
	"<Default>Emits a beam of lighting, "
	"propagating to %d additional targets nearby, causing: </>"
	//Damage
	"<Damage>%d</><Default> lightning damage with a chance to stun</>"),
	Level,
	ManaCost,
	Cooldown,
	FMath::Min(Level, MaxNumShockTargets - 1),
	ScaledDamage);
}
