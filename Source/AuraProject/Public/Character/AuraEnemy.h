// Copyright LiuSha

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AbilitySystem/Data/CharacterClassInfo.h"
#include "AuraEnemy.generated.h"

struct FGameplayTag;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeChangedDelegate, float, NewValue);


class UWidgetComponent;
/**
 * 
 */
UCLASS()
class AURAPROJECT_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
public:
	AAuraEnemy();
	/* Enemy Interface*/
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/* End Enemy Interface*/

	/* Combat Interface*/
	virtual int32 GetPlayerLevel() override;
	/* end Combat Interface*/
	
    UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedDelegate OnHealthChanged;
	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedDelegate OnMaxHealthChanged;

	void HitReactTagChanged(const FGameplayTag CallBackTag, int32 NewCount);
	
    UPROPERTY(BlueprintReadOnly, Category="Combat")
	bool bHitReacting = false;
	float BaseWalkSpeed = 250.F;
	
protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
	virtual void InitializeDefaultAttributes() const override;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Character Class Default")
	int32 Level = 1;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Character Class Default")
	ECharacterClass CharacterClass = ECharacterClass::Warrior;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> HealthBar;
};
