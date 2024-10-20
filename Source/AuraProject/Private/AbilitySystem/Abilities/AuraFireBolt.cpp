// Copyright LiuSha


#include "AbilitySystem/Abilities/AuraFireBolt.h"

#include "AuraGameplayTags.h"

FString UAuraFireBolt::GetDescription(int32 Level)
{
	const int32 Damage = GetDamageByDamageType(Level,FAuraGameplayTags::Get().Damage_Fire);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	if (Level == 1)
	{
		return FString::Printf(TEXT(
			//Title
			"<Title>FIRE BOLT</>\n"
			//Level
			"<Small>Level: </><Level>%d</>\n"
			//ManaCost
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			//Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n>"
			//Description
			"<Default>Launched a bolt of fire, "
			"exploding on impact and dealing: </>"
			//Damage
			"<Damage>%d</><Default> fire damage with a chance to burn</>"),
			Level,
			ManaCost,
			Cooldown,
			Damage);
	}
	return FString::Printf(TEXT(
	//Title
	"<Title>FIRE BOLT</>\n"
	//Level
	"<Small>Level: </><Level>%d</>\n"
	//ManaCost
	"<Small>ManaCost: </><ManaCost>%.1f</>\n"
	//Cooldown
	"<Small>Cooldown: </><Cooldown>%.1f</>\n>"
	//Description
	"<Default>Launched %d bolts of fire, "
	"exploding on impact and dealing: </>"
	//Damage
	"<Damage>%d</><Default> fire damage with a chance to burn</>"),
	Level,
	ManaCost,
	Cooldown,
	FMath::Min(Level, NumProjectiles),
	Damage);
}

FString UAuraFireBolt::GetNextLevelDescription(int32 Level)
{
	const int32 Damage = GetDamageByDamageType(Level,FAuraGameplayTags::Get().Damage_Fire);
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
	"<Default>Launched %d bolts of fire, "
	"exploding on impact and dealing: </>"
	//Damage
	"<Damage>%d</><Default> fire damage with a chance to burn</>"),
	Level,
	ManaCost,
	Cooldown,
	FMath::Min(Level, NumProjectiles),
	Damage);
}