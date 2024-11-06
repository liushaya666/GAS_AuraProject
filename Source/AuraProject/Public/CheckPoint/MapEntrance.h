// Copyright LiuSha

#pragma once

#include "CoreMinimal.h"
#include "CheckPoint/CheckPoint.h"
#include "MapEntrance.generated.h"

/**
 * 
 */
UCLASS()
class AURAPROJECT_API AMapEntrance : public ACheckPoint
{
	GENERATED_BODY()
public:
	/*Highlight Interface*/
	virtual void HighlightActor_Implementation() override;
	/*UnHighlight Interface*/

	/*Save Interface*/
	virtual void LoadActor_Implementation() override;
	/**End Save Interface*/

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UWorld> DestinationMap;

	UPROPERTY(EditAnywhere)
    FName DestinationPlayerStartTag;
protected:
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	
};
