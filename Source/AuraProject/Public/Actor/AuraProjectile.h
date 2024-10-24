// Copyright LiuSha

#pragma once

#include "CoreMinimal.h"
#include "AuraAbilityTypes.h"
#include "GameFramework/Actor.h"
#include "AuraProjectile.generated.h"


class UProjectileMovementComponent;
class USphereComponent;
class UNiagaraSystem;

UCLASS()
class AURAPROJECT_API AAuraProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AAuraProjectile();
	
	UPROPERTY(VisibleAnywhere)
    TObjectPtr<UProjectileMovementComponent> ProjectileMovement;

	UPROPERTY(BlueprintReadWrite, meta = (ExposeOnSpawn = true))
	FDamageEffectParams DamageEffectParams;

	UPROPERTY()
	TObjectPtr<USceneComponent> HomingTargetSceneComponent;
protected:
	virtual void BeginPlay() override;
	void OnHit();
	virtual void Destroyed() override;
	UPROPERTY(VisibleAnywhere,BlueprintReadonly)
	TObjectPtr<USphereComponent> Sphere;
	UFUNCTION()
	void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
private:
    float LifeSpan = 8.f;
	bool bHit = false;


	UPROPERTY(EditAnywhere)
	TObjectPtr<UNiagaraSystem> ImpactEffect;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USoundBase> ImpactSound;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USoundBase> LoopingSound;
    UPROPERTY()
	TObjectPtr<UAudioComponent> LoopingSoundComponent;
};
