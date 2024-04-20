


#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Mover.generated.h"

/**
 * Handles movement of an actor to a specified location over time.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CRYPTRAIDER_API UMoverEnhanced : public UActorComponent
{
    GENERATED_BODY()

public:
    UMoverEnhanced();

protected:
    virtual void BeginPlay() override;

public:
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    // Toggles the movement.
    void ToggleMovement(bool EnableMovement);

private:
    UPROPERTY(EditAnywhere)
    FVector DestinationOffset;

    UPROPERTY(EditAnywhere)
    float Duration = 4.0f;

    UPROPERTY(EditAnywhere)
    bool bIsMoving = false;

    FVector StartLocation;
};


