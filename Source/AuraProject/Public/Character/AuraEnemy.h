// Copyright LiuSha

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AbilitySystem/Data/CharacterClassInfo.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "AuraEnemy.generated.h"

//struct FGameplayTag;



class UWidgetComponent;
class UBehaviorTree;
class AAuraAIController;
/**
 * 
 */
UCLASS()
class AURAPROJECT_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
public:
	AAuraEnemy();
	virtual void PossessedBy(AController* NewController) override;
	/* Enemy Interface*/
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/* End Enemy Interface*/

	/* Combat Interface*/
	virtual int32 GetPlayerLevel() override;
	virtual void Die() override;
	/* end Combat Interface*/
	
    UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnHealthChanged;
	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnMaxHealthChanged;

	void HitReactTagChanged(const FGameplayTag CallBackTag, int32 NewCount);
	
    UPROPERTY(BlueprintReadOnly, Category="Combat")
	bool bHitReacting = false;
	
	float BaseWalkSpeed = 250.F;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat")
	float LifeSpan = 5.f;
	
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

	UPROPERTY(EditAnywhere, Category="AI")
	TObjectPtr<UBehaviorTree> BehaviorTree;

	UPROPERTY()
	TObjectPtr<AAuraAIController> AuraAIController;
	
};
