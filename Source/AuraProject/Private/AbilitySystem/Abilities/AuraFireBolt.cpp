// Copyright LiuSha


#include "AbilitySystem/Abilities/AuraFireBolt.h"

#include "AbilitySystem/AuraAbilitySystemLibrary.h"
#include "Actor/AuraProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"

FString UAuraFireBolt::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
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
			ScaledDamage);
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
	ScaledDamage);
}

FString UAuraFireBolt::GetNextLevelDescription(int32 Level)
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
	"<Default>Launched %d bolts of fire, "
	"exploding on impact and dealing: </>"
	//Damage
	"<Damage>%d</><Default> fire damage with a chance to burn</>"),
	Level,
	ManaCost,
	Cooldown,
	FMath::Min(Level, NumProjectiles),
	ScaledDamage);
}

void UAuraFireBolt::SpawnProjectiles(const FVector& ProjectileTargetLocation, const FGameplayTag& SocketTag,
	bool bOverridePitch, float PitchOverride, AActor* HomingTarget)
{
	const bool bIsServer = GetAvatarActorFromActorInfo()->HasAuthority();
	if(!bIsServer) return;
	
	const FVector SocketLocation = ICombatInterface::Execute_GetCombatSocketLocation(GetAvatarActorFromActorInfo(),SocketTag);
	FRotator Rotation = (ProjectileTargetLocation - SocketLocation).Rotation();
	if (bOverridePitch) Rotation.Pitch = PitchOverride;
    
	const FVector Forward = Rotation.Vector();
	const int32 EffectiveNumProjectiles = FMath::Min(NumProjectiles, GetAbilityLevel());
	TArray<FRotator> Rotations = UAuraAbilitySystemLibrary::EvenlySpacedRotators(Forward, FVector::UpVector, ProjectileSpread, EffectiveNumProjectiles);
    for (const FRotator& Rot : Rotations)
    {
    	FTransform SpawnTransform;
    	SpawnTransform.SetLocation(SocketLocation);
    	SpawnTransform.SetRotation(Rot.Quaternion());

    	AAuraProjectile* Projectile = GetWorld()->SpawnActorDeferred<AAuraProjectile>(
		ProjectileClass,
		SpawnTransform,
		GetOwningActorFromActorInfo(),
		Cast<APawn>(GetOwningActorFromActorInfo()),
		ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

    	Projectile->DamageEffectParams = MakeDamageEffectParamsFromClassDefaults();
	    if (HomingTarget && HomingTarget->Implements<UCombatInterface>())
	    {
		    Projectile->ProjectileMovement->HomingTargetComponent = HomingTarget->GetRootComponent();
	    }
	    else
	    {
	    	Projectile->HomingTargetSceneComponent = NewObject<USceneComponent>(USceneComponent::StaticClass());
	    	Projectile->HomingTargetSceneComponent->SetWorldLocation(ProjectileTargetLocation);
		    Projectile->ProjectileMovement->HomingTargetComponent = Projectile->HomingTargetSceneComponent;
	    }
        Projectile->ProjectileMovement->HomingAccelerationMagnitude = FMath::RandRange(HomingAccelerationMin, HomingAccelerationMax);
    	Projectile->ProjectileMovement->bIsHomingProjectile = bLaunchHomingProjectiles;
    	Projectile->FinishSpawning(SpawnTransform);
    }

	

}
