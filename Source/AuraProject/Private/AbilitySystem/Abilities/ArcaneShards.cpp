// Copyright LiuSha


#include "AbilitySystem/Abilities/ArcaneShards.h"

FString UArcaneShards::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	if (Level == 1)
	{
		return FString::Printf(TEXT(
			//Title
			"<Title>ARCANE SHRARDS</>\n"
			//Level
			"<Small>Level: </><Level>%d</>\n"
			//ManaCost
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			//Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n>"
			//Description
			"<Default>Summon a shard of arcane energy, "
			"causing radial arcane damage of: </>"
			//Damage
			"<Damage>%d</><Default> at the shard origin</>"),
			Level,
			ManaCost,
			Cooldown,
			ScaledDamage);
	}
	return FString::Printf(TEXT(
	//Title
	"<Title>ARCANE SHRARDS</>\n"
	//Level
	"<Small>Level: </><Level>%d</>\n"
	//ManaCost
	"<Small>ManaCost: </><ManaCost>%.1f</>\n"
	//Cooldown
	"<Small>Cooldown: </><Cooldown>%.1f</>\n>"
	//Description
	"<Default>Summon %d shards of arcane energy, "
	"causing radial arcane damage of: </>"
	//Damage
	"<Damage>%d</><Default> at the shard origins</>"),
	Level,
	ManaCost,
	Cooldown,
	FMath::Min(Level, MaxNumShards),
	ScaledDamage);
	
}

FString UArcaneShards::GetNextLevelDescription(int32 Level)
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
	"<Default>Summon %d shards of arcane energy, "
	"causing radial arcane damage of: </>"
	//Damage
	"<Damage>%d</><Default> at the shard origins</>"),
	Level,
	ManaCost,
	Cooldown,
	FMath::Min(Level, MaxNumShards),
	ScaledDamage);
}
