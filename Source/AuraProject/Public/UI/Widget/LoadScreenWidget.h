// Copyright LiuSha

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoadScreenWidget.generated.h"

/**
 * 
 */
UCLASS()
class AURAPROJECT_API ULoadScreenWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void BlueprintInitializeWidget();
};
