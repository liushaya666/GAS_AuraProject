// Copyright LiuSha

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "LoadScreenSaveGame.generated.h"


UENUM(BlueprintType)
enum ESaveSlotStatus
{
	Vacant,
	EnterName,
	Taken
};
/**
 * 
 */
UCLASS()
class AURAPROJECT_API ULoadScreenSaveGame : public USaveGame
{
	GENERATED_BODY()
public:

	UPROPERTY()
	FString SlotName = FString();

	UPROPERTY()
	int32 SlotIndex = 0;

	UPROPERTY()
	FString PlayerName = FString("Default Name");

	UPROPERTY()
	TEnumAsByte<ESaveSlotStatus> SaveSlotStatus = ESaveSlotStatus::Vacant;
};